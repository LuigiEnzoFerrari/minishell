#include <minishell.h>

void    builtin_echo(char **args)
{
    size_t  i;
	int		option;

    i = 0;
	option = 0;
    if (*args == NULL);
    else if (ft_strcmp(*args, "-n") == 0)
		option = 1;
	i += option;
    while (args[i] != NULL)
    {
        ft_putstr(args[i]);
        i++;
        if (args[i] != NULL)
            write(1, " ", 1);
    }
	if (option != 1)
        write(1, "\n", 1);
}
