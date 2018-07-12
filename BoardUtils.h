// Board Utilities 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
using namespace std;

typedef struct Board
{
	int **table;
	int available;
	int n;
};
//Funtions

Board * createBoard();
void printBoard(Board board);
Board * generateRandom2(Board * board);
// creating Board

Board * createBoard()
{
	printf("Enter n for nxn board\n");
	int n;
	scanf_s("%d", &n);
	fflush(stdin);

	Board *board = (Board *)calloc(n, sizeof(Board ));
	board->n = n;
	board->table = (int **)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		board->table[i] = (int  *)calloc(n, sizeof(int));
	board = generateRandom2(board);
	board->available = n * n - 2;
	printBoard(*board);
	return board;
}

int checkAvailable(Board * board)
{
	int count = 0;
	for (int i = 0; i < board->n; i++)
		for (int j = 0; j < board->n; j++)
			if (board->table[i][j] == 0)
				count++;
	return count;
}
void printBoard( Board board)
{
	system("CLS");
	for (int r = 0; r < board.n; r++)

	{
		for (int c = 0; c < board.n; c++)
		{
			printf("|____%d____", board.table[r][c]);
		}
		printf("|\n");
	}
	fflush(stdin);
}
int checkWin(Board * board, int * arr, int n)
{
	int N = 2 * n * n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		if (arr[N - 1] == board->table[i][j])
				return 1;
	//return checkAvailable(board);
	return 0;
}
Board * generateRandom2(Board * board)
{
	int count = 2;
	srand(time(NULL));
		while(count--)
		{
			int x = rand() % board->n;
			int y = rand() % board->n;
			board->table[x][y] = 1;
		}
		return board;
}