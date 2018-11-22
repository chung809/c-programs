#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char OnesDigits[10][10] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight",
    "nine", "ten"
};
int OnesDigits_num[10] = { 3, 3, 5, 4, 4, 3, 5, 5, 4, 3 };

int OnesDigits_flag = 0;
char TensDigits[8][10] = {
    "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty",
    "ninety"
};
int TensDigits_num[8] = { 6, 6, 5, 5, 5, 7, 6, 6 };

int TensDigits_flag = 0;
char Teens[9][15] = {
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen"
};
int Teens_num[9] = { 6, 6, 8, 8, 7, 7, 9, 8, 8 };
int Teens_value[9] = { 11, 12, 13, 14, 15, 16, 17, 18, 19 };

int Teens_flag = 0;

int main()
{

    int i = 0, sum = 0;

    int j, k, total;

    char input_num[50000][50];


    while (scanf("%s", input_num[i]) != EOF) {

        i++;

    }

    total = i;

    for (i = 0; i < total; i++) {

        /* Test tens digits */
        for (j = 0; j < 8; j++) {

            if (strncasecmp
                    (input_num[i], TensDigits[j], TensDigits_num[j]) == 0) {

                char *test;

                int test_flag = 0;

                test = strchr(input_num[i], '-');

                if (test) {

                    for (k = 0; k < 10; k++) {

                        if (strncasecmp
                                (test + 1, OnesDigits[k],
                                 OnesDigits_num[k]) == 0) {

                            sum = sum + k + 1;

                            test_flag = 1;

                        }

                    }

                }

                if (test_flag) {

                    sum = sum + j * 10 + 20;

                }

                TensDigits_flag = 1;

                break;

            }

        }

        if (TensDigits_flag) {

            TensDigits_flag = 0;

            continue;

        }

        /* Test teens */
        for (j = 0; j < 9; j++) {

            if (strncasecmp(input_num[i], Teens[j], Teens_num[j]) == 0) {

                char *test;

                test = strchr(input_num[i], '-');

                if (test == NULL) {

                    sum = sum + Teens_value[j];

                }

                Teens_flag = 1;

                break;

            }

        }

        if (Teens_flag) {

            Teens_flag = 0;

            continue;

        }

        /* Test ones digits */
        for (j = 0; j < 10; j++) {

            if (strncasecmp
                    (input_num[i], OnesDigits[j], OnesDigits_num[j]) == 0) {

                char *test;

                test = strchr(input_num[i], '-');

                if (test == NULL) {

                    sum = sum + j + 1;

                }

                OnesDigits_flag = 1;

                break;

            }

        }

        if (OnesDigits_flag) {

            OnesDigits_flag = 0;

            continue;

        }

    }

    printf("%d\n", sum);

    return 0;
}


