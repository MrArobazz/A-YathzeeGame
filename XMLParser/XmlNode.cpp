#include "XmlNode.h"

XmlNode::~XmlNode()
{
	for (auto cNode : childNodes)
		delete cNode;
	delete nextSibling;
}

XmlNode::XmlNode(const XmlNode& other)
	: name(other.name), inner(other.inner)
{
	for (const auto& o_node : other.childNodes)
		childNodes.push_back(new XmlNode(*o_node));

	nextSibling = nullptr;
	if (other.nextSibling)
		nextSibling = new XmlNode(*other.nextSibling);
}

XmlNode& XmlNode::operator=(const XmlNode& other)
{
	if (this == &other)
		return *this;
	delete nextSibling;
	for (auto cNode : childNodes)
		delete cNode;
	childNodes = {};
	for (auto cNode : other.childNodes)
		childNodes.push_back(new XmlNode(*cNode));
	name = other.name;
	inner = other.inner;

	nextSibling = new XmlNode(*other.nextSibling);
	return *this;
}
