void setup (){
  pinMode (2, INPUT);
  pinMode (6, INPUT);
  pinMode (4, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (7, OUTPUT);
}

void loop() {
  if ((( digitalRead (2))==(1))){
    # A realiser pendant un temps precis
    digitalWrite (3,0);
    digitalWrite(7,0);
    digitalWrite (4,1);
  }else if (((digitalRead (6))==(1))){
    # A realiser pendant un temps precis
    digitalWrite (3,0);
    digitalWrite(7,0);
    digitalWrite (8,1);
  } else{
    digitalWrite (4,0);
    digitalWrite (8,0);
    digitalWrite (3,1);
    digitalWrite(7,1);
  }
  _loop();
}

void _delay(float seconds){
  long endTime = millis() + seconds *1000;
  while(millis()<endTime)_loop();

}

void _loop(){

}