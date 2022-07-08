#ifndef _NODE_H_
#define _NODE_H_

#include <string>
#include <memory>

using std::string;
using std::shared_ptr;
using std::weak_ptr;

namespace liuyuan
{
class Node {
private:
	string mStr_nodeName;
	char mCh_nodeType;
	shared_ptr<Node> mPtr_child;
	shared_ptr<Node> mPtr_sibling;
	weak_ptr<Node> mPtr_parent;
public:
	// 构造函数，必须传入节点的名称和节点的类型
	// 可以选择传入父节点，在默认情况下为空
	Node(const string& nodeName, const char& nodeType, const shared_ptr<Node>& parent = shared_ptr<Node>())
		: mStr_nodeName(nodeName), mCh_nodeType(nodeType), 
		mPtr_child(nullptr), mPtr_sibling(nullptr), mPtr_parent(parent) {}
	// 拷贝构造函数
	Node(const Node& other) = delete;
	// 移动构造函数
	Node(const Node&& other) noexcept = delete;
	// 析构函数
	~Node() = default;

	// 节点比较
	inline bool operator<(const Node& right) { return this->mStr_nodeName < right.mStr_nodeName; }
	// 节点比较
	inline bool operator==(const string& name) { return this->mStr_nodeName == name; }
	// 拷贝赋值符号：不允许使用
	inline Node& operator=(const Node& right) = delete;
	// 移动赋值符号
	inline Node& operator=(const Node&& right) noexcept = delete;

	// name
	inline void set_name(const string& name) { this->mStr_nodeName = name; }
	inline string get_name() { return this->mStr_nodeName; }
	// parent
	inline void set_parent(const weak_ptr<Node> newParent) { this->mPtr_parent = newParent; }
	inline weak_ptr<Node>& get_parent() { return this->mPtr_parent; }
	// sibling
	inline void add_sibling(shared_ptr<Node>& newSib);
	inline bool has_sibling(shared_ptr<Node>& sibName);
	// child
	inline void set_child(const shared_ptr<Node>& newChild) { this->mPtr_child = newChild; }
	inline shared_ptr<Node>& get_child() { return this->mPtr_child; }
};
}

#endif
