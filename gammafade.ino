int bluepin = 10;
int redpin = 9;
int greenpin = 11;
float smoothness_pts = 1000;
float gamma = 0.17; // affects the width of peak (more or less darkness)
float beta = 0.5; // shifts the gaussian to be symmetric
int dtime = 10; //downtime between colors

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);

}

void loop() {
  fadeBlue();
  delay(1000);
  fadeWhite();
  delay(1000);  
}

void fadeBlue(){
  for (int ii=0;ii<smoothness_pts;ii++){
    float pwm_val = 255.0*(exp(-(pow(((ii/smoothness_pts)-beta)/gamma,2.0))/2.0));
    analogWrite(bluepin,int(pwm_val));
    delay(dtime);
  Serial.println(int(pwm_val));
  } 
}

void fadeWhite(){
  for (int ii=0;ii<smoothness_pts;ii++){
    float pwm_val = 255.0*(exp(-(pow(((ii/smoothness_pts)-beta)/gamma,2.0))/2.0));
    analogWrite(redpin,int(pwm_val));
    analogWrite(greenpin, int(pwm_val));
    analogWrite(bluepin, int(pwm_val));    
    delay(dtime);
  Serial.println(int(pwm_val));
  } 
}