#include "GameLogic.h"
#include "Player.h"
#include "AI.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Injection point. This executes the game's events at the highest level.
int main()
{
	GameLogic game;
	Player player;
	AI ai;

	string engage = "y";
	while(engage == "y")
	{

		// Initiating the 'board'. I refer to the 3x3 grid as the board in this program.  
		vector<vector<string>> board = game.initiateBoard();
		string whoGoesFirst = "null";
		engage = "null";


		// Validating who goes first.
		while(whoGoesFirst != "p" && whoGoesFirst != "a")
		{		
			system("cls");

			cout << "Who goes first, Player or A.I. ? ('p' or 'a'): " << endl;
			cin >> whoGoesFirst;
			cout << endl;

			if(cin.eof())
			{
				cin.clear();
			}
		}


		// Executing the order of output and turns based on which side goes first
		// until either side wins, or the game is a tie. 
		while(!game.isWin("x", board) && !game.isWin("o", board) && whoGoesFirst == "p") // Player is going first.
		{			
			game.printBoard(board);
			board = player.playerTurn(board);
			if(game.isTie(board)){break;}

			if(!game.isWin("x", board) && !game.isWin("o", board))
			{			
				board = ai.aiTurn(board);
			}
			if(game.isTie(board)){break;}
		}

		while(!game.isWin("x", board) && !game.isWin("o", board) && whoGoesFirst == "a") // A.I. is going first.
		{					
			board = ai.aiTurn(board);
			if(game.isTie(board)){break;}

			if(!game.isWin("x", board) && !game.isWin("o", board))
			{		
				game.printBoard(board);
				board = player.playerTurn(board);
			}
			if(game.isTie(board)){break;}
		}	


		// Print out the game's results and final state. 
		game.printBoard(board);
		if(game.isTie(board))
		{
			cout << "It's a tie." << endl;
		}
		if(game.isWin("x", board))
		{
			cout << "x wins." << endl;
		}
		if(game.isWin("o", board))
		{
			cout << "o wins." << endl;
		}


		// Validating the response to play again once the game has ended.
		while(engage != "y" && engage != "n")
		{
			cout << "Play again? ('y' or 'n'):" << endl;
			cin >> engage;
			cout << endl;

			if(cin.eof())
			{
				cin.clear();
			}
		}
	}
	return 0;
}