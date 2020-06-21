多文件编译
========
gcc -o hello hello_03.c add.c

或单个编译
========
gcc -c hello_03.c 
gcc -c add.c

gcc -o hello hello_03.o add.o

目标文件(.o)
===========
不可执行