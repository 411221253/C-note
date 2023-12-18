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
