
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

char vow[5] = {'a', 'e', 'i', 'o', 'u'};
char con[22] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 
  'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
char con2[13] = {'b', 'd', 'g', 'k', 'l', 'm', 'n', 'p', 'r', 't', 'w', 'y'};

char headCombo[10] = "creative"; //8
char bodyCombo[10] = "embedded"; //8
char tailCombo[10] = "system"; //6

char headCon[10] = {'c', 'r', 't', 'v'}; //4
char headVow[10] = {'e', 'a', 'i', 'e'}; //4

int indexs[] = {0, 1, 2, 3, 4, 5, 6, 7};
  

void setup() {

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);


}

void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(random(0xFFFF));
  
  /* chapter: engine 
   *  reproduction, replication
  */
  tft.drawString(String("ENGINE AS SCALING."), 0, 0);
  
  delay(6000); //break
  tft.fillScreen(TFT_BLACK);

  /* chapter: economy 
  * exchange, swapping
  
  */
  tft.drawString(String("ECONOMY AS EXCHANGING."), 0, 0);
  delay(6000); //break


  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2.8);

  //shuffle tailCombo
  for (int i = 0; i < 6; i++) 
  {
    int index = random(6);
    char temp = tailCombo[i];   
    tailCombo[i] = tailCombo[index];
    tailCombo[index] = temp;
  }

  //shuffle index
  for (int i = 0; i < 8; i++) 
  {
    int p = random(8);
    int temp = indexs[i];   
    indexs[i] = indexs[p];
    indexs[p] = temp;
  }

  // randomly generated words
  for (int i = 0; i < 3; i++)
  {
    int rx = random(40);
    int ry = random(40);
    int x = random(160 - rx - rx);
    int y = 18 + 36*i;
    tft.setTextColor(random(0xFFFF));

    String head;
    for (int h=0; h < 8; h++){            
        head += headCombo[indexs[h]];
      }

    String body;
    for (int h=0; h < 8; h++){            
        body += bodyCombo[indexs[h]];
      }
          
    String tail;
    for (int t=0; t<6; t++){
      tail += tailCombo[t];
      }

    if (i == 0){
      tft.drawString(head, x, y, 2);
    }

    if (i == 1){
      tft.drawString(body, x, y, 2);
    }

    if (i == 2){
      tft.drawString(tail, x, y, 2);
    }
    
  }
  delay(6000); //break
  tft.fillScreen(TFT_BLACK);


  /* chapter: ecology */
  
  tft.drawString(String("ECOLOGY AS BALANCING."), 0, 0);
  delay(6000); //break

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
