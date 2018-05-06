// Mad Max Competition Starter Light
// Uses tower light: https://www.adafruit.com/product/2993
// Wire as such: https://learn.adafruit.com/rgb-led-strips/usage
// Add a start button to pin 13

// NOTE: These are all set to PWM pins.  Not a requirement
const int BUZZER = 11;
const int GREEN = 9;
const int YELLOW = 5;
const int RED = 3;
const int START_BTN = 13;

int start_race = false;
int countdown_done = true;
int btn_state = 0;

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(START_BTN, INPUT);
  
  testrun();
  digitalWrite(RED, HIGH);
}

// 1 sec test of each light and buzzer
void testrun() {
  digitalWrite(RED, HIGH);
  delay(1000);
  digitalWrite(RED, LOW);
   digitalWrite(YELLOW, HIGH);
  delay(1000);
  digitalWrite(YELLOW, LOW);
   digitalWrite(GREEN, HIGH);
  delay(1000);
  digitalWrite(GREEN, LOW);
  digitalWrite(BUZZER, HIGH);
  delay(1000);
  digitalWrite(BUZZER, LOW);
}

// Does the countdown
void go() {
  if (!countdown_done) {
    return;
  }
  countdown_done = false;
  start_race = true;
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BUZZER, LOW);
  delay(300);
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  delay(1000);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BUZZER, HIGH);
  delay(1000);
  digitalWrite(BUZZER, LOW);
  countdown_done = true;  
}

// Race waiting (red light only)
void stop_race() {
  start_race = false;
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BUZZER, LOW);
  digitalWrite(RED, HIGH);
  delay(2000); // 2 second delay (for debounce)
}

void loop() {
  btn_state = digitalRead(START_BTN);
  if(btn_state == HIGH) {  // Protoshield pulled high by default
   if (start_race) {
    stop_race();
   } else {
    go(); 
   }
  }
}
