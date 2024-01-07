C 函式庫函數size_t strcspn(const char *str1, const char *str2) 擷取字串str1 開頭連續有幾個字元都不含字串str2 中的字元。

size_t strcspn(constchar *str1,constchar *str2) 

str1 -- 要擷取的 C 字串。
str2 -- 此字串包含了要在 str1 中進行匹配的字元清單。

  
#include <stdio.h>
#include <string.h>


int main ()
{
   int len;
   const char str1[] = "ABCDEF4960910";
   const char str2[] = "013";

   len = strcspn(str1, str2);

   printf("第一个匹配的字符是在 %d\n", len + 1);
   
   return(0);
}

第一个匹配的字符是在 10

void *memcpy(void *dest, const void *src, size_t n);	將n位元組長的內容從一個記憶體位址複製到另一個位址；如果兩個位址存在重疊，則最終行為未定義
void *memmove(void *dest, const void *src, size_t n);	將n位元組長的內容從一個記憶體位址複製到另一個位址；與memcpy不同的是它可以正確作用於兩個存在重疊的位址
void *memchr(const void *s, char c, size_t n);	在從s開始的n個位元組內尋找c第一次出現的位址並返回，若未找到則返回NULL
int memcmp(const void *s1, const void *s2, size_t n);	對從兩個記憶體位址開始的n個字元進行比較
void *memset(void *, int, size_t);	用某種位元組內容覆寫一段記憶體空間
char *strcat(char *dest, const char *src);	在字串dest之後連接上src
char *strncat(char *dest, const char *src, size_t n);	從src截取n個字元連接在字串dest之後，返回dest字串
char *strchr(const char* str, int ch);	從字串str頭開始尋找字元ch首次出現的位置
char *strrchr(const char* str,int ch);	從字串str尾開始尋找字元ch首次出現的位置
int strcmp(const char *, const char *);	基於字典順序比較兩個字串
int strncmp(const char *, const char *, size_t n);	基於字典順序比較兩個字串，最多比較n個位元組
int strcoll(const char *, const char *);	基於當前區域設定的字元順序比較兩個字串
char *strcpy(char* str1, const char* str2);	將str2拷貝給str1
char *strncpy(char* str1, const char* str2, size_t n);	截取str2的n個字元拷貝給str1
char *strerror(int);	返回錯誤碼對應的解釋字串，參見errno.h（非執行緒安全函數）
size_t strlen(const char *);	返回一個字串的長度
size_t strspn(const char *s, const char *strCharSet);	從字串s的起始處開始，尋找第一個不出現在strCharSet中的字元，返回其位置索引值。換句話說，返回從字串s的起始位置的完全由strCharSet中的字元構成的子串的最大長度。strspn為string span的縮寫。不支援多位元組字元集。
size_t strcspn(const char *s, const char *strCharSet);	從字串s的起始處開始，尋找第一個出現在strCharSet中的字元，返回其位置索引值。換句話說，返回從字串s的起始位置的完全由不屬於strCharSet中的字元構成的子串的最大長度。strcspn為string complement span的縮寫。不支援多位元組字元集。
char *strpbrk(const char *s, const char *breakset);	在字串s中尋找breakset中任意字元第一次出現的位置的指標值。strpbrk為string pointer break縮寫。通常，breakset是分隔符的集合。不支援多位元組字元集。
char *strstr(const char *haystack, const char *needle);	在字串haystack中尋找字串needle第一次出現的位置，heystack的長度必須長於needle
char *strtok(char *strToken, const char *strDelimit );	將一個字串strToken依據分界符（delimiter）分隔成一系列字串。此函數非執行緒安全，且不可重入；但MSVC實現時使用了thread-local static variable因而是執行緒安全的但仍然是不可重入，即在單執行緒中不能對兩個源字串交替呼叫該函數來分析token，應當對一個字串分析完成後再處理別的字串。
size_t strxfrm(char *dest, const char *src, size_t n);	根據當前locale轉換一個字串為strcmp使用的內部格式

#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello, World!";
    char str2[20];

    // 將 str1 中的內容複製到 str2
    memmove(str2, str1, strlen(str1) + 1);

    // 在屏幕上輸出結果
    printf("複製後的字符串：%s\n", str2);

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello";

    // 比較兩個字符串
    int result = memcmp(str1, str2, sizeof(str1));

    if (result == 0) {
        printf("字符串相等。\n");
    } else if (result < 0) {
        printf("字符串 str1 小於字符串 str2。\n");
    } else {
        printf("字符串 str1 大於字符串 str2。\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char dest[20] = "Hello, ";
    const char src[] = "World!";

    // 連接兩個字符串
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);

    // 在屏幕上輸出結果
    printf("連接後的字符串：%s\n", dest);

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    const char *str1 = "apple";
    const char *str2 = "orange";

    // 使用 strcoll 比較兩個字符串
    int result = strcoll(str1, str2);

    if (result < 0) {
        printf("%s 在 %s 之前。\n", str1, str2);
    } else if (result > 0) {
        printf("%s 在 %s 之後。\n", str1, str2);
    } else {
        printf("%s 與 %s 相等。\n", str1, str2);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "123abc456";
    const char *charSet = "1234567890";

    // 計算字符串開頭包含在字符集中的字符數
    size_t length = strspn(str, charSet);

    printf("前綴中包含在字符集中的字符數：%zu\n", length);

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    const char *haystack = "Hello, World!";
    const char *needle = "World";

    // 在 haystack 中尋找 needle 的第一次出現
    char *result = strstr(haystack, needle);

    if (result != NULL) {
        printf("找到匹配的子字符串：%s\n", result);
    } else {
        printf("未找到匹配的子字符串。\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "apple,orange,banana";
    const char delimiters[] = ",";

    // 第一次調用
    char *token = strtok(str, delimiters);

    // 循環調用直到找不到更多的分隔符
    while (token != NULL) {
        printf("子字符串：%s\n", token);

        // 下一次調用
        token = strtok(NULL, delimiters);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    const char *src = "apple";
    char dest[20];

    // 使用 strxfrm 將源字符串轉換並存儲到目標字符串
    size_t length = strxfrm(dest, src, sizeof(dest));

    // 在屏幕上輸出轉換後的字符串和長度
    printf("轉換後的字符串：%s\n", dest);
    printf("轉換後的字符串長度：%zu\n", length);

    return 0;
}


