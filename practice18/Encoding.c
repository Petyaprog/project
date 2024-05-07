#include <stdio.h>
#include <wchar.h>
#include <wctype.h>

int main() {

    wchar_t str[1000];
    wprintf(L"enter the string: ");
    fgetws(str, sizeof(str)/sizeof(str[0]), stdin);
    for (int i = 0; str[i] != L'\0'; i++) {
        str[i] = towupper(str[i]);
    }

    wprintf(L"Строка в прописных буквах: %ls", str);

    return 0;
}