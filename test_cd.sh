#!/bin/sh

MINISHELL="valgrind -q --leak-check=full --track-fds=no ./minishell"
BASH="bash"
# MINISHELL="valgrind -q --leak-check=full --track-fds=yes ./minishell"
# MINISHELL="./minishell"

make
clear

#Case cd is null
echo 'cd\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd .\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd -\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd ~\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd ~~\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd nope~\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd ~nope\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd ~/\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd ..\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd ..\ncd ..\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd ../..\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd /\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd \npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'cd not_exist\necho $?\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'unset HOME\ncd\necho $?\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'unset HOME\ncd \necho $?\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'unset HOME\ncd ~\necho $?\npwd\nexit' | $MINISHELL
echo "══════════════════════════════════════════════════════════════"
echo 'unset HOME\ncd $HOME\necho $?\npwd\nexit' | $MINISHELL