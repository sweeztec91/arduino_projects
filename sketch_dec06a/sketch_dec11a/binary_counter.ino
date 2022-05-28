int ledOne = 13;
int ledTwo = 12;
int ledThree = 11;
int ledFour = 10;
int MOST_SIGNIFICANT_BIT = 10;
int count;

void setup() {
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
  pinMode(ledFour, OUTPUT);
  count = 0;
}

void loop() {
  count++;
  for (int currentPin = ledOne; currentPin >= MOST_SIGNIFICANT_BIT; currentPin--) {
    if (toggle(currentPin)) {
      digitalWrite(currentPin, (digitalRead(currentPin) == HIGH) ? LOW : HIGH);
    }
  }
  delay(1000);
}

/*
   If all bits below this bit are unset then we need to toggle this bit
*/
boolean toggle(int pin) {
  if (pin == ledOne) {
    return true;
  }
  pin++;
  while (pin <= ledOne) {
    if (digitalRead(pin) != LOW) {
      return false;
    }
    pin++;
  }
  return true;
}
