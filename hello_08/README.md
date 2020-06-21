make构建
=======

参考资料: C语言核心技术 P527 P538

格式

目标: 前提 ...
    \t命令
    \t...

$@ 目标名称
$^ 前提的列表，排除重复
$< 第一个前提

make命令
=======

在主目录中执行：

make
make circle
make -n circle
make clean

输出结果: ./circle