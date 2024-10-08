# IoT Client and Server

# Sistema de Monitoreo y Control de Humedad con ESP32

Este proyecto implementa un sistema de monitoreo y control automático de la humedad del suelo utilizando dos ESP32 conectados mediante TCP sobre Wi-Fi. El sistema supervisa los niveles de humedad y gestiona una bomba de agua y LEDs indicadores.

## Objetivo

Monitorear el nivel de humedad del suelo en tiempo real y controlar automáticamente una bomba de agua y dos LEDs:
- **LED rojo:** Humedad ≤ 30% (suelo seco, necesita riego).
- **LED verde:** Humedad > 30% (humedad adecuada).

## Características

- **Monitoreo:** Sensor de humedad HL-69 conectado al primer ESP32.
- **Control:** Segundo ESP32 controla una bomba de agua y los LEDs.
- **Comunicación:** Los ESP32 se comunican vía TCP sobre una red Wi-Fi.

## Requisitos

- 2x ESP32
- 1x Sensor de Humedad HL-69
- 1x Bomba de Agua
- 1x LED Rojo y 1x LED Verde
- Arduino IDE, Python (servidor TCP)

## Instalación

1. Configura el hardware (sensor y actuadores conectados a los ESP32).
2. Sube el código a los ESP32.
3. Ejecuta el servidor TCP en Python.
4. Asegúrate de que los ESP32 y el servidor estén en la misma red Wi-Fi.

## Uso

- El primer ESP32 mide la humedad y envía datos al servidor.
- El servidor controla la bomba y los LEDs según los datos recibidos.