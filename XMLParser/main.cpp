#include "XmlDocument.h"


using namespace std;
int main()
{
    XmlDocument doc;
    XmlDocument doc2(doc);
    XmlNode n = doc.createElement("test");
    XmlNode n2 = doc.createElement("test2");
    doc.addElementTree(n);
    doc.addElementTree(n2);
    doc.replaceElementTree(n2);
    XmlDocument doc3(doc);
    doc2 = doc3;
}