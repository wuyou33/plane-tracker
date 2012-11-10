#include "src/ui/ui.h"
#include "src/ui/ui_ui.h"
#include "src/util/Log.h"
#include "src/util/Messages.h"
#include "src/vision/FrameAnalyzerActor.h"
#include "src/gps/GeoreferencingActor.h"
#include "src/main/MultimodalActor.h"
#include <boost/lexical_cast.hpp>
#include <Theron/Theron.h>

using namespace Messages;

UI::UI( QWidget *parent,
        FrameAnalyzerActor* frameAnalyzerActor,
        GeoreferencingActor* georeferencingActor,
        MultimodalActor* multimodalActor):
    QMainWindow(parent),
    frameAnalyzerActor(frameAnalyzerActor),
    georeferencingActor(georeferencingActor),
    multimodalActor(multimodalActor),
    ui(new Ui::UI) {
    ui->setupUi(this);
      QObject::connect(ui->toggleVideoButton,SIGNAL(clicked(bool)),this,SLOT(toggleVideo(bool)));
      QObject::connect(ui->toggleGPSButton,SIGNAL(clicked(bool)),this,SLOT(toggleGPS(bool)));
      QObject::connect(ui->panSlider, SIGNAL(valueChanged(int)),this,SLOT(updatePan(int)));
      QObject::connect(ui->tiltSlider, SIGNAL(valueChanged(int)),this,SLOT(updateTilt(int)));
      QObject::connect(ui->amplificationSlider, SIGNAL(valueChanged(int)),this,SLOT(updateAmplification(int)));
}


void UI::toggleVideo(bool disabled){
  if (disabled){
    frameAnalyzerActor->disable();
    Log::log("Video disabled.\n");
  } else {
    frameAnalyzerActor->enable();
    Log::log("Video enabled.\n");
  }
}

void UI::toggleGPS(bool disabled) {
  if (disabled){
    georeferencingActor->disable();
    Log::log("GPS disabled.\n");
  } else {
    georeferencingActor->enable();
    Log::log("GPS enabled.\n");
  }
}

void UI::updatePan(int pan){
  this->pan = pan;
  multimodalActor->instructGimbal(AbsolutePositionMessage(pan,tilt));
  Log::debug("Changing pan to: "+ boost::lexical_cast<string>(pan));
}

void UI::updateTilt(int tilt){
  this->tilt = tilt;
  multimodalActor->instructGimbal(AbsolutePositionMessage(pan,tilt));
  Log::debug("Changing tilt to: " + boost::lexical_cast<string>(tilt));
}

void UI::updateAmplification(int amplification){
  Log::debug("Changing amplification to: "+ boost::lexical_cast<string>(amplification));
}

UI::~UI()
{
    delete ui;
}