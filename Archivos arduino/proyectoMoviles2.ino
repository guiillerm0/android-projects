#include<SoftwareSerial.h>
SoftwareSerial BT(10, 11); // 10 RX, 11 TX.

byte Led_1 = 14;
byte Led_2 = 15;
byte Led_3 = 16;
byte Led_4 = 17;
char DataBluetooth = ' ';

void setup(){
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("");
  Serial.println("Iniciando Control ...");
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Led_3, OUTPUT);
  pinMode(Led_4, OUTPUT);
  digitalWrite(Led_1, HIGH);
  digitalWrite(Led_2, HIGH);
  digitalWrite(Led_3, HIGH);
  digitalWrite(Led_4, HIGH);
}

//Brillo: 0 - 255
//Frecuencia

float valor = 100;

float brillo = valor * 2.55;

float frecuencia = 0;
int frecuencia_cast = 0;
bool finCiclo = false;

void loop(){
  // Si hay datos disponibles en el módulo bluetooth HC-05
  if(BT.available()){
    DataBluetooth = BT.read();
    Serial.print(DataBluetooth);

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
              if(BT.available()){
                DataBluetooth = BT.read();
                Serial.print(DataBluetooth);
                if(DataBluetooth == 'C' || DataBluetooth == 'B'){
                  break;
                }
                if(DataBluetooth == 'P'){
                  while(DataBluetooth != 'A' && DataBluetooth != 'C' && DataBluetooth != 'B'){
                    if(BT.available()){
                      DataBluetooth = BT.read();
                      Serial.print(DataBluetooth);
                    }
                      delay(1000);
                  }
                  if(DataBluetooth == 'C' || DataBluetooth == 'B'){
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
        if(BT.available()){
          DataBluetooth = BT.read();
          Serial.print(DataBluetooth);
          if(DataBluetooth == 'C' || DataBluetooth == 'A'){
            break;
          }
          if(DataBluetooth == 'P'){
            while(DataBluetooth != 'B' && DataBluetooth != 'A' && DataBluetooth != 'C'){
                if(BT.available()){
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(1000);
            }
            if(DataBluetooth == 'C' || DataBluetooth == 'A'){
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

        if(BT.available()){
          DataBluetooth = BT.read();
          Serial.print(DataBluetooth);
          if(DataBluetooth == 'A' || DataBluetooth == 'B'){
            break;
          }
          if(DataBluetooth == 'P'){
            while(DataBluetooth != 'C' && DataBluetooth != 'A' && DataBluetooth != 'B'){
              if(BT.available()){
                  DataBluetooth = BT.read();
                  Serial.print(DataBluetooth);
                }
                delay(100);
            }
            if(DataBluetooth == 'A' || DataBluetooth == 'B'){
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

      

    }
  }
}
