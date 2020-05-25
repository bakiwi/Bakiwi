#include "jcl_capsense.h"


jcl::CapSense cap0(2 /*send*/, 8 /*recv*/); //TODO adapt these pins!
jcl::CapSense cap1(2 /*send*/,12 /*recv*/);

void setup() {
  Serial.begin(1000000);
}

void loop() {
    long start = micros();

    uint8_t U = 127*cap0.step() + 128;
    uint8_t V = 127*cap1.step() + 128;

    float dt = 0.001 *(micros() - start);
    //Serial.print(dt);
    //Serial.print(" ");
    Serial.print(50*U);
    Serial.print(" ");
    Serial.print(50*V);
    Serial.print(" ");
    Serial.println(100*cap0.w);

    //float upos = constrain(U, 0,1);
    //analogWrite(11, (uint8_t) 255*upos);
    //digitalWrite(13, fabs(U) > 0.9f);
    delay(10);
}
