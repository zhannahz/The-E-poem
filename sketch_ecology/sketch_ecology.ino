
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

//fixed
char wordList[10] = "create";

int16_t h = 128;
int16_t w = 160;

int xspeed = 5;
int yspeed = 7;


void setup(void) {
  randomSeed(analogRead(0) * analogRead(1));

  tft.init();
  tft.setRotation(1);

}

void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(random(0xFFFF));

  // Draw some randomly generated C-V words
  int i = random(0,6);
  int rx = random(40);
  int ry = random(40);
  int x = rx + random(160 - rx - rx);
  int y = 24*i;
  
  for (int h = y; h < 120; h+=8)
  {

    //word falling
    y = h;
    tft.drawString(
      String(wordList[0])+
      String(wordList[1])+
      String(wordList[2])+
      String(wordList[3])+
      String(wordList[4])+
      String(wordList[5]), x, y, 2);
    delay(60);
    tft.fillScreen(TFT_BLACK);

    
  }

    //if hit the bottom, bounce off
    if (y > 50) {
      
      tft.fillScreen(TFT_BLACK);
      int count = 0;
      while (count < 200){
        y -= yspeed;
        x += xspeed;
  
        //give letters diff speed
        tft.drawString(String(wordList[0]) + 
                        String(wordList[1]) +
                        String(wordList[2]) + 
                        String(wordList[3]) + 
                        String(wordList[4]) + 
                        String(wordList[5]), x, y, 2);

                        
        if (x < 10 || x > w - 20){
          xspeed *= (-1);
          count++;
        }
  
        if (y > h - 60 || y < 10){
          yspeed *= (-1);
          count++;
        }
        
  
        delay(120);
  
        tft.fillScreen(TFT_BLACK);

        
      }
      
    
  }

  

  delay(10);
  
}

  
