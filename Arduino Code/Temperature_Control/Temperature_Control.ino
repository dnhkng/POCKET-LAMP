#include <OneWire.h>
#include <DS18B20.h>

#define ONE_WIRE_BUS 17

OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);


void setup(void)
{
  Serial.begin(115200);
  sensor.begin();
}


void loop(void)
{ 
  sensor.requestTemperatures();
  
  while (!sensor.isConversionComplete());  // wait until sensor is ready
  
  Serial.print("Temp: ");
  Serial.println(sensor.getTempC());
}
