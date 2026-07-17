#include <stdio.h>

void reverse_string(char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    int left = 0;
    int right = length - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("invalid");
        return 1;
    }

    reverse_string(argv[1]);

    printf("%s\n", argv[1]);

    return 0;
}