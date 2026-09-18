#define PINO 4
#define FREQ 50
#define RES 14  // ledc do c3 supermini tem res max de 14
#define RESLEDC (1UL << RES)

// em microsegundos
#define MINPWM 1000
#define MAXPWM 1200 // valor máximo de 2000

void setarESC(int larguraPulso) {
    int duty {larguraPulso * RESLEDC / 20000};
    ledcWrite(PINO, duty);
}

void setup() {
    Serial.begin(115200);
    Serial.println("Iniciando...");  
    ledcAttach(PINO, FREQ, RES);

    Serial.println("Conexão efetivada.");
    Serial.print("Conecte a bateria. Aguardando 7 segundos. Enviando pulso mínimo de");
    Serial.print(MINPWM);
    Serial.println("us para armar o ESC.");
    setarESC(MINPWM);
    delay(7000);
}

// pega o PWM e eleva ele aos poucos até o maximo, após zera
void loop() {
    for(int pulso {MINPWM}; pulso<=MAXPWM; pulso+=10) {
        setarESC(pulso);
        Serial.print(pulso);
        Serial.print(" us.");
        delay(100);
    }

    Serial.println("Velocidade máxima do brushless atingida.");
    delay(5000);

    setarESC(MINPWM);
}
