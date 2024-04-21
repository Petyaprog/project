#include <stdio.h>
#include <ctype.h>

int main() {

    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }

    printf("Строка в прописных буквах: %s", str);

    return 0;
}