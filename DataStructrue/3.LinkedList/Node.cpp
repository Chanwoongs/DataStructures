#include "Node.h"

std::ostream& operator<<(std::ostream& os, const Node& node)
{
	return os << "Data: " << node.data;
}

Node::Node()
{
}

Node::Node(int data)
	: data(data)
{
}
