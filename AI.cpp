#include "AI.h"
using namespace std;

AI::AI()
{
	// Empty constructor. In case I would like to add instance variables later.
}

// This method checks for an available position for the A.I. to take,
// that will result in the A.I. winning the game.
bool AI::checkForWinningMoves(string xOrO, vector<vector<string>> board)
{
	for(int i = 0; i < 3; i++)   
	{
		// Checking colomn potential.
		if (board[0][i] == xOrO && board[1][i] == xOrO && board[2][i] != "x")
		{
			return true;
		}
		if (board[0][i] != "x" && board[1][i] == xOrO && board[2][i] == xOrO)
		{
			return true;
		}
		if (board[0][i] == xOrO && board[1][i] != "x" && board[2][i] == xOrO)
		{
			return true;
		}


		// Checking row potential.
		if (board[i][0] == xOrO && board[i][1] == xOrO && board[i][2] != "x")
		{
			return true;
		}
		if (board[i][0] != "x" && board[i][1] == xOrO && board[i][2] == xOrO)
		{
			return true;
		}
		if (board[i][0] == xOrO && board[i][1] != "x" && board[i][2] == xOrO)
		{
			return true;
		}

		// Checking diagonal potential. 
		if ((board[0][0] == xOrO && board[1][1] == xOrO && board[2][2] != "x") || 
			(board[0][0] != "x" && board[1][1] == xOrO && board[2][2] == xOrO))
		{
			return true;
		}
		if ((board[0][2] == xOrO && board[1][1] == xOrO && board[2][0] != "x") || 
			(board[0][2] != "x" && board[1][1] == xOrO && board[2][0] == xOrO))
		{
			return true;
		}
	}
	return false;
}

// This method takes a position that will result in the A.I. winning.
vector<vector<string>> AI::takeWin(string xOrO, vector<vector<string>> board)
{
	for(int i = 0; i < 3; i++)   
	{
		// Checking colomn potential.
		if (board[0][i] == xOrO && board[1][i] == xOrO && board[2][i] != "x")
		{
			board[2][i] = xOrO;
			return board;
		}
		if (board[0][i] != "x" && board[1][i] == xOrO && board[2][i] == xOrO)
		{
			board[0][i] = xOrO;
			return board;
		}
		if (board[0][i] == xOrO && board[1][i] != "x" && board[2][i] == xOrO)
		{
			board[1][i] = xOrO;
			return board;
		}

		// Checking row potential.
		if (board[i][0] == xOrO && board[i][1] == xOrO && board[i][2] != "x")
		{
			board[i][2] = xOrO;
			return board;
		}
		if (board[i][0] != "x" && board[i][1] == xOrO && board[i][2] == xOrO)
		{
			board[i][0] = xOrO;
			return board;
		}
		if (board[i][0] == xOrO && board[i][1] != "x" && board[i][2] == xOrO)
		{
			board[i][1] = xOrO;
			return board;
		}

		// Checking diagonal potential. 
		if (board[0][0] == xOrO && board[1][1] == xOrO && board[2][2] != "x")
		{
			board[2][2] = xOrO;
			return board;
		}
		if(board[0][0] != "x" && board[1][1] == xOrO && board[2][2] == xOrO)
		{
			board[0][0] = xOrO;
			return board;
		}
		if (board[0][2] != "x" && board[1][1] == xOrO && board[2][0] == xOrO)
		{
			board[0][2] = xOrO;
			return board;
		}
		if (board[0][2] == xOrO && board[1][1] == xOrO && board[2][0] != "x")
		{
			board[2][0] = xOrO;
			return board;
		}
	}
	return board;
}

// This method executes the A.I.'s turn.
vector<vector<string>> AI::aiTurn(vector<vector<string>> board)
{
	if(checkForWinningMoves("o", board))
	{
		return takeWin("o", board);
	}

	// If the center is taken by the player.
	if (board[1][1] == "x") 
	{

		// Defend the diagonals intersecting the center. 
		if (board[0][0] == "x" && board[2][2] != "o")
		{
			board[2][2] = "o";
			return board;
		}
		if (board[0][2] == "x" && board[2][0] != "o")
		{
			board[2][0] = "o";
			return board;
		}
		if (board[2][0] == "x" && board[0][2] != "o")
		{
			board[0][2] = "o";
			return board;
		}
		if (board[2][2] == "x" && board[0][0] != "o")
		{
			board[0][0] = "o";
			return board;
		}

		// Defend the row and colomn intersecting the center. 
		if (board[1][0] == "x" && board[1][2] != "o")
		{
			board[1][2] = "o";
			return board;
		}
		if (board[1][2] == "x" && board[1][0] != "o")
		{
			board[1][0] = "o";
			return board;
		}
		if (board[0][1] == "x" && board[2][1] != "o")
		{
			board[2][1] = "o";
			return board;
		}
		if (board[2][1] == "x" && board[0][1] != "o")
		{
			board[0][1] = "o";
			return board;
		}
	}

	// If the center is availible, take it.
	if (board[1][1] != "x") 
	{
		if(board[1][1] != "o")
		{
			board[1][1] = "o";
			return board;
		}
	}

	// Defending moves near the top-left corner.
	if (board[0][0] == "x") 
	{
		if (board[0][1] == "x" && board[0][2] != "o")
		{
			board[0][2] = "o";
			return board;
		}
		if (board[0][2] == "x" && board[0][1] != "o")
		{
			board[0][1] = "o";
			return board;
		}
		if (board[1][0] == "x" && board[2][0] != "o")
		{
			board[2][0] = "o";
			return board;
		}
		if (board[2][0] == "x" && board[1][0] != "o")
		{
			board[1][0] = "o";
			return board;
		}
	}

	// Defending moves near the bottom-right corner.
	if (board[2][2] == "x")
	{
		if (board[1][2] == "x" && board[0][2] != "o")
		{
			board[0][2] = "o";
			return board;
		}
		if (board[0][2] == "x" && board[1][2] != "o")
		{
			board[1][2] = "o";
			return board;
		}
		if (board[2][1] == "x" && board[2][0] != "o")
		{
			board[2][0] = "o";
			return board;
		}
		if (board[2][0] == "x" && board[2][1] != "o")
		{
			board[2][1] = "o";
			return board;
		}
	}

	// Defending moves near the top-right corner.
	if (board[0][2] == "x")
	{
		if (board[1][2] == "x" && board[2][2] != "o")
		{
			board[2][2] = "o";
			return board;
		}
		if (board[0][1] == "x" && board[0][0] != "o")
		{
			board[0][0] = "o";
			return board;
		}
	}

	// Defending moves near the bottom-left corner.
	if (board[2][0] == "x")
	{
		if (board[2][1] == "x" && board[2][2] != "o")
		{
			board[2][2] = "o";
			return board;
		}
		if (board[1][0] == "x" && board[0][0] != "o")
		{
			board[0][0] = "o";
			return board;
		}
	}

	// If the center is taken by AI:
	if(board[1][1] == "o")
	{
		// Check the center row for potential.
		if(board[1][0] != "x" && board[1][2] != "x")
		{			
			if(board[1][2] != "x" && board[1][2] != "o")
			{		
				board[1][2] = "o";
				return board;
			}
			if(board[1][0] != "x" && board[1][0] != "o")
			{		
				board[1][0] = "o";
				return board;
			}
		}

		// Check the center colomn for potential. 
		if(board[0][1] != "x" && board[2][1] != "x")
		{			
			if(board[2][1] != "x" && board[2][1] != "o")
			{		
				board[2][1] = "o";
				return board;
			}
			if(board[0][1] != "x" && board[0][1] != "o")
			{		
				board[0][1] = "o";
				return board;
			}
		}
	}

	// Check top-left postion for potential.
	if(board[0][0] != "x" && board[0][0] != "o" && board[2][2] != "x")
	{		
		board[0][0] = "o";
		return board;
	}

	// Check bottom-right postion for potential.
	if(board[2][2] != "x" && board[2][2] != "o"&& board[0][0] != "x")
	{		
		board[2][2] = "o";
		return board;
	}

	// Check top-right postion for potential.
	if(board[0][2] != "x" && board[0][2] != "o" && board[2][0] != "x")
	{		
		board[0][2] = "o";
		return board;
	}

	// Check bottom-left postion for potential.
	if(board[2][0] != "x" && board[2][0] != "o" && board[0][2] != "x")
	{		
		board[2][0] = "o";
		return board;
	}	

	return endTie(board);
}

// This method returns an available position when the board's state 
// has reached an 'early tie' - in other words: This gets called
// when no one can win the game.
vector<vector<string>> AI::endTie(vector<vector<string>> board)
{
	for(int i = 0; i < 3; i++)   
	{
		for(int j = 0; j < 3; j++)
		{
			if(board[i][j] != "o" && board[i][j] != "x")
			{
				board[i][j] = "o";
				return board;
			}			
		}
	}
	return board;
}