//Made by Veseliy Radiolubitel & RCL Radio
//https://www.youtube.com/channel/UCR89Lrc44Ecpb211AybTGbg

#include <MsTimer2.h>
#include <Wire.h> 
#include <DS3231.h>
DS3231 clock;RTCDateTime DateTime;
  int an, segm,times,i;
  byte a[4];
 
void setup(){  Wire.begin();clock.begin();
MsTimer2::set(5, to_Timer);MsTimer2::start();
 clock.setDateTime(__DATE__, __TIME__); // Устанавливаем время на часах, основываясь на времени компиляции скетча
 pinMode(9,OUTPUT);  // D9  === A0  //Прошиваем, если какие-то баги, то прошиваем, потом ставим (//) перед предыдущей строкой (clock.setDateTime...)
 pinMode(10,OUTPUT); // D10 === A1
 pinMode(11,OUTPUT); // D11 === A2
 pinMode(12,OUTPUT); // D12 === A3
 pinMode(2,OUTPUT);  // D2  === a
 pinMode(3,OUTPUT);  // D3  === b
 pinMode(4,OUTPUT);  // D4  === c
 pinMode(5,OUTPUT);  // D5  === d
 pinMode(6,OUTPUT);  // D6  === e
 pinMode(7,OUTPUT);  // D7  === f
 pinMode(8,OUTPUT);  // D8  === g
 pinMode(A0,INPUT_PULLUP); // A0 === +hour
 pinMode(A1,INPUT_PULLUP); // A1 === +minute
clock.setOutput(DS3231_1HZ);
Serial.begin(9600);
}
 
void loop(){ 
  DateTime=clock.getDateTime();// опрос времени
  if ( digitalRead(A0) == 0) {
    DateTime.hour == DateTime.hour + 1;
    }
  times = DateTime.hour*100+DateTime.minute;
   
   Serial.println(DateTime.hour);
   Serial.println(DateTime.minute);


  
  a[0]=times/1000;
  a[1]=times/100%10;
  a[2]=times/10%10;
  a[3]=times%10%10;
 }// loop
 
void to_Timer(){ 
  switch(i){
    case 0: segm=a[0]; an=0; anod(); segment();delay(1);break;
    case 1: segm=a[1]; an=1; anod(); segment();delay(1);break;
    case 2: segm=a[2]; an=2; anod(); segment();delay(1);break;
    case 3: segm=a[3]; an=3; anod(); segment();delay(1);break;}i++;if(i>3){i=0;}}
 
 
void segment(){
  switch(segm){                                                                 
             //  A       B       C       D       E       F       G  
    case 0: ch(2,0);ch(3,0);ch(4,0);ch(5,0);ch(6,0);ch(7,0);ch(8,1);break;// 0 
    case 1: ch(2,1);ch(3,0);ch(4,0);ch(5,1);ch(6,1);ch(7,1);ch(8,1);break;// 1
    case 2: ch(2,0);ch(3,0);ch(4,1);ch(5,0);ch(6,0);ch(7,1);ch(8,0);break;// 2
    case 3: ch(2,0);ch(3,0);ch(4,0);ch(5,0);ch(6,1);ch(7,1);ch(8,0);break;// 3   
    case 4: ch(2,1);ch(3,0);ch(4,0);ch(5,1);ch(6,1);ch(7,0);ch(8,0);break;// 4 
    case 5: ch(2,0);ch(3,1);ch(4,0);ch(5,0);ch(6,1);ch(7,0);ch(8,0);break;// 5 
    case 6: ch(2,0);ch(3,1);ch(4,0);ch(5,0);ch(6,0);ch(7,0);ch(8,0);break;// 6 
    case 7: ch(2,0);ch(3,0);ch(4,0);ch(5,1);ch(6,1);ch(7,1);ch(8,1);break;// 7 
    case 8: ch(2,0);ch(3,0);ch(4,0);ch(5,0);ch(6,0);ch(7,0);ch(8,0);break;// 8
    case 9: ch(2,0);ch(3,0);ch(4,0);ch(5,0);ch(6,1);ch(7,0);ch(8,0);break;// 9  
  }}
void anod(){
  switch(an){                                                             
    case 0:ch(9,0);ch(10,1);ch(11,1);ch(12,1);break;  
    case 1:ch(9,1);ch(10,0);ch(11,1);ch(12,1);break; 
    case 2:ch(9,1);ch(10,1);ch(11,0);ch(12,1);break;
    case 3:ch(9,1);ch(10,1);ch(11,1);ch(12,0);break;
  }}
 
  void ch(int pin, int logic){digitalWrite(pin,logic);}
