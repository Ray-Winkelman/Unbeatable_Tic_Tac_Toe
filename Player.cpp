#include "Player.h"
using namespace std;

Player::Player() 
{
	// Empty constructor. In case I would like to add instance variables later.
}

// Method to validate and execute the Player's turn.
vector<vector<string>> Player::playerTurn(vector<vector<string>> board)
{
	string input;

	while(input != "null")
	{
		cout << "Please pick a number:" << endl;
		cin >> input;

		for(int i = 0; i < 3; i++)   
		{
			for(int j = 0; j < 3; j++)
			{
				if (input == board[i][j])
				{
					board[i][j] = "x";
					cout << endl;
					return board;
				}
			}
		}

		if(cin.eof())
		{
			cin.clear();
		}
		cout << "Invalid entry." << endl;
		input = "notnull";
	}
	return board;
}