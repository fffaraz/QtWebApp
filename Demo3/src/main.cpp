/**
  @file
  @author Stefan Frings
*/

#include "startup.h"

using namespace stefanfrings;

/**
  Entry point of the program.
*/
int main(int argc, char *argv[])
{
    // Use qtservice to start the application as a Windows service
    Startup startup(argc, argv);
    return startup.exec();

}
