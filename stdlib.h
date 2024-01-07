/*
atof	把字符串轉換為雙精度浮點數。相當於strtod(s, (char**)NULL).
atoi	把字符串轉換為整型. 相當於(int)strtol(s, (char**)NULL, 10).
atol	把字符串轉換為長整型. Equivalente a strtol(s, (char**)NULL, 10).
atoll	把字符串轉換為長長整型. Equivalente a strtol(s, (char**)NULL, 10). 這是C99新增加的庫函數。
strtod	把字符串轉換為雙精度浮點數，檢查結果是否溢出，並返回字符串不能轉換部分的地址.
strtof	把字符串轉換為單精度浮點數，檢查結果是否溢出，並返回字符串不能轉換部分的地址.
strtold	把字符串轉換為長雙精度浮點數，檢查結果是否溢出，並返回字符串不能轉換部分的地址.
strtol	把字符串轉換為長整型，檢查結果是否溢出，並返回字符串不能轉換部分的地址.
strtoll	把字符串轉換為long long int，檢查結果是否溢出，並返回字符串不能轉換部分的地址.
strtoul	把字符串轉換為無符號長整形，檢查結果是否溢出，並返回字符串不能轉換部分的地址.
strtoull	把字符串轉換為unsigned long long int，檢查結果是否溢出，並返回字符串不能轉換部分的地址.
  */

#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *str = "123.45";
    double result = atof(str);

    printf("轉換後的浮點數：%f\n", result);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *str = "123";
    int result = atoi(str);

    printf("轉換後的整數：%d\n", result);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *str = "123.456";
    char *endptr;
    long double result = strtold(str, &endptr);

    if (endptr == str) {
        // 轉換失敗
        fprintf(stderr, "無法轉換字符串 %s 為浮點數。\n", str);
        return 1;
    }

    printf("轉換後的浮點數：%Lf\n", result);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *str = "123";
    char *endptr;
    long result = strtol(str, &endptr, 10);

    if (endptr == str) {
        // 轉換失敗
        fprintf(stderr, "無法轉換字符串 %s 為整數。\n", str);
        return 1;
    }

    printf("轉換後的整數：%ld\n", result);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *str = "123";
    char *endptr;
    unsigned long result = strtoul(str, &endptr, 10);

    if (endptr == str) {
        // 轉換失敗
        fprintf(stderr, "無法轉換字符串 %s 為整數。\n", str);
        return 1;
    }

    printf("轉換後的整數：%lu\n", result);

    return 0;
}

rand	返回在0到RAND_MAX之間的偽隨機數. 不接受參數作為隨機數種子，因此產生的偽隨機數列相同，有利於程序調試。
srand	初始化rand()接受無符號整型參數作為偽隨機數種子.如果種子相同，偽隨機數列也相同。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 使用時間作為種子，以確保每次運行生成不同的隨機數序列
    srand((unsigned int)time(NULL));

    // 生成一個隨機整數並輸出
    int random_number = rand();
    printf("隨機數：%d\n", random_number);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 使用時間作為種子，以確保每次運行生成不同的隨機數序列
    srand((unsigned int)time(NULL));

    // 生成並輸出 5 個隨機數
    for (int i = 0; i < 5; ++i) {
        int random_number = rand();
        printf("隨機數：%d\n", random_number);
    }

    return 0;
}

//aligned_alloc	邊界對齊的動態內存分配.
calloc	數組的動態內存分配，且初始化為全零
malloc	動態內存分配，其內容不初始化
realloc	釋放老的動態內存塊，按照給出的尺寸分配新的動態內存塊，老的內存塊的內容儘量複製到新的內存塊
free	系統釋放動態分配的內存. 如果是空指針，則無動作發生；如果指針所指不是動態分配的內存塊或者是已釋放的內存塊，則行為是未定義的。

#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t alignment = 16; // 例如，要求 16 字節對齊
    size_t size = 64;      // 要分配的內存大小

    // 使用 aligned_alloc 分配內存
    void *ptr = aligned_alloc(alignment, size);

    if (ptr == NULL) {
        fprintf(stderr, "內存分配失敗。\n");
        return 1;
    }

    printf("已成功分配 %zu 字節內存，位於 %p。\n", size, ptr);

    // 使用完畢後記得釋放內存
    free(ptr);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 64; // 要分配的內存大小

    // 使用 malloc 分配內存
    void *ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "內存分配失敗。\n");
        return 1;
    }

    printf("已成功分配 %zu 字節內存，位於 %p。\n", size, ptr);

    // 使用完畢後記得釋放內存
    free(ptr);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size1 = 10; // 初始內存大小
    size_t size2 = 20; // 新的內存大小

    // 使用 malloc 分配初始內存
    int *ptr = (int *)malloc(size1 * sizeof(int));

    if (ptr == NULL) {
        fprintf(stderr, "內存分配失敗。\n");
        return 1;
    }

    printf("已成功分配 %zu 個整數的內存，位於 %p。\n", size1, (void *)ptr);

    // 使用 realloc 重新分配內存大小
    int *new_ptr = (int *)realloc(ptr, size2 * sizeof(int));

    if (new_ptr == NULL) {
        fprintf(stderr, "內存重新分配失敗。\n");
        free(ptr); // 釋放之前分配的內存
        return 1;
    }

    printf("已成功重新分配 %zu 個整數的內存，位於 %p。\n", size2, (void *)new_ptr);

    // 使用完畢後記得釋放內存
    free(new_ptr);

    return 0;
}

/*
abort	導致程序非正常的結束，各種流緩衝區與臨時文件直接放棄。實際上拋出raise(SIGABRT)，預設的信號處理行為是使用退出代碼3執行終止（terminate）操作。如果SIGABRT被捕捉且信號處理程序不返回，則程序將不終止.
atexit	登記一個函數，當程序使用exit正常退出時被登記的函數自動被調用.
exit	程序正常終止。首先atexit()登記的函數按照登記的逆序被調用；如果多次調用atexit登記了多個函數，按照登記的逆序調用這些函數。如果一個函數被登記了多次，則程序正常退出時該函數也將被調用多次。然後所有緩衝區中的數據被寫回(flushed)；所有打開著的流被關閉；tmpfile函數創建的文件被刪除。最後，控制權返回給調用環境，返回數值表示程序返回時的狀態，0表示EXIT_SUCCESS, 1表示EXIT_FAILURE.
at_quick_exit	登記一個函數，當程序使用quick_exit正常退出時被登記的函數自動被調用.
_Exit	程序正常終止, 但atexit(), at_quick_exit(), signal()登記的函數不被調用; 打開的流、文件是否被關閉，由編譯器的實現者決定
getenv	獲得某一個環境變量的字符串值，如果該環境變量不存在，返回NULL.
quick_exit	程序正常終止, 但atexit(), 登記的函數不被調用; at_quick_exit()登記的函數按登記順序的逆序被調用。
system	把參數作為外部環境的命令執行。 如果參數為空，則判斷外部環境是否有命令解釋器。
*/

#include <stdio.h>
#include <stdlib.h>

void cleanup_function() {
    printf("在快速退出時執行清理操作。\n");
}

int main() {
    // 註冊在快速退出時執行的清理函式
    if (at_quick_exit(cleanup_function) != 0) {
        fprintf(stderr, "註冊失敗。\n");
        return 1;
    }

    // 在這裡可以執行其他程式邏輯

    // 觸發快速退出
    quick_exit(0);

    // 這裡的程式碼將不執行，因為已經觸發了快速退出

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void cleanup_function() {
    printf("在快速退出時執行清理操作。\n");
}

int main() {
    // 註冊在快速退出時執行的清理函式
    if (at_quick_exit(cleanup_function) != 0) {
        fprintf(stderr, "註冊失敗。\n");
        return 1;
    }

    // 在這裡可以執行其他程式邏輯

    // 觸發快速退出
    quick_exit(0);

    // 這裡的程式碼將不執行，因為已經觸發了快速退出

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("程序執行到這裡。\n");

    // 模擬一個致命錯誤，觸發 abort 函式
    abort();

    // 這裡的程式碼將不執行，因為已經觸發了 abort 函式

    printf("這行代碼將不會執行。\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void cleanup_function1() {
    printf("第一個清理函式。\n");
}

void cleanup_function2() {
    printf("第二個清理函式。\n");
}

int main() {
    // 註冊兩個在程序結束時執行的清理函式
    if (atexit(cleanup_function1) != 0 || atexit(cleanup_function2) != 0) {
        fprintf(stderr, "註冊失敗。\n");
        return 1;
    }

    printf("在 main 函式中執行一些工作。\n");

    // 程序正常結束，清理函式將按照註冊的相反順序執行

    return 0;
}

/*
mblen	計算多字節字符的長度並確定是否為有效字符 .
mbtowc	多字節字符轉換為寬字符.
wctomb	寬字符轉換為多字節字符.
  */

#include <stdio.h>
#include <wchar.h>

int main() {
    const char multibyte_string[] = "你好"; // UTF-8 encoded "Hello" in Chinese
    wchar_t wide_char;
    
    int result = mbtowc(&wide_char, multibyte_string, sizeof(multibyte_string));

    if (result > 0) {
        wprintf(L"轉換後的寬字符：%lc\n", wide_char);
    } else if (result == 0) {
        printf("輸入是一個空字節。\n");
    } else {
        printf("轉換失敗。\n");
    }

    return 0;
}

#include <stdio.h>

int main() {
    const char multibyte_string[] = "你好"; // UTF-8 encoded "Hello" in Chinese

    int byte_count = mblen(multibyte_string, sizeof(multibyte_string));

    if (byte_count > 0) {
        printf("多字節字符的字節數：%d\n", byte_count);
    } else if (byte_count == 0) {
        printf("空字節序列。\n");
    } else {
        printf("多字節字符解析失敗。\n");
    }

    return 0;
}



