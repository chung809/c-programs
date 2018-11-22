#include <stdio.h>

int SpiralMatrix[100][100];

int main()
{
	int order, square_order;
	int i = 0, j = 0, inc = 1, counter = 0;
        
        /* Initialize SpiralMatrix to 0 */
	for(i = 0; i < 100; i++)
		for(j = 0; j < 100; j++)
			SpiralMatrix[i][j] = 0;

	i = j = 0;

	scanf("%d", &order);
	square_order = order * order;
	while (inc <= square_order) {
		counter++;
		if (counter > square_order)
			break;
		/* go right */
		while ((i < order) && (j < order) && (SpiralMatrix[i][j] == 0)) {
			SpiralMatrix[i][j++] = inc++;
                        //printf("SpiralMatrix[%d][%d]=%d\n", i, j-1, SpiralMatrix[i][j-1]);
		}
		j--;
		i++;
		/* go down */
		while ((i < order) && (j < order) && (SpiralMatrix[i][j] == 0)) {
			SpiralMatrix[i++][j] = inc++;
			//printf("SpiralMatrix[%d][%d]=%d\n", i-1, j, SpiralMatrix[i-1][j]);
		}
		i--;
		if (j < 0)
			j = 0;
		else		
			j--;
		/* go left */
		while ((j >= 0) && (j < order) && (SpiralMatrix[i][j] == 0)) {
			SpiralMatrix[i][j--] = inc++;
			//printf("SpiralMatrix[%d][%d]=%d\n", i, j+1, SpiralMatrix[i][j+1]);
		}
		if (j < 0)
			j = 0;
		else
			j++;
		i--;
		/* go up */
		while ((i > 0) && (i < order) && (SpiralMatrix[i][j] == 0)) {
			SpiralMatrix[i--][j] = inc++;
			//printf("SpiralMatrix[%d][%d]=%d\n", i+1, j, SpiralMatrix[i+1][j]);
		}
		i++;
		j++;
	}
	for (i = 0; i < order; i++) {
		for (j = 0; j < order; j++) {
			printf("%4d", SpiralMatrix[i][j]);
		}
		printf("\n");
	}
}
	
			
