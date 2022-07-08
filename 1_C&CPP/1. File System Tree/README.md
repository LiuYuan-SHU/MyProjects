# File System Tree

## To-Do List

- [] 完成`./shell.h`的设计，先将基本的程序运行逻辑需要调用到的函数声明写出来
- [] 首先设计和测试完成splitCmd函数。
	- [] 将tools.h中的内容删除，整合到command中

## 项目架构

-- main.cpp
	|
	|--	shell.h
		 |
		 |--	command.h
		 |	|
		 |	|-----	tools.h
		 |
		 |--	directory.h
		 |
		 |--	Node.h

* shell.h：程序的基本运行逻辑对象，整个程序只有一个对象
* command.h：存储命令和路径，并且执行命令
* tools.h：为command提供基本的函数
* directory.h：存储dirName，baseName，并进行调整
* Node.h：数据结构
