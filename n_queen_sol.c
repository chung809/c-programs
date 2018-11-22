#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int board[15], count = 0;

//function for printing the solution
void print(int n)
{
    int i, j;

    printf("Solution %d:\n", ++count);

    for (i = 0; i <= n; i++) {
	for (j = 0; j <= n; j++) {	//for nxn board
	    if (board[i] == j)
		printf("X");		//queen at i,j position
	    else
		printf("O");		//empty slot
	}
	printf("\n");
    }
}

/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row, int column)
{
    int i;
    for (i = 0; i <= row - 1; i++) {
	//checking column and digonal conflicts
	if (board[i] == column) {
	    return 0;
	} else if (abs(board[i] - column) == abs(i - row)) {
	    return 0;
	}
    }

    return 1;
}

//function to check for proper positioning of queen
void queen(int row, int n)
{
    int column;
    for (column = 0; column <= n; column++) {
	if (place(row, column)) {
	    board[row] = column;	//no conflicts so place queen
	    if (row == n)		//dead end
		print(n);		//printing the board configuration
	    else			//try queen with next position
		queen(row + 1, n);
	}
    }
}

int main()
{
    int n, i, j;
    void queen(int row, int n);
    for (i = 0; i < 15; i++)
        board[i] = -1;
    scanf("%d", &n);
    if (n < 15)
        queen(0, n - 1);
    return 0;
}

