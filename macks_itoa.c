#include <math.h>
#include <stdlib.h>
#include <stdio.h>

char * itoa(int num) {
  if (num == 0) {
    return "0";
  }

  int sign = 0;
  if (num >= 0) {
    sign = 1;
  } else {
    num = -num;
  }

  int highest_power_of_ten_less_than_num = 0;
  while (pow(10,highest_power_of_ten_less_than_num) <= num) {
    highest_power_of_ten_less_than_num++;
  }
  highest_power_of_ten_less_than_num--;
  char * ans = calloc(highest_power_of_ten_less_than_num+1,1);

  int power = highest_power_of_ten_less_than_num;
  int multiplier = 1;
  int highest = pow(10,power)*multiplier;

  int i = 0;

  if (sign == 0) {
    ans[i] = '-';
    i++;
  }

  while (power >= 0) {
    highest = 0;
    multiplier = 0;
    while (highest <= num) {                  /* first get our highest multiplier and amt to subtract */
      multiplier++;                           /* in eg 1024 we would want multiplier to be 10 and highest to be 1000 */
      highest = pow(10,power)*multiplier;
    }

    if (highest > num) {                      /* ONLY IF we have gone OVER do we want to go back under again */ 
      multiplier--;
      highest -= pow(10,power);
    }
 
    ans[i] = (char) multiplier + 48;

    num -= highest;
    
    power--;
    i++;
  }
  ans[i] = '\0';

  return ans;
}

int main() {
  printf("My itoa returns %s for 234\n",itoa(234));
  printf("My itoa returns %s for 10\n",itoa(10));
  printf("My itoa returns %s for 100035\n",itoa(100035));
  printf("My itoa returns %s for -8\n",itoa(-8));
  printf("My itoa returns %s for -120\n",itoa(-120));
  printf("My itoa returns %s for 0\n",itoa(0));
  return 0;
}
