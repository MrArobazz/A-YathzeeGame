#pragma once
#include <vector>
#include <string>

class XmlNode
{
	std::vector<XmlNode*> childNodes;
	std::string name;
	std::string inner;
	XmlNode* nextSibling;
public:
	XmlNode(const std::string& name) : nextSibling(nullptr) {};
	~XmlNode() { delete nextSibling; };
	XmlNode(const XmlNode& other);
	XmlDocument& operator=(const XmlDocument&);

};