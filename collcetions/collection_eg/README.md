从github例子中完成自定义标准库
==========================
1、下载例子
---------
https://github.com/srdja/Collections-C#examples

2、安装cmake，cpputest
---------------------
```
sudo apt install cmake
```
在新立得中安装cpputest

3、在项目中创建build目录，在build目录中执行cmake
-------------------------------------------
```
mkdir build
cd build
cmake ..
```

4、在build目录中执行make
----------------------
```
make
```

5、在build目录中安装
------------------
```
sudo make install
```
*生成/usr/local/lib/libcollectc.so库*
.so共享库可以使用在任意一个项目中

编译
===
gcc hello.c -static -lcollectc -o hello