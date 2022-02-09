
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

//fixed
char wordList[10] = "create";

int xspeed = 5;
int yspeed = 2;

void setup(void) {
  
  tft.init();
  tft.setRotation(1);

}

void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2.9);
  tft.setTextColor(random(0xFFFF));


  // Draw some randomly generated C-V words
  int i = random(0,6);

  int rx = random(40);
  int ry = random(40);
  int x = rx + random(160 - rx - rx);
  int y = 24*i;
  
  for (int h = y; h < 120; h+=8)
  {

    //falling
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
    if (y = 90) {
      
      tft.fillScreen(TFT_BLACK);
      int count = 0;
      while (count < 10){
        
        if ((x < 20 || x > 100) || (y > 150 || y < 5)){
          xspeed *=(-1);
          yspeed *=(-1);

          count++;
        }

        y -= yspeed;
        x += xspeed;

        //give letters diff speed
        tft.drawString(String(wordList[0]), x-20, y, 2);
        tft.drawString(String(wordList[1]), x-10, y, 2);
        tft.drawString(String(wordList[2]), x-5, y, 2);
        tft.drawString(String(wordList[3]), x, y, 2);
        tft.drawString(String(wordList[4]), x+5, y, 2);
        tft.drawString(String(wordList[5]), x+10, y, 2);

        delay(60);

        tft.fillScreen(TFT_BLACK);
        tft.drawString(String("Ecology is balance."), 0, 0);

        
      }
      
    
  }

  

  delay(10);
  
}

  
