#ifndef PUZZLEBOX_LIGHTS_OUT_TRELLIS_VIEW_H
#define PUZZLEBOX_LIGHTS_OUT_TRELLIS_VIEW_H

#include <arduino.h>

#include "Adafruit_Trellis.h"
#include "lights_out.h"

class LightsOutTrellisView {
 public:
  explicit LightsOutTrellisView(LightsOut& lightsOut);
  void begin();
  void render();
  void renderWithDelay(int delay_time);
  void renderWinSequence();
  bool shouldHandleButtonActivity();
  bool wasButtonJustPressed(int row, int column);

 private:
  LightsOut& lightsOut_;
  Adafruit_Trellis matrix_;
  Adafruit_TrellisSet trellis_;
  int numberOfKeys_;
  unsigned long lastSwitchRead_;

  void renderStartupSequence();
};

#endif  // PUZZLEBOX_LIGHTS_OUT_TRELLIS_VIEW_H