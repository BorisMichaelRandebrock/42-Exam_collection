#!/bin/bash
# basic complining and testing

gcc -Wextra -Werror -Wall minishell.c -o minishell

./minishell cd a b c d e
./minishell cd x
./minishell cd ..
./minishell x
./minishell /bin/echo x
./minishell /bin/echo y ; /bin/ls | /usr/bin/wc -l
./minishell /bin/sleep 3 | /bin/sleep 3 | /bin/sleep 3 | /bin/sleep 3
./minishell /bin/ls "|" /usr/bin/grep minishell ";" /bin/echo i love my minishell 🥰
