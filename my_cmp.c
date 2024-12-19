#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[] ){

    if (argc < 3){
        perror("No hi han arguments suficients");
        exit(-1);
    }
    char *filename1 = argv[1];
    char *filename2 = argv[2];
    int fd1 = open(filename1, O_RDONLY);
    int fd2 = open(filename2, O_RDONLY);
    if ((fd1 == -1) || (fd2 == -1)){
        perror("Error obrint el fitxer");
        exit(-1);
    }


    int line = 1;
    int i = 1;
    char buffer1,buffer2;
    while (read(fd1,&buffer1, 1)>0 || read(fd2,&buffer2, 1)>0){
        if (read(fd1, &buffer1, 1)==-1 || read(fd2, &buffer2, 1) == -1){
            perror("Error llegint el fitxer");
            exit(-1);
        }
        if (buffer1 == '\n'){
            line ++;
        }
        if (buffer1 != buffer2){
            printf("%c\n", buffer1);
            printf("%c\n", buffer2);
            printf("Hi ha una diferencia en el byte %d i en la linea %d\n",i,line);
        exit(-1);
        }
        i ++;
    }
    close(fd1);
    close(fd2);

    return 0;
}
