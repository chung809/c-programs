#include <stdio.h> 

void print_matrix(int *matrix, int row, int col)
{
	int c, r;
	for (r = 0; r < row; r++) {
		for (c = 0; c < col ; c++) {
			printf("%8d ", *(matrix + r * row + c));
		}
		printf("\n");
	}
}

int matrix_power(int *matrix, int row, int col, int power)
{
	int i, c, r, c_step;
	int sum = 0;
	int matrix_array[row][col], tmp[row][col];
	int result[row][col];
	
	for (r = 0; r < row; r++)
		for (c = 0; c < col ; c++)
			matrix_array[r][c] = tmp[r][c] = *(matrix + r * row + c);
	for (int i = 0; i < (power - 1); i++) {
		for (r = 0; r < row; r++) {
			for (c = 0; c < col; c++) {
		                for (c_step = 0; c_step < col ; c_step++ ) {
                    			sum += matrix_array[r][c_step] * tmp[c_step][c];
				}
				result[r][c] = sum;
				sum = 0;
			}
        	}
		for (r = 0; r < row; r++) {
			for (c = 0; c < col ; c++) {
				matrix_array[r][c] = result[r][c];
				result[r][c] = 0;
			}
		} 
	}
	for (r = 0; r < row; r++) {
		for (c = 0; c < col ; c++) {
			*(matrix + r * row + c) = matrix_array[r][c];
		}
	}
	return 0;
}

int main()
{
	int rol, col, i, p;
	
	scanf("%d", &i);
	int a[i][i];

	for (rol = 0; rol < i; rol++)
		for (col = 0; col < i; col++)
			scanf("%d", &a[rol][col]);
	scanf("%d", &p);
	print_matrix((int*)a, i, i);
	matrix_power((int*)a, i, i, p);
	print_matrix((int*)a, i, i);
	return 0;
}
