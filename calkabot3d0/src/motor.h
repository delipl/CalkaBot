void initMotor(){
    pinMode(Ma1, OUTPUT);
    pinMode(Mb1, OUTPUT);
    pinMode(Ma2, OUTPUT);
    pinMode(Mb2, OUTPUT);
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(STBY, OUTPUT);
    digitalWrite(STBY, HIGH);
    
}

//speed in %
void goBackward(int speed){
    speed = map(speed, 0, 100, 0, 255);
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
    digitalWrite(Ma2, HIGH);
    digitalWrite(Ma1, LOW);

    digitalWrite(Mb2, LOW);
    digitalWrite(Mb1, HIGH);
}

void goForward(int speed){
    speed = map(speed, 0, 100, 0, 255);
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
    digitalWrite(Ma2, LOW);
    digitalWrite(Ma1, HIGH);

    digitalWrite(Mb2, HIGH);
    digitalWrite(Mb1, LOW);
}

void rotateTill(int angle, int speed){
    speed = map(speed, 0, 100, 0, 255);
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
    digitalWrite(Ma2, HIGH);
    digitalWrite(Ma1, LOW);
    digitalWrite(Mb2, HIGH);
    digitalWrite(Mb1, LOW);
}