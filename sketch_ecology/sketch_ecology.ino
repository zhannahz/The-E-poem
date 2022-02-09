
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

char vow[5] = {'a', 'e', 'i', 'o', 'u'};
char con[22] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 
  'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
char con2[13] = {'b', 'd', 'g', 'k', 'l', 'm', 'n', 'p', 'r', 't', 'w', 'y'};

int xspeed = 10;
int yspeed = 2;

void setup(void) {
  
  tft.init();
  tft.setRotation(1);

}

void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2.9);

  // Draw some randomly generated C-V words
  int i = random(0,6);

  int rx = random(40);
  int ry = random(40);
  int x = rx + random(160 - rx - rx);
  int y = 24*i;
  tft.setTextColor(random(0xFFFF));

  //fixed head and tail
  String head = String(con[ random(0,21) ]);
    head.toUpperCase();
  String tail = String(con2[ random(0,12) ]);
  String body = String(vow[ random(0,5) ]);

  
  for (int h = y; h < 120; h+=8)
  {

    //falling
    y = h;
    tft.drawString(head+body+tail, x, y, 2);
    delay(60);
    tft.fillScreen(TFT_BLACK);

    
    }

    //if hit the bottom, bounce off
    if (y = 110) {
      int x1 = x - 30;
      int x2 = x;
      int x3 = x + 30;
      
      tft.fillScreen(TFT_BLACK);
      for (; y > 0; y -= 1){
        
        if ((x == 20 || x == 100) && (x == 160 || x == 20)){
          xspeed *=(-1);
          yspeed *=(-1);
        }
          
        y -= yspeed;
        x1 += xspeed*0.5;
        x2 += xspeed*0.7;
        x3 += xspeed*(-0.5);
        tft.drawString(head, x1, y, 2);
        tft.drawString(body, x2, y, 2);
        tft.drawString(tail, x3, y, 2);
        delay(20);

        tft.fillScreen(TFT_BLACK);

        
      }
    
  }

  

  delay(10);
  
}

  
