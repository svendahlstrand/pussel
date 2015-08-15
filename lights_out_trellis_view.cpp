#include "lights_out_trellis_view.h"

#define INTPIN A2
#define BUTTON_CHECK_TIMEOUT 30

LightsOutTrellisView::LightsOutTrellisView(LightsOut& lightsOut) : lightsOut_(lightsOut), matrix_(), trellis_(&matrix_) {
  numberOfKeys_ = lightsOut_.kNumberOfLights();
  lastSwitchRead_ = 0;

  clearPressedButtonsBuffer();
}

void LightsOutTrellisView::begin() {
  pinMode(INTPIN, INPUT);
  digitalWrite(INTPIN, HIGH);
  trellis_.begin();

  renderStartupSequence();
}

void LightsOutTrellisView::render() {
  int keyNumber;

  for (int row = 0; row < numberOfKeys_; row++) {
    for (int column = 0; column < numberOfKeys_; column++) {
      keyNumber = row * lightsOut_.kNumberOfRowsAndColumns() + column;

      if (lightsOut_.isLit(row, column)) {
        trellis_.setLED(keyNumber);
      }
      else {
        trellis_.clrLED(keyNumber);
      }
    }
  }

  trellis_.writeDisplay();
}

void LightsOutTrellisView::renderWithDelay(int delay_time) {
  int keyNumber;

  for (int row = 0; row < numberOfKeys_; row++) {
    for (int column = 0; column < lightsOut_.kNumberOfRowsAndColumns(); column++) {
      keyNumber = row * lightsOut_.kNumberOfRowsAndColumns() + column;

      if (lightsOut_.isLit(row, column)) {
        trellis_.setLED(keyNumber);
        delay(delay_time);
      }
      else {
        trellis_.clrLED(keyNumber);
      }

      trellis_.writeDisplay();
    }
  }
}

bool LightsOutTrellisView::shouldHandleButtonActivity() {
  bool shouldHandle = false;

  // According to Adafruit a 30 ms delays is required
  if (millis() - lastSwitchRead_ > 30) {
    shouldHandle = trellis_.readSwitches();
    lastSwitchRead_ = millis();
  }

  return shouldHandle;
}

bool LightsOutTrellisView::wasButtonJustPressed(int row, int column) {
  int keyNumber = row * lightsOut_.kNumberOfRowsAndColumns() + column;

  return trellis_.justPressed(keyNumber);
}

void LightsOutTrellisView::renderStartupSequence() {
  for (int i = 0; i < numberOfKeys_; i++) {
    trellis_.clrLED(i);
  }

  trellis_.writeDisplay();
  delay(50);
}

void LightsOutTrellisView::renderWinSequence() {
  int i = 0;
  int counter = 1;
  int plusOrMinusOne = 1;

  for (int i = 0; i < numberOfKeys_; i++) {
    trellis_.setLED(i);
  }

  trellis_.writeDisplay();
  delay(1000);

  while (counter <= lightsOut_.kNumberOfLights()) {
    trellis_.clrLED(i);
    trellis_.writeDisplay();
    delay(50);

    if (counter % lightsOut_.kNumberOfRowsAndColumns() == 0) {
      plusOrMinusOne *= -1;

      if (plusOrMinusOne == -1) {
        i += lightsOut_.kNumberOfRowsAndColumns() + 1;
      }
      else {
        i += lightsOut_.kNumberOfRowsAndColumns() - 1;
      }
    }

    i += plusOrMinusOne;
    counter += 1;
  }

  delay(1000);
}

void LightsOutTrellisView::clearPressedButtonsBuffer() {
  for (int i = 0; i < sizePressedButtonsBuffer(); i++) {
    pressedButtonsBuffer_[i] = -1;
  }
}
void LightsOutTrellisView::pushPressedButtonsBuffer(int button) {
  int nextFreeIndex = nextFreeIndexForPressedButtonsBuffer();

  if (nextFreeIndex != -1) {
    pressedButtonsBuffer_[nextFreeIndex] = button;
  }
}

int LightsOutTrellisView::popPressedButtonsBuffer() {
  for (int i = sizePressedButtonsBuffer() - 1; i >= 0; i--) {
    if (pressedButtonsBuffer_[i] != -1) {
      int button = pressedButtonsBuffer_[i];
      pressedButtonsBuffer_[i] = -1;

      return button;
    }
  }

  return -1;
}

int LightsOutTrellisView::sizePressedButtonsBuffer() {
  return sizeof(pressedButtonsBuffer_) / sizeof(int);
}

int LightsOutTrellisView::nextFreeIndexForPressedButtonsBuffer() {
  for (int i = 0; i < sizePressedButtonsBuffer(); i++) {
    if (pressedButtonsBuffer_[i] == -1) return i;
  }

  return -1;
}

void LightsOutTrellisView::update() {
  if (shouldHandleButtonActivity()) {
    for (int row = 0; row < lightsOut_.kNumberOfRowsAndColumns(); row++) {
      for (int column = 0; column < lightsOut_.kNumberOfRowsAndColumns(); column++) {
        if (wasButtonJustPressed(row, column)) {
          pushPressedButtonsBuffer(row * lightsOut_.kNumberOfRowsAndColumns() + column);
        }
      }
    }
  }
}

bool LightsOutTrellisView::oneOrMoreInPressedButtonsBuffer() {
  return pressedButtonsBuffer_[0] != -1;
}

