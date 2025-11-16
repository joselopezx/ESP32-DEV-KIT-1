// el boton se coloca en GND para hacer los pulsos despues de 3 segundos el led se apaga
#define LED_PIN 2        // LED del ESP32 DevKit V1
#define BUTTON_PIN 4     // Botón conectado al GPIO 4

int numeroPulsos = 0;        // Debe ser variable global
bool lastState = HIGH;       // Último estado del botón
unsigned long lastDebounce = 0;
const unsigned long debounceDelay = 50;  // Antirrebote

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  int lectura = digitalRead(BUTTON_PIN);

  // --- Antirrebote ---
  if (lectura != lastState) {
    lastDebounce = millis();
    lastState = lectura;
  }

  if ((millis() - lastDebounce) > debounceDelay) {
    
    // Detectar un "nuevo" pulso (presión)
    if (lectura == LOW) {   // Botón presionado
      numeroPulsos++;
      Serial.print("Pulsos: ");
      Serial.println(numeroPulsos);

      // Evitar contar varias veces mientras el botón sigue presionado
      while(digitalRead(BUTTON_PIN) == LOW) {
        delay(10);
      }
    }
  }

  // --- Acción al llegar a 2 pulsos ---
  if (numeroPulsos == 2) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ENCENDIDO");
    numeroPulsos = 0; 
    delay(3000);
    digitalWrite(LED_PIN, LOW);
     // Reset para volver a empezar
  }

  delay(10);
}
