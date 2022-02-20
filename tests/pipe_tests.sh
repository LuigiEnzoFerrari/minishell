#!/bin/sh

# MINISHELL="valgrind -q --leak-check=full --track-fds=no ./minishell"
# MINISHELL="valgrind -q --leak-check=full --track-fds=yes ./minishell"
MINISHELL="./minishell"

echo 'echo |\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'env | grep USER\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'env | grep PATH\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'cat | cat | ls\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaa | wc -l\necho $?\nexit' | $MINISHELL
echo "=============================================================="
