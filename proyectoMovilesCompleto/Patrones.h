#define PATRONES_H

void ajustarBrillo(bool increase, float &valor, float&brillo, float duracion, float cantidad);
void ajustarFrecuencia(bool increase, float &frecuencia, int &frecuencia_cast, float duracion, float cantidad);
void patron1(int frecuencia_cast, float brillo, int momento, int duracion);
void patron2(int frecuencia_cast, float brillo, int momento, int duracion);
void patron3(int frecuencia_cast, float brillo, int momento, int duracion);
void patron4(int frecuencia_cast, float brillo, int momento, int duracion);
void patron5(int frecuencia_cast, float brillo, int momento, int duracion);
void patron6(int frecuencia_cast, float brillo, int momento, int duracion);
void patron7(int frecuencia_cast, float brillo, int momento, int duracion);
void patron8(int frecuencia_cast, float brillo, int momento, int duracion);
void patron9(int frecuencia_cast, float brillo, int momento, int duracion);
void patron10(int frecuencia_cast, float brillo, int momento, int duracion);
void patternLeftOffRightOn(int frecuencia_cast, float brillo);
void patternLeftOnRightOff(int frecuencia_cast, float brillo);
void patternAllOn(int frecuencia_cast, float brillo);

