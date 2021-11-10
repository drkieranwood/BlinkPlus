#include "BlinkPlus.h"

//For Adafruit FeatherM0
BlinkPlus blink(13);

//For Teensy3.6
//BlinkPlus blink(13);

int count = 0;

void setup() {
  //Recommend calling the init. early in the setup to hold the
  //LED high to indicate the code is still within the setup() block.
  blink.init();
  
  
  Serial.begin(115200);
  delay(5000);
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  Serial.println("Test BlinkPlus Library");
  Serial.println("University of Manchester");
  Serial.println("kieran.wood@manchester.ac.uk");
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

void loop() {
  //Recommend calling the init. early in the main loop.
  //NOTE the main loop must not block for this library to work (i.e. no significant delays)
  blink.update();
  count+=1;
  Serial.print("Count=");Serial.println(count);


  //With defaults, LED will blink once every two seconds for normal operation
  //and at 4Hz for an error condition.
  if (millis() > 15*1000) {
	  blink.setError(true);
  }
  
  //To allow interupts to reboot for programming
  delay(2);
}
//eof
