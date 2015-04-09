#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AI
{
public:
	AI();
	bool AI::checkForWinningMoves(string xOrO, vector<vector<string>> board);
	vector<vector<string>> aiTurn(vector<vector<string>> board);
	vector<vector<string>> takeWin(string xOrO, vector<vector<string>> board);
	vector<vector<string>> endTie(vector<vector<string>> board);
};