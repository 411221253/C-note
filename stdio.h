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
