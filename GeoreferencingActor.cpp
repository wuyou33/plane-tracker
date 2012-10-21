#include "GeoreferencingActor.h"
#include "Georeferencing.h"
#include "Messages.h"

GeoreferencingActor::Handler(const GPSDataMessage* message, const Theron::Address sender){
  AbsolutePositionMessage positionMessage = calculateAbsolutePosition(message)
  Send(positionMessage,multiModalActor);
}

AbsolutePositionMessage calculateAbsolutePosition(GPSDataMessage * message){
  double roll,pitch;
  Georeference::reverseGeoreference(trackerLatitude,trackerLongitude,trackerAltitude,0,0,0,message->lat,message->lon,message->lon,roll,pitch);
  return AbsolutePositionMessage(roll,pitch);
}
