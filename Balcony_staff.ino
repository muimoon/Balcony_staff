int Bright_sensor = A0;
int Pir_sensor = 2;
int Spraying_Pin = 4;
int Light_Pin = 6;
int sensorValue = 0;
int RXLED = 17;
// Turn on (true) or off (false) the Tx and Rx led.
// ------------------------------------------------
// They are turned off by making them input.
// That prevents that any RX or TX activity will turn them on.
// However, when the leds are on, any RX or TX action will
// make them blink or turn them off.
void ledTx(boolean on)
{
  if (on)
  {
    // led on. The led is connected to VCC. Make pin low to turn led on.
    pinMode(LED_BUILTIN_TX, OUTPUT); // pin as output.
    digitalWrite(LED_BUILTIN_TX, LOW); // pin low
    // These two lines will do the same:
    // bitSet( DDRD, 5);
    // bitClear( PORTD, 5);
  }
  else
  {
    // led off
    // turn it off, by setting it as input, so the serial activity can't turn it on.
    // If the internal pullup resistor is enabled or not, that does not matter,
    // since the led it connected to VCC.
    pinMode(LED_BUILTIN_TX, INPUT);
    // This line will do the same:
    // bitClear( DDRD, 5);        // set pin as input
  }
}

void ledRx(boolean on)
{
  if (on)
  {
    pinMode(LED_BUILTIN_RX, OUTPUT);
    digitalWrite(LED_BUILTIN_RX, LOW);
    // bitSet( DDRB, 0);
    // bitClear( PORTB, 0);
  }
  else
  {
    pinMode(LED_BUILTIN_RX, INPUT);
    // bitClear( DDRB, 0);
  }
}

void setup()
{
  // initialize both leds to be off
  ledTx(false);
  ledRx(false);
  pinMode(Pir_sensor, INPUT);
  pinMode(Spraying_Pin, OUTPUT);
  pinMode(Light_Pin, OUTPUT);
  digitalWrite(Spraying_Pin, LOW);
  digitalWrite(Light_Pin, LOW);
}

void loop()
{
  sensorValue = analogRead(Bright_sensor);
  if (digitalRead(Pir_sensor) == 1)
  {
    if (sensorValue > 800)
    {
      digitalWrite(Light_Pin, HIGH);
    }
    digitalWrite(Spraying_Pin, HIGH);
  }
  delay(30000);
  digitalWrite(Light_Pin, LOW);
  digitalWrite(Spraying_Pin, LOW);
}
