#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void url_encode(char *str, int true_length) {
    int space_count = 0;

    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ') {
            space_count++;
        }
    }

    int new_length = true_length + (space_count * 2);

    str[new_length] = '\0';

    for (int i = true_length - 1, j = new_length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
    }
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string> <true_length>\n", argv[0]);
        return 1;
    }

    char str[200];

    int i = 0;
    while (argv[1][i] != '\0') {
        str[i] = argv[1][i];
        i++;
    }
    str[i] = '\0';

    int true_length = atoi(argv[2]);

    url_encode(str, true_length);

    printf("%s\n", str);

    return 0;
}