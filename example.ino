#include <Wire.h>
#include "TUX032.h"

TUX032 tuner; // Cria objeto do sintonizador

// Variáveis para controle
unsigned int frequency = 10250; // Frequência inicial (102.50 MHz)
bool isMono = false; // Modo estéreo inicial

void setup() {
  Wire.begin(); // Inicia comunicação I2C
  Serial.begin(9600);
    while (!Serial); // Leonardo: wait for Serial Monitor
    Serial.println("TUX032 - Controle de Rádio FM");
  tuner.tunerInit(); // Inicializa o sintonizador (desliga)
  tuner.powerOn();   // Liga o sintonizador
  tuner.setFreq(frequency); // Define frequência inicial
  tuner.mono(isMono); // Configura modo estéreo


  Serial.println("Comandos:");
  Serial.println("[+] : Aumenta frequência (1 MHz)");
  Serial.println("[-] : Diminui frequência (1 MHz)");
  Serial.println("[m] : Alternar Mono/Estéreo");
  Serial.println("-----------------------------");
  Serial.print("Frequência Atual: ");
  Serial.print(frequency / 100.0, 2); // Exibe em MHz
  Serial.println(" MHz");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    switch(command) {
      case '+':
        frequency += 50; // Aumenta 1 MHz (100 unidades = 1.00 MHz)
        break;
      case '-':
        frequency -= 50; // Diminui 1 MHz
        break;
      case 'm':
        isMono = !isMono; // Alterna modo
        tuner.mono(isMono);
        Serial.print("Modo: ");
        Serial.println(isMono ? "Mono" : "Estéreo");
        break;
    }
   tuner.setFreq(frequency); // Define frequência inicial
   Serial.println(frequency);

    
    delay(1000);


  }



   
}
