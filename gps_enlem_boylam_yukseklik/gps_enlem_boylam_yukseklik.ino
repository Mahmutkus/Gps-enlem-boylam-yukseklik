#include <TinyGPS++.h>
#include <SoftwareSerial.h>

TinyGPSPlus gps;

#define ss Serial2

unsigned long SimdikiZaman = 0;
unsigned long OncekiZaman = 0;
int aralik = 999;

void setup()
{
  Serial.begin(57600);
  ss.begin(9600);
}

void loop()
{
  while (ss.available() > 0)
    gps.encode(ss.read());
  gps.charsProcessed();

  SimdikiZaman = millis();
  if  (SimdikiZaman - OncekiZaman > aralik)
  {
    OncekiZaman = SimdikiZaman;
    Serial.print(gps.location.lat(), 8);
    Serial.print(F(" , "));
    Serial.print(gps.location.lng(), 8);
    Serial.print(F(" , "));
    Serial.println(gps.altitude.meters(), 2);
  }

}
