#include "Node.h"
#include <memory>

using namespace liuyuan;

void liuyuan::Node::add_sibling(shared_ptr<Node> &newSib)
{
	// 建立一个weak智能指针，来遍历所有的兄弟节点
	shared_ptr<Node> ite(this->mPtr_sibling);
	
	// 寻找可以插入sibling的位置
	while (ite) { ite = ite->mPtr_sibling; }

	ite->mPtr_sibling = newSib;	
}

bool liuyuan::Node::has_sibling(shared_ptr<Node> &sinName)
{
	shared_ptr<Node> ite = this->mPtr_sibling;
	
	while (ite) 
	{
		if (ite->mStr_nodeName == sinName->mStr_nodeName)
		{
			return true;
		}
	}

	return false;
}
