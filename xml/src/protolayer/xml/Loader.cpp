#include "Loader.h"


namespace protolayer
{

namespace xml
{

namespace
{

struct Loader
{
  static bool flag;

  static xercesc::DOMImplementation* implementation;

  //  static xercesc::DOMWriter* writer;

  //  static xercesc::DOMBuilder* parser;

  static void initialise();

};

bool Loader::flag = true;

xercesc::DOMImplementation* Loader::implementation = 0;

  //xercesc::DOMWriter* Loader::writer = 0;

  //xercesc::DOMBuilder* Loader::parser = 0;

void Loader::initialise()
{
  if (flag) {
    try {
      xercesc::XMLPlatformUtils::Initialize();
    } catch (const xercesc::XMLException& toCatch) {
      throw; // XMLException("Failed initialisation");
    }

    XMLCh* str = ::xercesc::XMLString::transcode("Range");
    implementation = ::xercesc::DOMImplementationRegistry::getDOMImplementation(str);
    //    writer = implementation->createDOMWriter();
    //    parser = implementation->createDOMBuilder(xercesc::DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    flag = false;
  }
}

}

xercesc::DOMDocument* createDocument()
{
  Loader::initialise();
  XMLCh* str = xercesc::XMLString::transcode("root");
  return Loader::implementation->createDocument(0, str, 0);  
}


void writeToFile(std::string& fileName, xercesc::DOMDocument* document)
{
  Loader::initialise();
  xercesc::LocalFileFormatTarget* target = new xercesc::LocalFileFormatTarget(fileName.c_str());
  //  Loader::writer->writeNode(target, *document);
  delete target;
}


xercesc::DOMDocument* readFromFile(std::string& fileName)
{
  Loader::initialise();
  xercesc::DOMDocument* temp = 0;
  //  temp = Loader::parser->parseURI(fileName.c_str());
  return temp;
}


void release(xercesc::DOMDocument& document)
{
}


}


}
