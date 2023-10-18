#include <stdio.h>

int main()
{
  struct Coordinates
  {
    int x;
    int y;
    int z;
  };
  int i, j, m, n, s, f;
  int a;
  int chess[8][8];
  s = 0;
  f = 0;
  struct Coordinates list[9];

  //輸入棋盤狀態
  for(m = 0;m < 8;m = m + 1)
  {
    for(n = 0;n < 8;n = n + 1)
    {
      scanf("%d", &chess[m][n]);
    }
  }

  //輸入指定座標，判斷該座標狀態
  scanf("%d,%d", &i, &j);
  if(chess[i][j] == 0)
  {
    printf("不能下");
  }
  else if(chess[i][j] == 1)
  {
    printf("[%d,%d] = 1,是黑棋", i, j);
  }
  else if(chess[i][j] == 2)
  {
    printf("[%d,%d] = 2,是白棋", i, j);
  }

  //判斷8方位相鄰是否為異色棋子，將其座標存入list
  for(m = -1;m < 2;m = m + 1)
  {
    for(n = -1;n < 2;n = n + 1)
    {
      s = s + 1;
      if(chess[m][n] == 0 || chess[m][n] == chess[i][j])
      {
        break;
      }
      else if(chess[m][n] - chess[i][j] != 0)
      {
        list[s].x = m;
        list[s].y = n;
        list[s].z = s;
        f = f + 1;
      }
    }
  }

  //取出剛8方位中是異色棋子的座標，開始向其方向延伸出去至該座標狀態為空格時輸出該座標
  for(a = 0;a < s;a = a + 1)
  {
    switch (list[a].z)
    {
      case 1:
        for(m = (i - 2);m > 0;m = m - 1)
        {
          for(n = (j - 2);n > 0;n = n - 1)
          {
            if(chess[m][n] == 0)
            {
              printf("(%d,%d) ", m, n);
            }
          }
        }
        break;
      case 2:
        for(m = (i - 2);m > 0;m = m - 1)
        {
          if(chess[m][n] == 0)
          {
            printf("(%d,%d) ", m, j);
          }
        }
        break;
      case 3:
        for(m = (i - 2);m > 0;m = m - 1)
        {
          for(n = (j + 2);n < 9;n = n + 1)
          {
            if(chess[m][n] == 0)
            {
              printf("(%d,%d) ", m, n);
            }
          }
        }
        break;
      case 4:
        for(n = (j - 2);m > 0;n = n - 1)
        {
          if(chess[m][n] == 0)
          {
            printf("(%d,%d) ", i, n);
          }
        }
        break;
      case 6:
        for(n = (j + 2);m < 9;n = n + 1)
        {
          if(chess[m][n] == 0)
          {
            printf("(%d,%d) ", i, n);
          }
        }
        break;
      case 7:
        for(m = (i + 2);m < 9;m = m + 1)
        {
          for(n = (j - 2);n > 0;n = n - 1)
          {
            if(chess[m][n] == 0)
            {
              printf("(%d,%d) ", m, n);
            }
          }
        }
        break;
      case 8:
        for(m = (i + 2);m < 9;m = m + 1)
        {
          if(chess[m][n] == 0)
          {
            printf("(%d,%d) ", m, j);
          }
        }
        break;
      case 9:
        for(m = (i + 2);m < 9;m = m + 1)
        {
          for(n = (j + 2);n > 9;n = n + 1)
          {
            if(chess[m][n] == 0)
            {
              printf("(%d,%d) ", m, n);
            }
          }
        }
        break;
    }
  }

  //在輸出座標後，於句子最後補上可以下，若沒有點可以下則輸出不能下
  if(f > 0)
  {
    printf("可以下");
  }
  else
  {
    printf("沒有地方可以下");
  }
  return 0;
}
