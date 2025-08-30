#include <stdio.h>

typedef struct {
  int year;
  int month;
  int day;
} YMD;

YMD before(YMD x, int n);
YMD after(YMD x, int n);

const int mdays[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                         {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int isleap(int year);
int day_of_year(int year, int month, int day);

int main(void) {
  int n;
  YMD date = {.year = 0, .month = 0, .day = 0};
  YMD result;
  printf("年 : ");
  scanf("%d", &date.year);
  printf("月 : ");
  scanf("%d", &date.month);
  printf("日 : ");
  scanf("%d", &date.day);

  printf("何日後？ : ");
  scanf("%d", &n);

  result = after(date, n);
  printf("入力された日付の%d日後は %d年 %d月 %d日です。 \n", n, result.year,
         result.month, result.day);

  printf("何日前? : ");
  scanf("%d", &n);

  result = before(date, n);
  printf("入力された日付の%d日前は %d年 %d月 %d日です。\n", n, result.year,
         result.month, result.day);
}

int isleap(int year) {
  return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int day_of_year(int year, int month, int day) {

  while (--month > 0)
    day += mdays[isleap(year)][month - 1];

  return day;
}

YMD before(YMD x, int n) {
  int year = x.year;
  int month = x.month;
  int day = x.day;
  YMD newdate;

  while (n > 0) {
    day--;
    if (day <= 0) {
      month--;
      if (month > 0) {
        day = mdays[isleap(year)][month - 1];
      } else {
        year--;
        month = 12;
        day = mdays[isleap(year)][month - 1];
      }
    }
    n--;
  }

  newdate.year = year;
  newdate.month = month;
  newdate.day = day;

  return newdate;
}

YMD after(YMD x, int n) {
  int year = x.year;
  int month = x.month;
  int day = x.day;

  YMD newdate;
  int day_of_month = mdays[isleap(year)][month - 1];

  while (n > 0) {
    day++;
    if (day > day_of_month) {
      month++;
      day = 1;
      if (month < 13)
        day_of_month = mdays[isleap(year)][month - 1];
    }
    if (month > 12) {
      year++;
      month = 1;
      day_of_month = mdays[isleap(year)][month - 1];
    }
    n--;
  }

  newdate.year = year;
  newdate.month = month;
  newdate.day = day;

  return newdate;
}
