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
  if (v < 0.0) v = 0.0;
  Serial.print(v);/*Serial.print("V; ");*/
  Serial.print(",");
  
  float i = pzem.current(ip);
  if(i >= 0.0)
  { Serial.print(i);
  /*Serial.print("A; ");*/ 
  }
  Serial.print(",");
  
  float p = pzem.power(ip);
  if(p >= 0.0)
  { Serial.print(p);
  /*Serial.print("W; ");*/ 
  }
  Serial.print(",");
  
  float e = pzem.energy(ip);
  if(e >= 0.0)
  { Serial.print(e);
  /*Serial.print("Wh; ");*/ 
  }
  Serial.print(",");

  Serial.println();

  delay(1000);
}
