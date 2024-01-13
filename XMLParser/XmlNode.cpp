#include "XmlNode.h"

XmlNode::XmlNode(const XmlNode& other)
	: name(other.name), inner(other.inner)
{
	for (const auto& o_node : other.childNodes)
		if (o_node)
			childNodes.push_back(new XmlNode(*o_node));

	nextSibling = new XmlNode(*other.nextSibling);
}
