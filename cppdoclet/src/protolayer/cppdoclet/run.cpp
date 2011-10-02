#include <map>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <rpc/rpc.h>
#include <iostream.h>
#include <errno.h>
#include <stdexcept>
#include <sys/stat.h>
#include <dirent.h>

#include "protolayer/protolayer-util.h"
#include "protolayer/protolayer-iostream.h"
#include "protolayer/protolayer-logger.h"
#include "protolayer/protolayer.h"

#include "Namespace.h"
#include "Component.h"
#include "PrototypeDoclet.h"
#include "RemoteDoclet.h"
#include "SerialiseDoclet.h"
#include "PersistDoclet.h"
#include "PoolDoclet.h"
#include "Dependencies.h"


int main(int num, char* args[])
{
  if (mkdir("/tmp/cppdoclet", 0755) == -1) {
    if (errno != EEXIST) {
      throw std::runtime_error("Unable to create generation directory");
    }
  }

  if (mkdir("/tmp/cppdoclet/src", 0755) == -1) {
    if (errno != EEXIST) {
      throw std::runtime_error("Unable to create generation directory");
    }
  }

  // Reconstruct command to redirect output to the temporary file "/tmp/cppdoclet/deps"
  std::string token;
  std::string file;

  std::string preprocess("g++");
  std::string compile("g++");

  for (int i = 1; i < num; i++) {
    token = args[i];

    if (token == "-c") {
      file = args[i + 1];
    }

    // Extract all include paths
    if (protolayer::util::beginsWith(token, "-I")) {
      preprocess += " ";
      preprocess += token;
    }

    // Extract the file being compiled
    if (token == "-c") {
      preprocess += " ";
      preprocess += "-c";
      preprocess += " ";
      preprocess += args[i+1];
    }

    compile += " ";
    compile += args[i];
  }

  // Switch on preprocessing to extract dependencies file "/tmp/cppdoclet/deps"
  preprocess += " -MM -MP -MF /tmp/cppdoclet/deps";
  system(preprocess.c_str());

  // First process only the specific component being analysed
  //  protolayer::cppdoclet::Component component(file);

  // Obtain inmemory dependencies from the dependency file
  protolayer::cppdoclet::Dependencies dependencies("/tmp/cppdoclet/deps");

  // Apply doclets to the dependency/parse tree
  std::string outputDir("/tmp/cppdoclet/src");
  //protolayer::cppdoclet::PrototypeDoclet prototypeDoclet(dependencies);
  // protolayer::cppdoclet::PersistDoclet persistDoclet(dependencies);
  protolayer::cppdoclet::SerialiseDoclet serialiseDoclet(dependencies);
  //  protolayer::cppdoclet::RemoteDoclet remoteDoclet(dependencies);

  std::string output;
  dependencies.getTargetComponent().serialise(output);
  std::cout << output << std::endl;

  system(compile.c_str());





  /*
  for (int i = 1; i < num; i++) {
    protolayer::cppdoclet::Component component(args[i]);

    std::string outputDir("/tmp");
    protolayer::cppdoclet::PrototypeDoclet prototypeDoclet(component, outputDir);
    protolayer::cppdoclet::RemoteDoclet remoteDoclet(component, outputDir);
    protolayer::cppdoclet::SerialiseDoclet serialiseDoclet(component, outputDir);
    protolayer::cppdoclet::PersistDoclet persistDoclet(component, outputDir);
  }
  */

  /*
  std::string classPoolTag("@pool");
  std::string classPooledTag("@pooled");
  std::string classManagedTag("@managed");
  std::string classPrototypedTag("@prototyped");
  std::string classStatelessTag("@stateless");
  std::string classStatefulTag("@stateful");
  std::string classRemoteTag("@remote");
  std::string classLibrary("@library");

  std::string attributeSerialisedTag("@serialised");
  std::string attributePrototypedTag("@prototype");
  std::string attributePersistTag("@persist");
  std::string attributePersistedTag("@persisted");
  std::string attributexmlAttributeTag("@xml attribute");
  std::string classXmlElementTag("@xml element");

  std::string methodRemoteTag("@remote");

  std::string persistedPrototypeTag("@prototype serialised persisted");
  std::string persistedPrototypeTag("@prototype serialised");
  std::string persistedPrototypeTag("@prototype persisted");

  std::string xdrKeyword("xdr");
  std::string xmlKeyword("xml");
  std::string soapKeyword("soap");

  findClasses(buffer);
  findAttributes(className, attributes);
  findMethods(className, buffer);
  */

  return 0;
}
