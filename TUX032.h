#ifndef TUX032_h
#define TUX032_h

#include <Arduino.h>
#include <Wire.h> // Adicione esta linha!

class TUX032 {
public:
    TUX032(); // Construtor declarado corretamente
    void setFreq(unsigned int freq_tux);
    void powerOn();
    void powerOff();
    void mono(bool monoEnable);
    void tunerInit();

private:
    byte h_freq; 
    byte l_freq;
    void sendData();
};

#endif
