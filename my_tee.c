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
  else{
    int fd = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IROTH);
    if (fd == -1){
      perror("Error: no s'ha pogut crear el arxiu");

    }
    else{
      char caracters[1024];
      while (byte_llegit = read(0,caracters,1024) > 0){
        write(filename,caracters,1024);
        write(1,caracter,1024);
      }        
      if (byte_llegit == -1){
        perror("Error: no s'ha pogut llegir el arxiu");
        exit
      }
     

    }

  }
}