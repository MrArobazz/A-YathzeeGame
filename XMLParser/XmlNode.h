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
	XmlNode(const std::string& name) : name(name), nextSibling(nullptr) {};
	~XmlNode();
	XmlNode(const XmlNode& other);
	XmlNode& operator=(const XmlNode&);

	void appendChild(XmlNode&);
	void insertBefore(XmlNode&, XmlNode&);
	void insertAfter(XmlNode&, XmlNode&);

	bool operator==(const XmlNode&);
};