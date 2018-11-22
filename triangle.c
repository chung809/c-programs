#include <stdio.h>

#define ARRAY_ROW 100 /* 三角形最大高度 */
#define ARRAY_COL 202
#define ASCII_A	65
static char array[ARRAY_ROW][ARRAY_COL];


void inverted_v(char ascii, int order, int begin)
{
	int i, j, k, l;
	for (i = 0, j = order; i < order - begin; i++, j--) {
		array[i + begin][j]=ascii;
		array[i + begin][order + i]=ascii;
		
		if (!begin) {
			/* 如果begin是0,則在二維陣列每行結束時增加linefeed('\n')及字串結束字元('\0')*/
			array[i + begin][order + i + 1]='\n';
			array[i + begin][order + i + 2]='\0';
		}
	}
	return;
}

int main()
{
	int order;

	scanf("%d", &order);
	
	int i, j;

	/* 先將array填入空白 */
	for (i = 0; i < order; i++) {
		for (j = 0; j < ARRAY_COL; j++) {
			array[i][j] = ' ';
		}
	}

	/* 根據order計算要填幾個"倒V"到array*/		
	for (i = 0; i < (order / 2 + order % 2); i++) {
		inverted_v((char)(ASCII_A + i), order, 2 * i);
	}

	/* 將array內容印出就是所要的三角形 */
	for (i = 0; i < order; i++) {
		printf("%s", array[i]);
	}
	
	return 0;
}
