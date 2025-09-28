#include <Keyboard.h>
#include <DIYables_IRcontroller.h> // DIYables_IRcontroller library
#define IR_RECEIVER_PIN 7 // The Arduino Nano pin connected to IR controller

DIYables_IRcontroller_17 irController(IR_RECEIVER_PIN, 200); // debounce time is 200ms
//int lang=0;//0 default eng,1 tr
void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  irController.begin();
}

void loop() {
  Key17 key = irController.getKey();
  if (key != Key17::NONE) {
    switch (key) {
      case Key17::KEY_1:
        //screen_photo
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press(KEY_LEFT_SHIFT);
        delay(100);
        Keyboard.press('s');
        delay(100);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_2:
        //alt_f4
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press('d');
        delay(100);
        Keyboard.releaseAll();
        delay(100);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_F4);
        delay(100);
        Keyboard.releaseAll();
        delay(500);
        Keyboard.press(KEY_DOWN_ARROW);
        Keyboard.releaseAll();
        delay(2000);
        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_3:
        //close_off
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press('l');
        delay(100);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_4:
        //code=1
        break;

      case Key17::KEY_5:
        //code=2
        break;

      case Key17::KEY_6:
        //gui_d
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press('d');
        delay(100);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_7:
        //f11
        Keyboard.press(KEY_F11);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_8:
        //enter
        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_9:
        //chance_language
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_SHIFT);
        delay(100);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_STAR:
        //esc
        Keyboard.press(KEY_ESC);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_0:
        //rickroll*english
        if(lang==0){
          Keyboard.press(KEY_LEFT_GUI);
          delay(100);
          Keyboard.press('r');
          delay(100);
          Keyboard.releaseAll();
          delay(500);
          Keyboard.println("chrome www.youtube.com/watch?v=dQw4w9WgXcQ");
          delay(1000);
          Keyboard.press(KEY_RETURN);
          delay(100);
          Keyboard.releaseAll();}
        if(lang==1){
          //tr_rickroll
          }
        break;

      case Key17::KEY_SHARP:
        //alt_tab
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_TAB);
        delay(100);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_UP:
        //sound_up
        Keyboard.press(KEY_UP_ARROW);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_DOWN:
        //sound_down
        Keyboard.press(KEY_DOWN_ARROW);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_LEFT:
        //take_video_left
        Keyboard.press(KEY_LEFT_ARROW);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_RIGHT:
        //take_video_right
        Keyboard.press(KEY_RIGHT_ARROW);
        Keyboard.releaseAll();
        break;

      case Key17::KEY_OK :
        //space
        Keyboard.press(' ');
        Keyboard.releaseAll();
        break;

      default:
        Serial.println("WARNING: undefined key:");
        break;
    }
  }
}
