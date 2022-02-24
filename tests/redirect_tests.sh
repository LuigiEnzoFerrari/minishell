#!/bin/sh

# MINISHELL="valgrind -q --leak-check=full --track-fds=no ./minishell"
# BASH="bash"
# MINISHELL="valgrind -q --leak-check=full --track-fds=yes ./minishell"
MINISHELL="./minishell"

echo 'echo aaaaaaaaaaaaaaaaa > out\ncat out\necho $?\nrm -rf out\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaaaaaaaa > out\ncat out | cat out > out\ncat out\necho $?\nrm -rf out\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaaaaaaaa > out\necho "cat out | cat out > out"\necho $?\nrm -rf out\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1 > out2 > out3\ncat out1\ncat out2\ncat out3\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa>out1>out2>out3\ncat out1\ncat out2\ncat out3\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat < out1 < out2 < out3\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa>out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat <out1<out2<out3\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat <out1<out2<out3\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\ncat < out1 > out2\ncat < out2\nrm -rf out1 out2\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat <not_exist<out2<out3\necho $?\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat <out1<not_exist<out3\necho $?\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat <out1<out2<not_exist\necho $?\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat < out1 < out2 < not_exist\necho $?\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\n< out1 tr a b | tr b c | tr c d\necho $?\nrm -rf out1\nexit' | $MINISHELL
echo "=============================================================="
echo 'ping -c1 8.8.8.8 > out1\ncat out1 | grep ms | more\necho $?\nrm -rf out1\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo > <\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo >\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo "=============================================================="
echo '<< OUT\nexit' | $MINISHELL
echo "=============================================================="
echo '<<OUT\nexit' | $MINISHELL