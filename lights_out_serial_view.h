#ifndef PUZZLEBOX_LIGHTS_OUT_SERIAL_VIEW_H
#define PUZZLEBOX_LIGHTS_OUT_SERIAL_VIEW_H

#include <arduino.h>

#include "lights_out.h"

class LightsOutSerialView {
 public:
  explicit LightsOutSerialView(LightsOut& lightsOut);

  void begin();
  void render();
 private:
  LightsOut& lightsOut_;
};

#endif  // PUZZLEBOX_LIGHTS_OUT_SERIAL_VIEW_H
