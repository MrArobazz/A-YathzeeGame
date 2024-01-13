#include "XmlDocument.h"

XmlDocument::XmlDocument(const XmlDocument& other)
{
    elementTree = nullptr;
    if (other.elementTree)
        elementTree = new XmlNode(*other.elementTree);
}

XmlDocument& XmlDocument::operator=(const XmlDocument& other)
{
    if (this == &other)
        return *this;
    delete elementTree;
    elementTree = nullptr;
    if (other.elementTree)
        elementTree = new XmlNode(*other.elementTree);
    return *this;
}

XmlNode XmlDocument::createElement(const std::string& name)
{
    return XmlNode(name);
}

void XmlDocument::addElementTree(XmlNode& root)
{
    if (!elementTree)
        elementTree = new XmlNode(root);
}

void XmlDocument::removeElementTree()
{
    delete elementTree;
    elementTree = nullptr;
}

void XmlDocument::replaceElementTree(XmlNode& newRoot)
{
    delete elementTree;
    elementTree = new XmlNode(newRoot);
}

void XmlDocument::save(std::ostream& stream)
{

}

void XmlDocument::save(std::string& uri)
{

}
