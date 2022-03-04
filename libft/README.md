# Libft 42 School

## About

Libft is a open source C library, with several function to help all kinds of projects in development. This is a very well organized and more completed version of the [Ecole 42](https://www.42.fr/en/ "42 schoool") libft project.

**Read:** [Libft Wiki](https://github.com/LuigiEnzoFerrari/42School_Libft/wiki/libft3 "all functions")



## How to use it

First clone the repository:

```sh
git clone http://github.com/LuigiEnzoFerrari/42School_Libft libft
```

Then use command **make** inside the libft repository to generate a **libft.a** file.


```sh
make -C <libft-path>
```

To clean the **.o** files use the command **make clean**.

```sh
make clean -C <libft-path>
```

Now you have a static library **.a** with all functions from the [libft](https://github.com/LuigiEnzoFerrari/42School_Libft/wiki/libft1 "libft by header type"). Now you can compile your project with the static library.  


First include the libft.h on your **.c** file.

```c
#include <libft.h>
```
Then compile your project like the example below:

```sh
clang main.c -I <libft-path> -L <libft.a-path> -lft
```

**[Libft Wiki](https://github.com/LuigiEnzoFerrari/42School_Libft/wiki/libft3 "42 functions")**