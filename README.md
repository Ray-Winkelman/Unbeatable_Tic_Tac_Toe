#Unbeatable Tic Tac Toe

This is an algorithm for an unbeatable, artificial Tic Tac Toe opponent. I wrote this program in C++ and have included the algorithm’s activity diagram. 

##UML Activity Diagram:
<img src="http://s18.postimg.org/ontd8iow9/PNG_UML_Activity_Diagram.png" alt="UML Activity Diagram"> 

The logic controlling one turn of the artificial opponent is in the method below. It's quite long (I wrote this in my first semester - Don't judge) but it's easy to follow when reading the comments.

```cpp
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
```
##Tic Tac Toe Directory Tree:
<img src="http://s13.postimg.org/r8m6aqlwn/tictree.png" alt="Humans Versus Zombies Directory Tree"> 

##Tic Tac Toe Source Summary:
<img src="http://s30.postimg.org/sah3etbc1/ticsource.png" alt="Humans Versus Zombies Source Summary"> 