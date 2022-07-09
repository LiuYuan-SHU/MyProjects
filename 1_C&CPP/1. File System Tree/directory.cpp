#include "directory.h"
#include <string>
#include <stdexcept>

using std::string;
using std::invalid_argument;
using namespace liuyuan;

string liuyuan::Directory::dirname(shared_ptr<Node> currentNode)
{
	switch (currentNode->get_type())
	{
	case 'D':
		return currentNode->get_name() == "/" ? "~" : currentNode->get_name();
		break;
	case 'F':
		return (currentNode->get_parent().lock()->get_name());
	default:
		throw invalid_argument("Wrong Node Type");
		break;
	}
}

string liuyuan::Directory::basename(shared_ptr<Node> currentNode)
{
	return currentNode->get_name();	
}
