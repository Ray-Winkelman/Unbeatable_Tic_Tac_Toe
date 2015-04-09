#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GameLogic
{
public:
	GameLogic();
	vector<vector<string>> initiateBoard();
	void printBoard(vector<vector<string>> board);
	bool isWin(string xOrO, vector<vector<string>> board);
	bool isTie(vector<vector<string>> board);
};

