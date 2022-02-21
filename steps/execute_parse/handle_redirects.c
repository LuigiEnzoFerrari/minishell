#include <minishell.h>

void redirects(char *args, int flag, int std_fd)
{
    int fd;

    fd = open(args, flag, 0664);
    if (fd < 0)
    {
        perror(strerror(errno));
        return ;
    }
    dup2(fd, std_fd);
    close(fd);
}

void here_call(int sig)
{
    *last_status_number() = 130;
    write(1, "\n", 1);
    exit(130);
}

void while_here_document(char *args, char *line, int write_fd)
{
    mysignal(SIGINT, here_call);
    while (42)
    {
        line = readline("> ");
        if (line == NULL)
            break;
        if (ft_strcmp(line, args) == 0)
        {
            free(line);
            exit(0);
        }
        ft_putendl_fd(line, write_fd);
        free(line);
    }
    exit(0);
}

void here_document(char *args, int flag, int std_fd)
{
    int     write_fd;
    int     read_fd;
    char    *line;

    line = NULL;
    write_fd = open("/tmp/EasyAsHell.tmp", flag, 0664);
    *last_status_number() = 0;
    int pid;
    int status;
	mysignal(SIGINT, SIG_IGN);
	mysignal(SIGINT, SIG_IGN);
    pid = fork();
    if (pid == 0)
        while_here_document(args, line, write_fd);
    waitpid(pid, &status, 0);
    *last_status_number() = WEXITSTATUS(status);
    read_fd = open("/tmp/EasyAsHell.tmp", O_RDONLY);
    dup2(read_fd, std_fd);
    close(write_fd);
    close(read_fd);
    unlink(args);
}

static size_t how_many_non_redirects(char **args, int *labels)
{
    size_t i;
    size_t n;

    i = 0;
    n = 0;
    while (args[i] != NULL)
    {
        if (labels[i] == DOUBLE_REDIRECT || labels[i] == SINGLE_REDIRECT || labels[i] == SINGLE_REDIRECT_IN || labels[i] == hereDOC)
            i++;
        else
            n++;
        i++;
    }
    return (n);
}

char **remove_redirects(char **args, int *labels)
{
    char **new_args;
    size_t size;
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    size = how_many_non_redirects(args, labels);
    new_args = malloc(sizeof(char *) * (size + 1));
    while (args[j] != NULL)
    {
        if (labels[j] == DOUBLE_REDIRECT || labels[j] == SINGLE_REDIRECT || labels[j] == SINGLE_REDIRECT_IN || labels[i] == hereDOC)
        {
            j += 2;
            continue;
        }
        new_args[i] = ft_strdup(args[j]);
        i++;
        j++;
    }
    new_args[i] = NULL;
    ft_arrayfree(args);
    return (new_args);
}

void case_redirect(int saveIN, t_cmds *cmds)
{
    size_t i;

    i = 0;
    while (cmds->args[i] != NULL)
    {
        if (cmds->labels[i] == SINGLE_REDIRECT)
            redirects(cmds->args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, OUT);
        else if (cmds->labels[i] == DOUBLE_REDIRECT)
            redirects(cmds->args[i + 1], O_WRONLY | O_CREAT | O_APPEND, OUT);
        else if (cmds->labels[i] == SINGLE_REDIRECT_IN)
            redirects(cmds->args[i + 1], O_RDONLY, IN);
        else if (cmds->labels[i] == hereDOC)
            here_document(cmds->args[i + 1], O_WRONLY | O_CREAT, saveIN);
        i++;
    }
    cmds->args = remove_redirects(cmds->args, cmds->labels);
    if (cmds->args[0] != NULL)
        return;
    ft_arrayfree(cmds->args);
    cmds->args = NULL;
}
