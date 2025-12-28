#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(21, 22);
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if(temperatura<=29){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura baja encendiendo resistencia . . . ");
    delay(2000);
  }else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura normal . . . ");
    delay(2000);
  }
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura);

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humedad);

  delay(2000);

}