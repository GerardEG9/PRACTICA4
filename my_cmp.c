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
    int i = 0;
    char buffer1,buffer2;
    int read1, read2;
    int acabat = 0;
    while (acabat==0) {
        i++;
        read1 = read(fd1, &buffer1, 1);
        read2 = read(fd2, &buffer2, 1);
        if (read1 == -1 || read2 == -1) {
            perror("Error llegint el fitxer");
            exit(-1);
        }
        if (buffer1 != buffer2){
            printf("Hi ha una diferencia en el byte %d i en la linea %d\n",i,line);
            exit(-1);
        }
        if (read1==0 && read2==0){
        acabat++;
        }

        if (buffer1 == '\n'){
            line ++;
        }
    }




}
