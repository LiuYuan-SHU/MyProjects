# File System Tree

## To-Do List

- [ ] 删除`Directory`类
- [ ] 重构`Command`类

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

## 目前存在的问题

需要认真考虑`Directory`本身存在的意义。就目前而言是没有必要的

如果删除`Directory`，那么需要在Command类中继承、重写`dirname`&`basename`

删除主要还需要思考的事情是，将pathname的分割交给谁

所以最好的解决方法可能是，重新设计一个新的类内类，并且在Command类中组合这个类。从逻辑的角度也是清晰的思路

所以到最后整个代码的样子应该是：

```cpp
class Command
{
    string command;
    class PathName
    {
        string pathname;
        
        // 一些字符串处理函数
    };
};
class Shell
{
	shared_ptr<Node> root, pwd;
    Command cmd;
};
```

