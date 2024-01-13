#pragma once
#include "XmlNode.h"

class XmlDocument
{
	XmlNode* elementTree;
public:
	XmlDocument() : elementTree(nullptr) {};
	~XmlDocument() { delete elementTree; };
	XmlDocument(const XmlDocument& other);
	XmlDocument& operator=(const XmlDocument&);

	XmlNode createElement(const std::string& name);
	void addElementTree(XmlNode&);
	void removeElementTree();
	void replaceElementTree(XmlNode&);

	void save(std::ostream& stream);
	void save(std::string& uri);
};

