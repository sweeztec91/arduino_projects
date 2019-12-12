
const int sensorPin = 0;
const int redLight = 13;
const int yellowLight = 12;
const int greenLight = 11;
int lightVal;

void setup()
{
  Serial.begin(9600);
  pinMode(redLight, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
}

void loop()
{
  lightVal = analogRead(sensorPin);
  Serial.println(lightVal);
  if (lightVal < 3) {
    digitalWrite(redLight, HIGH);
    digitalWrite(yellowLight, LOW);
    digitalWrite(greenLight, LOW);
  } else if (lightVal >= 3 && lightVal < 8) {
    digitalWrite(redLight, LOW);
    digitalWrite(yellowLight, HIGH);
    digitalWrite(greenLight, LOW);
  } else {
    digitalWrite(redLight, LOW);
    digitalWrite(yellowLight, LOW);
    digitalWrite(greenLight, HIGH);
  }
  delay(100);
}
