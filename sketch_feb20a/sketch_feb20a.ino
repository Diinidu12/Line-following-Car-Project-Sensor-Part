int ADC_value,Val;
int lines=0;
int analogValue,value, valR, valG, valB;

void setup() {
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);  //Red
  pinMode(12, OUTPUT);  //Green
  pinMode(13, OUTPUT);  //Blue
  Serial.begin(9600);
}

void loop() {
  //red,green,blue,yellow,white and black
  /*analogWrite(11,32);
  ADC_value = analogRead(A0);
  Serial.print(ADC_value);
  Serial.print(" ");
  delay(100);
  digitalWrite(11,LOW);
  delay(100);
  digitalWrite(12,HIGH);
  delay(100);
  ADC_value = analogRead(A0);
  Serial.print(ADC_value);
  Serial.print(" ");
  digitalWrite(12,LOW);
  delay(100);
  digitalWrite(13,HIGH);
  delay(100);
  ADC_value = analogRead(A0);
  Serial.println(ADC_value);
  digitalWrite(13,LOW);
  delay(100);
  */
  //value=map(ADC_value,0,1023,0,10);
  //
  // int p=changeColor(11);
  // Serial.print("Red :");
  // Serial.println(p);
  // int p2=changeColor(12);
  // Serial.print("Green :");
  // Serial.println(p2);
  // int p3=changeColor(13);
  // Serial.print("Blue :");
  // Serial.println(p3);
  readColor();
}
int changeColor(int n) {
  digitalWrite(n, HIGH);
  delay(100);
  ADC_value = analogRead(A0);
  digitalWrite(n, LOW);
  delay(100);
  delay(100);
  return ADC_value;
}

int readColor(void) {
  int n = 100, m, j;
  for (int i = 11; i < 14; i++) {
    m = changeColor(i);
    Val = map(m, 0, 1023, 0, 100);
    if (i == 11) {
      valR = Val;
    } else if (i == 12) {
      valG = Val;
    } else {
      valB = Val;
    }
    Serial.print("Color value (0-100) for ");
    if (i == 11) {
      Serial.print("Red: ");
    } else if (i == 12) {
      Serial.print("Green: ");
    } else {
      Serial.print("Blue: ");
    }
    Serial.println(Val);
    if (Val < n) {
      n = Val;
      j = i;
    }
  }

  Serial.print("Detected color: ");
  if (j == 11 && 63 < valR && valR < 72) {
    Serial.println("Red");
  } else if (j == 12 && 70 < valG && valG < 80) {
    Serial.println("Green");
  } else if (j == 13 && valB > 74 && valB < 86) {
    Serial.println("Blue");
  } else {
    Serial.println("Unknown");
  }
}
