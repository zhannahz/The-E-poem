
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

char vow[5] = {'a', 'e', 'i', 'o', 'u'};
char con[22] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 
  'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
char con2[13] = {'b', 'd', 'g', 'k', 'l', 'm', 'n', 'p', 'r', 't', 'w', 'y'};
  

void setup() {

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);


}

void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(random(0xFFFF));
  
  // chapter: engine
  tft.drawString(String("ENGINE AS SCALING."), 0, 0);
  
  delay(6000); //break
  tft.fillScreen(TFT_BLACK);

  int count = 300;
  while (count > 0){
    stack();
    count--;
  }
  tft.resetViewport();

  tft.fillScreen(TFT_BLACK);

  // chapter: economy
  tft.drawString(String("ECONOMY AS EXCHANGING."), 0, 0);
  

  
  delay(6000); //break
  tft.fillScreen(TFT_BLACK);


  // chapter: ecology
  
  tft.drawString(String("ECOLOGY AS BALANCING."), 0, 0);
  tft.fillScreen(TFT_BLACK);

  delay(3000); //break


}

//stack() and plotbox() function for engine
void stack()
{
  tft.resetViewport();
  
  uint16_t w = 40;
  uint16_t h = 40;
  uint16_t x = random(tft.width() - w);
  uint16_t y = random(tft.height() - h);

  tft.setViewport(x, y, w, h);

  plotBox();

  delay(10);

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
  String any = String(con[random(0,21)]);
  tft.drawString(any, 20, 20, 1);  
}
