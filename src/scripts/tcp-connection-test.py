import socket
import threading
import random

def main():
    # Set the host and port to connect to
    host = "127.0.0.1"
    port = 12345

    # Create a TCP socket
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        try:
            # Connect to the server
            s.connect((host, port))

            # Receive a message from the server
            # received_data = s.recv(1024)
            # print(f"Received: {received_data.decode('utf-8')}")

            # Send a response back to the server
            message_to_send = random.randint(0,2)
            s.sendall(message_to_send.to_bytes(1, byteorder='big'))
            print(f"s")    
        except Exception as e:
            print(f"Error: {e}")
        

if __name__ == "__main__":
    for i in range(1):
        threads = []
        size = 1
        for j in range(size):
            threads.append(threading.Thread(target=main))
            threads[j].start()

        for j in range(size):
            threads[j].join()
        
