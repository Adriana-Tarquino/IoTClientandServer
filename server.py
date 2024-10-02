import socket
from _thread import *

# Configuración del servidor
ServerSocket = socket.socket()
host = "0.0.0.0"  # Cambia esto por la IP local si es necesario
port = 8080
led_red_state = False  # Estado del LED rojo
led_green_state = False  # Estado del LED verde

try:
    ServerSocket.bind((host, port))
    print(f"Servidor iniciado en {host}:{port}")
except socket.error as e:
    print(f"Error al enlazar el puerto: {str(e)}")
    exit()

print("Esperando conexiones...")
ServerSocket.listen(5)

# Función que maneja cada conexión de cliente en un nuevo hilo
def threaded_client(connection):
    global led_red_state, led_green_state
    while True:
        try:
            data = connection.recv(2048).decode('utf-8')
            if not data:
                
                print("No se recibieron datos, cerrando conexión.")
                break
            print(f"Datos recibidos: {data}")

            # Verificar si se recibe el comando "GET"
            if data.startswith('GET'):
                # Aquí puedes implementar la lógica para enviar el estado de humedad.
                # Si estás usando el estado 1 o 2 del sensor, por ejemplo:
                if led_red_state:
                    reply = "humidity=1\n"  # Seco
                elif led_green_state:
                    reply = "humidity=2\n"  # Moderadamente húmedo
                else:
                    reply = "humidity=0\n"  # Apagar LEDs
            elif data.startswith('humidity='):
                estado = int(data[9:])  # Obtener el estado de humedad
                print(f"Estado de humedad recibido: {estado}")

                # Controlar LEDs según el estado recibido
                if estado == 1:  # Seco
                    led_red_state = True
                    led_green_state = False
                    print("Encendiendo LED Rojo.")
                elif estado == 2:  # Moderadamente húmedo
                    led_red_state = False
                    led_green_state = True
                    print("Encendiendo LED Verde.")
                else:
                    led_red_state = False
                    led_green_state = False
                    print("Apagando LEDs.")

                reply = "ACK\n"
            else:
                print(f"Datos no reconocidos: {data}")
                reply = "Error: Comando no reconocido\n"

            connection.sendall(reply.encode('utf-8'))
        except socket.error as e:
            print(f"Error en la conexión: {str(e)}")
            break
    connection.close()
    print("Conexión cerrada")

# Bucle principal para aceptar nuevas conexiones
try:
    while True:
        Client, address = ServerSocket.accept()
        print(f"Conexión desde: {address[0]}:{str(address[1])}")
        start_new_thread(threaded_client, (Client,))
except KeyboardInterrupt:
    print("\nServidor detenido manualmente")
finally:
    ServerSocket.close()
    print("Socket cerrado, fin de programa")
