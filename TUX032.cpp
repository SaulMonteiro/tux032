#include "TUX032.h"

// Implementação do construtor
TUX032::TUX032() {
    h_freq = 0;
    l_freq = 0;
}

// Implementações dos métodos (já fornecidas por você)
void TUX032::sendData() {
    Wire.beginTransmission(0x61);
    Wire.write(0x80);
    Wire.write(h_freq);
    Wire.write(l_freq);
    Wire.write(0x64);
    Wire.write(0xB1);
    Wire.write(0xC6);
    Wire.write(0x4B);
    Wire.write(0xA2);
    Wire.write(0xD2);
    Wire.endTransmission();
}

void TUX032::mono(bool monoEnable) {
    Wire.beginTransmission(0x61);    
    Wire.write(0x03);
    Wire.write(0xC3);
    Wire.write(0x2F);
    Wire.write(0xFF);
    Wire.write(0x07);
    if(monoEnable == false) {
        Wire.write(0x05);
    } else {
        Wire.write(0x04);    
    }
    Wire.write(0x84);
    Wire.endTransmission();        
}

void TUX032::powerOn() {
    Wire.beginTransmission(0x61);
    Wire.write(0x82);
    Wire.write(0x64);
    Wire.endTransmission();
}

void TUX032::powerOff() {
    Wire.beginTransmission(0x61);
    Wire.write(0x82);
    Wire.write(0x00);
    Wire.endTransmission();
}

void TUX032::tunerInit() {
    powerOff();
}

void TUX032::setFreq(unsigned int freq_tux) {
    freq_tux = freq_tux / 5 + 214;
    h_freq = freq_tux >> 8;
    l_freq = freq_tux & 0xff;
    sendData();
}
