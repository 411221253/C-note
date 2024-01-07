ptrdiff_t 有符號整數型

#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr1 = &arr[2];
    int *ptr2 = &arr[4];

    // 使用指標差異計算偏移量
    ptrdiff_t offset = ptr2 - ptr1;

    printf("偏移量：%td\n", offset);

    return 0;
}

size_t 無符號整數型

#include <stdio.h>

int main() {
    // 使用 size_t 表示陣列的大小
    int arr[] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(arr) / sizeof(arr[0]);

    printf("陣列的大小：%zu\n", array_size);

    // 使用 size_t 表示字符串的長度
    const char *str = "Hello, World!";
    size_t string_length = 0;

    while (str[string_length] != '\0') {
        string_length++;
    }

    printf("字符串的長度：%zu\n", string_length);

    return 0;
}

wchar_t 16位元或32位元整數型

#include <stdio.h>
#include <wchar.h>

int main() {
    // 使用 wchar_t 表示寬字符
    wchar_t wide_char = L'東';

    // 使用 wprintf 函式輸出寬字符
    wprintf(L"寬字符：%lc\n", wide_char);

    return 0;
}
