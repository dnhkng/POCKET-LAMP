/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>
#include <OneWire.h>
#include <DS18B20.h>

#define ONE_WIRE_BUS 17

OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);

#define PIN_OUTPUT 3

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Serial.begin(115200);
  sensor.begin();
  Setpoint = 100;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{

  sensor.requestTemperatures();
  while (!sensor.isConversionComplete());  // wait until sensor is ready
  
  Input = sensor.getTempC();
  Serial.print("Temp: ");
  Serial.println(Input);
  myPID.Compute();
  
  analogWrite(PIN_OUTPUT, Output);
  Serial.print("Output: ");
  Serial.println(Output);
}
