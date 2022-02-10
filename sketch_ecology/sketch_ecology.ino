
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

//fixed
char wordList[10] = "create";

int xspeed = 1.5;
int yspeed = 2;

void setup(void) {
  
  tft.init();
  tft.setRotation(1);

}

void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(random(0xFFFF));

  tft.drawString(String("Ecology is homeostasis."), 0, 0);


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
    if (y < tft.width()-20) {
      
      tft.fillScreen(TFT_BLACK);
      int count = 0;
      while (count < 10){
        
        if ((x < 45 || x > tft.height()-20) || (y > tft.width()-20 || y < 20)){
          xspeed *=(-1);
          yspeed *=(-1);

          count++;
        }

        //y -= yspeed;
        //x += xspeed;

        //give letters diff speed
        tft.drawString(String(wordList[0]), x+=xspeed + 10, y-= yspeed, 2);
        tft.drawString(String(wordList[1]), x+=xspeed*1.2 + 5, y-= yspeed, 2);
        tft.drawString(String(wordList[2]), x+=xspeed*0.2 + 2, y-= yspeed*1.8, 2);
        tft.drawString(String(wordList[3]), x+=xspeed*1.5, y-= yspeed, 2);
        tft.drawString(String(wordList[4]), x+=xspeed*0.8 + 2, y-= yspeed*0.2, 2);
        tft.drawString(String(wordList[5]), x+=xspeed*0.4 + 8, y-= yspeed, 2);

        delay(100);

        tft.fillScreen(TFT_BLACK);
        tft.drawString(String("Ecology is homeostasis."), 0, 0);

        
      }
      
    
  }

  

  delay(10);
  
}

  
