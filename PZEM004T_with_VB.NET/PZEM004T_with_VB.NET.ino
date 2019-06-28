#include <SoftwareSerial.h> // 配合Vb.Net接收資料
#include <PZEM004T.h>

PZEM004T pzem(10,11);  // (RX,TX) connect to TX,RX of PZEM
IPAddress ip(192,168,1,1);

void setup() {
  Serial.begin(9600);
  pzem.setAddress(ip);
}

void loop() {
  float v = pzem.voltage(ip);
  float i = pzem.current(ip);
  float p = pzem.power(ip);
  float e = pzem.energy(ip);
  
  Serial.print(v);
  Serial.print(",");
  Serial.print(i);
  Serial.print(",");
  Serial.print(p);
  Serial.print(",");
  Serial.print(e);
  Serial.print(",");
  Serial.println();

  delay(1000);
}
