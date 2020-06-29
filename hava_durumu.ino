#include <LiquidCrystal.h>
#include "DHT.h"
#include "Wire.h"
#include "Adafruit_BMP085.h" //Basınç Sensörü Kütüphanesi

#define DHTPIN 2
#define DHTTYPE DHT11
 
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 basincsensoru;


byte santigratderece[8] = {
  0b11000,
  0b11000,
  0b00110,
  0b01001,
  0b01000,
  0b01000,
  0b01001,
  0b00110
};

void setup() {
  
  lcd.begin(16, 2);
  basincsensoru.begin();
  dht.begin();
  Serial.begin(9600);

  lcd.createChar(0,santigratderece);
 

}

void loop() {
 
  
  float h = dht.readHumidity();
  float t1 = dht.readTemperature();
  float t2 = basincsensoru.readTemperature();
  float basinc = basincsensoru.readPressure();
  float t_ort = (t1+t2)/2;
  float hic = dht.computeHeatIndex(t_ort, h, false);
  
  if (isnan(h) || isnan(t_ort) ) {
    Serial.println(F("Sensorde Hata Okundu!"));
    return;
    }

    int menu_kontrol=analogRead(A0);

    
    if((menu_kontrol>=0)&&(menu_kontrol<=214)){
lcd.setCursor(0,0);
nem_yaz(h);


}


    else if((menu_kontrol>=270)&&(menu_kontrol<=484)){
lcd.setCursor(0,0);
sicaklik_yaz(t_ort);

}


    else if((menu_kontrol>=538)&& (menu_kontrol<=752)){
lcd.setCursor(0,0);
basinc_yaz(basinc);

}


    else if((menu_kontrol>=807)&& (menu_kontrol<=1023)){
lcd.setCursor(0,0);
hissedilen(hic);

}

else{
bos();
}


Serial.print(h);
Serial.print(" ");
Serial.print(t_ort);
Serial.print(" ");
Serial.print(basinc/1000);
Serial.print(" ");
Serial.println(hic);




}

void nem_yaz(float a){
  
lcd.print("       NEM");
lcd.setCursor(5,1);
lcd.print(a);
lcd.print("% ");  

  }
void sicaklik_yaz(float t_ort){
lcd.print("    SICAKLIK");
lcd.setCursor(5,1);
lcd.print(t_ort);
lcd.write(byte(0));  
  }
void basinc_yaz(float basinc){
lcd.print("     BASINC");
lcd.setCursor(3,1);
lcd.print(basinc);
lcd.print("Pa ");
  }
void hissedilen(float hic){
lcd.print("   HISSEDILEN");
lcd.setCursor(5,1);
lcd.print(hic);
lcd.write(byte(0));
  }
  void bos(){
lcd.setCursor(0,0);   
lcd.clear();

  }
