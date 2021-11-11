
//Definición de pines
#define PINLED 2 // Pin de control de un relé al que está conectado una tira led 
#define PINPIR 3 // Pin de salida de datos del sensor de movimiento 
#define TIMEOFF 20 // Tiempo en segundos para desactivar la tira led tras el movimiento HC-SR501
int i = 0;

void setup()
{
  // Configuración del sistema
  pinMode(PINPIR, INPUT);
  digitalWrite(PINLED , HIGH);
  pinMode(PINLED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Semsor inicializado");
}

void loop()
{
  // Enciende la tira led al detectar movimiento
  if (digitalRead(PINPIR) == HIGH)
  {
    Serial.println("Detectado movimiento por el sensor pir");
    digitalWrite(PINLED, LOW);
    Serial.println("Encendido");
    
    // Temporizador que se reinicia con la detección de movimiento
    for (i = 0; i <= TIMEOFF ; i++) {
      Serial.print("El valor de i es:");
      Serial.println(i);
      if (digitalRead(PINPIR) == HIGH) {
        digitalWrite(PINLED, LOW);
        Serial.print("Detectado movimiento por el sensor pir: ");
        Serial.println("Reseteando cuenta");
        i = 0;
      }
      delay(1000);
    }

    // Apaga la tira led
    digitalWrite(PINLED , HIGH);
    Serial.println("Apagado");
  }


}
