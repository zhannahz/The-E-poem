
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
  tft.resetViewport();

  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2.9);
  
  tft.drawString(String("Economy is exchange."), 0, 0);


  // Draw some randomly generated C-V words
  for (int i = 0; i < 3; i++)
  {
    int rx = random(40);
    int ry = random(40);
    int x = rx + random(160 - rx - rx);
    int y = 32+32*i;
    tft.setTextColor(random(0xFFFF));

    
    String head = String(con[i]);
    head.toUpperCase();

    String tail = String(con2[i]);

    String body;
    for (int j = 0; j < i+1; j++){
      body += String( vow[ random(0,5) ] );
    }
    
    tft.drawString(head + body + tail, x, y, 2);
  }


  delay(3000); //break

  tft.fillScreen(TFT_BLACK);

  //stack();

  //tft.fillScreen(TFT_BLACK);
  

}

void stack(void)
{
  for (int i = 0; i < 500; i++)
  {
    tft.resetViewport(); 

    uint16_t w = 40;
    uint16_t h = 40;
    uint16_t x = random(tft.width());
    uint16_t y = random(tft.height());

    tft.setViewport(x, y, w, h);

    plotBox();

    delay(10);
  }
}

void plotBox(void)
{ 
  // These are always plotted at a fixed position but they can 
  // be plotted into a viewport anywhere on the screen because
  // a viewport can move the screen datum
  tft.fillScreen(TFT_BLACK); // When a viewport is set, this just fills the viewport
  tft.drawRect(0,0, 40,40, TFT_WHITE);
  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_WHITE);
  String any = String(con[random(0,8)]);
  tft.drawString(any, 20, 20, 1);  
}
