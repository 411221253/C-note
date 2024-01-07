//math.h
//平方根sqrt

#include <stdio.h>
#include <math.h>

int sqrt(){
  double num;
  scanf("%lf", &num);
  double squareRoot = sqrt(num);
  printf("%lf\n", squareRoot);
  return 0;
}

//abs

int abs(){
  int num;
  scanf("%d", &num);
  int ans = abs(num);
  printf("%d", ans);
  return 0;
}

double modf(double, double *);	將參數的整數部分通過指針回傳，返回小數部分
double fmod(double, double);	返回兩參數相除的餘數

#include <stdio.h>
#include <math.h>

int main() {
    double input = 123.456;
    double fractionalPart;

    // 呼叫 modf 函式
    double integerPart = modf(input, &fractionalPart);

    // 輸出結果
    printf("原始數字：%lf\n", input);
    printf("整數部分：%lf\n", integerPart);
    printf("小數部分：%lf\n", fractionalPart);

    return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
    double dividend = 10.5;
    double divisor = 3.2;

    // 呼叫 fmod 函式
    double remainder = fmod(dividend, divisor);

    // 輸出結果
    printf("被除數：%lf\n", dividend);
    printf("除數：%lf\n", divisor);
    printf("餘數：%lf\n", remainder);

    return 0;
}

double exp(double);	指數函數
double sqrt(double);	開平方根
double log(double);	自然對數
double log10(double);	常用對數
double pow(double, double);	計算 x^y
float powf(float, float);	功能等同於 pow()，只是輸入參數與輸出參數皆為單浮點數

#include <stdio.h>
#include <math.h>

int main() {
    float base = 2.5;
    float exponent = 3.0;

    // 呼叫 powf 函式
    float result = powf(base, exponent);

    // 輸出結果
    printf("%f 的 %f 次方為 %f\n", base, exponent, result);

    return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
    double number = 5.0;

    // 呼叫 log 函式
    double result = log(number);

    // 輸出結果
    printf("自然對數 %f 的結果為 %f\n", number, result);

    return 0;
}

double poly(double x, int degree, double coeffs [] );	計算多項式

#include <stdio.h>

double poly(double x, int degree, double coeffs[]) {
    double result = 0.0;

    for (int i = 0; i <= degree; i++) {
        result += coeffs[i] * pow(x, degree - i);
    }

    return result;
}

int main() {
    // 例如，計算多項式 2x^3 + 3x^2 - 4x + 1 在 x = 2 的值
    double coefficients[] = {2.0, 3.0, -4.0, 1.0};
    int degree = 3;
    double x = 2.0;

    double result = poly(x, degree, coefficients);

    printf("多項式的值為：%lf\n", result);

    return 0;
}
