#include <string>
#include <protolayer/xml.h>

#include "ConversionTest.hpp"
#include "ExtractionTest.hpp"
#include "XMLExceptionTest.hpp"

int main(int argc, char ** argv)
{
  protolayer::ConversionTest convTest;
  convTest.testSuite();

  protolayer::ExtractionTest extractionTest;
  extractionTest.testSuite();

  protolayer::XMLExceptionTest xmlExceptionTest;
  xmlExceptionTest.testSuite();

  return 0;
}

