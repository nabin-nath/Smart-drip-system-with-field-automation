String voice;
 void setup(){
Serial.begin(9600);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);}
void loop(){
while(Serial.available()){
delay(3);
char c = Serial.read();
voice+=c;}
if(voice.length()>0){
  Serial.println(voice);
  if(voice == "turn on light")
  {digitalWrite(6,HIGH);}
  else  if(voice == "turn off light")
  {digitalWrite(6,LOW);}
   else  if(voice == "turn on fan")
    {digitalWrite(5,HIGH);}
     else  if(voice == "turn off fan")
     {digitalWrite(5,LOW);}
      else  if(voice == "turn on all")
      {digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);}
      else (voice == "turn on all");
       {digitalWrite(5,LOW);
      digitalWrite(6,LOW);}
      voice = "";}}
