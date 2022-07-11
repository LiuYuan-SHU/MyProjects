#include "Node.h"
#include <cstddef>
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

bool liuyuan::Node::has_sibling(const string& sibName)
{
	shared_ptr<Node> ite = this->mPtr_sibling;
	
	while (ite) 
	{
		if (ite->mStr_nodeName == sibName)
		{
			return true;
		}
	}

	return false;
}

shared_ptr<Node> liuyuan::Node::get_child(const string& childName)
{
	if (this->mPtr_child == std::make_shared<Node>(nullptr))
	{
		return std::make_shared<Node>(nullptr);
	}

	shared_ptr<Node> ite = this->mPtr_child;
	if (childName == "") { return ite; }
	while(ite)
	{
		if (ite->mStr_nodeName == childName)
		{
			return ite;
		}
		ite = ite->mPtr_sibling;
	}

	return std::make_shared<Node>(nullptr);
}

bool liuyuan::Node::has_child(const string &childName)
{
	// 如果当前节点没有子节点
	if (this->get_child() == std::make_shared<Node>(nullptr))
	{
		return false;
	}

	// 查找子节点的兄弟节点
	if (this->get_child()->has_sibling(childName))
	{
		return true;
	}
	else
	{
		return false;
	}
}
