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

//tolower，將字母大寫轉小寫，小寫維持小寫

#include <stdio.h>
#include <ctype.h>

int main() {
    char userInput;

    printf("請輸入一個字符：");
    scanf("%c", &userInput);

    if (isalpha(userInput)) {
        if (isupper(userInput)) {
            printf("%c 是一個大寫字母。\n", userInput);

            // 將大寫字母轉換為小寫
            char lowercaseChar = tolower(userInput);
            printf("對應的小寫字母是：%c\n", lowercaseChar);
        } else {
            printf("%c 是一個小寫字母。\n", userInput);
        }
    } else {
        printf("%c 不是一個字母。\n", userInput);
    }

    return 0;
}



