#include <Keyboard.h>

void setup() {
  delay(2000); // Espera a que la PC reconozca el dispositivo
  Keyboard.begin();

  // Abrir "Ejecutar" (Windows + R)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();

  delay(500);

  // Escribir "notepad" y presionar Enter
  Keyboard.print("notepad");
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  delay(1000);

  // Escribir el mensaje
  Keyboard.print("Hola desde Arduino!");

  Keyboard.end();
}

void loop() {
}