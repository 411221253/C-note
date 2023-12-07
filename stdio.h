//

#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch;

    // 打開文件以進行讀取
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("無法打開文件");
        return 1;
    }

    // 打開文件以進行寫入
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("無法創建或打開目標文件");
        fclose(inputFile);
        return 2;
    }

    // 讀取字符並寫入新文件
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch, outputFile);
    }

    // 關閉文件
    fclose(inputFile);
    fclose(outputFile);

    printf("複製完成\n");

    return 0;
}


//attribute

#include <stdio.h>

// 使用屬性指定變數對齊為16位元組
int my_variable __attribute__((aligned(16)));

int main() {
    my_variable = 42;

    // 在這裡可以使用my_variable，並且可以確保其對齊方式為16位元組

    printf("The value of my_variable: %d\n", my_variable);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// 使用屬性指定函數不會返回
void my_exit_function() __attribute__((noreturn));

int main() {
    printf("This is the main function.\n");

    // 呼叫標記為noreturn的函數
    my_exit_function();

    // 這行程式碼永遠不會執行，因為my_exit_function標記為不會返回

    return 0;
}

// 定義標記為noreturn的函數
void my_exit_function() {
    printf("This function will exit the program.\n");
    exit(0);
}
