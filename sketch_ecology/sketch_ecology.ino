
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

//fixed
char wordOrigin[] = ("create");
String wordList6[200] = {"create", "cetera", "cerate", "ecarte"}; //4
String wordList5[200] = {"arete", "caret", "carte", "cater", "crate", 
                  "eater", "erect", "erect", "react", "recta", "terce", "trace"}; //12
String wordList4[200] = {"acer", "acre", "arte", "care", "cart", "cate", "cere"}; //7
char headCon[10] = {'c', 'r', 't', 'v'}; //4
char headVow[10] = {'e', 'a', 'i', 'e'}; //4

int16_t h = 128;
int16_t w = 160;

int xspeed = 20;
int yspeed = 15;

int x = w/2;
int y = h/2;

void setup(void) {
  randomSeed(analogRead(0) * analogRead(1));

  tft.init();
  tft.setRotation(1);

}

void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(3);
  tft.setTextColor(random(0xFFFF));

  tft.fillScreen(TFT_BLACK);
  
  int count = 0;
  
  while (count < 155){
    y -= yspeed;
    x += xspeed;
                    
    if (x < 10 || x > w - 20){
      xspeed *= (-1);
      count+=2;
    }
  
    if (y > h - 40 || y < 10){
      yspeed *= (-1);
      count+=2;
    }

  
    //draw blinking & bouncing letters
    if (count < 20){
      tft.drawString(String(wordList6[random(4)]), x, y, 2);
      //tft.drawString(String(count), 0, 0);
      delay(120);

      tft.fillScreen(TFT_BLACK);

      }

    else if (count < 40){
      tft.drawString(String(wordList5[random(12)]), x, y, 2);
      //tft.drawString(String(count), 0, 0);
      delay(120);

      tft.fillScreen(TFT_BLACK);

    }

    else if (count < 70){
      tft.drawString(String(wordList4[random(7)]), x, y, 2);
      //tft.drawString(String(count), 0, 0);
      delay(120);

      tft.fillScreen(TFT_BLACK);

    }

    else if (count < 150){
      tft.drawString(String(headCon[random(4)]) + String(headVow[random(4)]) + String(headCon[random(6) % 2]), x, y, 2);
      //tft.drawString(String(count), 0, 0);
      delay(120);

      tft.fillScreen(TFT_BLACK);

    }
  
        
    }

  
      
    
}

    


  
