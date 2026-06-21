#include "Patrones.h"
#include <Arduino.h>

#define Led_1 14
#define Led_2 15
#define Led_3 16
#define Led_4 17

void patron1(int frecuencia_cast, float brillo, int momento, int duracion){
  
  int segmento = static_cast<int>((duracion/9)*2);

  int mMod = static_cast<int>(momento%segmento);

  if(mMod < segmento/2){
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }
  else{
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }

}

void patron2(int frecuencia_cast, float brillo, int momento, int duracion){
  
  int segmento = static_cast<int>(duracion/9);

  int mMod = static_cast<int>(momento%(segmento*4));

  if(mMod < segmento){

    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        }
        delay(1000 / frecuencia_cast);
    }

  } 
  else if (mMod > segmento*2 && mMod < segmento*3){
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }
  else {
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }

}

void patron3(int frecuencia_cast, float brillo, int momento, int duracion){

  int segmento = static_cast<int>((duracion/9));
  int mMod = static_cast<int>(momento%(segmento*4));

  if(mMod > segmento && mMod < segmento*2){
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }
  else if(mMod > segmento*3){
      for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        }
        delay(1000 / frecuencia_cast);
    }
  }
  else {
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }

}

void patron4(int frecuencia_cast, float brillo, int momento, int duracion){

  int segmento = static_cast<int>(duracion/9);

  int mMod = static_cast<int>(momento%(segmento*4));

  if(mMod < segmento){

    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        }
        delay(1000 / frecuencia_cast);
    }

  } 
  else if (mMod > segmento*2 && mMod < segmento*3){
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }
  else {
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }

}

void patron5(int frecuencia_cast, float brillo, int momento, int duracion){

  int segmento = static_cast<int>(duracion/9);

  int mMod = static_cast<int>(momento%(segmento*4));

  if(mMod < segmento){
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }
  else{
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }

}

void patron6(int frecuencia_cast, float brillo, int momento, int duracion){
  
  int segmento = static_cast<int>((duracion/9)*2);

  int mMod = static_cast<int>(momento%segmento);

  if(mMod < segmento/2){
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }
  else{
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }

}

void patron7(int frecuencia_cast, float brillo, int momento, int duracion){

  int segmento = static_cast<int>(duracion/9);

  int mMod = static_cast<int>(momento%(segmento*4));

  if(mMod < segmento){

    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        }
        delay(1000 / frecuencia_cast);
    }

  } 
  else if (mMod > segmento*2 && mMod < segmento*3){
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }
  else {
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }

}

void patron8(int frecuencia_cast, float brillo, int momento, int duracion){

  int segmento = static_cast<int>(duracion/9);

  int mMod = static_cast<int>(momento%(segmento*7));

  if(mMod > segmento*4 && mMod < segmento*5){

    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        }
        delay(1000 / frecuencia_cast);
    }

  }
  else if(mMod > segmento*6){

    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }

  }
  else{
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }

}

void patron9(int frecuencia_cast, float brillo, int momento, int duracion){

  int segmento = static_cast<int>(duracion/9);

  int mMod = static_cast<int>(momento%(segmento*7));

  if(mMod > segmento*4 && mMod < segmento*5){

    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }

  }
  else if(mMod > segmento*6){

    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        }
        delay(1000 / frecuencia_cast);
    }

  }
  else{
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }
}

void patron10(int frecuencia_cast, float brillo, int momento, int duracion){

  int segmento = static_cast<int>(duracion/9);

  int mMod = static_cast<int>(momento%(segmento*7));

  if(mMod > segmento*4 && mMod < segmento*5){

    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        }
        delay(1000 / frecuencia_cast);
    }

  }
  else if(mMod > segmento*6){

    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }

  }
  else{
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
  }

}



void ajustarBrillo(bool increase, float &valor, float&brillo, float duracion, float cantidad){
  if (increase) {
        valor += cantidad / duracion;
    } else {
        valor -= cantidad / duracion;
    }
    brillo = valor * 2.55;
}

void ajustarFrecuencia(bool increase, float &frecuencia, int &frecuencia_cast, float duracion, float cantidad) {
    
    if (increase) {
        frecuencia += cantidad / duracion;
    } else {
        frecuencia -= cantidad / duracion;
    }
    frecuencia_cast = static_cast<int>(frecuencia);

}


void patternLeftOffRightOn(int frecuencia_cast, float brillo) {
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            digitalWrite(Led_1, LOW);
            digitalWrite(Led_2, LOW);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
}

void patternLeftOnRightOff(int frecuencia_cast, float brillo) {
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            digitalWrite(Led_3, LOW);
            digitalWrite(Led_4, LOW);
        }
        delay(1000 / frecuencia_cast);
    }
}

void patternAllOn(int frecuencia_cast, float brillo) {
    for (int z = 0; z < frecuencia_cast; z++) {
        if (z % 2 == 0) {
            analogWrite(Led_1, brillo);
            analogWrite(Led_2, brillo);
            analogWrite(Led_3, brillo);
            analogWrite(Led_4, brillo);
        } else {
            analogWrite(Led_1, 0);
            analogWrite(Led_2, 0);
            analogWrite(Led_3, 0);
            analogWrite(Led_4, 0);
        }
        delay(1000 / frecuencia_cast);
    }
}
