int Bright_sensor = A0;
int Pir_sensor = 2;
int Spraying_Pin = 4;
int Light_Pin = 6;
int sensorValue = 0;
int PersonValue;
unsigned long previousMillis = 0;
// Intervalo de medicao temperatura
const long interval = 6000;
void PersonCome(boolean come)
{
  if (come)
  {
    if (sensorValue > 800)
    {
      digitalWrite(Light_Pin, HIGH);
    }
    digitalWrite(Spraying_Pin, HIGH);
  }
  else
  {
    digitalWrite(Light_Pin, LOW);
    digitalWrite(Spraying_Pin, LOW);
  }
}

void setup()
{
  PersonCome(false);
  // initialize both leds to be off
  pinMode(Pir_sensor, INPUT);
  pinMode(Spraying_Pin, OUTPUT);
  pinMode(Light_Pin, OUTPUT);
  digitalWrite(Spraying_Pin, LOW);
  digitalWrite(Light_Pin, LOW);//
}

void loop()
{
  PersonValue = digitalRead(Pir_sensor);
  sensorValue = analogRead(Bright_sensor);
  unsigned long currentMillis = millis();
  if (PersonValue == 1)
  {
    PersonCome(true);
    previousMillis = currentMillis;
  }
  
  if (currentMillis - previousMillis >= interval)
  {
    PersonCome(false);
    previousMillis = currentMillis;
  }
}
