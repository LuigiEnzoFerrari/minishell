#!/bin/sh

# MINISHELL="valgrind -q --leak-check=full --track-fds=no ./minishell"
# MINISHELL="valgrind -q --leak-check=full --track-fds=yes ./minishell"
MINISHELL="./minishell"

# echo "=============================================================="
# echo '<< OUT \n exit' | $MINISHELL
# echo "=============================================================="
echo '<<OUT' | $MINISHELL