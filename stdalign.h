alignas 被擴展為_Alignas，_Alignas為C11的關鍵字。
alignof 被擴展為_Alignof，_Alignof為C11的關鍵字。
__alignas_is_defined 被擴展為1
__alignof_is_defined 被擴展為1

#include <stdio.h>

struct MyStruct {
    int a;
    char b;
    double c;
} alignas(16); // 將 MyStruct 的對齊要求設置為 16

int main() {
    struct MyStruct myVar;

    printf("Size of myVar: %zu\n", sizeof(myVar));
    printf("Address of myVar: %p\n", (void*)&myVar);

    return 0;
}

#include <stdio.h>

int main() {
    // 獲取不同類型的對齊要求
    printf("Alignment of int: %zu\n", alignof(int));
    printf("Alignment of double: %zu\n", alignof(double));
    printf("Alignment of char: %zu\n", alignof(char));

    // 獲取對象的對齊要求
    struct {
        int a;
        double b;
    } myStruct;

    printf("Alignment of myStruct: %zu\n", alignof(myStruct));

    return 0;
}

