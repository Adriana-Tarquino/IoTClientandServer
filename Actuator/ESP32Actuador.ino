#include <WiFi.h>

// Pines de los LEDs
int ledPinRed = 16;   // Pin para el LED rojo
int ledPinGreen = 17; // Pin para el LED verde
int bomba= 5;

// Definir credenciales WiFi
const char *ssid = "INVITADO";
const char *password = "";

WiFiClient client;
const char* serverIP = "192.168.41.16";  // Cambia a la IP de tu servidor
int serverPort = 8080;

void setup() {
    Serial.begin(115200);
    // Inicializar LEDs
    pinMode(ledPinRed, OUTPUT);
    pinMode(ledPinGreen, OUTPUT);
    pinMode(bomba, OUTPUT);
    
    // Conectar a WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Conectando a WiFi...");
    }
    Serial.println("Conectado a WiFi");
}

void loop() {
    // Conectar al servidor y solicitar el estado
    if (client.connect(serverIP, serverPort)) {
        client.println("GET");  // Solicitar el estado al servidor

        // Leer la respuesta del servidor
        String response = client.readStringUntil('\n');
        Serial.println("Respuesta del servidor: " + response);  // Imprimir respuesta completa

        // Manejar la respuesta
        if (response.startsWith("humidity=")) {
            int estadoRecibido = response.substring(9).toInt(); // Extraer el estado

            // Controlar LEDs según el estado recibido
            if (estadoRecibido == 1) {  // Seco
                Serial.println("Estado: Seco. Encendiendo LED Rojo.");
                digitalWrite(ledPinRed, HIGH);  // Encender LED rojo
                digitalWrite(ledPinGreen, LOW);  // Apagar LED verde
                 digitalWrite(bomba, HIGH);  // Apagar LED verde
                 delay(2000);

            } else if (estadoRecibido == 2) {  // Moderadamente húmedo
                Serial.println("Estado: Moderadamente húmedo. Encendiendo LED Verde.");
                digitalWrite(ledPinRed, LOW);  // Apagar LED rojo
                digitalWrite(ledPinGreen, HIGH);  // Encender LED verde
            } else {
                Serial.println("Estado no reconocido. Apagando LEDs.");
                digitalWrite(ledPinRed, LOW);  // Apagar LED rojo
                digitalWrite(ledPinGreen, LOW);  // Apagar LED verde
            }
        } else {
            Serial.println("Formato de respuesta no reconocido.");
        }

        client.stop();  // Cerrar la conexión con el servidor
    } else {
        Serial.println("Conexión fallida al servidor.");
        delay(2000);  // Esperar 2 segundos antes de intentar reconectar
    }

    delay(500); // Esperar un segundo antes de la próxima solicitud
}
