Al utilizar el ESP32 dev kit 1, deveras revisar numero del chip, en mi caso es el CP2102, 
para poder utilizarlo y cargar el codigo hace falta descargar los drives para este chip los puedes encintrar en:
https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers.

<img width="218" height="307" alt="image" src="https://github.com/user-attachments/assets/b9b2bf18-8c0d-4025-a96c-ca187e5c896b" />

<img width="1024" height="576" alt="image" src="https://github.com/user-attachments/assets/a420bb1f-6d55-43ae-9c35-a49a34d88b8f" />

Para utilizar el LCD es necesrio conetar el GRD en la tierra del esp32 su propio GRD, VCC al puerto con salida de 5v el cuel es VIN en la placa de desarrollo, SDA al GPIO 21,  y SCL al GPIO 22.

