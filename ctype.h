//ctype.h常見函式
isalnum		是否為字母數字
isalpha		是否為字母
islower		是否為小寫字母
isupper		是否為大寫字母
isdigit		是否為數字
isxdigit	是否為16進位數字
iscntrl		是否為控制字元
isgraph		是否為圖形字元（例如，空格、控制字元都不是）
isspace		是否為空格字元（包括制表符、回車字元、換行符等）
isblank		是否為空白字元 (C99/C++11新增)（包括水平制表符）
isprint		是否為可列印字元
ispunct		是否為標點
tolower		轉換為小寫
toupper		轉換為大寫

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



