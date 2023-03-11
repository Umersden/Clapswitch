int reading = 0;
int mic = A0;
int led = 13;
boolean ledOn = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(mic, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = analogRead(mic);
  Serial.println(ledOn);

  if (reading > 100) {
    delay(500);
    for (int i = 0; i < 1000; i++) {
      reading = analogRead(mic);
      delay(1);
      if (reading > 100) {
        ledOn = !ledOn;
        break;
      }
    }
  }
  if (ledOn == 1) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
