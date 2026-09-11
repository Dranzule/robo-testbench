#include <Arduino.h>

const int PINO {4};
const int FREQ {50}; 
const int RES {14}; // ledc do c3 supermini tem max de 14
const int RESLEDC {1LL << RES};

const int MINPWM {1000};
const int MAXPWM {1200};
const int TESTPWM {1100};

const int DUTY_MIN {MINPWM * RESLEDC / 20000};
const int DUTY_MID {TESTPWM * RESLEDC / 20000};
const int DUTY_MAX {MAXPWM * RESLEDC / 20000};

void setup() {
    Serial.begin(115200);
    Serial.println("Iniciando...");  
    ledcAttach(PINO, FREQ, RES);

    Serial.println("Conexão efetivada.");
    Serial.print("Conecte a bateria. Aguardando 10 segundos. Enviando pulso mínimo de ...");
    Serial.print(MINPWM);
    Serial.println("us.");
    ledcWrite(PINO, DUTY_MIN);
    delay(10000);
}

void loop() {
    ledcWrite(PINO, DUTY_MID);
    delay(2000);
    ledcWrite(PINO, DUTY_MAX);
    delay(2000);
    ledcWrite(PINO, DUTY_MID);
    delay(2000);
    ledcWrite(PINO, DUTY_MIN);
    delay(1000);
}
