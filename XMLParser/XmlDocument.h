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

	XmlNode* createElement(const std::string& name);
};

