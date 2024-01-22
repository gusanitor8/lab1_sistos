#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int file_descriptor = -1;
	int file_descriptor_dest = -1;

	if (argc > 2) {
		char* origin = argv[1];
		char* destination = argv[2];
		file_descriptor = open(origin, O_RDONLY);
		file_descriptor_dest = open(destination, O_WRONLY);

		printf("origen: %s\n", origin);
		printf("destino: %s\n", destination);
	}
	
	// validamos el file descriptor del origen
	if (file_descriptor == -1){
		printf("hubo un error abriendo el archivo de origen\n");
		return(1);
	}

	// validamos el file descriptor del destino
	if (file_descriptor_dest == -1) {
		printf("hubo un error abriendo el archivo de destino\n");
		return(1);
	}

	char buffer[1024];
	ssize_t bytesRead;
	
	bytesRead = read(file_descriptor, buffer, sizeof(buffer));

	//validamos el error del read
	if (bytesRead == -1) {
		printf("Hubo un error al leer el archivo \n");
	}

	// como el archivo que vamos a leer contiene texto 
	// agregegamos el null terminator en su ultimo indice
	buffer[bytesRead] = '\0';

	write(file_descriptor_dest, buffer, sizeof(buffer));

	return(0);
}
