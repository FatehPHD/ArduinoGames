#include <TFT_eSPI.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

TFT_eSPI tft = TFT_eSPI();

float cursorX = 240.0;
float cursorY = 190.0;
int resetCount = 0;
int hasRun=20;
int mazeRun;
int runner;
char u;

#define JOYSTICK_X_PIN A11
#define JOYSTICK_Y_PIN A15
#define JOYSTICK_BUTTON_PIN 34

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define DARK_GREEN 0x970B00
#define BROWN	0x7164

int i;
unsigned long interval1 = 500;
unsigned long currentMillis1;
unsigned long currentMillis2;
unsigned long currentMillis3;
unsigned long previousMillis = 0;
unsigned long totalMillis;
int home;
int x;
int z;
int w;
int var = 300;
int rest = 0;
int rnd = 200;
int loss = 0;
int score_= 0;
int bargap = 50;
int starx=240;
int stary = 160;
int counter_st= 0;
int highest = 0;
int coin_collect=0;
int flap_loss_ = 0;
int rect_pos;
int j;
int k;
int m;
int player_y;
unsigned long run_millis;
unsigned long run_previousMillis;
int player_height;
int jump;
int countjump = 0;
int line_;
int line_run;
int line_gap;
int var_height;
int var_height2;
int c;
int line_1;
int flap_points;
int flap_high_score;

void setup() {
  pinMode(6,INPUT);
  pinMode(11,INPUT);
  pinMode(8, INPUT);
  pinMode(5, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(BLACK);

  pinMode(JOYSTICK_BUTTON_PIN, INPUT);
  digitalWrite(JOYSTICK_BUTTON_PIN, HIGH);
  Serial.begin(9600);  
  home = 1;
  int i = 0;
}

void loop() {
  if (digitalRead(6) == HIGH) {
    tft.fillScreen(BLACK);
    home = 1;
    hasRun = 20;
    mazeRun = 2;
    loss = 0;
    loss=0;
    var = 300;
    score_ = 0;
    bargap = 50;
    cursorX = 240;
    cursorY = 60;
    coin_collect =0;    
  }

  if (home == 1){
    tft.drawLine(30, 30, 450, 30, CYAN);
    tft.setCursor(40, 0);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.println("Select An Option!");
    
    tft.drawRect(7,49,220,60,WHITE);
    tft.setCursor(20, 70);
    tft.setTextSize(2.5);
    tft.println("Color Game");
    
    tft.drawRect(130,120,220,60,WHITE);
    tft.setCursor(140, 141);
    tft.setTextSize(2.5);
    tft.println("Dodge the bar");
    
    tft.drawRect(253,49,220,60,WHITE);
    tft.setCursor(283, 70);
    tft.setTextSize(2);
    tft.println("Flappy Ball");
    tft.setCursor(220, 80);

    tft.setCursor(20, 200);
    tft.setTextSize(3);
    tft.println("-> Press down on joystick to select a game");
    tft.setCursor(220, 80);    

    tft.setCursor(10,140);
    tft.setTextSize(3);
    tft.setTextColor(CYAN);
    tft.println("BETTER");

    tft.setCursor(354,140);
    tft.setTextSize(3);
    tft.setTextColor(CYAN);
    tft.println("STATION");

    home = 2;
  }  

  if (home == 2 ){
    while (home !=7){
      tft.fillTriangle(cursorX,cursorY,cursorX+10,cursorY+13,cursorX,cursorY+17,BLACK);
      tft.fillRect(cursorX+3.5, cursorY+13, 3, 10, BLACK);
      float JoyStickX = map(analogRead(JOYSTICK_X_PIN), 0, 1023, -1000, 1000)/40.0;
      float JoyStickY = map(analogRead(JOYSTICK_Y_PIN), 0, 1023, -1000, 1000)/40.0;
      cursorY = cursorY + JoyStickY;
      cursorX = cursorX + JoyStickX;
      cursorX = constrain(cursorX, 0,480);
      cursorY = constrain(cursorY, 0,320);
      
      //tft.drawPixel(int(cursorX), int(cursorY), WHITE);
      //tft.drawPixel(int(cursorX), int(cursorY), BLACK);
      //delay(100);
      tft.fillTriangle(cursorX,cursorY,cursorX+10,cursorY+13,cursorX,cursorY+17,MAGENTA);
      tft.fillRect(cursorX+3.5, cursorY+13, 3, 10, MAGENTA);
      
      tft.drawLine(30, 30, 450, 30, CYAN);      
      tft.setCursor(40, 0);
      tft.setTextColor(WHITE);
      tft.setTextSize(4);
      tft.println("Select An Option!");
      
      tft.drawRect(7,49,220,60,WHITE);
      tft.setCursor(20, 70);
      tft.setTextSize(2.5);
      tft.println("Color Game");
      
      
      
      tft.drawRect(130,120,220,60,WHITE);
      tft.setCursor(140, 141);
      tft.setTextSize(2.5);
      tft.println("Dodge the bar");
      
      tft.drawRect(253,49,220,60,WHITE);
      tft.setCursor(283, 70);
      tft.setTextSize(2);
      tft.println("Flappy Ball");
      tft.setCursor(220, 80);

      tft.setCursor(20, 200);
      tft.setTextSize(3);
      tft.println("-> Press down on joystick to select a game");
      tft.setCursor(220, 80);
      
      tft.fillTriangle(cursorX,cursorY,cursorX+10,cursorY+13,cursorX,cursorY+17,BLACK);
      tft.fillRect(cursorX+3.5, cursorY+13, 3, 10, BLACK);

      JoyStickX = map(analogRead(JOYSTICK_X_PIN), 0, 1023, -1000, 1000)/40.0;
      JoyStickY = map(analogRead(JOYSTICK_Y_PIN), 0, 1023, -1000, 1000)/40.0;
      
      cursorY = cursorY + JoyStickY;
      cursorX = cursorX + JoyStickX;

      tft.fillTriangle(cursorX,cursorY,cursorX+10,cursorY+13,cursorX,cursorY+17,MAGENTA);
      tft.fillRect(cursorX+3.5, cursorY+13, 3, 10, MAGENTA);  

      tft.setCursor(10,140);
      tft.setTextSize(3);
      tft.setTextColor(CYAN);
      tft.println("BETTER");

      tft.setCursor(354,140);
      tft.setTextSize(3);
      tft.setTextColor(CYAN);
      tft.println("STATION");
      tft.setCursor(cursorX, cursorY);

      if (cursorX>=7 and cursorX<=227 and cursorY>=49 and cursorY<=109){
        if (digitalRead(JOYSTICK_BUTTON_PIN) == 0){
          tft.fillScreen(BLACK);
          hasRun=0;
          mazeRun = 2;
          runner = 10;
          home = 7;
        }
      }

      if (cursorX>=130 and cursorX<=350 and cursorY>=120 and cursorY<= 180){
        if (digitalRead(JOYSTICK_BUTTON_PIN) == 0){
          tft.fillScreen(BLACK);
          hasRun = 21;          
          mazeRun = 0;
          runner = 10;
          home = 7;
        }
      }
      
      if (cursorX>=253 and cursorX<=473 and cursorY>=49 and cursorY<=109){
        if (digitalRead(JOYSTICK_BUTTON_PIN) == 0){
          tft.fillScreen(BLACK);
          hasRun = 21;
          mazeRun = 2;
          runner = 0;
          home = 7;
        }
      }
    }
  }  
  if (loss!=1){
    reset_();
  }
  
  tft.setCursor(0,0);
  tft.setTextSize(4);
  tft.println("        ");

  if (i == 10) {
    interval1 -= 1;
    i = 0;
  }

  if(mazeRun ==0){
    tft.setTextSize(6);
    tft.setTextColor(CYAN);
    tft.setCursor(10,10);
    tft.drawRect(0,0,480,60,MAGENTA);    
    tft.println("DODGE THE BAR");

    tft.setCursor(20,70);
    tft.setTextSize(3);
    tft.setTextColor(GREEN);
    tft.println("Press Joystick to BEGIN!");
    
    tft.setCursor(5,110);
    tft.setTextSize(4);
    tft.setTextColor(RED); 
    tft.println("RULES:");

    tft.setCursor(5,150);
    tft.setTextSize(2);
    tft.setTextColor(WHITE); 
    tft.println("-> Avoid the bars by going through the gaps,");

    tft.setCursor(5,190);
    tft.setTextSize(2);
    tft.setTextColor(WHITE); 
    tft.println("-> Collect the coins for extra points,");
    
    tft.setCursor(5,215);
    tft.setTextSize(2);
    tft.setTextColor(WHITE); 
    tft.println("-> It gets harder with time!");

    if (digitalRead(JOYSTICK_BUTTON_PIN) == 0){
      tft.fillScreen(BLACK);      
      mazeRun=1;
    }
  }
  if (mazeRun == 1){
    home = 20;
    Maze();
  }

  if (hasRun == 0) {
    tft.setTextSize(5);
    tft.setTextColor(CYAN);
    tft.setCursor(15,10);
    tft.drawRect(0,0,480,55,MAGENTA);    
    tft.println("THE COLOUR GAME");

    tft.setCursor(20,70);
    tft.setTextSize(3);
    tft.setTextColor(GREEN);
    tft.println("Press Button 1 to BEGIN!");
    
    tft.setCursor(5,110);
    tft.setTextSize(4);
    tft.setTextColor(CYAN); 
    tft.println("RULES:");

    tft.setCursor(5,150);
    tft.setTextSize(2);
    tft.setTextColor(WHITE); 
    tft.println("-> Press the button corresponding to    the colour on the screen");

    tft.setCursor(5,200);
    tft.setTextSize(2);
    tft.setTextColor(WHITE); 
    tft.println("-> 2 is for green, 3 is for blue, and 4 is for magenta");
    
    tft.setCursor(5,250);
    tft.setTextSize(2);
    tft.setTextColor(WHITE); 
    tft.println("-> It gets harder with time, GOODLUCK!");

    hasRun0();
  }

  if (runner == 0) {
    tft.setTextSize(5);
    tft.setTextColor(CYAN);
    tft.setCursor(15,10);
    tft.drawRect(0,0,480,55,MAGENTA);    
    tft.println("FLAPPY BALL");

    tft.setCursor(15,70);
    tft.setTextSize(3);
    tft.setTextColor(GREEN);
    tft.println("Press Joystick to BEGIN!");
    
    tft.setCursor(15,110);
    tft.setTextSize(4);
    tft.setTextColor(CYAN); 
    tft.println("RULES:");

    tft.setCursor(15,150);
    tft.setTextSize(2);
    tft.setTextColor(WHITE); 
    tft.println("-> Avoid the bars by flapping your way through the gaps");

    tft.setCursor(15,190);
    tft.setTextSize(2);
    tft.setTextColor(WHITE); 
    tft.println("-> To flap press down on button 2");    

    runner_();
  }

  if (runner == 2){
    runner_();
    
    tft.setCursor(10,10);
    tft.setTextSize(6);
    tft.setTextColor(RED); 
    tft.println("GAME OVER...");

    tft.setCursor(10,70);
    tft.setTextSize(3);
    tft.setTextColor(WHITE); 
    tft.println("Press Joystick to RESTART!");   

    tft.drawRect(30,120,185,175,YELLOW); 
    tft.setCursor(35,125);
    tft.setTextSize(5);
    tft.setTextColor(WHITE); 
    tft.println("POINTS");    
    tft.setCursor(110,200);
    tft.setTextSize(6);
    tft.setTextColor(WHITE); 
    tft.println(flap_points);       

    tft.drawRect(265,120,185,175,YELLOW); 
    tft.setCursor(270,125);
    tft.setTextSize(3);
    tft.setTextColor(WHITE); 
    tft.println("HIGH SCORE");    
    tft.setCursor(350,200);
    tft.setTextSize(6);
    tft.setTextColor(WHITE); 
    tft.println(flap_high_score);      
  }

  if (hasRun == 1) { 
    hasRun1();
  }
  
  if (hasRun == 2) {   
    hasRun2();
  }
  
  if (hasRun == 3) {
    hasRun3();
  }
 
  if (hasRun == 4) {
    hasRun4();
  }

  if (hasRun == 5) {
    hasRun5();
  }
}

void hasRun0() {
  if (digitalRead(11) == HIGH) {
    tft.fillScreen(BLACK);
  
    tft.setCursor(120, 160);
    tft.setTextColor(WHITE);
    tft.setTextSize(6);
    tft.println("GO!!");

    hasRun = 1;
  }
}

void hasRun1() {
  totalMillis = millis();
  unsigned long time = millis();
  
  tft.fillRect(10,10,460,300,GREEN);
  tft.setCursor(240, 160);
  tft.setTextColor(WHITE);
  tft.setTextSize(7);
  tft.println("1");
  
  currentMillis1 = millis();

  while (millis() - currentMillis1 <= interval1) {
    if (digitalRead(8) == HIGH) {
      hasRun = 2;
      i += 1;
    }
  }

  if (hasRun != 2) {
    tft.fillScreen(BLACK);
    tft.setCursor(100, 160);
    tft.setTextColor(RED);
    tft.setTextSize(6);
    tft.println("You lose!!");

    i = 0;
    hasRun = 6;

    tft.setCursor(0, 0);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.println((time - totalMillis) / 1000);
  }
}

void hasRun2() {
  unsigned long time = millis(); 
  
  tft.fillRect(10,10,460,300,BLUE);

  tft.setCursor(240, 160);
  tft.setTextColor(WHITE);
  tft.setTextSize(6);
  tft.println("2");

  currentMillis2 = millis();
    
  while (millis() - currentMillis2 <= interval1) {
    if (digitalRead(5) == HIGH) {
      hasRun = 3;
      i += 1;
    }
  }

  if (hasRun != 3) {
    tft.fillScreen(BLACK);
    tft.setCursor(100, 160);
    tft.setTextColor(RED);
    tft.setTextSize(6);
    tft.println("You lose!!");

    i = 0;
    hasRun = 6;

    tft.setCursor(0, 0);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.println("Score:");
    tft.setCursor(150,0);
    tft.println((time - totalMillis) / 1000);
  }
}

void hasRun3() {
  unsigned long time = millis(); 
  
  tft.fillRect(10,10,460,300,MAGENTA);

  tft.setCursor(240, 160);
  tft.setTextColor(WHITE);
  tft.setTextSize(6);
  tft.println("3");

  currentMillis3 = millis();
  
  x = rand_int();

  while (millis() - currentMillis3 <= interval1) {
    if (digitalRead(3) == HIGH) {
      hasRun = x;
      i += 1;
    }
  }

  if (hasRun != x) {
    tft.fillScreen(BLACK);
    tft.setCursor(100, 160);
    tft.setTextColor(RED);
    tft.setTextSize(6);
    tft.println("You lose!!");  

    hasRun = 6;
    i = 0;

    tft.setCursor(0, 0);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.println("Score:");
    tft.setCursor(150,0);
    tft.println((time - totalMillis) / 1000);
  }
}

void hasRun4() {
  unsigned long time = millis();  
  
  tft.fillRect(10,10,460,300,GREEN);
  tft.setCursor(240, 160);
  tft.setTextColor(WHITE);
  tft.setTextSize(6);
  tft.println("1");
  
  currentMillis1 = millis();

  x = rand_int();

  while (millis() - currentMillis1 <= interval1) {
  
    if (digitalRead(8) == HIGH) {
      hasRun = x;
      i += 1;
    }
  }
  if (hasRun != x) {
    tft.fillScreen(BLACK);
    tft.setCursor(100, 160);
    tft.setTextColor(RED);
    tft.setTextSize(6);
    tft.println("You lose!!");

    hasRun = 6;
    i = 0;

    tft.setCursor(0, 0);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.println("Score:");
    tft.setCursor(150,0);    
    tft.println((time - totalMillis) / 1000);
  }
}

void hasRun5() {
  unsigned long time = millis();  
  
  tft.fillRect(10,10,460,300,BLUE);

  tft.setCursor(240, 160);
  tft.setTextColor(WHITE);
  tft.setTextSize(6);
  tft.println("2");

  currentMillis2 = millis();
  
  x = rand_int();

  while (millis() - currentMillis2 <= interval1) {
  
    if (digitalRead(5) == HIGH) {
      hasRun = x;
      i += 1;
    }
  }
  if (hasRun != x) {
    tft.fillScreen(BLACK);
    tft.setCursor(100, 160);
    tft.setTextColor(RED);
    tft.setTextSize(6);
    tft.println("You lose!!");

    hasRun = 6;
    i = 0;

    tft.setCursor(0, 0);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.println("Score:");
    tft.setCursor(150,0);
    tft.println((time - totalMillis) / 1000);
  }
}

int rand_int()
{
  int lower = 3, upper = 5;

  int num = (rand() % (upper - lower + 1)) + lower;

  Serial.print(num);

  return num;
}

void reset_() {

  if (digitalRead(JOYSTICK_BUTTON_PIN) == 0) {

    resetCount += 1;
  }
  else {
    resetCount = 0;
  }
  if (resetCount > 100) {
    hasRun = 0;
    tft.fillScreen(BLACK);

    tft.setCursor(160, 160);
    tft.setTextColor(WHITE);
    tft.setTextSize(5);
    tft.println("Ready?");
    resetCount = digitalRead(JOYSTICK_BUTTON_PIN);
  }
}

void Maze(){  
  counter_st=0;
  if( score_ >= 10){
    bargap = 45;
  }
  if( score_ >= 20){
    bargap = 35;
  }
  if( score_ >= 30){
    bargap = 30;
  }
  if( score_ >= 40){
    bargap = 25;
  }
  if( score_ >= 50){
    bargap = 20;
  }
  if( score_ >= 60){
    bargap = 15;
    
  }
  if ( rest == 1){
    rnd = randx();
    rest = 0;
    home = 20;
  }
  if (loss!=1){
    tft.fillCircle(starx,stary,8,YELLOW);
  }
  
  while (home !=7 and loss != 1){
      float JoyStickX = map(analogRead(JOYSTICK_X_PIN), 0, 1023, -1000, 1000)/60.0;
      float JoyStickY = map(analogRead(JOYSTICK_Y_PIN), 0, 1023, -1000, 1000)/160.0;
      cursorY = cursorY + JoyStickY;
      cursorX = cursorX + JoyStickX;
      cursorX = constrain(cursorX, 0,480);
      cursorY = constrain(cursorY, 0,320);
      tft.fillRect(cursorX-2, cursorY-2, 4, 4, WHITE);/////curser
      tft.fillRect(0, var, rnd, 10, GREEN);/////line
      tft.fillRect(rnd + bargap, var, 480-(rnd+bargap), 10, GREEN);/////line
      //tft.drawFastHLine(0,var,rnd,GREEN);
      //tft.drawFastHLine(rnd + bargap, var, 480-(rnd+bargap),GREEN);

      
      if((stary+8)>=(var)){
        counter_st+=1;
          if (counter_st == 1){
            tft.fillCircle(starx,stary,8,BLACK);
          }
      }
      else{
        if ((cursorX+2.5) >= (starx-8) and (cursorX-2.5) <=(starx + 8) and (cursorY+2.5) >= (stary-8) and (cursorY-2.5) <= (stary+8))   {
          counter_st+=1;
          if (counter_st == 1){
            tft.fillCircle(starx,stary,8,BLACK);
            score_+=1;
            coin_collect+=1;
          }
        
        }
      }
      //tft.drawFastHLine(0,var+12,rnd,BLACK);
      //tft.drawFastHLine(rnd + bargap, var+12, 480-(rnd+bargap),BLACK);
      tft.fillRect(cursorX-3, cursorY-3, 6, 6, BLACK);/////curser 
      tft.fillRect(0, var, rnd, 10, BLACK);/////line
      tft.fillRect(rnd + bargap, var, 480-(rnd+bargap), 10, BLACK);/////line  
      if ((cursorX-2) <= rnd and (cursorY+2)>=var and (cursorY-2)<= (var+10))   {
        home = 7;
        loss = 1;
        tft.fillCircle(starx,stary,8,BLACK);
      }  

      if ((cursorX+2) >= (rnd+bargap) and (cursorY+2)>=var and (cursorY-2)<= (var+10))   {
        home = 7;
        loss = 1;
        tft.fillCircle(starx,stary,8,BLACK);
      }  
      
    var-=(5+(score_/10));

    if (var < -5){
      var = 300;
      rest = 1;
      home = 7;
      tft.fillCircle(starx,stary,8,BLACK);
      starx= randx();
      stary = randy();
      counter_st = 0;
      score_+=1;
    }
  }

  if (loss == 1){
    tft.setTextSize(4);
    tft.setCursor(0,5);
    tft.setTextColor(WHITE);
    tft.println("Score:");
    tft.setCursor(160,5);
    tft.println(score_);    
    
    if(score_>= highest){
      highest = score_;
      tft.setTextSize(4);
      tft.setTextColor(BLUE);
      tft.setCursor(85,120);
      tft.println("Highest Score");
      tft.setTextSize(2);
      tft.setCursor(240,10);
      tft.setTextColor(YELLOW);
      tft.println("Coins Collected:");
      tft.setCursor(440,10);
      tft.println(coin_collect);
    }

    else{
      tft.setTextSize(3);
      tft.setTextColor(BLUE);
      tft.setCursor(5,290);
      tft.println("Highest was:");
      tft.setCursor(220,290);
      tft.println(highest);
      tft.setTextSize(5);
      tft.setTextColor(RED);
      tft.setCursor(120,120);
      tft.println("Nice try!");
      tft.setTextSize(2);
      tft.setCursor(240,10);
      tft.setTextColor(YELLOW);
      tft.println("Coins Collected:");
      tft.setCursor(440,10);
      tft.println(coin_collect);
    }

    tft.setCursor(20,170);
    tft.setTextSize(3);
    tft.setTextColor(GREEN);
    tft.println("Press joystick to restart");
    
    if (digitalRead(JOYSTICK_BUTTON_PIN) == 0) {
      tft.fillScreen(BLACK);
      loss=0;
      var = 300;
      score_ = 0;
      bargap = 50;
      cursorX = 240;
      cursorY=60;
      coin_collect =0;
      starx= randx();
      stary = randy();
    }
  }
}

int randx() {
  int lower = 0, upper = 430;

  int num = (rand() % (upper - lower + 1)) + lower;

  Serial.print(num);

  return num;
}

int randy() {
  int lower = 50, upper = 150;

  int num = (rand() % (upper - lower + 1)) + lower;

  Serial.print(num);

  return num;
}



void runner_(){
  if (digitalRead(JOYSTICK_BUTTON_PIN) == 0) {
    flap_loss_ = 1;
    flap_points = 0;
    tft.fillScreen(CYAN);
    line_ = 340;
    line_1 = 480;
    line_gap = 75;
    var_height = height_rand_int();
    var_height2 = height_rand_int();
    player_height = var_height + line_gap / 2;
    tft.fillRect(0,0,120,320,CYAN);
    tft.fillRect(360,0,480,320,CYAN);
    tft.fillRect(30,100,30,320,BROWN);
    tft.fillRect(0,5,100,100,DARK_GREEN);
    tft.fillRect(420,100,30,320,BROWN);
    tft.fillRect(380,5,100,100,DARK_GREEN);
  }

  while (flap_loss_ == 1) {
    if (line_ >= 320 and line_<= 340){
      tft.drawFastVLine(line_-220, 0, 320, CYAN);
    }
    
    runner = 1;
    player();
    
    tft.drawFastVLine(line_, 0, var_height, DARK_GREEN);

    tft.drawFastVLine(line_+20, 0, var_height, CYAN);

    tft.drawFastVLine(line_, (var_height + line_gap), (320 - var_height - line_gap), DARK_GREEN);

    tft.drawFastVLine(line_+20, (var_height + line_gap), (320 - var_height - line_gap), CYAN);

    line_ -= 1;
      
    if (line_ < 100){
      line_ = 340;
      var_height = height_rand_int();
      flap_points += 1;
    }

    if ((player_height <= var_height and line_ <= 158 and line_ + 20 > 140) or (player_height >= (var_height + line_gap) and line_ <= 158 and line_ + 20 > 140)) {
      if (flap_points > flap_high_score){
        flap_high_score = flap_points;
      }
      tft.fillScreen(BLACK);
      flap_loss_ = 0;
      runner = 2;
      line_ = 340;
    }    
  }
}

void under_rect(){
  tft.drawRect(400-z,240,80,40,CYAN);

  tft.drawRect(400-z,240,80,40,BLACK);

  z += 1;
}

void above_rect() {
  tft.drawRect(400-w,280,80,40,CYAN);
  
  tft.drawRect(400-w,280,80,40,BLACK);
  
  w += 1;
}

void player() {
  if (j == 0){
    if (digitalRead(5) == HIGH) {
      countjump+=1;
      if(countjump==1)   {
        j = 1;
        m = 0;
      }
      
    }
    player_height += 2;
    tft.fillCircle(150,(player_height),8,YELLOW);
    tft.fillCircle(150,(player_height),8,CYAN);
  }
  if(digitalRead(5)== LOW){
    countjump = 0;
  }
  if (player_height > 320){
    player_height=10;
  }
  if (player_height < 0) {
    player_height=310;
  }



  if (j == 1) {
    
    if (m < 18) {
      player_height -= 2;
      m += 1;
      tft.fillCircle(150,(player_height),8,GREEN);

      
      tft.fillCircle(150,(player_height),8,CYAN);
    }
    else {
      j = 0;
    }

  }
}

int height_rand_int()
{
  int lower = 20, upper = 245;

  int num = (rand() % (upper - lower + 1)) + lower;

  return num;
}

  
//  if (m == 0){
//    tft.drawRect(30,280,40,40,BLUE);
 // }

 // if (digitalRead(6) == HIGH) {
 //   m = 1;
//  }

 // if (m == 1) {
 //   tft.drawRect(30,(280 + k),40,40,BLUE);

 //   tft.drawRect(30,(280 + k),40,40,BLACK);
 //// 
 //   k -= 2;
//
//    if (k == -320){
//      m = 2;     
 //   } 
//  }


//  if (m == 2) {
//    tft.drawRect(30,(280 + k),40,40,BLUE);
//
//    tft.drawRect(30,(280 + k),40,40,BLACK);
//    k += 2;
//    if (k == 40){
//      m = 0; 
//      k = 0;     
//    }    
//  }
