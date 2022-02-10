
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

char vow[5] = {'a', 'e', 'i', 'o', 'u'};
char con[22] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 
  'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
char con2[13] = {'b', 'd', 'g', 'k', 'l', 'm', 'n', 'p', 'r', 't', 'w', 'y'};
  

void setup() {
  // put your setup code here, to run once:

  tft.init();
  tft.setRotation(1);

}

void loop() {
  tft.fillScreen(TFT_BLACK);

  // engine
  tft.setTextSize(2);
  tft.setTextColor(random(0xFFFF));
  tft.drawString(String("Ecology is homeostasis."), 0, tft.width()/2);
  
  while(){
    stack();
  }
  delay(3000); //break

  // economy

}

//stack() and plotbox() function for engine
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
