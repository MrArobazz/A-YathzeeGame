#pragma once
#include "XmlNode.h"
#include <iostream>
#include <fstream>

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

	bool save(std::ofstream& stream) const;
	bool save(std::string& uri) const;

	friend std::ostream& operator<<(std::ostream& out, const XmlDocument& doc);
};

