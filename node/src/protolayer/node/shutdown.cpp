#include <unistd.h>
#include "protolayer/protolayer-server.h"

int main()
{
  protolayer::server::Client client(80000);
  client.shutdown();
  return 0;
}

