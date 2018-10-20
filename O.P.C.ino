//declaring variables
// motor control
int en1 = 2; // enable pin motor 1
int en2 = 3; // enable pin motor 2
int in1 = 10; // input pin 1 motor 1
int in2 = 5; // input pin 2 motor 1
int in3 = 6; // input pin 1 motor 2  
int in4 = 7; // input pin 2 motor 2
float mv1; // control speed motor 1
float mv2; // control speed motor 2
// ultrasonic control
int trig = 8; // ultrasonic control pin
int echo = 9; // ultrasonic output pin
int dtm1 = 1000; // delay in low wave 1 by 1 millisecond
int dtm2 = 15; // delay in high wave by 15 microsecond
float pint; // the time the ultrasonic wave has returned back
float pins = 34300000000; //the ultrasonic wave speed
float dis; // the object distance from the car
float ldis = 20; //the limit distance from the object = 20cm
float wdis = 30; // the distance the car will warn the user on
// serial port channel and bluetooth
int baud = 9600; // the serial port channel
int dt = 300; //the speed of giving info
char choice; // the buttons control
//setting delay time
void delayt()
{
  delay(dt); // wait for 300 milisecond
}
// motor control setup
void forward ()
{
  // two motors move in full speed
  mv1 = 255; // motor 1 move forward by 5 volts
  mv2 = 255; // motor 2 move forward by 5 volts
  // two motors move forward
  // setting up motor 1
  analogWrite (en1 ,mv1 ); // turn on motor 1 in full speed
  digitalWrite (in1,HIGH); // motor 1 move forward
  digitalWrite (in2,LOW); // motor 1 move forward
  delayt(); // wait for 300 milisecond
  // setting up motor 2
  analogWrite(en2 , mv2); // turn on motor 2 in full speed
  digitalWrite(in3 , HIGH); // motor 2 move forward in full speed
  digitalWrite(in4, LOW); // motor 2 move forward in full speed
  delayt(); // wait for 300 milisecond
  Serial.println (" two motors are moving forward in full speed (5 volts) "); //telling user two motors moving in full speed
  delayt(); // wait for 300 milisecond
}
void backward()
{
  // two motors move in full speed
  mv1 = 255; // motor 1 move backward by 5 volts
  mv2 = 255; // motor 2 move backward by 5 volts
  // two motors move forward
  // setting up motor 1
  analogWrite (en1 ,mv1 ); // turn on motor 1 in full speed
  digitalWrite (in1,LOW); // motor 1 move backward in full speed
  digitalWrite (in2,HIGH); // motor 1 move backward in full speed
  delayt(); // wait for 300 milisecond
  // setting up motor 2
  analogWrite(en2 , mv2); // turn on motor 2 in full speed
  digitalWrite(in3 , LOW); // motor 2 move backward in full speed
  digitalWrite(in4, HIGH); // motor 2 move backward in full speed
  delayt(); // wait for 300 milisecond
  Serial.println (" two motors are moving backward in full speed (5 volts) "); //telling user two motors moving in full speed
  delayt(); // wait for 300 milisecond
}
void left()
{
  // motor 1 moves with 1 volt motor 2 moves with 5 volt
  mv1 = 51; // motor 1 move left by 1 volts
  mv2 = 255; // motor 2 move left by 5 volts
  // two motors move left
  // setting up motor 1
  analogWrite (en1 ,mv1 ); // turn on motor 1 with 1 volt
  digitalWrite (in1,HIGH); // motor 1 move to left with 1 volt
  digitalWrite (in2,LOW); // motor 1 move to left with 1 volt
  delayt(); // wait for 300 milisecond
  // setting up motor 2
  analogWrite(en2 , mv2); // turn on motor 2 in full speed
  digitalWrite(in3 , HIGH); // motor 2 move left in full speed
  digitalWrite(in4, LOW); // motor 2 move left in full speed
  delayt(); // wait for 300 milisecond
  Serial.println (" left motor is moving left in low speed (1 volt) ; right motor is moving left in full speed (5 volts) "); //telling user two motors moving
  delayt(); // wait for 300 milisecond
}
void right()
{
  // motor 1 moves with 5 volt motor 2 moves with 1 volt
  mv1 = 255; // motor 1 move right by 5 volts
  mv2 = 51; // motor 2 move right by 1 volts
  // two motors move right
  // setting up motor 1
  analogWrite (en1 ,mv1 ); // turn on motor 1 with 1 volt
  digitalWrite (in1,HIGH); // motor 1 move to right with 1 volt
  digitalWrite (in2,LOW); // motor 1 move to right with 1 volt
  delayt(); // wait for 300 milisecond
  // setting up motor 2
  analogWrite(en2 , mv2); // turn on motor 2 with 1 volt
  digitalWrite(in3 , HIGH); // motor 2 move left with 1 volt
  digitalWrite(in4, LOW); // motor 2 move forward with 1 volt 
  delayt(); // wait for 300 milisecond
  Serial.println (" left motor is moving right in full speed (5 volt) ; right motor is moving right in low speed (1 volts) "); //telling user two motors moving
  delayt(); // wait for 300 milisecond
}
//setting up the ultrasonic sensor
void ultrasonic()
{
  digitalWrite(trig , LOW); //give it a low pulse to start giving pulses
  delayMicroseconds(dtm1); //wait for a milisecond
  digitalWrite(trig,HIGH); //give it a high pulse
  delayMicroseconds(dtm2); //wait for 15 microseconds
  digitalWrite(trig, LOW); //give it a low pulse to begin getting info
  Serial.println (" detecting obastcules "); // telling user that pulsing began
  delayt(); // wait for 300 milisecond
  pint = pulseIn(echo, HIGH); // taking outputs from the sensor
  dis = pins * pint; // preparing the distance
  Serial.print (" the distance between me and the obastcule : "); // telling user the distance
  Serial.print (dis); // telling user the distance
  Serial.println (" cm (LIMIT DISTANCE TO OBSTACULES 20 CM) "); // telling user the distance
  delayt(); // wait for 300 milisecond
  // warning the user for obastcule
  if (dis<=wdis) // setting conditions for warnings
  {
    for(int i = 0;i<3;i++) //setting the number of warnings
    {
    Serial.print(" WARNING OBASTCULE ON "); //warning the user
    Serial.print (dis); //telling the distance to the user
    Serial.println(" CM SO CLOSE TO THE LIMIT DISTANCE (20 CM) "); //warning the user
    Serial.println(" PLEASE CHANGE LANE OR STOP "); // warning the user
    delay (150); // waiting for 150 milisecond
  }
  }
  // setting up obastcule passing conditions and procedures
  if(dis<=ldis) // setting up the condition of automatic passing obastcule
  {
    Serial.print(" WARNING OBASTCULE ON : "); //warning the user
    Serial.print(dis); // warning the user
    Serial.println(" CM LESS THAN THE SAFE DISTANCE ( 20 CM ) "); //warning the user
    delayt();
    left(); 
  }
}
void setup() {
  // put your setup code here, to run once:
if (SD.begin(4)){
  Serial.println("SD card is under control");
pinMode(en1,OUTPUT);
pinMode(en2,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(baud);
}
if (!SD.begin (4))
{
  Serial.println("SD CARD IS OF SERVICE");
}
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0)
{
  choice = Serial.read();
  switch(choice)
  {
    case'a':forward();break;
    case'b':right();break;
    case'c':backward();break;
    case'd':left();break;
    default: break;
  }
  delay(10); // wait for 10 miliseconds
  ultrasonic();
}
}
