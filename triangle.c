#include <stdio.h>

#define ARRAY_ROW 100 /* �T���γ̤j���� */
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
			/* �p�Gbegin�O0,�h�b�G���}�C�C�浲���ɼW�[linefeed('\n')�Φr�굲���r��('\0')*/
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

	/* ���Narray��J�ť� */
	for (i = 0; i < order; i++) {
		for (j = 0; j < ARRAY_COL; j++) {
			array[i][j] = ' ';
		}
	}

	/* �ھ�order�p��n��X��"��V"��array*/		
	for (i = 0; i < (order / 2 + order % 2); i++) {
		inverted_v((char)(ASCII_A + i), order, 2 * i);
	}

	/* �Narray���e�L�X�N�O�ҭn���T���� */
	for (i = 0; i < order; i++) {
		printf("%s", array[i]);
	}
	
	return 0;
}
