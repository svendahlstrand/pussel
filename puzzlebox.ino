#include <Wire.h>

#include "Adafruit_Trellis.h"
#include "board.h"

const int kBoardSize = 4;
Board board(kBoardSize);

void setup() {
  Serial.begin(9600);

  for (int row = 0; row < board.size(); row++) {
    for (int column = 0; column < board.size(); column++) {
      Serial.print(board.IsLit(row, column) ? "1" : "0");
      Serial.print(" ");
    }

    Serial.println("");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
