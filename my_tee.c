#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main ( int argc, char *argv[] ){
    char *filename = argv[1];
    if (argc < 2){
        perror("No hi han arguemnts suficients: ");
        return -1;
    }

        int fd = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IROTH);
        if (fd == -1){
            perror("Error: no s'ha pogut crear el arxiu");
            exit(-1);

        }

            char caracters[1024];
            int byte_llegit;
            while ((byte_llegit = read(0,caracters,1024)) > 0){
                write(fd,caracters,byte_llegit);
                write(1,caracters,byte_llegit);
            }
            if (byte_llegit == -1){
                perror("Error: no s'ha pogut llegir el arxiu");
                exit;
              }


        }

