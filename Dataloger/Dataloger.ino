
/*Sistemas de Computadoras - Dataloger usando Arduino*/

#include <DHT.h>
#include <LiquidCrystal.h>

/*Definiciones del sensor*/
#define DHTPIN 8 //pin donde se conecta el sensor DHT22
#define DHTTYPE DHT22 //define el senso conectado, DHT22
DHT dht(DHTPIN, DHTTYPE);

/*Definiciones del LCD*/
/* The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3) */
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  
  //Inicializar perifericos
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2); //Como parametro la LCD que recibe.
 
  lcd.print("DHT22 test!");
  delay(500);
  lcd.clear();
}

void loop() {
  
  delay(2000); //Espera para que el sensor este nueva vez para la lectura

  float h = dht.readHumidity(); //Obtener la humedad relativa
  float t = dht.readTemperature(); //Obtener la temperatura en Celsius

  //Revisa si el sensor esta respondiendo
  if (isnan(h) || isnan(t))
  {
    lcd.clear();
    lcd.print("Sensor Error!");
    delay(1000);
    lcd.clear();
    lcd.print("Revisar conexion");
    delay(1000);
    return;
  }

  lcd.clear();
  lcd.print("Hum: "); 
  lcd.print(h);
  lcd.print("%HR");
  lcd.setCursor(0, 2);
  lcd.print("Temp: "); 
  lcd.print(t);
  lcd.write(0xDF);
  lcd.print("C");
}
