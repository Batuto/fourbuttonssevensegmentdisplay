// Author: Batuto
// GitHub: github.com/batuto
// This code was designed using an Arduino Uno (and Nano) as reference, but may work in other devices,
// take this in mind when porting to another device.

// This program takes a four bit input and write its in a seven segment display


int i, value;
int list[][7] = {{0,1,2,3,4,5,5},  // 0
                 {2,3,3,3,3,3,3},  // 1
                 {0,1,3,4,6,6,6},  // 2
                 {1,2,3,4,6,6,6},  // 3
                 {2,3,5,6,6,6,6},  // 4
                 {1,2,4,5,6,6,6},  // 5
                 {0,1,2,4,5,6,6},  // 6
                 {2,3,4,4,4,4,4},  // 7
                 {0,1,2,3,4,5,6},  // 8
                 {2,3,4,5,6,6,6},  // 9
                 {0,2,3,4,5,6,6},  // A
                 {0,1,2,5,6,6,6},  // B
                 {0,1,4,5,5,5,5},  // C
                 {0,1,2,3,6,6,6},  // D
                 {0,1,4,5,6,6,6},  // E
                 {0,4,5,6,6,6,6}}; // F
/*
The previous matrix is defined to use a
 seven display numerating each segment
 in the next manner:
     4
 ========
||      ||
||5     ||3
||      ||
6========
||      ||
||0     ||2
||      ||
 ========
    1
*/

void setup(){
  for(i = 0; i < 8; i++)
    pinMode(i, OUTPUT);
  for(i = 8; i < 12; i++)
    pinMode(i, INPUT);  
}

void loop(){
  PORTD = 0;
  value = int(PINB);
  for(i = 0; i < 7; i++)
    digitalWrite(list[value][i], HIGH);
   delay(800);
}

