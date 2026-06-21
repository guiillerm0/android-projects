#define LEDCONTROL_H

class LEDControl {
public:
    LEDControl(int pin);
    void begin();
    void on();
    void off();
    void setBrightness(int brightness);

private:
    int _pin;
};

