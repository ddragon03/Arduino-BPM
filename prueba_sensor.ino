#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>

#define CS 53           // El pin donde se conecta la CS del display
#define CD 9             // El pin donde se conecta la CD del display
#define SDA 51           // El pin donde se conecta la SDA del display
#define MOSI SDA         // El pin donde se conecta la MOSI SDA del display
#define SCK 52           // El pin donde se conecta la SCK del display
#define RST 8            // El pin donde se conecta la RST del display
#define LED -1           // Si no necesitamos manejar el LED ( encender o apagar el display) entonces lo conectamos a la VCC  ( 3.3 o 5 V )

Adafruit_ST7735 tft = Adafruit_ST7735( CS, CD, RST );

float factor =  0.75;   // coeficiente para filtro pasa bajos
float maximo = 0.0;   // para almacenar valor maximo 
int minimoEntreLatidos = 300; // 300 mseg. de tiempo minimo entre latidos
float valorAnterior = 500;  // para almacenar valor previo
int latidos = 0;    // contador de cantidad de latidos

void setup() {
  {pinMode(13, OUTPUT);    // LED incorporado en pin 13 como salida
  Serial.begin(9600);   // inicializacion de monitor serie a 9600 bps
  Serial.println("Iniciando mediciones");}
  {  tft.initR(INITR_BLACKTAB);
  tft.setSPISpeed(40000000);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  tft.setTextSize(2,2);
  tft.setRotation(3);// texto a mostrar
  tft.setCursor(0,0);
  tft.print("Espere sus   mediciones                ");}
  tft.setTextSize(2,2);
  tft.println("BPM: ");
}

void loop() { 
  static unsigned long tiempoLPM = millis();  
  static unsigned long entreLatidos = millis(); 

  int valorLeido = analogRead(A0);    

  float valorFiltrado = factor * valorAnterior + (1 - factor) * valorLeido; 
  float cambio = valorFiltrado - valorAnterior;   
  valorAnterior = valorFiltrado;    

  if ((cambio >= maximo) && (millis() > entreLatidos + minimoEntreLatidos)) { 
    maximo = cambio;      
    digitalWrite(13, HIGH);   
    entreLatidos = millis();    
    latidos++;        
  }
  else {        
    digitalWrite(13, LOW);    
  }
  
  maximo = maximo * 0.97;   

  if (millis() >= tiempoLPM + 15000) {    
    Serial.print("Latidos por minuto: "); 
    Serial.println(latidos * 4);    
    latidos = 0;        
    tiempoLPM = millis();     
  }

  delay(50);        

  if (millis() >= tiempoLPM + 15000){
    // Limpiar el área donde se muestra la pulsación anterior
    tft.fillRect(50, 70, 55, 45, ST7735_BLACK);
    
    // Imprimir la nueva pulsación medida
    tft.setCursor(60, 80);  
    tft.setTextSize(3,3);  
    tft.setTextColor(ST7735_GREEN);
    tft.println(latidos * 4);
  }
}
