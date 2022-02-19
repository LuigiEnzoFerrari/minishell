#include <minishell.h>

int    set_errno(int exit_status)
{
    if (exit_status == EXIT_SUCCESS)
        return (EXIT_SUCCESS);
    else if (exit_status != ENOEXEC)
    {
        if (exit_status == ENOENT)
            return (EX_NOTFOUND);
        return (EX_NOEXEC);
    }
    return (exit_status);
}

char	*find_path(char *arg, char **bin_paths)
{
    char *path;
    char *slash;
    struct stat stats;
    while(*bin_paths)
    {
        slash = ft_strjoin(*bin_paths, "/");
        path = ft_strjoin(slash, arg);
        free(slash);
        if (stat(path, &stats) == 0)
        {
            free(arg);
            return (path);
        }
        free(path);
        bin_paths++;
    }
    return arg;
}

void    execute_builtout(char **args, char **envs, char **bin_paths)
{
    int     pid;
    int     status;

    status = 0;
    if(bin_paths != NULL)
        *args = find_path(*args, bin_paths);
    pid = fork();
    if (pid == 0)
    {
        execve(*args, args, envs);
        perror(strerror(errno));
        exit(errno);
    }
    if(bin_paths != NULL)
        ft_arrayfree(bin_paths);
    waitpid(pid, &status, 0);
    *last_status_number() =	set_errno(WEXITSTATUS(status));
}

void tratar(int sig)
{
    if (sig == SIGINT)
        write(1, "\n", 1);
}

char *to_environ(char *key, char *value)
{
    char *environ;

    environ = ft_strjoin(key, "=");
    environ = ft_rejoin(environ, value);
    return (environ);
}

char    **t_environ_to_environ(t_environ *global_vars)
{
    char    **envs;
    size_t  size;

    size = size_envs(global_vars);
    envs = malloc(sizeof(char *) * (size + 1));
    envs[size] = NULL;
    while (global_vars != NULL)
    {
        size--;
        envs[size] = to_environ(global_vars->key, global_vars->value);
        global_vars = global_vars->next;
    }
    return (envs);
}

char	**parse_path(char *path)
{
    char	**bin_paths;

    bin_paths = ft_split(path, ':');
    return bin_paths;
}

void	each_cmd(t_cmds  *cmds, t_env_vars *vars, int *save, int *stdpipe)
{
    char    **envs;
    char	**bin_paths;
    char	*path;
    
    path = get_env_value(vars->global_vars, "PATH");
    bin_paths = parse_path(path);
    envs = t_environ_to_environ(vars->global_vars);
    mysignal(SIGINT, tratar);
    case_pipe(save, cmds, stdpipe);
    case_redirect(save[IN], cmds);
    if (cmds->args == NULL)
        ;
    else if (isbuiltin(*cmds->args))
        execute_builtin(cmds->args, vars); 
    else
        execute_builtout(cmds->args, envs, bin_paths);
    ajust_pipes(cmds, stdpipe, save);
    ft_arrayfree(envs);
}

void    for_each_cmd(t_cmds *cmds, t_env_vars *vars)
{
    t_cmds  *temp;
    int		save[2];
    int     stdpipe[2];
    int     index;

    temp = cmds; 
    save[IN] = IN;
    index = 0;
    save_pipes(stdpipe);
    while (cmds != NULL)
    {
        cmds->index = index;
        pipe(cmds->pipe1);
        each_cmd(cmds, vars, save, stdpipe);
        index++;
        cmds = cmds->next;
    }
    close(save[IN]);
    delete_cmds(&temp);
}
    
void	execute_cmds(t_tokens *tokens, t_env_vars *vars)
{
    t_cmds  *cmds;

    if (check_syntax(tokens))
    {
        delete_tokens(&tokens);
        return ;
    }
    cmds = pipe_commands(tokens);
    for_each_cmd(cmds, vars);
    delete_tokens(&tokens);
}
