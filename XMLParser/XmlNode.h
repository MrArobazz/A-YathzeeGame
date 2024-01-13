#pragma once
#include <vector>
#include <string>

class XmlNode
{
public:
	std::vector<XmlNode*> childNodes;
	std::string name;
	std::string inner;
	XmlNode* nextSibling;
	XmlNode(const std::string& name) : name(name), nextSibling(nullptr) {};
	~XmlNode();
	XmlNode(const XmlNode& other);
	XmlNode& operator=(const XmlNode&);

};