/*
  Arduino Christmas Songs
  
  Based on a project and code by Dipto Pratyaksa, updated on 31/3/13

  Modified for Christmas by Joshi, on Dec 17th, 2017.
*/

#include "pitches.h"

#define melodyPin 8

// Jingle Bells

int melody[] = {
  E5, E5, E5,
  E5, E5, E5,
  E5, G5, C5, D5,
  E5,
  F5, F5, F5, F5,
  F5, E5, E5, E5, E5,
  E5, D5, D5, E5,
  D5, G5
};

int tempo[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

// We wish you a merry Christmas

int wish_melody[] = {
  B3, 
  F4, F4, G4, F4, E4,
  D4, D4, D4,
  G4, G4, A4, G4, F4,
  E4, E4, E4,
  A4, A4, B4, A4, G4,
  F4, D4, B3, B3,
  D4, G4, E4,
  F4
};

int wish_tempo[] = {
  4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2
};

// Santa Claus is coming to town

int santa_melody[] = {
  G4,
  E4, F4, G4, G4, G4,
  A4, B4, C5, C5, C5,
  E4, F4, G4, G4, G4,
  A4, G4, F4, F4,
  E4, G4, C4, E4,
  D4, F4, B3,
  C4
};

int santa_tempo[] = {
  8,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 2,
  4, 4, 4, 4,
  4, 2, 4,
  1
};

// nokia

int nokia_melody[] = {
    E5, D5, FS4, GS4,
  CS5, B4, D4, E4,
  B4, A4, CS4, E4,
  A4
};

int nokia_tempo[] = {
  8, 8, 4, 4, 
  8, 8, 4, 4, 
  8, 8, 4,  4,
  2
};

// startrek

int startrek_melody[] = {
  D4, G4, C5,
  B4, G4, E4, A4,
  D5
};

int startrek_tempo[] = {
  -8, 16, -4, 
  8, -16, -16, -16,
  2
};

// starwars

int starwars_melody[] = {
    E5, D5, FS4, GS4,
  CS5, B4, D4, E4,
  B4, A4, CS4, E4,
  A4
};

int starwars_tempo[] = {
  8, 8, 4, 4, 
  8, 8, 4, 4, 
  8, 8, 4,  4,
  2
};

int switchOne = 0;
int switchTwo = 0;
int switchThree = 0;

void setup(void) {
  pinMode(8, OUTPUT); // Buzzer
  pinMode(13, OUTPUT); // Led indicator when singing a note
  pinMode(6, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

void loop() {
  Serial.begin(9600);
  switchOne = digitalRead(6);
  switchTwo = digitalRead(4);
  switchThree = digitalRead(5);
  Serial.println(switchOne);
  Serial.println(switchTwo);
  Serial.println();
  //sing(1);
  //sing(2);
  //sing(3);
  sing(5);
}

int song = 0;

void sing(int s) {
  // iterate over the notes of the melody:
  song = s;
  if (song == 3) {
    Serial.println(" 'We wish you a Merry Christmas'");
    int size = sizeof(wish_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

   
      int noteDuration = 1000 / wish_tempo[thisNote];
      buzz(melodyPin, wish_melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(melodyPin, 0, noteDuration);

    }
  } else if (song == 2) {
    Serial.println(" 'Santa Claus is coming to town'");
    int size = sizeof(santa_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      int noteDuration = 900 / santa_tempo[thisNote];
      buzz(melodyPin, santa_melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(melodyPin, 0, noteDuration);

    }
  } else if (song == 4) {
    Serial.println(" 'Nokia'");
    int size = sizeof(nokia_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      int noteDuration = 900 / nokia_tempo[thisNote];
      buzz(melodyPin, nokia_melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(melodyPin, 0, noteDuration);

    }
  } else if (song == 5) {
    Serial.println(" 'startrek'");
    int size = sizeof(startrek_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      int noteDuration = 900 / startrek_tempo[thisNote];
      buzz(melodyPin, startrek_melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(melodyPin, 0, noteDuration);

    }
  } else {

    Serial.println(" 'Jingle Bells'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      
      int noteDuration = 1000 / tempo[thisNote];
      buzz(melodyPin, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
     buzz(melodyPin, 0, noteDuration);

    }
  }
}

void buzz(int targetPin, long frequency, long length) {
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }

}
