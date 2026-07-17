#include <stdio.h>

int my_strlen(const char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main(int argc , char* argv[]) {
    if(argc != 2){
        printf("invalid format");
        return 1;
    }
    char *str = argv[1];

    printf("Length = %d\n", my_strlen(str));

    return 0;
}