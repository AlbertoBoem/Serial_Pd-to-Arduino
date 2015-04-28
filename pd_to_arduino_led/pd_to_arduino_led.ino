#define led1_pin 8
#define led2_pin 9
#define led3_pin 10
#define led4_pin 11

#define led1_mask 0x80
#define led2_mask 0x40
#define led3_mask 0x20
#define led4_mask 0x10
#define value_mask 0xF

int led1_state = 0;
int led2_state = 0;
int led3_state = 0;
int led4_state = 0;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led3_pin, OUTPUT);
  pinMode(led4_pin, OUTPUT);
  
  analogWrite(led1_pin, 0);
  analogWrite(led2_pin, 0);
  analogWrite(led3_pin, 0);
  analogWrite(led4_pin, 0);

}

void loop() {
  
  if (Serial.available() > 0) {
    
    int ledState = Serial.read();
    
    if (ledState & led1_mask)
    led1_state = (ledState & value_mask) * 8;
    
    if (ledState & led2_mask)
    led2_state = (ledState & value_mask) * 8;
    
    if (ledState & led3_mask)
    led3_state = (ledState & value_mask) * 8;
    
    if (ledState & led4_mask)
    led4_state = (ledState & value_mask) * 8;
    
    analogWrite(led1_pin, led1_state);
    analogWrite(led2_pin, led2_state);
    analogWrite(led3_pin, led3_state);
    analogWrite(led4_pin, led4_state);
    
  }
}



