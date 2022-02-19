#!/bin/sh

MINISHELL="valgrind -q --leak-check=full --track-fds=no ./minishell"
# MINISHELL="valgrind -q --leak-check=full --track-fds=yes ./minishell"
# MINISHELL="./minishell"

make
clear

echo '  __  __ _____ _   _ _____  _____ _    _ ______ _      _
 |  \/  |_   _| \ | |_   _|/ ____| |  | |  ____| |    | |
 | \  / | | | |  \| | | | | (___ | |__| | |__  | |    | |
 | |\/| | | | | . ` | | |  \___ \|  __  |  __| | |    | |
 | |  | |_| |_| |\  |_| |_ ____) | |  | | |____| |____| |____
 |_|  |_|_____|_| \_|_____|_____/|_|  |_|______|______|______|'
echo "=============================================================="
echo '\nexit' | $MINISHELL
echo "=============================================================="
echo '         \nexit' | $MINISHELL
echo "=============================================================="
echo 'ls\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'ls srrc\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo '/bin/ls -la\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo Hello\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo -n Hello\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo -n Hello -n \necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'exit 0\necho $?' | $MINISHELL
echo $?
echo "=============================================================="
echo 'exit 1\necho $?' | $MINISHELL
echo $?
echo "=============================================================="
echo 'exit 33\necho $?' | $MINISHELL
echo $?
echo "=============================================================="
echo 'exit exit exit' | $MINISHELL
echo $?
echo "=============================================================="
echo 'exit exit 33' | $MINISHELL
echo $?
echo "=============================================================="
echo 'exit 2 exit\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'exit 2 2\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo '/usr/bin/tr -x\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo '/usr/bin/tr "-x b"\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo '/bin/ls srrc\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo '/bin/lss srrc\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echoo\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'lss\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'pwdd\necho $?\nexit' | $MINISHELL
echo "=============================================================="

echo "echo '\$USER'\\nexit" | $MINISHELL
echo "=============================================================="
echo "echo 'abacate'\nexit" | $MINISHELL
echo "=============================================================="
echo 'export TESTE1=batata\necho $TESTE1\nunset TESTE1\necho $TESTE1\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaa | wc -l\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'unset PATH\nls\nwc\nclear\nexport PATH=/usr/bin\nls\nexit' | $MINISHELL
echo "=============================================================="
echo 'unset PATH\nexport PATH=/usr/bin:/bin\nenv | grep PATH\nexit' | $MINISHELL
echo "=============================================================="

echo 'lol=0\necho $lol\nexit' | $MINISHELL
echo "=============================================================="

echo 'cat | cat | ls\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'export USER=potato\necho $?\necho $USER\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo $USER\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "$USER"\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo "echo "\"\'\$USER\'"\"\necho $?\nexit" | $MINISHELL
echo "=============================================================="
echo "echo "\'\"\$USER\"\'"\necho $?\nexit" | $MINISHELL
echo "=============================================================="
echo 'echo $USER $ $USER $\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo $ $USER $ $USER\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo $USER123\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo $U\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo $USE\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo $USERR\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo ~\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "~"\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo "echo '~'\necho \$?\nexit" | $MINISHELL
echo "=============================================================="
echo "echo ~nope\necho \$?\nexit" | $MINISHELL
echo "=============================================================="
echo "echo nope~\necho \$?\nexit" | $MINISHELL
echo "=============================================================="
echo "echo ~/\necho \$?\nexit" | $MINISHELL
echo "=============================================================="
echo "echo ~ ~nope ~ nope~ ~ ~nope~ ~ 'quote~' ~ \"dquote~\" ~/path '~/quote' \"~/dquote\"\necho \$?\nexit" | $MINISHELL
echo "=============================================================="
echo 'echo "oi\nexit' | $MINISHELL
echo "=============================================================="
echo "echo 'oi\nexit" | $MINISHELL
echo "=============================================================="
echo 'echo ()\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "()"\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo |\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'env | grep USER\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'env | grep PATH\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'top -bn 1\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'env ls\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'env TESTE=1 env | grep TESTE\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'env\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'unset ?\necho $?\nexit' | $MINISHELL
echo "=============================================================="