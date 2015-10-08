int myState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT);
  pinMode(3,OUTPUT);
  pinMode(9,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(7) == 1){
    if (myState == HIGH){
      myState = LOW;
      }else{
       myState = HIGH;
       }
    }

    digitalWrite(3,myState);
    digitalWrite(9,myState);
}
