const uint8_t PIR_PIN = 2;
const uint8_t TILT_PIN = 3;
const uint8_t REDLED_PIN = 13;
const uint8_t YLED_PIN = 12;

uint8_t redState = LOW;

void setup()
{
  pinMode(REDLED_PIN, OUTPUT);
  pinMode(YLED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(TILT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), handleMotionSensor, HIGH);
  attachInterrupt(digitalPinToInterrupt(TILT_PIN), handleTiltSensor, FALLING);
  Serial.begin(9600);
}

void handleMotionSensor()
{
  Serial.println("Motion detected");
  redState = !redState;
  digitalWrite(REDLED_PIN, redState);
}

void handleTiltSensor()
{
  Serial.println("Tilt detected");
  digitalWrite(YLED_PIN, HIGH);
  delay(10000);
  digitalWrite(YLED_PIN, LOW);
}

void loop()
{
  delay(500);
}
