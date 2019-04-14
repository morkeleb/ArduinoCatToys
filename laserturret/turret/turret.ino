#include <Button.h>
#include <Servo.h>

Button btnRoll(13);
Servo servo_x;
Servo servo_y;

int pos = 0;    // variable to store the servo position 
int next_position = 0;
int laser_pin = 12;
 
void setup() {

  Serial.begin(9600);
  
    Serial.println("Initiating turret...");
  btnRoll.begin();
  pinMode(laser_pin, OUTPUT); 
  
  servo_x.attach(9, 700, 2300);
  servo_y.attach(10, 700, 2300);
  servo_x.write(90);
  servo_y.write(90);

  randomSeed(analogRead(0));
  
  Serial.println("Laser powering up...");
  digitalWrite(laser_pin, HIGH);  //Turn on the laser
   
  Serial.println("Turret is ready for operation");
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(btnRoll.released()){
  //  turn();
  //}

  servo_x.write(random(45,135));
  servo_y.write(random(55,90));
  delay(2000);
   
}

void turn() {
  next_position = (next_position + 90) % 270;
  Serial.println(next_position);
  servo_x.write(next_position);
  servo_y.write(next_position);
}

void upDown() {
  setDice(6);
  delay(600);
  setDice(1);
  delay(600);
}

void setDice(int number){
  int dicePointer = map(number, 1, 6, 20, 140);

  servo_x.write(dicePointer);
}
