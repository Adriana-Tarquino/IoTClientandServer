#include <WiFi.h>

// Pin del sensor de humedad
int sensorPin = 32;

// Credenciales WiFi
const char *ssid = "INVITADO";
const char *password = "";

// Configuración del servidor
WiFiClient client;
const char* serverIP = "192.168.41.16";  // Asegúrate de que la IP sea correcta
int serverPort = 8080;

void setup() {
    Serial.begin(115200);
    
    // Intentar conectar al WiFi
    WiFi.begin(ssid, password);
    Serial.print("Conectando a WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConectado a WiFi");
}

void loop() {
    // Leer el nivel de humedad desde el pin analógico
    int valorHumedad = analogRead(sensorPin);  
    int porcentajeHumedad = map(valorHumedad, 0, 4095, 100, 0);  // Convertir a porcentaje

    Serial.print("Humedad del suelo: ");
    Serial.print(porcentajeHumedad);
    Serial.println("%");

    // Determinar el estado según la humedad
    int estado = 0;
    if (porcentajeHumedad >= 30) {
        estado = 2;   // Moderadamente húmedo
    } else {
        estado = 1;   // Seco
    }

    // Conectar al servidor
    if (client.connect(serverIP, serverPort)) {
        // Enviar estado de humedad al servidor
        String mensaje = "humidity=" + String(estado) + "\n";
        client.print(mensaje);
        Serial.println("Estado enviado: " + mensaje);
        
        // Cerrar la conexión después de enviar
        client.stop();
    } else {
        // Informar si no se pudo conectar al servidor
        Serial.println("No se pudo conectar al servidor.");
    }

    delay(2000);  // Esperar antes de la próxima lectura y envío
}
