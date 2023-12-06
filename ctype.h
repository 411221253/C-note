//isalpha，將字母小寫轉大寫，大寫維持大寫

#include <stdio.h>
#include <ctype.h>

int main() {
    char userInput;

    printf("請輸入一個字符：");
    scanf("%c", &userInput);

    if (isalpha(userInput)) {
        if (isupper(userInput)) {
            printf("%c 是一個大寫字母。\n", userInput);
        } else {
            printf("%c 是一個小寫字母。\n", userInput);
        }
    } else {
        printf("%c 不是一個字母。\n", userInput);
    }

    return 0;
}
