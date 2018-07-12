//__author__ = Sheetansh
//Main Function

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "BoardUtils.h"
#include "UserUtils.h"
#include "MovesUtils.h"

using namespace std;

int * FibboSeries(int n)

{
	int N = 2 * n * n;
	//N = 3;
	int * arr = (int *)malloc(sizeof(int)*N);
	int a = 0, b = 1;
	int count = 0;
	arr[count++] = a;
	arr[count++] = b;
	while (count < N)
	{
		arr[count] = a + b;
		a = b;
		b = arr[count++];
	}
	/*for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	cin.get();*/
	return arr;
}

int main()
{
	//createUser();
	User * nu = createUser();
	Board* nb = createBoard();
	//User * nu = createUser();
	//printf("%s\n", nu->name);
	//cin.get();//*/
	int * arr = FibboSeries(nb->n);
	srand(time(NULL));
	while (checkWin(nb, arr, nb->n) == 0)
	{
		printf("User : %s \t\t Moves : %d \n\n", nu->name, nu->movesCount);
		printf("Enter input : ");
		takeInput(nb, arr);
		printBoard(*nb);
		//printUserInfo(*nu);
		nu->movesCount = nu->movesCount + 1 ;
	}
	/*/
	cout << "y";
	del_col_entry_up(nb);
	cout << "x"<<endl;
	printBoard(*nb);

	del_row_entry_left(nb);
	cout << "x" << endl;
	printBoard(*nb);
	cin.get();

	cout << "y";
	del_row_entry_right(nb);
	cout << "x" << endl;
	printBoard(*nb);

	cin.get();
	cout << "y";
	del_col_entry_down(nb);
	cout << "x" << endl;
	printBoard(*nb);
	*/
	cin.get();

	return 0;
}