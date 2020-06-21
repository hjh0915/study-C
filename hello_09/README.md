单一的源代码目录
=============

参考redis源码，src目录中均是*.c文件，不再分离单独的目录，编译后的*.o也放在相同目录中

Makefile也进行调整

OBJS = $(patsubst %.c, %.o, $(wildcard *.c))

patsubst和wildcard
==================
想要实现自动检测 cpp 文件，并且自动替换文件名后缀，需要引入两个新的命令：patsubst 和 wildcard。

patsubst 基本语法是：$(patsubst 原模式，目标模式，文件列表)

wildcard 用于获取符合特定规则的文件名

编译/执行
========
在主目录中
make init（编译）
make
./bin/circle（执行）