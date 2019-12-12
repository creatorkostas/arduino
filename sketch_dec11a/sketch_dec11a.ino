#define trigger 5
#define echo 6
 
float distance=0,time=0,time0=0,time1=0,time2=0,hz=0;
 
void setup()
{
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(8,OUTPUT);
 Serial.begin(9600);
}
 
void loop()
{
 /*digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 distance=((time*340/20000)*10)*1.5;
 Serial.println(distance);*/
 //delay(1000);
 time0=100;
 time1=100*2;
 time2=100/2;
 hz = 300;
 tone(8, hz, time0);
 delay(1000);
 tone(8, hz, time0);
 delay(1000);
 tone(8, hz, time1);
 delay(1000);
 
 tone(8, hz, time0);
 tone(8, hz, time0);
 tone(8, hz, time1);
 
 tone(8, hz, time2);
 tone(8, hz, time2);
 
 tone(8, 1, time2);
 
 tone(8, hz, time2);
 tone(8, hz, time2);
 tone(8, hz, time0);
 
 tone(8, hz, time2);
 tone(8, hz, time2);
 
 tone(8, 1, time2);
 
 tone(8, hz, time2);
 tone(8, hz, time2);
 tone(8, hz, time0);
 
 tone(8, 1, time2);
 
 tone(8, hz, time2);
 tone(8, hz, time2);
 tone(8, hz, time0);


//-------------------------

 
 tone(8, hz, time0);
 tone(8, hz, time0);
 tone(8, hz, time1);
 
 tone(8, hz, time0);
 tone(8, hz, time0);
 tone(8, hz, time1);
 
 tone(8, hz, time2);
 tone(8, hz, time2);
 
 tone(8, 1, time2);
 
 tone(8, hz, time2);
 tone(8, hz, time2);
 tone(8, hz, time0);
 
 tone(8, hz, time2);
 tone(8, hz, time2);
 
 tone(8, 1, time2);
 
 tone(8, hz, time2);
 tone(8, hz, time2);
 tone(8, hz, time0);
 
 tone(8, 1, time2);
 
 tone(8, hz, time2);
 tone(8, hz, time2);
 tone(8, hz, time0);
 
 tone(8, hz, time0);
 
 //delay(1000);
}
