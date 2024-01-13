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

bool XmlDocument::save(std::ofstream& file) const
{
    if (file.is_open()) {
        file << *this;
        file.close();
        return true;
    }
    return false;
}

bool XmlDocument::save(std::string& uri) const
{
    std::ofstream file(uri, std::ios::out);
    return save(file);
}

std::ostream& operator<<(std::ostream& out, const XmlDocument& doc)
{
    if (doc.elementTree) {
        out << "<?xml version = \"1.0\"?>";
        out << 
    }
}
