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


stderr	標準錯誤流
stdin	標準輸入流
stdout	標準輸出流

#include <stdio.h>

int main() {
    int number;

    // 提示用戶輸入一個整數
    printf("請輸入一個整數： ");

    // 使用 stdin 讀取用戶輸入
    scanf("%d", &number);

    // 輸出用戶輸入的整數
    printf("您輸入的整數是：%d\n", number);

    return 0;
}

NULL	空指針
_IOFBF	用於控制緩衝方式的參數
_IOLBF
_IONBF
BUFSIZ	setbuf函數使用的緩衝區大小
EOF	文件結尾標誌
FOPEN_MAX	實現保證能夠同時打開的文件數量
FILENAME_MAX	實現保證支持的最長文件名的字符數
L_tmpnam	存放tmpnam函數生成的臨時文件名的char數組的大小
SEEK_CUR	用於控制文件定位方式的參數
SEEK_END
SEEK_SET
TMP_MAX	實現保證能生成的臨時文件名個數

#include <stdio.h>

int main() {
    printf("最大打開文件數量：%d\n", FOPEN_MAX);

    return 0;
}

#include <stdio.h>

int main() {
    char filename[L_tmpnam];

    // 使用 tmpnam 函式生成臨時文件名
    tmpnam(filename);

    // 輸出臨時文件名
    printf("臨時文件名：%s\n", filename);

    return 0;
}

//int fprintf(FILE * restrict stream, const char * restrict format, ...);

#include <stdio.h>

int main() {
    FILE *file;
    const char *filename = "example.txt";

    // 打開文件以進行寫入
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "無法打開文件 %s 進行寫入。\n", filename);
        return 1; // 結束程序，返回錯誤碼
    }

    // 使用 fprintf 將內容寫入文件
    fprintf(file, "這是一個寫入文件的例子。\n");

    // 關閉文件
    fclose(file);

    printf("成功寫入文件 %s。\n", filename);

    return 0;
}

//int fscanf(FILE * restrict stream, const char * restrict format, ...);

#include <stdio.h>

int main() {
    FILE *file;
    const char *filename = "example.txt";
    int number;

    // 打開文件以進行讀取
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "無法打開文件 %s 進行讀取。\n", filename);
        return 1; // 結束程序，返回錯誤碼
    }

    // 使用 fscanf 從文件中讀取一個整數
    if (fscanf(file, "%d", &number) == 1) {
        printf("從文件中讀取的數字：%d\n", number);
    } else {
        fprintf(stderr, "讀取文件時發生錯誤。\n");
    }

    // 關閉文件
    fclose(file);

    return 0;
}

//int vfprintf(FILE * restrict stream, const char * restrict format, va_list arg);

#include <stdio.h>
#include <stdarg.h>

// 自定義函式，使用 vfprintf 輸出格式化字符串到文件
void logToFile(FILE *file, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(file, format, args);
    va_end(args);
}

int main() {
    FILE *file;
    const char *filename = "log.txt";

    // 打開文件以進行寫入
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "無法打開文件 %s 進行寫入。\n", filename);
        return 1; // 結束程序，返回錯誤碼
    }

    // 使用自定義函式 logToFile 寫入格式化內容到文件
    logToFile(file, "這是一條寫入文件的消息。\n");

    // 關閉文件
    fclose(file);

    printf("成功寫入文件 %s。\n", filename);

    return 0;
}

//char *fgets(char * restrict s, int n, FILE * restrict stream);

#include <stdio.h>

int main() {
    FILE *file;
    const char *filename = "example.txt";
    char buffer[100];

    // 打開文件以進行讀取
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "無法打開文件 %s 進行讀取。\n", filename);
        return 1; // 結束程序，返回錯誤碼
    }

    // 使用 fgets 從文件中讀取一行文本
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("從文件中讀取的內容：%s", buffer);
    } else {
        fprintf(stderr, "讀取文件時發生錯誤或到達文件結尾。\n");
    }

    // 關閉文件
    fclose(file);

    return 0;
}

//int fputs(const char * restrict s, FILE * restrict stream);

#include <stdio.h>

int main() {
    FILE *file;
    const char *filename = "output.txt";
    const char *message = "這是一條寫入文件的消息。\n";

    // 打開文件以進行寫入
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "無法打開文件 %s 進行寫入。\n", filename);
        return 1; // 結束程序，返回錯誤碼
    }

    // 使用 fputs 將字符串寫入文件
    if (fputs(message, file) != EOF) {
        printf("成功寫入文件 %s。\n", filename);
    } else {
        fprintf(stderr, "寫入文件時發生錯誤。\n");
    }

    // 關閉文件
    fclose(file);

    return 0;
}

//size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);

#include <stdio.h>

int main() {
    FILE *file;
    const char *filename = "binary_data.bin";
    int data[] = {1, 2, 3, 4, 5};

    // 打開文件以進行寫入
    file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "無法打開文件 %s 進行寫入。\n", filename);
        return 1; // 結束程序，返回錯誤碼
    }

    // 使用 fwrite 將二進制數據寫入文件
    size_t elements_written = fwrite(data, sizeof(int), sizeof(data) / sizeof(int), file);

    printf("成功寫入 %zu 個數據項到文件 %s。\n", elements_written, filename);

    // 關閉文件
    fclose(file);

    return 0;
}

//int fgetpos(FILE * restrict stream, fpos_t * restrict pos);

#include <stdio.h>

int main() {
    FILE *file;
    const char *filename = "example.txt";
    fpos_t position;

    // 打開文件以進行讀取
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "無法打開文件 %s 進行讀取。\n", filename);
        return 1; // 結束程序，返回錯誤碼
    }

    // 使用 fgetpos 獲取當前位置
    if (fgetpos(file, &position) == 0) {
        printf("當前位置：%lld\n", (long long)position);
    } else {
        fprintf(stderr, "獲取文件位置時發生錯誤。\n");
    }

    // 關閉文件
    fclose(file);

    return 0;
}

//int fseek(FILE *stream, long int offset, int whence);

#include <stdio.h>

int main() {
    FILE *file;
    const char *filename = "example.txt";

    // 打開文件以進行讀取
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "無法打開文件 %s 進行讀取。\n", filename);
        return 1; // 結束程序，返回錯誤碼
    }

    // 使用 fseek 將文件位置設置到第 10 個字節的位置
    if (fseek(file, 10, SEEK_SET) == 0) {
        printf("成功將文件位置設置到第 10 個字節。\n");
    } else {
        fprintf(stderr, "設置文件位置時發生錯誤。\n");
    }

    // 關閉文件
    fclose(file);

    return 0;
}

//FILE *freopen(const char * restrict filename, const char * restrict mode, FILE * restrict stream);

#include <stdio.h>

int main() {
    FILE *file;

    // 使用 fopen 打開一個文件
    file = fopen("example.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "無法打開文件 example.txt 進行寫入。\n");
        return 1; // 結束程序，返回錯誤碼
    }

    // 寫入一條消息到文件
    fprintf(file, "這是一條寫入文件的消息。\n");

    // 關閉文件
    fclose(file);

    // 使用 freopen 將文件重新打開為只讀模式
    file = freopen("example.txt", "r", stdin);
    if (file == NULL) {
        fprintf(stderr, "無法重新打開文件 example.txt 進行讀取。\n");
        return 1; // 結束程序，返回錯誤碼
    }

    // 讀取文件中的內容
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("讀取的內容：%s", buffer);
    }

    // 關閉文件
    fclose(file);

    return 0;
}

//int setvbuf(FILE * restrict stream, char * restrict buf, int mode, size_t size);

#include <stdio.h>

int main() {
    FILE *file;
    const char *filename = "example.txt";

    // 打開文件以進行寫入
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "無法打開文件 %s 進行寫入。\n", filename);
        return 1; // 結束程序，返回錯誤碼
    }

    // 設置文件流的緩衝區為行緩衝，並使用自定義緩衝區
    char buffer[BUFSIZ]; // 自定義緩衝區
    if (setvbuf(file, buffer, _IOLBF, BUFSIZ) != 0) {
        fprintf(stderr, "設置緩衝區時發生錯誤。\n");
        return 1; // 結束程序，返回錯誤碼
    }

    // 寫入一條消息到文件
    fprintf(file, "這是一條寫入文件的消息。\n");

    // 關閉文件
    fclose(file);

    return 0;
}

//int ferror(FILE *stream);

#include <stdio.h>

int main() {
    FILE *file;
    const char *filename = "example.txt";

    // 打開一個不存在的文件進行讀取
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "無法打開文件 %s 進行讀取。\n", filename);
        return 1; // 結束程序，返回錯誤碼
    }

    // 在讀取之前檢查文件流的錯誤狀態
    if (ferror(file) != 0) {
        fprintf(stderr, "打開文件時發生錯誤。\n");
        return 1; // 結束程序，返回錯誤碼
    }

    // 這裡進行文件的讀取操作...

    // 在讀取之後再次檢查文件流的錯誤狀態
    if (ferror(file) != 0) {
        fprintf(stderr, "讀取文件時發生錯誤。\n");
        return 1; // 結束程序，返回錯誤碼
    }

    // 關閉文件
    fclose(file);

    return 0;
}

//int feof(FILE *stream);

#include <stdio.h>

int main() {
    FILE *file;
    const char *filename = "example.txt";
    char buffer[100];

    // 打開文件以進行讀取
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "無法打開文件 %s 進行讀取。\n", filename);
        return 1; // 結束程序，返回錯誤碼
    }

    // 逐行讀取文件內容
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("讀取的內容：%s", buffer);
    }

    // 檢查是否已到達文件結尾
    if (feof(file) != 0) {
        printf("已到達文件結尾。\n");
    } else {
        printf("未到達文件結尾。\n");
    }

    // 關閉文件
    fclose(file);

    return 0;
}





