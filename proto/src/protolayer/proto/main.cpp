#include <sys/time.h> 
#include <sys/types.h> 
#include <sys/resource.h> 
#include <unistd.h>

#include "forward.h"
#include "view/ViewLayer.h"
#include "state/StateLayer.h"
#include "controller/ControllerLayer.h"


extern "C" { OSErr CPSEnableForegroundOperation(ProcessSerialNumber *psn); }

void makeFrontProcess()
{
  ProcessSerialNumber currentProcess = { 0, kCurrentProcess };
  OSStatus result = GetCurrentProcess(&currentProcess);
  result = CPSEnableForegroundOperation(&currentProcess);
  SetFrontProcess(&currentProcess);
}

void setProcessLimits()
{
  struct rlimit limit;
  getrlimit(RLIMIT_STACK, &limit);
  limit.rlim_max = limit.rlim_cur * 3;
  limit.rlim_max = limit.rlim_max * 3;
  setrlimit(RLIMIT_STACK, &limit);
}


void evaluateFlags(int argc, char *argv[])
{
  bool ugly = false;

  char *cvalue = NULL;
  int index;
  int c;

  opterr = 0;

  while ((c = getopt (argc, argv, "u")) != -1)
    switch (c)
      {
      case 'u':
	ugly = true;
	break;
      case '?':
	if (isprint (optopt))
	  fprintf (stderr, "Unknown option `-%c'.\n", optopt);
	else
	  fprintf (stderr,
		   "Unknown option character `\\x%x'.\n",
		   optopt);
      default:
	abort ();
      }

  std::cout << ugly << std::endl;
}


int main(int argc, char *argv[])
{
  makeFrontProcess();
  evaluateFlags(argc, argv);
  setProcessLimits();

  protolayer::proto::ViewLayer* viewLayer =
    new protolayer::proto::ViewLayer();

  protolayer::proto::StateLayer* stateLayer =
    new protolayer::proto::StateLayer(*viewLayer);

  protolayer::proto::ControllerLayer* controllerLayer =
    new protolayer::proto::ControllerLayer(*stateLayer);

  RunApplicationEventLoop();  
  return 0;
}
