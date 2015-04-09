#include "GameLogic.h"
using namespace std;

GameLogic::GameLogic()
{
	// Empty constructor. In case I would like to add instance variables later.
}

// Method for initiating the board's state.
vector<vector<string>> GameLogic::initiateBoard()
{
	vector<vector<string>> board;
	board.resize(3);
	int count = 1;
	for(int i = 0; i < 3; i++)   
	{
		board[i].resize(3);
		for(int j = 0; j < 3; j++)
		{
			board[i][j] = to_string(count++);
		}
	}
	return board;
}

// Method for printing the board's state.
void GameLogic::printBoard(vector<vector<string>> board)
{
	system("cls");

	for(int i = 0; i < 3; i++)   
	{
		for(int j = 0; j < 3; j++)
		{
			cout << board[i][j] + " ";
		}
		cout << endl;
	}
	cout << endl;
}

// Method for scanning the board for a tied game state.
bool GameLogic::isTie(vector<vector<string>> board)
{
	for(int i = 0; i < 3; i++)   
	{
		for(int j = 0; j < 3; j++)
		{
			if(board[i][j] != "o" && board[i][j] != "x")
			{
				return false;
			}			
		}
	}
	return true;
}

// Method to find a winner in the board's state. 
bool GameLogic::isWin(string xOrO, vector<vector<string>> board)
{
	for(int i = 0; i < 3; i++)   
	{
		if (board[0][i] == xOrO && board[1][i] == xOrO && board[2][i] == xOrO)
		{
			return true;
		}
		if (board[i][0] == xOrO && board[i][1] == xOrO && board[i][2] == xOrO)
		{
			return true;
		}
		if (board[0][i] == xOrO && board[1][i] == xOrO && board[2][i] == xOrO)
		{
			return true;
		}
		if ((board[0][0] == xOrO && board[1][1] == xOrO && board[2][2] == xOrO) || 
			(board[0][2] == xOrO && board[1][1] == xOrO && board[2][0] == xOrO))
		{
			return true;
		}
	}
	return false;
}