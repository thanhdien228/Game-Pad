#include <Keyboard.h>
#include <Mouse.h>
#include <EEPROM.h>
#include <Arduino_FreeRTOS.h>

const int Wbutton = 9; 
const int Sbutton = 3;
const int Dbutton = 7;
const int Abutton = 8;
const int Y = 15;
const int B = 14; 
const int X = 16;
const int A = 10;
const int R1button = A3;
const int L1button = 2;
const int joystickVRx1 = A7;
const int joystickVRy1 = A6;
const int joystickVRx2 = A2;
const int joystickVRy2 = A1;
const int mouseVelocity = 20;
const int joystickCenter = mouseVelocity/2;

void setup() {
  xTaskCreate(taskWASDButtonsControl, "WASD Buttons Control", 128, NULL, 3, NULL);
  xTaskCreate(taskPlayStationButtonsControl, "PlayStation Buttons Control", 128, NULL, 2, NULL);
  xTaskCreate(taskJoystickMovementControl, "Joystick Movement Control", 128, NULL, 3, NULL);
  xTaskCreate(taskMouseMovementControl, "Mouse Movement Control", 128, NULL, 4, NULL);
  xTaskCreate(taskMouseClicksControl, "Mouse Clicks Control", 128, NULL, 5, NULL);

  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(Wbutton, INPUT_PULLUP);
  pinMode(Abutton, INPUT_PULLUP);
  pinMode(Sbutton, INPUT_PULLUP);
  pinMode(Dbutton, INPUT_PULLUP);
  pinMode(A, INPUT_PULLUP);
  pinMode(X, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
  pinMode(Y, INPUT_PULLUP);
  pinMode(R1button, INPUT_PULLUP);
  pinMode(L1button, INPUT_PULLUP);
  pinMode(joystickVRx1, INPUT);
  pinMode(joystickVRy1, INPUT);
  pinMode(joystickVRx2, INPUT);
  pinMode(joystickVRy2, INPUT);
  EEPROM.write(0, 'w');
  EEPROM.write(1, 's');
  EEPROM.write(2, 'd');
  EEPROM.write(3, 'a');
  EEPROM.write(4, 'j');
  EEPROM.write(5, 'k');
  EEPROM.write(6, 'l');
  EEPROM.write(7, ' ');
  Keyboard.begin();
  Mouse.begin();
}

 void loop() {
/*  if (Serial.available() > 0) {
    // Đọc dữ liệu từ cổng Serial
    String data = Serial.readString();
    char addrS = data.charAt(0);
    int addrI = atoi(addrS);
    // Ghi dữ liệu vào EEPROM
    EEPROM.write(addrI, data.charAt(1));    
  }
*/
  if (Serial.available() > 0) {
    // Đọc dữ liệu từ cổng Serial
    String data = Serial.readString();
    char addrS = data.charAt(0);
    if(addrS == '0'){
      // Ghi dữ liệu vào EEPROM
      EEPROM.write(0, data.charAt(1));  
    }
    else if(addrS == '1'){
      // Ghi dữ liệu vào EEPROM
      EEPROM.write(1, data.charAt(1));  
    }
    else if(addrS == '2'){
      // Ghi dữ liệu vào EEPROM
      EEPROM.write(2, data.charAt(1));  
    }
    else if(addrS == '3'){
      // Ghi dữ liệu vào EEPROM
      EEPROM.write(3, data.charAt(1));  
    }
    else if(addrS == '4'){
      // Ghi dữ liệu vào EEPROM
      EEPROM.write(4, data.charAt(1));  
    }
    else if(addrS == '5'){
      // Ghi dữ liệu vào EEPROM
      EEPROM.write(5, data.charAt(1));  
    }
    else if(addrS == '6'){
      // Ghi dữ liệu vào EEPROM
      EEPROM.write(6, data.charAt(1));  
    }  
    else if(addrS == '7'){
      // Ghi dữ liệu vào EEPROM
      EEPROM.write(7, data.charAt(1));  
    }
  }
}

void taskWASDButtonsControl(void *pvParameters) {

  for(;;) {
    char UP = EEPROM.read(0);
    char DOWN = EEPROM.read(1);
    char RIGHT = EEPROM.read(2);
    char LEFT = EEPROM.read(3);
    if(digitalRead(Wbutton) == LOW){
      Keyboard.press(UP);
    }
    else{
      Keyboard.release(UP);
    }

    if(digitalRead(Abutton) == LOW){
      Keyboard.press(LEFT);
    }
    else{
      Keyboard.release(LEFT);
    }

    if(digitalRead(Sbutton) == LOW){
      Keyboard.press(DOWN);
    }
    else{
      Keyboard.release(DOWN);
    }

    if(digitalRead(Dbutton) == LOW){
      Keyboard.press(RIGHT);
    }
    else{
      Keyboard.release(RIGHT);
    }
    vTaskDelay(5);
  }
}

void taskPlayStationButtonsControl(void *pvParameters) {

  for(;;) {
      char Skill1 = EEPROM.read(4);
  char Skill2 = EEPROM.read(5);
  char Skill3 = EEPROM.read(6);
  char Skill4 = EEPROM.read(7);
    //Code điều khiển nút X, O, Triangle và Square
  if(digitalRead(A)==0){
    Keyboard.press(Skill1);
  }
  else{
      Keyboard.release(Skill1);
  }
  if(digitalRead(B)==0){
    Keyboard.press(Skill2);
  }
  else{
      Keyboard.release(Skill2);
  }
  if(digitalRead(Y)==0){
    Keyboard.press(Skill3);
  }
  else{
      Keyboard.release(Skill3);
  }

  if(digitalRead(X)==0){
    Keyboard.press(Skill4);
  }
  else{
      Keyboard.release(Skill4);
  }
  vTaskDelay(5);
  }
}

void taskJoystickMovementControl(void *pvParameters) {

  for(;;) {
      char UP = EEPROM.read(0);
  char DOWN = EEPROM.read(1);
  char RIGHT = EEPROM.read(2);
  char LEFT = EEPROM.read(3);
    //Code điều khiển joystick trái
    int VRxlecture = analogRead(joystickVRy1);
  int VRylecture = analogRead(joystickVRx1);
  
  if(VRylecture > 600 ){
    Keyboard.press(UP);
  }

  if(VRylecture < 400 ){
    Keyboard.press(DOWN);
  }
  
  if(VRxlecture > 600 ){
    Keyboard.press(RIGHT);
  }
  
  if(VRxlecture <400){
    Keyboard.press(LEFT);
  }
  vTaskDelay(5);
  }
}

void taskMouseMovementControl(void *pvParameters) {
  for(;;) {
    //Code điều khiển joystick phải
  int VRxlecture = analogRead(joystickVRx2);
  int VRylecture = analogRead(joystickVRy2);

  int xMove = 0;
  int yMove = 0;
  if(VRxlecture>=0 && VRxlecture<=1024 && VRylecture>=0 && VRylecture<=1024){  
  //Comprueba si hay algún error en la lectura
    if(VRxlecture<450 || VRxlecture>550){
      xMove = map(VRxlecture, 1024, 0, 0, mouseVelocity);
      xMove = xMove - joystickCenter;
    }
    
    if(VRylecture<450 || VRylecture>550){
      yMove = map(VRylecture, 0, 1024, 0, mouseVelocity);
      yMove = yMove - joystickCenter;
    }
    
    //El tercer argumento es el scroll
    Mouse.move(yMove, xMove, 0);
  }
  vTaskDelay(1);
  }
}

void taskMouseClicksControl(void *pvParameters) {
  for(;;) {
    //Code điều khiển nút L1 và R1
    if(!digitalRead(L1button)){
    Mouse.press(MOUSE_LEFT);
  }
  else{
    Mouse.release(MOUSE_LEFT);
  }

  if(!digitalRead(R1button)){
    Mouse.press(MOUSE_RIGHT);
  }
  else{
    Mouse.release(MOUSE_RIGHT);
  }
  vTaskDelay(2);
  }
}
                         
