#include <SoftwareSerial.h>
#include "LEDControl.h"
#include "Patrones.h"


SoftwareSerial BT(10, 11); // 10 RX, 11 TX.

byte Led_1 = 14;
byte Led_2 = 15;
byte Led_3 = 16;
byte Led_4 = 17;

LEDControl led1(14);
LEDControl led2(15);
LEDControl led3(16);
LEDControl led4(17);

char DataBluetooth = ' ';
float valor = 100;
float brillo = valor * 2.55;
float frecuencia = 0;
int frecuencia_cast = 0;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("");
  Serial.println("Iniciando Control ...");

    led1.begin();
    led2.begin();
    led3.begin();
    led4.begin();

    led1.on();
    led2.on();
    led3.on();
    led4.on();

  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Led_3, OUTPUT);
  pinMode(Led_4, OUTPUT);
}

void loop() {
  
  if (BT.available()) {
    DataBluetooth = BT.read();
    Serial.print(DataBluetooth);

    if(DataBluetooth == 'A0'){

      frecuencia = 18;
      frecuencia_cast = static_cast<int>(frecuencia);

      valor = 50;
      brillo = valor * 2.55;

      for (int x = 0; x < 900; x++){

        if (BT.available()) {

            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'A0') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'A0'){
              break;
            }

            }
        }

        //Ajustamos la frecuencia
        if(x < 300){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 300, 11);
        }
        if(x > 720){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 33);
        }

        //Ajustamos el brillo
        if(x < 180){
          ajustarBrillo(true, valor, brillo, 180, 50);
        }
        else if(x < 300){
          ajustarBrillo(false, valor, brillo, 120, 20);
        }
        else if (x < 720){
          ajustarBrillo(false, valor, brillo, 420, 30);
        }
        else if (x < 840){
          ajustarBrillo(true, valor, brillo, 120, 50);
        }
        else if (x > 900){
          ajustarBrillo(false, valor, brillo, 60, 100);
        }

        //Patron
        patron1(frecuencia_cast, brillo, x, 900);
      }
    }

    if(DataBluetooth == 'A1'){

      frecuencia = 18;
      frecuencia_cast = static_cast<int>(frecuencia);

      valor = 50;
      brillo = valor * 2.55;

      for (int x = 0; x < 1320; x++){

        if (BT.available()) {

            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'A1') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

              if(DataBluetooth != 'A1'){
                break;
              }

            }
        }

        if (x < 240){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 240, 6);
        }
        else if(x < 420){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 7);
        }
        else if(x > 1200){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 120, 15);
        }

        if(x < 120){
          ajustarBrillo(true, valor, brillo, 120, 50);
        }
        else if(x < 420){
          ajustarBrillo(false, valor, brillo, 300, 60);
        }
        else if(x > 1200 && x < 1320){
          ajustarBrillo(true, valor, brillo, 120, 40);
        }
        else if(x>1320){
          ajustarBrillo(true, valor, brillo, 60, 100);
        }

        if(x < 60){
          patron2(frecuencia_cast, brillo, x, 60);
        }
        else if(x < 120){
          patron1(frecuencia_cast, brillo, x, 60);
        }
        else if(x < 180){
          patron6(frecuencia_cast, brillo, x, 60);
        }
        else if(x < 240){
          patron5(frecuencia_cast, brillo, x, 60);
        }
        else if(x < 300){
          patron2(frecuencia_cast, brillo, x, 60);
        }
        else{
          patron1(frecuencia_cast, brillo, x, 1020);
        }

      }

    }

    if(DataBluetooth == 'A2'){

      frecuencia = 8;
      frecuencia_cast = static_cast<int>(frecuencia);

      valor = 100;
      brillo = valor * 2.55;

      for(int x = 0; x < 1800; x++){

         if (BT.available()) {

            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'A2') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

              if(DataBluetooth != 'A2'){
                break;
              }

            }
        }

        if(x < 180){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 22);
        }
        else if(x < 360){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 23);
        }
        else if(x < 540){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 13);
        }
        else if(x < 720){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 16);
        }
        else if(x < 900){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 14);
        }
        else if(x < 1080){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 12);
        }
        else if(x < 1260){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 18);
        }
        else if(x < 1440){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 14);
        }
        else if(x < 1620){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 12);
        }
        else{
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 16);
        }

        if(x < 180){
          ajustarBrillo(false, valor, brillo, 180, 75);
        }
        else if(x > 1620){
          ajustarBrillo(true, valor, brillo, 180, 100);
        }

       if(x < 180){
          patron2(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 360){
          patron5(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 540){
          patron4(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 720){
          patron2(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 900){
          patron5(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 1080){
          patron4(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 1260){
          patron2(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 1440){
          patron5(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 1620){
          patron4(frecuencia_cast, brillo, x, 180);
        }
        else{
          patron2(frecuencia_cast, brillo, x, 180);
        }

      }

    }

    if(DataBluetooth == 'A3'){
      
      frecuencia = 18;
      frecuencia_cast = static_cast<int>(frecuencia);

      valor = 100;
      brillo = valor * 2.55;

      for(int x = 0; x < 1800; x++){

        if (BT.available()) {

            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'A3') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

              if(DataBluetooth != 'A3'){
                break;
              }

            }
        }

        if(x < 180){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 4);
          patron2(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 360){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 4);
          patron1(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 540){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 12);
          patron5(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 720){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 10);
          patron1(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 900){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 16);
          patron4(frecuencia_cast, brillo, x, 180);
        }
        else if (x < 1080){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 18);
          patron1(frecuencia_cast, brillo, x, 180);
        }
        else if (x < 1260){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 16);
          patron7(frecuencia_cast, brillo, x, 180);
        }
        else if(x < 1440){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 16);
          patron1(frecuencia_cast, brillo, x, 180);
        }
        else if (x < 1620){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 18);
          patron6(frecuencia_cast, brillo, x, 180);
        }
        else if (x < 1740){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 16);
          patron1(frecuencia_cast, brillo, x, 180);
        }
        else{
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 16);
          patron2(frecuencia_cast, brillo, x, 180);
        }

      }

    }

    if(DataBluetooth == 'A4'){

      frecuencia = 20;
      frecuencia_cast = static_cast<int>(frecuencia);

      valor = 80;
      brillo = valor * 2.55;

      for(int x = 0; x < 1500; x++){

        if (BT.available()) {

            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'A4') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

              if(DataBluetooth != 'A4'){
                break;
              }

            }
        }

        if(x < 60){
          ajustarBrillo(true, valor, brillo, 60, 20);
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 60, 8);
        }
        else if(x < 120){
          ajustarBrillo(false, valor, brillo, 60, 20);
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 60, 6);
        }
        else if(x < 240){
          ajustarBrillo(true, valor, brillo, 120, 20);
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 120, 6);
        }
        else if (x < 360){
          ajustarBrillo(false, valor, brillo, 120, 20);
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 120, 8);
        }
        else if (x < 540){
          ajustarBrillo(true, valor, brillo, 180, 20);
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 8);
        }
        else if (x < 720){
          ajustarBrillo(false, valor, brillo, 180, 20);
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 8);
        }
        else if (x < 900){
          ajustarBrillo(true, valor, brillo, 180, 20);
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 8);
        }
        else if (x < 1080){
          ajustarBrillo(false, valor, brillo, 180, 20);
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 8);
        }
        else if (x < 1260){
          ajustarBrillo(true, valor, brillo, 180, 20);
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 180, 8);
        }
        else {
          ajustarBrillo(false, valor, brillo, 180, 25);
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 180, 8);
        }

        if (x < 300){
          patron1(frecuencia_cast, brillo, x, 300);
        }
        else if (x < 480){
          patron2(frecuencia_cast, brillo, x, 180);
        }
        else if (x < 600){
          patron6(frecuencia_cast, brillo, x, 120);
        }
        else if (x < 900){
          patron4(frecuencia_cast, brillo, x, 300);
        }
        else if (x < 1080){
          patron1(frecuencia_cast, brillo, x, 180);
        }
        else if (x < 1200){
          patron2(frecuencia_cast, brillo, x, 120);
        }
        else if (x < 1320){
          patron6(frecuencia_cast, brillo, x, 120);
        }
        else if(x < 1440){
          patron4(frecuencia_cast, brillo, x, 120);
        }
        else{
          patron1(frecuencia_cast, brillo, x, 60);
        }

      }

    }

    int pauseA = 0;
    int x1 = 0;

    if(DataBluetooth == 'A'){
      BT.println("A");
      Serial.println("");

      frecuencia = 12;
      frecuencia_cast = static_cast<int> (frecuencia);

      valor  =  100;
      brillo = valor * 2.55;

      for (int m = pauseA; m < 1800; m++){

        pauseA++;
        //Para pausar o cambiar de cancion
        if (BT.available()) {

            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'A') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'A'){
              break;
            }

            }
        }

        int mMod = m%600;
        if(mMod < 300){
          //Ajustamos brillo
          valor -= 25/300;
          brillo = valor *2.55;
          //Ajustamos frecuencia
          frecuencia -= 7/300;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(mMod>300 && mMod<=600){
          //Ajustamos brillo
          valor += 25/300;
          brillo = valor *2.55;
          //Ajustamos frecuencia
          frecuencia += 7/300;
          frecuencia_cast = static_cast<int> (frecuencia);
        }

        if(m>800 && m<=1000){//Izq. apagado Der. Prendido
        
          for(int z = 0; z < frecuencia_cast; z++){
                if(z%2 == 0){
                  digitalWrite(Led_1, LOW);
                  digitalWrite(Led_2, LOW);
                  analogWrite(Led_3, brillo);
                  analogWrite(Led_4, brillo);
                  delay(1000/frecuencia_cast);
                }
                else{
                  digitalWrite(Led_1, LOW);
                  digitalWrite(Led_2, LOW);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
          }

        }
        else if(m>1200 && m<=1400){//Izq. prendido Der. apagado

          for(int z = 0; z < frecuencia_cast; z++){
                if(z%2 == 0){
                  analogWrite(Led_1, brillo);
                  analogWrite(Led_2, brillo);
                  digitalWrite(Led_3, LOW);
                  digitalWrite(Led_4, LOW);
                  delay(1000/frecuencia_cast);
                }
                else{
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  digitalWrite(Led_3, LOW);
                  digitalWrite(Led_4, LOW);
                  delay(1000/frecuencia_cast);
                }
            }

        }
        else{//Todo prendido
          for(int z = 0; z < frecuencia_cast; z++){
                if(z%2 == 0){
                  analogWrite(Led_1, brillo);
                  analogWrite(Led_2, brillo);
                  analogWrite(Led_3, brillo);
                  analogWrite(Led_4, brillo);
                  delay(1000/frecuencia_cast);
                }
                else{
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
            }
        }
      }
      if(pauseA >= 1800){
        pauseA = 0;
      }

      BT.println("A");
      Serial.println("");
    }

    int pauseB = 0;
    int x2 = 0;


    if(DataBluetooth == 'B'){
      frecuencia  = 15;
      valor = 100;
      brillo = valor * 2.55;

      BT.println("B");
      Serial.println("");
      for(int x = pauseB; x < 2700; x++){

        if (BT.available()) {

            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'B') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'B'){
              break;
            }

            }
        }

          if(x < 2400){
            valor -= 0.03333;
            brillo = valor*2.55;
          }
          else{
            valor -= 0.06666;
            brillo = valor*2.55;
          }

          if(x < 600){
            frecuencia -= 0.00833;
            frecuencia_cast = static_cast<int> (frecuencia);
          }
          else if(x>600 && x<=900){
          }
          else if(x>900 && x<=1080){
            frecuencia -= 0.01666;
            frecuencia_cast = static_cast<int> (frecuencia);
          }
          else if(x>1080 && x<=1500){
          }
          else if(x>1500 && x<=1680){
            frecuencia -= 0.01666;
            frecuencia_cast = static_cast<int> (frecuencia);
          }
          else if(x>1680 && x<=2100){
          }
          else if(x>2100 && x<= 2280){
            frecuencia -= 0.01666;
            frecuencia_cast = static_cast<int> (frecuencia);
          }

          x2 = x%180;

          if (x2 < 60){
            for(int z = 0; z < frecuencia_cast; z++){
                  digitalWrite(Led_1, LOW);
                  digitalWrite(Led_2, LOW);
                  digitalWrite(Led_3, LOW);
                  digitalWrite(Led_4, LOW);
                  delay(1000/frecuencia_cast);
            }
          }
          else if (x2>60 && x2<=120){
            for(int z = 0; z < frecuencia_cast; z++){
                if(z%2 == 0){
                  analogWrite(Led_1, brillo);
                  analogWrite(Led_2, brillo);
                  analogWrite(Led_3, brillo);
                  analogWrite(Led_4, brillo);
                  delay(1000/frecuencia_cast);
                }
                else{
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
            }
          }
          else if (x2>120 && x2<=180){
            for(int z = 0; z < frecuencia_cast; z++){
                  digitalWrite(Led_1, LOW);
                  digitalWrite(Led_2, LOW);
                  digitalWrite(Led_3, LOW);
                  digitalWrite(Led_4, LOW);
                  delay(1000/frecuencia_cast);
            }
          }


          

          pauseB++;
      }
      if(pauseB >= 2700){
        pauseB = 0;
      }
      BT.println("B");
      Serial.println("");
    }

    int pauseC = 0;
    int x3 = 0;

    if(DataBluetooth == 'C'){
      
      frecuencia  = 18;
      valor = 100;
      brillo = valor * 2.55;

      BT.println("C");
      Serial.println("");

      for(int y = pauseC; y < 2400; y++){

        if (BT.available()) {

            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'C') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'C'){
              break;
            }

            }
        }

        //Definir brillo
        if(y < 300){
          valor -= 0.0666;
          brillo = valor * 2.55;
        }
        else if(y>2100){
          valor += 0.0666;
          brillo = valor * 2.55;
        }

        //Definir frecuencia de encendido
        if(y < 420){
          frecuencia -= 0.026190;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(y>420 && y<=2280){
          frecuencia = 7.8;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(y>2280){
          frecuencia += 0.08333;
          frecuencia_cast = static_cast<int> (frecuencia);
        }

        //Patron 1
        if(y<360 || (y>840 && y<=1200) || (y>1800 && y<=2040)){
          int xmod = y%80;
          if(xmod<40){//Ambos apagados

            for(int z = 0; z < frecuencia_cast; z++){
                  digitalWrite(Led_1, LOW);
                  digitalWrite(Led_2, LOW);
                  digitalWrite(Led_3, LOW);
                  digitalWrite(Led_4, LOW);
                  delay(1000/frecuencia_cast);
            }

          }
          if(xmod>40 && xmod<=80){//Ambos prendidos

            for(int z = 0; z < frecuencia_cast; z++){
                if(z%2 == 0){
                  analogWrite(Led_1, brillo);
                  analogWrite(Led_2, brillo);
                  analogWrite(Led_3, brillo);
                  analogWrite(Led_4, brillo);
                  delay(1000/frecuencia_cast);
                }
                else{
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
            }

          }
        }
        //Patron 2
        if((y>360 && y<=840) || (y>2040 && y<=2400)){
          int xmod = y%240;
          if(xmod<60){//Izq. prendido Der. Apagado
            
            for(int z = 0; z < frecuencia_cast; z++){
                if(z%2 == 0){
                  analogWrite(Led_1, brillo);
                  analogWrite(Led_2, brillo);
                  digitalWrite(Led_3, LOW);
                  digitalWrite(Led_4, LOW);
                  delay(1000/frecuencia_cast);
                }
                else{
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  digitalWrite(Led_3, LOW);
                  digitalWrite(Led_4, LOW);
                  delay(1000/frecuencia_cast);
                }
            }

          }
          if((xmod>60 && xmod<=120) || (xmod>180 && xmod<=240)){//Ambos prendidos

            for(int z = 0; z < frecuencia_cast; z++){
                if(z%2 == 0){
                  analogWrite(Led_1, brillo);
                  analogWrite(Led_2, brillo);
                  analogWrite(Led_3, brillo);
                  analogWrite(Led_4, brillo);
                  delay(1000/frecuencia_cast);
                }
                else{
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
            }

          }
          if(xmod>120&&xmod<=180){//Der. prendido Izq. Apagado

            for(int z = 0; z < frecuencia_cast; z++){
                if(z%2 == 0){
                  digitalWrite(Led_1, LOW);
                  digitalWrite(Led_2, LOW);
                  analogWrite(Led_3, brillo);
                  analogWrite(Led_4, brillo);
                  delay(1000/frecuencia_cast);
                }
                else{
                  digitalWrite(Led_1, LOW);
                  digitalWrite(Led_2, LOW);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
            }

          }

        }

        if(y>1200 && y<=1800){//Patron 0, todo se apaga
          for(int z = 0; z < frecuencia_cast; z++){
                digitalWrite(Led_1, LOW);
                digitalWrite(Led_2, LOW);
                digitalWrite(Led_3, LOW);
                digitalWrite(Led_4, LOW);
                delay(1000/frecuencia_cast);
            }
        }

        pauseC++;
      }
      if(pauseC >= 2400){
        pauseC = 0;
      }
      BT.println("d");
      Serial.println("");
    }

    pauseA = 0;
    x1 = 0;

    if(DataBluetooth == 'B1'){
      BT.println("A");
      Serial.println("");

      frecuencia = 15;
      frecuencia_cast = static_cast<int> (frecuencia);

      valor  =  100;
      brillo = valor * 2.55;

      for (int m = pauseA; m < 1800; m++){

        pauseA++;
        //Para pausar o cambiar de cancion
              if (BT.available()) {

            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'B1') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'B1'){
              break;
            }

            }
        }

        // Ajustes de la frecuencia
        if(m >= 0 && m < 300) {
          // Ajustamos la frecuencia
          frecuencia += 0.06;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 300 && m < 600) {
          // Ajustamos la frecuencia
          frecuencia += -0.0866;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 600 && m < 900) {
          // Ajustamos la frecuencia
          frecuencia += 0.0366;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 900 && m < 1200) {
          // Ajustamos la frecuencia
          frecuencia += -0.0366;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 1200 && m < 1500) {
          // Ajustamos la frecuencia
          frecuencia += 0.0233;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 1500 && m <= 1800) {
          // Ajustamos la frecuencia
          frecuencia += 0.0633;
          frecuencia_cast = static_cast<int> (frecuencia);
        }

        // Patrón de LED's
        if((m >= 240 && m < 840) || (m >= 1200 && m < 1440) || (m >= 1680 && m <= 1800)) {  // Patrón 2
          bool flag_patron = true;
          for(int z = 0; z <= frecuencia_cast; z++){
                if(z % 2 == 0) {
                  if(flag_patron) {
                    digitalWrite(Led_1, LOW);
                    digitalWrite(Led_2, LOW);
                    analogWrite(Led_3, brillo);
                    analogWrite(Led_4, brillo);
                    delay(1000/frecuencia_cast);
                    flag_patron = false;
                  }
                  else if(!flag_patron) {
                    analogWrite(Led_1, brillo);
                    analogWrite(Led_2, brillo);
                    digitalWrite(Led_3, LOW);
                    digitalWrite(Led_4, LOW);
                    delay(1000/frecuencia_cast);
                    flag_patron = true;
                  }
                }
                else {
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
          }

        }
        else {  // Todo prendido
          for(int z = 0; z <= frecuencia_cast; z++){
                if(z%2 == 0){
                  analogWrite(Led_1, brillo);
                  analogWrite(Led_2, brillo);
                  analogWrite(Led_3, brillo);
                  analogWrite(Led_4, brillo);
                  delay(1000/frecuencia_cast);
                }
                else{
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
            }
        }
      }
      if(pauseA >= 1800){
        pauseA = 0;
      }

      BT.println("A");
      Serial.println("");
    }
    pauseB = 0;
    x2 = 0;
    if(DataBluetooth == 'B2'){
      frecuencia = 18;
      frecuencia_cast = static_cast<int> (frecuencia);
      valor = 75;
      brillo = valor * 2.55;

      BT.println("B");
      Serial.println("");

      // Iniciamos el ciclo for
      for(int m = pauseB; m < 2700; m++) {

        if (BT.available()) {

            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'B2') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'B2'){
              break;
            }

            }
        }

        // Actualizamos las frecuencias
        if(m >= 0 && m < 600) {
          // Ajustamos la frecuencia
          frecuencia += -0.0216;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 600 && m < 900) {
          // Ajustamos la frecuencia
          frecuencia += 0.0066;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 900 && m < 1200) {
          // Ajustamos la frecuencia
          frecuencia += -0.01;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 1200 && m < 1800) {
          // Ajustamos la frecuencia
          frecuencia += 0.005;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 1800 && m < 2400) {
          // Ajustamos la frecuencia
          frecuencia += -0.005;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 2400 && m < 2640) {
          // Ajustamos la frecuencia
          frecuencia += 0.025;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 2640 && m <= 2700) {
          // Ajustamos la frecuencia
          frecuencia += 0.0666;
          frecuencia_cast = static_cast<int> (frecuencia);
        }

        // Actualizamos el brillo
        if(m >= 0 && m < 180) {
          // Ajustamos el brillo
          valor += 0.1388;
          brillo = valor * 2.55;
        }
        else if(m >= 180 && m < 1500) {
          // Ajustamos el brillo
          valor += -0.0189;
          brillo = valor * 2.55;
        }
        else if(m >= 1500 && m < 2400) {
          // Ajustamos el brillo
          valor += 0;
          brillo = valor * 2.55;
        }
        else if(m >= 2400 && m <= 2700) {
          // Ajustamos el brillo
          valor += 0.0694;
          brillo = valor * 2.55;
        }

      // Patrón de LED's
        if((m >= 0 && m < 600) || (m >= 2640 && m < 2700)) {  // Patrón 1
          for(int z = 0; z <= frecuencia_cast; z++){
                if(z % 2 == 0) {
                    analogWrite(Led_1, brillo);
                    analogWrite(Led_2, brillo);
                    analogWrite(Led_3, brillo);
                    analogWrite(Led_4, brillo);
                    delay(1000/frecuencia_cast);
                }
                else {
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
          }
        }
        else if((m >= 1200 && m < 1500) || (m >= 1800 && m < 2100) || (m >= 2400 && m < 2640)) {  // Patrón 2
          bool flag_patron = true; 
          for(int z = 0; z <= frecuencia_cast; z++){   
                if(z % 2 == 0) {
                  if(flag_patron) {
                    digitalWrite(Led_1, LOW);
                    digitalWrite(Led_2, LOW);
                    analogWrite(Led_3, brillo);
                    analogWrite(Led_4, brillo);
                    delay(1000/frecuencia_cast);
                    flag_patron = false;
                  }
                  else if(!flag_patron) {
                    analogWrite(Led_1, brillo);
                    analogWrite(Led_2, brillo);
                    digitalWrite(Led_3, LOW);
                    digitalWrite(Led_4, LOW);
                    delay(1000/frecuencia_cast);
                    flag_patron = true;
                  }
                }
                else {
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
          }
        }
        else if((m >= 600 && m < 1200) || (m >= 1500 && m < 1800) || (m >= 2100 && m < 2400)) {  // Patrón 4
          bool flag_patron = true; 
          for(int z = 0; z <= frecuencia_cast; z++){
                if(z % 2 == 0) {
                  if(flag_patron) {
                    digitalWrite(Led_1, LOW);
                    digitalWrite(Led_2, LOW);
                    analogWrite(Led_3, brillo);
                    analogWrite(Led_4, brillo);
                    delay(1000/frecuencia_cast);
                    flag_patron = false;
                  }
                  else if(!flag_patron) {
                    analogWrite(Led_1, brillo);
                    analogWrite(Led_2, brillo);
                    digitalWrite(Led_3, LOW);
                    digitalWrite(Led_4, LOW);
                    delay(1000/frecuencia_cast);
                    flag_patron = true;
                  }
                }
                else {
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
          }
        }
        else {  // Todo prendido
          for(int z = 0; z <= frecuencia_cast; z++){
                if(z%2 == 0){
                  analogWrite(Led_1, brillo);
                  analogWrite(Led_2, brillo);
                  analogWrite(Led_3, brillo);
                  analogWrite(Led_4, brillo);
                  delay(1000/frecuencia_cast);
                }
                else{
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
            }
        }
      
      pauseB++;
      }
      if(pauseB >= 2700){
        pauseB = 0;
      }
      BT.println("B");
      Serial.println("");
    }
    pauseC = 0;
    x3 = 0;
    if(DataBluetooth == 'B3'){
      
      frecuencia  = 16;
      valor = 60;
      brillo = valor * 2.55;

      BT.println("C");
      Serial.println("");

      for(int m = pauseC; m < 1500; m++){

        if (BT.available()) {

            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'B3') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'B3'){
              break;
            }

            }
        }

        // Actualizamos las frecuencias
        if(m >= 0 && m < 300) {
          // Ajustamos la frecuencia
          frecuencia += 0.06;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 300 && m < 900) {
          // Ajustamos la frecuencia
          frecuencia += -0.04;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 900 && m < 1200) {
          // Ajustamos la frecuencia
          frecuencia += -0.0066;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 1200 && m < 1440) {
          // Ajustamos la frecuencia
          frecuencia += 0;
          frecuencia_cast = static_cast<int> (frecuencia);
        }
        else if(m >= 1400 && m <= 1500) {
          // Ajustamos la frecuencia
          frecuencia += 0.1;
          frecuencia_cast = static_cast<int> (frecuencia);
        }

        // Actualizamos el brillo
        if(m >= 0 && m < 600) {
          // Ajustamos el brillo
          valor += 0.0666;
          brillo = valor * 2.55;
        }
        else if(m >= 600 && m < 900) {
          // Ajustamos el brillo
          valor += -0.0833;
          brillo = valor * 2.55;
        }
        else if(m >= 900 && m < 1200) {
          // Ajustamos el brillo
          valor += 0.0833;
          brillo = valor * 2.55;
        }
        else if(m >= 1200 && m < 1380) {
          // Ajustamos el brillo
          valor += -0.1388;
          brillo = valor * 2.55;
        }
        else if(m >= 1380 && m <= 1500) {
          // Ajustamos el brillo
          valor += 0.2083;
          brillo = valor * 2.55;
        }

        // Patrón de LED's
        if((m >= 0 && m < 60) || (m >= 120 && m < 240) || (m >= 600 && m < 720) || (m >= 900 && m < 1200) || (m >= 1440 && m < 1500)) {  // Patrón 1
          for(int z = 0; z <= frecuencia_cast; z++){
                if(z % 2 == 0) {
                    analogWrite(Led_1, brillo);
                    analogWrite(Led_2, brillo);
                    analogWrite(Led_3, brillo);
                    analogWrite(Led_4, brillo);
                    delay(1000/frecuencia_cast);
                }
                else {
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
          }
        }
        else if(m >= 240 && m < 420) {  // Patrón 2
          bool flag_patron = true; 
          for(int z = 0; z <= frecuencia_cast; z++){   
                if(z % 2 == 0) {
                  if(flag_patron) {
                    digitalWrite(Led_1, LOW);
                    digitalWrite(Led_2, LOW);
                    analogWrite(Led_3, brillo);
                    analogWrite(Led_4, brillo);
                    delay(1000/frecuencia_cast);
                    flag_patron = false;
                  }
                  else if(!flag_patron) {
                    analogWrite(Led_1, brillo);
                    analogWrite(Led_2, brillo);
                    digitalWrite(Led_3, LOW);
                    digitalWrite(Led_4, LOW);
                    delay(1000/frecuencia_cast);
                    flag_patron = true;
                  }
                }
                else {
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
          }
        }
        else if((m >= 60 && m < 120) || (m >= 1200 && m < 1440)) {  // Patrón 4
          bool flag_patron = true; 
          for(int z = 0; z <= frecuencia_cast; z++){
                if(z % 2 == 0) {
                  if(flag_patron) {
                    digitalWrite(Led_1, LOW);
                    digitalWrite(Led_2, LOW);
                    analogWrite(Led_3, brillo);
                    analogWrite(Led_4, brillo);
                    delay(1000/frecuencia_cast);
                    flag_patron = false;
                  }
                  else if(!flag_patron) {
                    analogWrite(Led_1, brillo);
                    analogWrite(Led_2, brillo);
                    digitalWrite(Led_3, LOW);
                    digitalWrite(Led_4, LOW);
                    delay(1000/frecuencia_cast);
                    flag_patron = true;
                  }
                }
                else {
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
          }
        }
        else if(m >= 720 && m < 900) {  // Patrón 5
          for(int z = 0; z <= frecuencia_cast; z++){
                if(z % 4 == 0) {
                    analogWrite(Led_1, brillo);
                    analogWrite(Led_2, brillo);
                    analogWrite(Led_3, brillo);
                    analogWrite(Led_4, brillo);
                    delay(1000/frecuencia_cast);
                }
                else {
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
          }
        }
        else if(m >= 420 && m < 600) {  // Patrón 6
          for(int z = 0; z <= frecuencia_cast; z++){
                if(z % 2 == 0) {
                    analogWrite(Led_1, brillo);
                    analogWrite(Led_2, brillo);
                    analogWrite(Led_3, brillo);
                    analogWrite(Led_4, brillo);
                    delay(1000/frecuencia_cast);
                }
                else {
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
          }
        }
        else {  // Todo prendido
          for(int z = 0; z <= frecuencia_cast; z++){
                if(z%2 == 0){
                  analogWrite(Led_1, brillo);
                  analogWrite(Led_2, brillo);
                  analogWrite(Led_3, brillo);
                  analogWrite(Led_4, brillo);
                  delay(1000/frecuencia_cast);
                }
                else{
                  analogWrite(Led_1, 0);
                  analogWrite(Led_2, 0);
                  analogWrite(Led_3, 0);
                  analogWrite(Led_4, 0);
                  delay(1000/frecuencia_cast);
                }
            }
        }

        pauseC++;
      }
      if(pauseC >= 2400){
        pauseC = 0;
      }
      BT.println("d");
      Serial.println("");
    }

    if(DataBluetooth == 'B4'){
      
      BT.println("B4");
      Serial.println("");

      frecuencia = 16;
      frecuencia_cast = static_cast<int> (frecuencia);

      valor  =  60;
      brillo = valor * 2.55;
      
      for(int x = 0; x < 1500; x++){

        if (BT.available()) {
            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'B4') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'B4'){
              break;
            }

            }
        }

        if(x < 300){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 300, 18);
        }
        else if (x < 900){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 600, 24);
        }
        else if(x < 1200){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 300, 3);
        }
        else if (x > 1440 ){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 60, 13);
        }

        if(x < 600){
          ajustarBrillo(true, valor, brillo, 600, 40);
        }
        else if (x < 900){
          ajustarBrillo(false, valor, brillo, 300, 25);
        }
        else if (x < 1200){
          ajustarBrillo(true, valor, brillo, 300, 25);
        }
        else if(x < 1380){
          ajustarBrillo(false, valor, brillo, 180, 25);
        }
        else{
          ajustarBrillo(true, valor, brillo, 120, 25);
        }

        if(x < 60){
          patron1(frecuencia_cast, brillo, x, 60);
        }
        else if (x < 120){
          patron4(frecuencia_cast, brillo, x, 60);
        }
        else if (x < 180){
          patron1(frecuencia_cast, brillo, x, 60);
        }
        else if (x < 300){
          patron2(frecuencia_cast, brillo, x, 120);
        }
        else if (x < 420){
          patron6(frecuencia_cast, brillo, x, 120);
        }
        else if (x < 600){
          patron1(frecuencia_cast, brillo, x, 180);
        }
        else if (x < 720){
          patron5(frecuencia_cast, brillo, x, 60);
        }
        else if (x < 900){
          patron1(frecuencia_cast, brillo, x, 180);
        }
        else if (x < 1200){
          patron4(frecuencia_cast, brillo, x, 300);
        }
        else{
          patron1(frecuencia_cast, brillo, x, 1440);
        }

      }


      }

      

    }

    if(DataBluetooth == 'B5'){

      BT.println("B5");
      Serial.println("");

      frecuencia = 20;
      frecuencia_cast = static_cast<int> (frecuencia);

      valor  =  60;
      brillo = valor * 2.55;

      for (int x = 0; x < 2700; x++){

        if (BT.available()) {
            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'B5') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'B5'){
              break;
            }

            }
        }

        if(x < 600){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 600, 16);
        }
        else if (x < 1200){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 600, 4);
        }
        else if (x < 1800){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 600, 4);
        }
        else if (x < 2400){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 600, 4);
        }
        else{
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 300, 10);
        }

        if(x < 180){
          ajustarBrillo(true, valor, brillo, 180, 40);
        }
        else if (x < 600){
          ajustarBrillo(false, valor, brillo, 420, 25);
        }
        else if (x > 2400){
          ajustarBrillo(true, valor, brillo, 300, 25);
        }

        if(x < 60){
          patron2(frecuencia_cast, brillo, x, 60);
        }
        else if (x < 120){
          patron1(frecuencia_cast, brillo, x, 60);
        }
        else if (x < 180){
          patron4(frecuencia_cast, brillo, x, 60);
        }
        else if (x < 300){
          patron1(frecuencia_cast, brillo, x, 120);
        }
        else if (x < 360){
          patron2(frecuencia_cast, brillo, x, 60);
        }
        else if (x < 600){
          patron1(frecuencia_cast, brillo, x, 240);
        }
        else if (x < 1200){
          patron6(frecuencia_cast, brillo, x, 600);
        }
        else if (x < 1800){
          patron1(frecuencia_cast, brillo, x, 600);
        }
        else if (x < 2400){
          patron2(frecuencia_cast, brillo, x, 600);
        }
        else{
          patron1(frecuencia_cast, brillo, x, 300);
        }

      }

    }

    if(DataBluetooth == 'B6'){

      BT.println("B6");
      Serial.println("");

      frecuencia = 15;
      frecuencia_cast = static_cast<int> (frecuencia);

      valor  =  100;
      brillo = valor * 2.55;

      for (int x = 0; x < 2700; x++){

        if (BT.available()) {
            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'B6') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'B6'){
              break;
            }

            }
        }

        if(x < 600){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 600, 10);
          ajustarBrillo(false, valor, brillo, 600, 25);
        }
        else if (x > 2400){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 300, 10);
          ajustarBrillo(true, valor, brillo, 300, 25);
        }

        if(x < 600){
          patron1(frecuencia_cast, brillo, x, 600);
        }
        else if (x < 2400){
          patron6(frecuencia_cast, brillo, x, 1800);
        }
        else{
          patron1(frecuencia_cast, brillo, x, 300);
        }

      }

    }
    if(DataBluetooth == 'AB0'){

      BT.println("AB0");
      Serial.println("");

      frecuencia = 15;
      frecuencia_cast = static_cast<int> (frecuencia);

      valor  =  100;
      brillo = valor * 2.55;

      for (int x = 0; x < 3600; x++){

        if (BT.available()) {
            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'AB0') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'AB0'){
              break;
            }

            }
        }

        if(x < 1200){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 600, 10);
          ajustarBrillo(false, valor, brillo, 1200, 40);
        }
        else if (x > 3000){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 300, 10);
          ajustarBrillo(true, valor, brillo, 600, 40);
        }

        if(x < 240){
          patron1(frecuencia_cast, brillo, x, 240);
        }
        else if (x < 600){
          patron6(frecuencia_cast, brillo, x, 360);
        }
        else if (x < 900){
          patron2(frecuencia_cast, brillo, x, 300);
        }
        else{
          patron1(frecuencia_cast, brillo, x, 2700);
        }

      }

    }
    if(DataBluetooth == 'AB1'){

      BT.println("AB1");
      Serial.println("");

      frecuencia = 16;
      frecuencia_cast = static_cast<int> (frecuencia);

      valor  =  100;
      brillo = valor * 2.55;

      for (int x = 0; x < 1080; x++){

        if (BT.available()) {
            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'AB1') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'AB1'){
              break;
            }

            }
        }

        if(x < 240){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 240, 12);
          ajustarBrillo(false, valor, brillo, 240, 25);
        }
        else if (x > 840){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 240, 20);
          ajustarBrillo(true, valor, brillo, 600, 25);
        }

        if(x < 240){
          patron1(frecuencia_cast, brillo, x, 240);
        }
        else if (x < 900){
          patron6(frecuencia_cast, brillo, x, 660);
        }
        else{
          patron1(frecuencia_cast, brillo, x, 180);
        }

      }

    }

    if(DataBluetooth == 'AB2'){

      BT.println("AB2");
      Serial.println("");

      frecuencia = 18;
      frecuencia_cast = static_cast<int> (frecuencia);

      valor  =  100;
      brillo = valor * 2.55;

      for (int x = 0; x < 2400; x++){

        if (BT.available()) {
            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'AB2') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'AB2'){
              break;
            }

          }
        }

        if(x < 420){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 420, 14);
          ajustarBrillo(false, valor, brillo, 420, 25);
        }
        else if (x > 2280){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 120, 20);
          ajustarBrillo(true, valor, brillo, 120, 25);
        }

        if(x < 360){
          patron1(frecuencia_cast, brillo, x, 360);
        }
        else if (x < 600){
          patron3(frecuencia_cast, brillo, x, 600);
        }
        else if (x < 1200){
          patron4(frecuencia_cast, brillo, x, 600);
        }
        else if (x < 1800){
          patron3(frecuencia_cast, brillo, x, 600);
        }
        else{
          patron4(frecuencia_cast, brillo, x, 600);
        }

      }

    }

    if(DataBluetooth == 'AB3'){

      BT.println("AB3");
      Serial.println("");

      frecuencia = 18;
      frecuencia_cast = static_cast<int> (frecuencia);

      valor  =  100;
      brillo = valor * 2.55;

      for (int x = 0; x < 1800; x++){

        if (BT.available()) {
            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'AB3') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'AB3'){
              break;
            }

          }
        }

        if(x < 720){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 720, 8);
        }
        else{
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 1080, 10);
        }

        if(x < 840){
          patron1(frecuencia_cast, brillo, x, 840);
        }
        else{
          patron2(frecuencia_cast, brillo, x, 960);
        }

      }

    }

    if(DataBluetooth == 'AB4'){

      BT.println("AB4");
      Serial.println("");

      frecuencia = 20;
      frecuencia_cast = static_cast<int> (frecuencia);

      valor  =  100;
      brillo = valor * 2.55;

      for (int x = 0; x < 4500; x++){

        if (BT.available()) {
            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'AB4') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'AB4'){
              break;
            }

            }
        }

        if(x < 480){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 480, 16);
        }
        else if (x > 4200){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 300, 14);
        }

        if(x < 840){
          ajustarBrillo(false, valor, brillo, 840, 40);
        }
        else if (x > 4200){
          ajustarBrillo(true, valor, brillo, 300, 40);
        }

        if(x < 420){
          patron1(frecuencia_cast, brillo, x, 420);
        }
        else if (x < 4500){
          patron6(frecuencia_cast, brillo, x, 4080);
        }
        else{
          patron1(frecuencia_cast, brillo, x, 300);
        }

      }

    }

    if(DataBluetooth == 'AB5'){
      BT.println("AB5");
      Serial.println("");

      frecuencia = 16;
      frecuencia_cast = static_cast<int> (frecuencia);

      valor  =  100;
      brillo = valor * 2.55;

      for(int x = 0; x < 2160; x++){
        if (BT.available()) {
            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'AB5') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'AB5'){
              break;
            }

            }
        }

        if(x < 300){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 300, 8);
        }
        else if (x < 900){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 600, 2);
        }
        else if (x < 1200){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 300, 6);
        }
        else if (x < 1500){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 300, 12);
        }
        else if(x < 1800){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 300, 6);
        }
        else{
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 360, 11);
        }

        if(x < 420){
          ajustarBrillo(false, valor, brillo, 420, 25);
        }
        else if(x > 2040){
          ajustarBrillo(true, valor, brillo, 120, 25);
        }

        if(x < 180){
          patron2(frecuencia_cast, brillo, x, 180);
        }
        else if (x < 300){
          patron1(frecuencia_cast, brillo, x, 120);
        }
        else if (x < 2040){
          patron5(frecuencia_cast, brillo, x, 1740);
        }
        else{
          patron1(frecuencia_cast, brillo, x, 120);
        }

      }
    }

    if(DataBluetooth == 'AB6'){
      BT.println("AB5");
      Serial.println("");

      frecuencia = 16;
      frecuencia_cast = static_cast<int> (frecuencia);

      valor  =  100;
      brillo = valor * 2.55;

      for(int x = 0; x < 2160; x++){
        if (BT.available()) {
            DataBluetooth = BT.read();
            Serial.print(DataBluetooth);

            if (DataBluetooth != 'AB5') {
                break;
            }
            if(DataBluetooth == 'P'){
              while(DataBluetooth == 'P'){
                if (BT.available()) {
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
              }

            if(DataBluetooth != 'AB5'){
              break;
            }

            }
        }

        if(x < 300){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 300, 8);
        }
        else if (x < 900){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 600, 2);
        }
        else if (x < 1200){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 300, 6);
        }
        else if (x < 1500){
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 300, 12);
        }
        else if(x < 1800){
          ajustarFrecuencia(false, frecuencia, frecuencia_cast, 300, 6);
        }
        else{
          ajustarFrecuencia(true, frecuencia, frecuencia_cast, 360, 11);
        }

        if(x < 420){
          ajustarBrillo(false, valor, brillo, 420, 25);
        }
        else if(x > 2040){
          ajustarBrillo(true, valor, brillo, 120, 25);
        }

        if(x < 180){
          patron2(frecuencia_cast, brillo, x, 180);
        }
        else if (x < 300){
          patron1(frecuencia_cast, brillo, x, 120);
        }
        else if (x < 2040){
          patron5(frecuencia_cast, brillo, x, 1740);
        }
        else{
          patron1(frecuencia_cast, brillo, x, 120);
        }

      }
    }
}
