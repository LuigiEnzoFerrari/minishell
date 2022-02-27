#include <minishell.h>

void	here_ctrl_c(int sig)
{
	*last_status_number() = 130;
	write(1, "\n", 1);
	exit(130);
}

void	while_here_document(char *args, char *line, int write_fd)
{
	mysignal(SIGINT, here_ctrl_c);
	while (42)
	{
		line = readline("> ");
		if (line == NULL)
		{
			ft_putendl_fd(
				HERE_D,
				STDIN_FILENO);
			break ;
		}
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

void	finish_here_doc(int write_fd, int std_fd)
{
	int	read_fd;

	read_fd = open("/tmp/EasyAsHell.tmp", O_RDONLY);
	dup2(read_fd, std_fd);
	close(write_fd);
	close(read_fd);
	unlink("/tmp/EasyAsHell.tmp");
}

void	here_document(char *args, int flag, int std_fd)
{
	int		write_fd;
	char	*line;
	int		pid;
	int		status;

	line = NULL;
	write_fd = open("/tmp/EasyAsHell.tmp", flag, 0664);
	*last_status_number() = 0;
	mysignal(SIGINT, SIG_IGN);
	mysignal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		while_here_document(args, line, write_fd);
	waitpid(pid, &status, 0);
	*last_status_number() = WEXITSTATUS(status);
	finish_here_doc(write_fd, std_fd);
}
