#include <stdio.h>

int mdays[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                   {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int isleap(int year) {
  return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int day_of_year(int year, int month, int day) {
  int i;
  int days;

  days = day;
  for (i = 1; i < month; i++)
    days += mdays[isleap(year)][i - 1];
  return (days);
}

int main(void) {
  int year, month, day;
  int retry;

  do {
    printf("年 : ");
    scanf("%d", &year);
    printf("月 : ");
    scanf("%d", &month);
    printf("日 : ");
    scanf("%d", &day);

    printf("年内で%d 日目です。\n", day_of_year(year, month, day));

    printf("もう一度しますか? (1 --- はい /2 --- いいえ) : ");
    scanf("%d", &retry);
  } while (retry == 1);

  return (0);
}
