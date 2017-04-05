void setup() {
  Serial.begin(9600);

}

const int rows = 3;
const int columns = 4;
int leds [rows][columns];
float d;

void randomGenerator(int (&a)[3][4], int rows, int columns) { // figure out how to not use size in decleration
  for (int r = 0; r < rows; r++) {//assign new values to rows
    for (int c = 0; c < columns; c++) {// now columns
      d = random(0, 3);
      if (d > 1) {
        a[r][c] = 1;
      }
      else {
        a[r][c] = 0;
      }
    }
  }
}


void togglePixels(int (&a)[3][4], int rows, int columns) {
  int incomingByte = 0;


  if (Serial.available() > 0) {
    int one, two, stopbit;
    one = Serial.read() - 49;
    two = Serial.read() - 49;
    while (Serial.available() > 0) {
      stopbit = Serial.read();
    }
    Serial.println(one);
    Serial.println(two);
    if (a[one][two] == 1) {
      a[one][two] = 0;
    }
    else {
      a[one][two] = 1;
    }
  }
}

void showScreen(int (&a)[3][4], int rows, int columns, int delaytime) {
  for (int r = 0; r < rows; r++) {// switch through 3 rows
    digitalWrite(r + 6, HIGH); // "+ 6" is to take it to the right pins

    for (int c = 0; c < columns; c++) {// switch through 4 columns

      if (leds[r][c] == 1) {
        digitalWrite((c + 2), HIGH);
      }
      else
      {
        digitalWrite((c + 2), LOW);
      }
    }
    delay(delaytime);
    digitalWrite(r + 6, LOW);
  }
}

void loop() {

  togglePixels(leds, rows, columns);

  for (int b = 0; b <= 50; b++) { // keep screen
    showScreen(leds, rows, columns, 2);

  }
}
