#include <string>
#include <protolayer/protolayer-assembly.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-xml.h>

#include "AssemblyTest.hpp"
#include "DomainInstanceDependencyTest.hpp"
#include "DomainInstanceTest.hpp"
#include "InstanceDependencyTest.hpp"
#include "InstanceTest.hpp"
#include "LayerTest.hpp"
#include "ReferenceTest.hpp"

int main()
{
  protolayer::assembly::InstanceTest instanceTest;
  instanceTest.testSuite();

  protolayer::assembly::ReferenceTest referenceTest;
  referenceTest.testSuite();

  protolayer::assembly::LayerTest layerTest;
  layerTest.testSuite();

  protolayer::assembly::DomainInstanceTest domainInstTest;
  domainInstTest.testSuite();

  protolayer::assembly::AssemblyTest assemblyTest;
  assemblyTest.testSuite();

  /** TODO: Implement tests */
  protolayer::assembly::DomainInstanceDependencyTest domainInstDepTest;
  domainInstDepTest.testSuite();

  /** TODO: Implement tests */
  protolayer::assembly::InstanceDependencyTest instDepTest;
  instDepTest.testSuite();

  return 0;
}

