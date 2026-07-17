// #include <fcntl.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>

// #define BUF_SIZE 1024

// void add(char* fileName, char* data){
//     int fileFd = open(fileName, O_WRONLY | O_CREAT, 0644);
//     char buf[BUF_SIZE];
//     write(fileFd,buf ,data );

// }

// void view(char* fileName){
//     int fileFd = open(fileName, O_RDONLY);
//     char buf[BUF_SIZE];
//     ssize_t numRead;
//     while((numRead = read(fileFd,buf, BUF_SIZE ) > 0) ){
        
//     }
// }

// int main(int argc , char* argv[]){

//     if(argv[1] == "--add"){
//         add(argv[2], argv[3]);
//         if(argc != 4 ){
//             printf("not enough arguments");
//             exit(-1);
//         }
//     }
//     if(argv[1] == "--view"){
//         view(argv[2]);
//         if(argc != 3){
//             printf("invalid");
//             exit(-1);
//         }
//     }


// }
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024
#define LOG_FILE "audit.log"

void add(char *message) {

    int fileFd;

    fileFd = open(LOG_FILE, O_CREAT | O_WRONLY | O_APPEND, 0644);

    if (fileFd == -1) {
        printf("Error opening log file\n");
        exit(-1);
    }

    write(fileFd, message, strlen(message));
    write(fileFd, "\n", 1);

    close(fileFd);
}

void view() {

    int fileFd;
    char buf[BUF_SIZE];
    ssize_t numRead;
    int line = 1;

    fileFd = open(LOG_FILE, O_RDONLY);

    if (fileFd == -1) {
        printf("Error opening log file\n");
        exit(-1);
    }

    printf("%d: ", line);

    while ((numRead = read(fileFd, buf, BUF_SIZE)) > 0) {

        for (int i = 0; i < numRead; i++) {

            write(STDOUT_FILENO, &buf[i], 1);

            if (buf[i] == '\n') {
                line++;
                printf("%d: ", line);
            }
        }
    }

    close(fileFd);
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Invalid arguments\n");
        exit(-1);
    }

    if (strcmp(argv[1], "--add") == 0) {

        if (argc != 3) {
            printf("Usage: ./auditlog --add \"message\"\n");
            exit(-1);
        }

        add(argv[2]);
    }

    else if (strcmp(argv[1], "--view") == 0) {

        if (argc != 2) {
            printf("Usage: ./auditlog --view\n");
            exit(-1);
        }

        view();
    }

    else {
        printf("Invalid command\n");
    }

    return 0;
}