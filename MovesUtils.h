
int left(Board * board, int * arr);
int right(Board * board, int * arr);
int up(Board * board, int * arr);
int down(Board * board, int * arr);

Board * ProcessInput(Board * board, int * arr, char letter);

int isValidInput(char letter)
{
	if (letter == 'a' || letter == 's' || letter == 'd' || letter == 'w' || letter == 'z'
		|| letter == 'A' || letter == 'S' || letter == 'D' || letter == 'W' || letter == 'Z')
		return 1;
	else
		return 0;
}
void generateRandom(Board * board)
{
	if (checkAvailable(board))
	{
		int x, y;
		srand(time(NULL));
		x = rand() % board->n;
		y = rand() % board->n;
		while (board->table[x][y] != 0)
		{
			x = rand() % board->n;
			y = rand() % board->n;
		}
		board->table[x][y] = 1;
		board->available = board->available - 1;
	}
}
void takeInput(Board * board, int * arr)
{
	char  inpt;
	scanf_s("%c", &inpt);
	if (isValidInput(inpt))
	{
		ProcessInput(board, arr, inpt);
		generateRandom(board);
		board->available = checkAvailable(board);
		//printBoard(*board);
	}
}

Board * ProcessInput(Board * board, int * arr, char letter)
{
	if (letter == 'a' || letter == 'A')
		left(board, arr);
	if (letter == 'd' || letter == 'D')
		right(board, arr);
	if (letter == 's' || letter == 'S')
		down(board, arr);
	if (letter == 'w' || letter == 'W')
		up(board, arr);
	return NULL;
}

void playMove(Board * board, User * user, char letter)
{

}
void del_row_entry_left(Board *board)
{
	int i, j, x, k;
	for (i = 0; i < board->n; i++)
	{
		for (j = 0; j < board->n; j++)
		{
			if (board->table[i][j] == 0)
			{
				for (k = j + 1; k < board->n; k++)
				{
					board->table[i][k - 1] = board->table[i][k];
				}
				board->table[i][k - 1] = -1;
				j = j - 1;
			}
		}
	}
	for (i = 0; i < board->n; i++)
	{
		for (j = 0; j < board->n; j++)
		{
			if (board->table[i][j] == -1)
			{
				board->table[i][j] = 0;
			}
		}
	}
}
void del_row_entry_right(Board *board)
{
	int i, j, x, k;
	for (i = 0; i < board->n; i++)
	{
		for (j = board->n - 1; j >= 0; j--)
		{
			if (board->table[i][j] == 0)
			{
				for (k = j - 1; k >= 0; k--)
				{
					board->table[i][k + 1] = board->table[i][k];
				}
				board->table[i][0] = -1;
				j = j + 1;
			}
		}
	}
	for (i = 0; i < board->n; i++)
	{
		for (j = 0; j < board->n; j++)
		{
			if (board->table[i][j] == -1)
			{
				board->table[i][j] = 0;
			}
		}
	}
}
void del_col_entry_up(Board *board)
{
	int i, j, x, k;
	for (i = 0; i < board->n; i++)
	{
		for (j = 0; j < board->n; j++)
		{
			if (board->table[j][i] == 0)
			{
				for (k = j + 1; k < board->n; k++)
				{
					board->table[k - 1][i] = board->table[k][i];
				}
				board->table[k - 1][i] = -1;
				j--;
			}
		}
	}
	for (i = 0; i < board->n; i++)
	{
		for (j = 0; j < board->n; j++)
		{
			if (board->table[i][j] == -1)
			{
				board->table[i][j] = 0;
			}
		}
	}
}
void del_col_entry_down(Board *board)
{
	int i, j, x, k;
	for (i = 0; i < board->n; i++)
	{
		for (j = board->n - 1; j >= 0; j--)
		{
			if (board->table[j][i] == 0)
			{
				for (k = j - 1; k >= 0; k--)
				{
					board->table[k + 1][i] = board->table[k][i];
				}
				board->table[0][i] = -1;
				j++;
			}
		}
	}
	for (i = 0; i < board->n; i++)
	{
		for (j = 0; j < board->n; j++)
		{
			if (board->table[i][j] == -1)
			{
				board->table[i][j] = 0;
			}
		}
	}
}
int left(Board * board, int * arr)
{
	del_row_entry_left(board);
	int i, j,x;
	for (i = 0; i < board->n; i++)
	{
		for (j = 0; j <= board->n-2; j++)
		{
			x = board->table[i][j] + board->table[i][j + 1];
			if (binary_search(arr, arr + 32, x))
			{
				board->table[i][j] = x;
				board->table[i][j + 1] = 0;
			}
		}
	}
	del_row_entry_left(board);
	printBoard(*board);
	return 0;
}
int right(Board * board, int * arr)
{
	del_row_entry_right(board);
	int i, j, x;
	for (i = 0; i < board->n; i++)
	{
		for (j = 0; j <= board->n - 2; j++)
		{
			x = board->table[i][j] + board->table[i][j + 1];
			if (binary_search(arr, arr + 32, x))
			{
				board->table[i][j] = 0;
				board->table[i][j + 1] = x;
			}
		}
	}
	del_row_entry_right(board);
	printBoard(*board);
	return 0;
}
int up(Board * board, int * arr)
{
	del_col_entry_up(board);
	int i, j, x;
	for (i = 0; i < board->n -1; i++)
	{
		for (j = 0; j < board->n ; j++)
		{
			x = board->table[i][j] + board->table[i+1][j];
			if (binary_search(arr, arr + 32, x))
			{
				board->table[i+1][j] = 0;
				board->table[i][j] = x;
			}
		}
	}
	del_col_entry_up(board); 
	printBoard(*board);
	return 0;
}
int down(Board * board, int * arr)
{
	del_col_entry_down(board);
	int i, j, x;
	for (i = 0; i < board->n - 1; i++)
	{
		for (j = 0; j < board->n; j++)
		{
			x = board->table[i][j] + board->table[i + 1][j];
			if (binary_search(arr, arr + 32, x))
			{
				board->table[i][j] = 0;
				board->table[i+1][j] = x;
			}
		}
	}
	del_col_entry_down(board);
	printBoard(*board);
	return 0;
}