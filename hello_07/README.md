编译构建分离
==========

mkdir bin
mkdir -p lib/utils

在主目录下运行命令

gcc -o ./lib/circle.o -c ./src/circle.c
gcc -o ./lib/utils/circulararea.o -c ./src/utils/circulararea.c
gcc -o ./bin/circle ./lib/circle.o ./lib/utils/circulararea.o -lm

执行
===
./bin/circle