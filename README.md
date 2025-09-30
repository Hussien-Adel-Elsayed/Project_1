# Rock-Paper-Scissors Game (C++ Console)

Rock-Paper-Scissors Game (C++ Console)
This project is an implementation of the classic Rock-Paper-Scissors (Stone-Paper-Scissors) game as a C++ console application. It allows a single player (Player 1) to compete against the computer over multiple rounds, providing a detailed summary of the game's results.

🎯 Game Features
Multi-Round Gameplay: The user can specify the number of rounds (1 to 10) to be played.

Player vs. Computer: The player inputs their choice, and the computer's choice is determined randomly.

Detailed Round Results: After each round, the program displays:

The choices made by the player and the computer.

The winner of that specific round.

The screen color changes to visually highlight the winner (Green for Player 1, Red for Computer, Yellow for Draw).

Final Game Summary: At the end of the specified rounds, a "Game Over" screen is displayed with a summary, including:

Total rounds played.

Player 1 wins count.

Computer wins count.

Draw count.

The Final Game Winner announcement.

Play Again Option: The user is prompted to start a new game immediately after the current one concludes.

🏗️ Code Structure and Modularity
The code is highly organized using modular programming principles for clarity and maintainability:

Enums for Clarity: Uses enum class (implicitly, as C++ 98 style enums are used) for game choices (enGameChoice) and winners (enWinner), making the code highly readable.

Structs for Data Grouping:

stRoundInfo: Stores all data relevant to a single round (choices, winner, winner name).

stGameResults: Stores aggregated statistics for the entire game (total wins, draws, final winner).

Separation of Concerns: Functions are specialized for distinct tasks:

Logic: WhoWonTheRound, WhoWonTheGame.

I/O: ReadPlayer1Choice, ReadHowManyRounds.

Presentation: PrintRoundResults, ShowFinalGamesResults, SetWinnerScreenColor.

This clean structure ensures that any future modifications (e.g., adding sound effects, improving the computer's AI, or changing display formats) can be implemented with minimal impact on the core game logic.

🎮 How to Play
Compile and run the C++ application.

The game will first ask: "How Many Rounds 1 to 10?" (Enter your desired number of rounds).

In each round, you will be prompted to enter your choice:

[1] for Stone

[2] for Paper

[3] for Scissors

The results of the round will be displayed immediately.

After all rounds are complete, the final results will be shown, and you'll be asked if you wish to play again.
