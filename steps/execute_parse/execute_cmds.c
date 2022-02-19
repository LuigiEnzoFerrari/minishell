#include <minishell.h>



void tratar(int sig)
{
    if (sig == SIGINT)
        write(1, "\n", 1);
}

void	each_cmd(t_cmds  *cmds, t_env_vars *vars, int *save, int *stdpipe)
{

    mysignal(SIGINT, tratar);
    case_pipe(save, cmds, stdpipe);
    case_redirect(save[IN], cmds);
    if (cmds->args == NULL)
        ;
    else if (isbuiltin(*cmds->args))
        execute_builtin(cmds->args, vars); 
    else
        execute_builtout(cmds->args, vars);
    ajust_pipes(cmds, stdpipe, save);
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
