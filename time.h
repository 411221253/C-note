int tm_hour	小時 (0 – 23)
int tm_isdst	夏令時啟用 (> 0)、禁用 (= 0)、未知 (< 0)
int tm_mday	一月中的哪一天 (1 – 31)
int tm_min	分 (0 – 59)
int tm_mon	月 (0 – 11, 0 = 一月)
int tm_sec	秒 (0 – 60, 60 = 閏秒)
int tm_wday	一周中的哪一天 (0 – 6, 0 = 周日)
int tm_yday	一年中的哪一天 (0 – 365)
int tm_year	1900 以來的年數

time_t time(time_t* timer)
得到從標準計時點（一般是UTC 1970年1月1日午夜）到當前時間的秒數。

#include <stdio.h>
#include <time.h>

int main() {
    // 獲取當前時間
    time_t current_time = time(NULL);

    // 在屏幕上輸出當前時間
    printf("當前時間（自 1970 年 1 月 1 日以來的秒數）：%lld\n", (long long)current_time);

    return 0;
}

clock_t clock(void)
得到從行程啟動到此次函數呼叫的累計的時鐘滴答數。

#include <stdio.h>
#include <time.h>

int main() {
    // 記錄開始時鐘時間
    clock_t start_time = clock();

    // 這裡放入需要測量執行時間的代碼
    for (int i = 0; i < 1000000; ++i) {
        // 一些計算
    }

    // 記錄結束時鐘時間
    clock_t end_time = clock();

    // 計算執行時間
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // 在屏幕上輸出執行時間
    printf("代碼執行時間：%f 秒\n", elapsed_time);

    return 0;
}

char *asctime(const struct tm* tmptr)
把分解時間tm輸出到字串，結果的格式為"Www Mmm dd hh:mm:ss yyyy"，即「周幾 月份數 日數 小時數:分鐘數:秒鐘數 年份數」。函數返回的字串為靜態分配，長度不大於26，與ctime函數共享。函數的每次呼叫將覆蓋該字串內容。

  #include <stdio.h>
#include <time.h>

int main() {
    // 獲取當前時間
    time_t current_time;
    time(&current_time);

    // 轉換為本地時間結構體
    struct tm *local_time = localtime(&current_time);

    // 使用 asctime 函式將 struct tm 轉換為字符串
    char *time_string = asctime(local_time);

    // 在屏幕上輸出時間字符串
    printf("當前時間：%s", time_string);

    return 0;
}
  
char* ctime(const time_t* timer)
把日曆時間time_t timer輸出到字串，輸出格式與asctime函數一樣.

  #include <stdio.h>
#include <time.h>

int main() {
    // 獲取當前時間
    time_t current_time;
    time(&current_time);

    // 使用 ctime 函式將 time_t 轉換為字符串
    char *time_string = ctime(&current_time);

    // 在屏幕上輸出時間字符串
    printf("當前時間：%s", time_string);

    return 0;
}

size_t strftime(char* s, size_t n, const char* format, const struct tm* tptr)
把分解時間tm轉換為自訂格式的字串，類似於常見的字串格式輸出函數sprintf。例如：strftime(buf, 64, "%Y-%m-%d %H:%M:%S", localtime);

#include <stdio.h>
#include <time.h>

int main() {
    // 獲取當前時間
    time_t current_time;
    time(&current_time);

    // 轉換為本地時間結構體
    struct tm *local_time = localtime(&current_time);

    // 按照指定格式轉換時間為字符串
    char time_string[100];
    size_t length = strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);

    // 在屏幕上輸出格式化後的時間字符串
    printf("格式化後的時間：%s\n", time_string);

    return 0;
}


char * strptime(const char* buf, const char* format, struct tm* tptr)
strftime的逆操作，把字串按照自訂的格式轉換為分解時間tm。

#include <stdio.h>
#include <time.h>

int main() {
    const char *input_string = "2022-01-07 15:30:00";
    const char *format = "%Y-%m-%d %H:%M:%S";

    // 初始化 struct tm 結構體
    struct tm parsed_time = {0};

    // 使用 strptime 函式解析時間字符串
    char *result = strptime(input_string, format, &parsed_time);

    // 檢查解析結果
    if (result != NULL) {
        printf("解析成功，解析後的時間：%d-%02d-%02d %02d:%02d:%02d\n",
               parsed_time.tm_year + 1900, parsed_time.tm_mon + 1, parsed_time.tm_mday,
               parsed_time.tm_hour, parsed_time.tm_min, parsed_time.tm_sec);
    } else {
        printf("解析失敗。\n");
    }

    return 0;
}

double difftime(time_t timer2, time_t timer1)
比較兩個日曆時間之差。

#include <stdio.h>
#include <time.h>

int main() {
    // 獲取兩個時間點
    time_t start_time, end_time;
    time(&start_time);

    // 在這裡放入需要測量執行時間的代碼
    for (int i = 0; i < 1000000; ++i) {
        // 一些計算
    }

    // 獲取結束時間
    time(&end_time);

    // 計算時間差
    double elapsed_time = difftime(end_time, start_time);

    // 在屏幕上輸出時間差
    printf("執行時間：%f 秒\n", elapsed_time);

    return 0;
}

//
# include <stdio.h>
# include <time.h>

int main(void)
{
    time_t  timer = time(NULL);
    printf("ctime is %s\n", ctime(&timer));
    return 0;
}
