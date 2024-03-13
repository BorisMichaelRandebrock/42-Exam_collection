#!/bin/bash
# basic complining and testing

gcc -Wextra -Werror -Wall microshell.c -o microshell

./microshell cd a b c d e
./microshell cd x
./microshell cd ..
./microshell x
./microshell /bin/echo x
./microshell /bin/echo y ; /bin/ls | /usr/bin/wc -l
./microshell /bin/sleep 3 | /bin/sleep 3 | /bin/sleep 3 | /bin/sleep 3
./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell 🥰
