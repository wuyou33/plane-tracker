#include <Theron/Theron.h>
#include <iostream>
#include <boost/thread.hpp>
#include <termios.h>
#include "src/gps/GPSReceiverInterface.h"
#include "src/util/Messages.h"
#include "src/gps/Protocol.h"
#include "src/util/Log.h"


using namespace std;
using namespace Messages;

GPSReceiverInterface::GPSReceiverInterface(Theron::Framework& framework,
                                           const string serialPort,
                                           const int baudRate,
                                           const Theron::Address georeferencingActor):
  framework(framework),
  serialPort(serialPort),
  baudRate(baudRate),
  georeferencingActor(georeferencingActor) { 
    DEBUG("Starting GPS Receiver worker thread");
    const boost::thread workerThread(&GPSReceiverInterface::workerFunction,this);
}


void GPSReceiverInterface::workerFunction(){
  const int fd = open(serialPort.c_str(),O_RDONLY | O_NOCTTY | O_NDELAY);
  termios options;
  tcgetattr(fd, &options);
  cfsetispeed(&options,baudRate);
  cfsetospeed(&options,baudRate);
  options.c_cflag |= (CLOCAL | CREAD);
  tcsetattr(fd,TCSANOW, &options);
  char* const buffer = (char*)malloc(1024);
  string extra = "";
  while (true){
    read(fd,buffer,1024);
    if (*buffer != '\0'){
      try {
        GPSDataMessage message = Protocol::parseSerialInputForGPS(extra + string(buffer),extra);
        sendGPSData(message);
      } catch (string msg){
        Log::error("Protocol error: " + msg);
      }
    }
    *buffer = '\0';
    boost::this_thread::sleep(boost::posix_time::milliseconds(200)); 
  }
}

void GPSReceiverInterface::sendGPSData(const GPSDataMessage message) {
  framework.Send(message,receiver.GetAddress(),georeferencingActor); 
}
