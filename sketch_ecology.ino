
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

char vow[5] = {'a', 'e', 'i', 'o', 'u'};
char con[22] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 
  'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
char con2[13] = {'b', 'd', 'g', 'k', 'l', 'm', 'n', 'p', 'r', 't', 'w', 'y'};

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

  
  for (int h = y; h < 120; h+=5)
  {

    //falling
    y = h;

    //switching letters
    int count = h % 5 + 1;
    String body;
    for (; count > 0; count--)
    {
      body += String(vow[ random(0,5) ]);
    }

    tft.drawString(head+body+tail, x, y, 2);
    delay(100);

    tft.fillScreen(TFT_BLACK);
  }

  

  delay(10);
  
}

  
