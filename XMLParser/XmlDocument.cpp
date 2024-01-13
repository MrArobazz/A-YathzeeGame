#include "XmlDocument.h"

XmlDocument::XmlDocument(const XmlDocument& other)
{
    elementTree = new XmlNode(*other.elementTree);
}

XmlDocument& XmlDocument::operator=(const XmlDocument& other)
{
    if (this == &other)
        return *this;
    delete elementTree;
    elementTree = new XmlNode(*other.elementTree);
    return *this;
}

XmlNode* XmlDocument::createElement(const std::string& name)
{
    return new XmlNode(name);
}
