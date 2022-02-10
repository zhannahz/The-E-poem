
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

int16_t h = 128;
int16_t w = 160;

int xspeed = 20;
int yspeed = 15;

uint16_t x = w/2;
uint16_t y = h/2;

char vow[5] = {'a', 'e', 'i', 'o', 'u'};
char con[22] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 
  'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
char con2[13] = {'b', 'd', 'g', 'k', 'l', 'm', 'n', 'p', 'r', 't', 'w', 'y'};

char headCombo[10] = "creative"; //8
char bodyCombo[10] = "embedded"; //8
char tailCombo[10] = "system"; //6

char wordOrigin[] = ("create");
String wordList6[200] = {"create", "cetera", "cerate", "ecarte"}; //4
String wordList5[200] = {"arete", "caret", "carte", "cater", "crate", 
                  "eater", "erect", "erect", "react", "recta", "terce", "trace"}; //12
String wordList4[200] = {"acer", "acre", "arte", "care", "cart", "cate", "cere"}; //7
char headCon[10] = {'c', 'r', 't', 'v'}; //4
char headVow[10] = {'e', 'a', 'i', 'e'}; //4

int indexs[] = {0, 1, 2, 3, 4, 5, 6, 7};
  

void setup() {
  randomSeed(analogRead(0) * analogRead(1));
  Serial.begin(115200);

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);


}

void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(random(0xFFFF));

  tft.drawString(String("H. Z. presents"), 0, 60, 1);
  delay(2000); 
  tft.fillScreen(TFT_BLACK);
  
  /* chapter: engine 
   *  reproduction, replication
  */

  tft.drawString(String("ENGINE as"), 0, 0);
  tft.drawString(String("SCALING <1>"), 0, 32);

  delay(3000); 
  tft.fillScreen(TFT_BLACK);

  int countChp0 = 0;
  while (countChp0 < 150){

      int rx = random(20);
      int ry = random(10);
      int x = rx + random(160);
      int y = ry + random(128);
      
      tft.setTextColor(random(0xFFFF));
      tft.drawString(String(con[random(20)]), x, y, 1);
      tft.drawString(String(vow[random(5)]), x, y, 2);

      
      delay(120);
      countChp0++;
    
  }
  
  tft.fillScreen(TFT_BLACK);
  
  x = 64;
  y = 80;
  
  delay(3000); //break


  

  /* chapter: economy 
  * exchange, swapping
  
  */
  tft.drawString(String("ECONOMY as"), 0, 0);
  tft.drawString(String("EXCHANGE <2>"), 0, 32);
  delay(6000); 


  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2.8);


  // randomly generated words
  int countChp = 0;
  while (countChp < 80) {
    
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
        countChp++;
      }
  
      if (i == 1){
        tft.drawString(body, x, y, 2);
        countChp++;
      }
  
      if (i == 2){
        tft.drawString(tail, x, y, 2);
        
      }
    }
    countChp+=5;
    delay(1000); 
    tft.fillScreen(TFT_BLACK);
    
  }
  delay(3000); //break
  tft.fillScreen(TFT_BLACK);


  /* chapter: ecology */
  
  tft.drawString(String("ECOLOGY as"), 0, 0);
  tft.drawString(String("CONSERVATION <3>"), 0, 32);
  delay(3000); //break

  tft.fillScreen(TFT_BLACK);

  tft.setTextSize(3);
  tft.setTextColor(random(0xFFFF));

  tft.fillScreen(TFT_BLACK);
  
  int count = 0;
  
  while (count < 155){
    y -= yspeed;
    x += xspeed;
                    
    if (x < 10 || x > w - 30){
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

  delay(3000); //break

}

//stack() and plotbox() function for engine
/* too many bugs…give up for now
void stack()
{
  tft.resetViewport();

  uint16_t w = 40;
  uint16_t h = 40;
  uint16_t x = random(tft.width()  - w);
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
  String any = String(bodyCombo[random(0,8)]);
  tft.drawString(any, 20, 20, 1);  
}
*/
