#include <stdio.h>
#include <string.h>

char tmp[1024];

char *dec2bin(int i)
{
	int c, t, len;
	unsigned int d;
	char *r;

	t = 0;
	r=tmp;
	len = sizeof(int) * 8;
	for (c=0; c < len; c++) {
		t = 0x80000000 & (i << c);
		d = (unsigned int)t >> (len - 1);
		sprintf(r++, "%1u", d);
	}
	return tmp;	
}

int main()
{
	int m, n, i, j;
	int ceiling;

	scanf("%d %d", &m, &n);
	ceiling = (m * n) / 32;	
	ceiling += (m * n) % 32?1:0;

	char *bitmap[ceiling];
	int dec_num[ceiling];
	char remap_tmp[1024];
	char remap[n][m + 1];

	for (i = 0; i < ceiling; i++) {
		scanf("%d", &dec_num[i]);
	}
	for (i = 0; i < ceiling; i++) {
		bitmap[i] = dec2bin(dec_num[i]);
		strcpy(remap_tmp + i*32, bitmap[i]);
	}
	//printf("(%p)%s\n", remap_tmp, remap_tmp);
	
	for (i = 0; i < n; i++) {
		memset(remap[i], '\0', m + 1);
		strncpy(remap[i], &remap_tmp[i * m], m);
		remap[i][m + 1] = 0;
		printf("%s\n", remap[i]);
	}	
	return 0;
}