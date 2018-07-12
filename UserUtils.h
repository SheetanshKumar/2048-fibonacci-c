#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
struct User
{
	char name[20];
	int score;
	int boardSize;
	int movesCount;
};

User * createUser()
{
	printf("Enter your Name : \n");
	User * user = (User *)malloc(sizeof(User));
	
	//scanf_s("%[^\n]c", &(user->name));
	gets_s( user->name);
	fflush(stdin);
	user->score = 0;
	user->movesCount = 0;
	return user;
}
void printUserInfo(User user)
{
	printf("User : %s \t\t Moves : %s \n\n", user.name, user.movesCount);
}