#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName = "";

};

struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string FinalWinner = "";
};

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1", "Computer", "No Winner" };

	return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
		return enWinner::Draw;

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
			return enWinner::Computer;
		break;
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
			return enWinner::Computer;
		break;
	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
			return enWinner::Computer;
		break;
	}

	return enWinner::Player1;
}

string ChoiceName(enGameChoice Choice)
{
	string arrChoiceName[3] = { "Stone", "Paper", "Scissors" };

	return arrChoiceName[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2f");
		break;
	case enWinner::Computer:
		system("color 4f");
		cout << "\a";
		break;
	default:
		system("color 6f");
	}

}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n---------- Round [" << RoundInfo.RoundNumber << "] -----------\n\n";
	cout << "   Player1  Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "   Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "   Round Winner   : [" << RoundInfo.WinnerName << "] \n";
	cout << "\n--------------------------------\n" << endl;

	SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(short Player1WonTimes, short ComputerWonTimes)
{
	if (Player1WonTimes > ComputerWonTimes)
		return enWinner::Player1;
	else if (ComputerWonTimes > Player1WonTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

stGameResults FillGameResults(int GameRound, short Player1WonTimes, short ComputerWonTimes, short DrawTimes)
{
	stGameResults GameResults;

	GameResults.GameRounds = GameRound;
	GameResults.Player1WinTimes = Player1WonTimes;
	GameResults.ComputerWinTimes = ComputerWonTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WonTimes, ComputerWonTimes);
	GameResults.FinalWinner = WinnerName(GameResults.GameWinner);

	return GameResults;
}

enGameChoice ReadPlayer1Choice()
{
	int Choice = 0;

	do
	{
		cout << "\nyour choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Choice;

	} while (Choice < 1 || Choice > 3);

	return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Player1WonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;

	for (int GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player1)
			Player1WonTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWonTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);

	}

	return FillGameResults(HowManyRounds, Player1WonTimes, ComputerWonTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
	string t = "";

	for (int i = 1; i <= NumberOfTabs; i++)
		t += "\t";

	return t;
}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "-----------------------------------------------\n\n";
	cout << Tabs(2) << "                +++ Game Over +++               \n\n";
	cout << Tabs(2) << "-----------------------------------------------\n\n";
}

void ShowFinalGamesResults(stGameResults GameResults)
{
	cout << Tabs(2) << "---------------------- [Game Results] ----------------------\n\n";
	cout << Tabs(2) << "Game Rounds         : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 won times   : " << GameResults.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer won times  : " << GameResults.ComputerWinTimes << endl;
	cout << Tabs(2) << "Draw times          : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner        : " << GameResults.FinalWinner << endl;
	cout << Tabs(2) << "-------------------------------------------------------------\n\n";

	SetWinnerScreenColor(GameResults.GameWinner);
}

int ReadHowManyRounds()
{
	int GameRounds = 1;
	do
	{
		cout << "How Many Rounds 1 to 10 ?\n";
		cin >> GameRounds;
	} while (GameRounds < 1 || GameRounds > 10);

	return GameRounds;
}

void ResetScreen()
{
	system("cls");
	system("color 0f");
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGamesResults(GameResults);

		cout << endl << Tabs(2) << "Do yo want to play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}



int main()
{
	srand((unsigned)time(NULL));


	StartGame();


	// Rock-Paper-Scissors game














	return 0;
}
