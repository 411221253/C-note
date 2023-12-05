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






