//Assigning pins to led and sensor
const uint8_t PIR_PIN = 2;
const uint8_t LED_PIN = 13;

//Initializing state of led 
uint8_t ledState = LOW;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), handleMotionSensor, HIGH);
  Serial.begin(9600);
}

//ISR or when motion is detected
void handleMotionSensor()
{
  Serial.println("Motion detected");
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState);
}

void loop()
{
  // No polling required
}
