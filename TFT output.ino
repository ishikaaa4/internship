#include"LIS3DHTR.h"
LIS3DHTR<TwoWire> lis;
#include"TFT_eSPI.h"
TFT_eSPI tft;
#include"Free_Fonts.h" //include the header file


void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setTextColor(TFT_RED);
  tft.fillScreen(TFT_WHITE);
  tft.setFreeFont(&FreeSansBoldOblique12pt7b);
  lis.begin(Wire1);
 
  if (!lis) {
    Serial.println("ERROR");
    while(1);
  }
  lis.setOutputDataRate(LIS3DHTR_DATARATE_25HZ); //Data output rate
  lis.setFullScaleRange(LIS3DHTR_RANGE_2G); //Scale range set to 2g
}
 
void loop() {
  float x_values, y_values, z_values;
  x_values = lis.getAccelerationX();
  y_values = lis.getAccelerationY();
  z_values =lis.getAccelerationZ();
  Serial.print("X: "); Serial.print(x_values);
  Serial.print(" Y: "); Serial.print(y_values);
  Serial.print(" Z: "); Serial.print(z_values);
  Serial.println();

  tft.drawString(" X: ",10,20); 
  tft.drawString(" Y: ",10,60);
  tft.drawString(" Z: ",10,100);  
  tft.drawFloat(x_values,0,40,20);
  tft.drawFloat(y_values,0,40,60); 
  tft.drawFloat(z_values,0,40,100);
  tft.fillScreen(TFT_WHITE);
  delay(750);
}
