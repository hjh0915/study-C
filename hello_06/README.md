源文件目录分离
============

在src目录下运行

gcc -c circle.c
gcc -o ./utils/circulararea.o -c ./utils/circulararea.c
gcc -o circle ./circle.o ./utils/circulararea.o -lm