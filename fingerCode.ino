#include <LiquidCrystal.h>

LiquidCrystal lcd_1(13,12,8,7,4,2);

int thumbPin = A0;
int pointerPin = A1;
int middlePin = A2;
int ringPin = A3;
int pinkyPin = A4;
int thumb, pointer, middle, ring, pinky;

int thumbLed = 10;
int pointerLed = 9;
int middleLed = 6;
int ringLed = 5;
int pinkyLed = 3;

int flex_min = 236;
int flex_max = 580;
int flexThreshold = 400;

void setup() {
  pinMode(thumbLed,OUTPUT);
  pinMode(pointerLed,OUTPUT);
  pinMode(middleLed,OUTPUT);
  pinMode(ringLed,OUTPUT);
  pinMode(pinkyLed,OUTPUT);
  lcd_1.begin(16,2);
  lcd_1.print("Hello World!");
  Serial.begin(9600);
}

void loop() {
  thumb = analogRead(thumbPin);
  pointer = analogRead(pointerPin);
  middle = analogRead(middlePin);
  ring = analogRead(ringPin);
  pinky = analogRead(pinkyPin);

  Serial.println("Thumb: " + String(thumb));
  Serial.println("Pointer: " + String(pointer));
  Serial.println("Middle: " + String(middle));
  Serial.println("Ring: " + String(ring));
  Serial.println("Pinky: " + String(pinky));
  Serial.println();

  int thumbBrightness = map(thumb, flex_min, flex_max, 0, 255);
  int pointerBrightness = map(pointer, flex_min, flex_max, 0, 255);
  int middleBrightness = map(middle, flex_min, flex_max, 0, 255);
  int ringBrightness = map(ring, flex_min, flex_max, 0, 255);
  int pinkyBrightness = map(pinky, flex_min, flex_max, 0, 255);
  
  thumbBrightness = constrain(thumbBrightness, 0, 255);
  pointerBrightness = constrain(pointerBrightness, 0, 255);
  middleBrightness = constrain(middleBrightness, 0, 255);
  ringBrightness = constrain(ringBrightness, 0, 255);
  pinkyBrightness = constrain(pinkyBrightness, 0, 255);
  
  analogWrite(thumbLed, thumbBrightness);
  analogWrite(pointerLed, pointerBrightness);
  analogWrite(middleLed, middleBrightness);
  analogWrite(ringLed, ringBrightness);
  analogWrite(pinkyLed, pinkyBrightness);

  bool t = thumb > flexThreshold;
  bool p = pointer > flexThreshold;
  bool m = middle > flexThreshold;
  bool r = ring > flexThreshold;
  bool k = pinky > flexThreshold;

  // Debug: Print boolean values to see what's being detected
  Serial.println("Bools - T:" + String(t) + " P:" + String(p) + " M:" + String(m) + " R:" + String(r) + " K:" + String(k));
  
  // Middle finger gesture
  if (t && p && !m && r && k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("fuck you!");
    Serial.println("F");
    
  } 
  // Rock on gesture (thumb and pinky bent, others straight)
  else if (!t && p && m && r && !k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);  // Changed from (0, 2) to (0, 0)
    lcd_1.print("Radical Dude!");
    Serial.println("Rad");
    
  } 
  else if (t && !p && m && r && k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);  // Changed from (0, 2) to (0, 0)
    lcd_1.print("Pointing");
    Serial.println("p");
    
  } 
  else if (!t && p && m && r && k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);  // Changed from (0, 2) to (0, 0)
    lcd_1.print("Good Job!");
    Serial.println("gg");
    
  } 
// ASL Letter C (C-shaped hand)
else if (!t && !p && m && r && k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Letter: C");
    Serial.println("C");
}
// ASL Letter D (Index finger up, others closed)
else if (!t && !p && !m && r && !k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Letter: D");
    Serial.println("D");
}
// ASL Letter E (Fingers curled, thumb across)
else if (t && !p && !m && !r && !k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Letter: E");
    Serial.println("E");
}
// ASL Letter F (OK sign - thumb and index touching)
else if (!t && !p && !m && r && k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Letter: F / OK");
    Serial.println("F/OK");
}
// ASL Letter I (Pinky up, others closed)
else if (!t && p && !m && !r && !k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Letter: I");
    Serial.println("I");
}
// ASL Letter L (Index and thumb extended)
else if (t && !p && !m && r && !k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Letter: L");
    Serial.println("L");
}
// ASL Letter V (Peace sign)
else if (!t && !p && !m && r && k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Peace / Letter: V");
    Serial.println("V");
}
// ASL Letter W (Three fingers up: middle, ring, pinky)
else if (!t && p && !m && r && k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Letter: W");
    Serial.println("W");
}
// ASL Letter Y (Thumb and pinky extended)
else if (t && p && !m && !r && !k) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Letter: Y");
    Serial.println("Y");
}
  else {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Stop");
    lcd_1.setCursor(0, 1);
    //lcd_1.print("Ready");
    //Serial.println("None");
  }
  
  delay(300); // Single delay at the end
}
