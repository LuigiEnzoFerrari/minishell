# Infos to think

1. Pipes, redirects and operators work even when down have a space beetween them and the "arguments".
2. When pipes ... are beetween quotes they are treated as part of the string.
3. Even when we add a lot of extra spaces as input the came back well formated when we go arrow up and history.
4. When the **filename**(first word of the comand line) is in double quotes the result is the same as witout it.
5. Colocar 1 ou 2 variaveis para serem expandidas ao mesmo tempo

como que vc fez no caso de ter uma variavel de ambiente dentro das aspas strings com continuacao depois da variavel

colorcar varios $$$ um do lado do outro

# infos

1. when a command line is put in the execve u should put the path and the commans as it is.
    a. if you expand the command when you receive, the aout put about the command you will the path as well.

atribuitions that comes before the command shouldn't will be ignored, attribuition after the command will be treat like a simple string, atributions in solo line will work

    when you print something with echo you shoudn't terminated with a space unless the space is in the end between quotes.

    when you change director you always set a new oldpath in env variables.

    using some built-in that shouldn't have arguments with arguments

    export should be able to persist even in process child, but atribution without export not should env be in the env list

    export are organized by alphabetic ordem