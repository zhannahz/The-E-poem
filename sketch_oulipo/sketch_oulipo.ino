
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

char headCombo[10] = "creative"; //8
char bodyCombo[10] = "embedded"; //8
char tailCombo[10] = "system"; //6

char headCon[10] = {'c', 'r', 't', 'v'}; //4
char headVow[10] = {'e', 'a', 'i', 'e'}; //4

int indexs[] = {0, 1, 2, 3, 4, 5, 6, 7};


char vow[5] = {'a', 'e', 'i', 'o', 'u'}; //4
char con[22] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 
  'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'}; //20

//char legit5[20] = {"messy", "stems", "styes"};
//char legit4[20] = {"mess", "sets", "stem", "stey", "stye", "tyes"};


void setup(void) {
  randomSeed(analogRead(0) * analogRead(1));

  tft.init();
  tft.setRotation(1);

}

void loop() {
  tft.resetViewport();

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

  
  // Draw some randomly generated words
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
    
//      tft.drawString(String(headCon[random(4)]) + 
//                  String(headVow[random(4)]) + 
//                  String(headCon[random(4 - random(2))]), x, y, 2);
//      }

    if (i == 1){
      tft.drawString(body, x, y, 2);
    }

    if (i == 2){
      tft.drawString(tail, x, y, 2);
    }
    
  }

  delay(3000); //break

  tft.fillScreen(TFT_BLACK);

  }
