#include <SoftwareSerial.h>
SoftwareSerial MY_Serial(8, 9);

char Phone_No[] = "+8801730288553";
int Buzzer = 13;
int Flame_Sensor = 6;
int Flame_Sensor_Value;

void setup() 
{
 MY_Serial.begin(9600);
 pinMode(Buzzer, OUTPUT); 
}

void loop() 
{   
  Flame_Sensor_Value = digitalRead(Flame_Sensor);
  if (Flame_Sensor_Value == LOW)
    {
      digitalWrite(Buzzer, HIGH);
      Make_Call(Phone_No);
      delay(5000);
      digitalWrite(Buzzer, LOW);
    }
    
}

void Make_Call(char *number) 
{
  MY_Serial.print("ATD + "); 
  MY_Serial.print(number); 
  MY_Serial.println(";");
  delay(20000);       // wait for 20 seconds...
  MY_Serial.println("ATH"); //hang up
  delay(100);
}
