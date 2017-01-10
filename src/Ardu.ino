#include <project.h>
#include "LongBoard.h"
#include "ButtonTest.h"

Project* proj;
int heartBeatCount = 0;
int heartBeat = HIGH;

void setup() {
  // Choose project here
  proj = new LongBoard();

  // Basic setup
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  // Project setup
  proj->setup();
}

void loop() {
  // Keep consistent loop timing
  delay(1);

  // Project loop
  proj->loop();

  // Heartbeat
  heartBeatCount++;
  if (heartBeatCount > 1000) {
    heartBeat = !heartBeat;
    heartBeatCount = 0;
    digitalWrite(LED_BUILTIN, heartBeat);
  }
}
