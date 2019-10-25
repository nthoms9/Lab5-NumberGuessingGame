/*
Nick Thoms
C++ 2019
Due: 10/1024/19
Lab 5 Number Guessing Game
Description: This program is a number guessing game that will prompt the user to guess a 
             random number between 0 and 100. Then it will allow the user to input a guess 
			 and react accordingly. The user should get 20 guesses and the option to play again.
			 at the end the amount of wins and losses is outputted to the screen.
*/

#include<iostream> // This library is for basic functions in c++.
#include<stdlib.h> // This library is for the random number generator.
#include<time.h>   // This library is for the time seed.
#include<cassert>  // This library is for the assert function.

using namespace std;

void gameInterior(int& winScore, int& loseScore);
//preconditions: The flow of control is valid and the main function's 
//               do while loop is active.
//postconditions: The variables "input" and "ranNum" are initialized. The for loop is
//                run and a statement is ouputted and "guessNum" is called, then
//                a value is inputted into "input". Statements are outputted,
//                the functions "winningStatements" and "losingStatements" are 
//                potentially called, and the loop either continues or exits all of
//                which depending on the value of "input". Lastly the "score" function 
//                is called.
//(The next four void functions are called to within the "gameInterior" function.)
	void guessNum(int);
	//preconditions: The flow of control has moved to the "game interior" function and
	//               its for loop is active.
	//postconditions: A statement is outputted depending on the value of "guesses".
	void winningStatements();
	//preconditions: The flow of control has moved to the "game interior" function and
	//               its for loop is active. The variables "input" and "ranNum" are initialized
	//               and (cin) is valid. The assertion ("input"=="ranNum") is true.
	//postconditions: The variable "ranWin" is initialized and a random statement is outputted
	//                depending on the value of "ranWin"
	void losingStatements(int);
	//preconditions: The flow of control has moved to the "game interior" function and
	//               its for loop is active. The variables "input" "ranNum" are initialized
	//               and (cin) is valid. The assertion ("input"=="ranNum") is not true and the
	//               assertion ("guesses" != 20 && "input" != "ranNum") is not true.
	//postconditions: The variable "ranLoss" is initialized and a random statement is outputted
	//                depending on the value of "ranLoss".
	void score(int, int, int& winScore, int& loseScore);
    //preconditions: The flow of control has moved to the "game interior" function and
	//               the variables "input" "ranNum" are initialized. (cin) is valid.
	//               The for loop has exited.
	//postconditions: The value for "winScore" or the value of "loseScore" is updated 
	//                depending on the value of "input".
void playAgainPrompt();
//preconditions: The flow of control is valid and the main function's 
//               do while loop is active.The "gameInterior" function has exited and (cin)
//               is valid.
//postconditions: The variable "ranPrompt" is initialized and a random statement is outputted
	//            depending on the value of "ranPrompt".

int main() // The main function is defined here.
{
	int winScore = 0;    //The varaibles winScore and loseScore are declared.
	int loseScore = 0;
	int playAgain;       //The variabel playAgain is declared.

	cout << "Welcome to the number guessing game. "; // A welcome statement is ouputted.
		 
	do // The game is contained within a do loop so that the user will have the option
	   // to play again.
	{
		cout << "This game will calculate a random number between 0 and 100."
			 << "\nYour goal is to guess this number, you'll  have 20 guesses. Good Luck! \n";
		
		gameInterior(winScore, loseScore); // The game Interior function is called.
		playAgainPrompt(); // The play again function is called.

		cin >> playAgain; // The user inputs an integer into the playAgain variable,
		cout << endl;     // which will determine if the program will be run again.

	} while (playAgain == 1); // This is the loop test for the do loop.

	//Next, a statement that tells the user his or her score is outputted
	cout << "Your score was: " << winScore << " win(s) and " << loseScore << " loss(es)\n";

	return 0; // The program exits with code 0.
}

// This is the function definition for the gameInterior function. This function contains a for
// loop that deals with the guesses and the function call for the score function
void gameInterior(int& winScore, int& loseScore) 
{
	srand(unsigned int(time(NULL)));  // The time seed is initialized
	int ranNum = rand() % 100 + 0;    // The random number to be guessed is calclulated.
	int input;  // The variable for the user input is declared.

	// This for loop contains the part of the program that has the user input a guess
	// then, it determines how it should react. Its maximum amount of iterations is
	// 20 for the amount of guesses allowed
	for (int guesses = 1; guesses <= 20; guesses++) 
	{

		cout << "\nPlease input your "; guessNum(guesses); cout << " guess then press enter : ";

		cin >> input; // The user inputs their guess.
		if (!cin)     // A check is made to verify that the input is valid.
		{
			cout << "\nInvalid input. Please do not use characters or decimals.\n\n";
		}
		assert(cin); // This assertion will close the program if the input is invalid.


		if (input < 0 || input >100) // A check is made to verify if the input is
		{                            // within bounds then outputs and appropriate
			guesses--;               // prompt
			cout << "\nHey you can't guess that silly, try agin.\n";
			cout << "(You have " << 20-guesses << " guesses left)";
		}
		else if (input == ranNum)    // A check is made to see whether or not the
		{                            // users guess is correct, if it is the 
			winningStatements();     // winningStatements functions is called and
			guesses = 21;            // the loop is exited.
		}
		else if (guesses != 20 && input != ranNum) // If the guess is incorrect
		{                                          // a message is outputted and the
			cout << "\nwrong, try again ";         // loop continues
			cout << "(You have " << 20 - guesses << " guesses left)\n";
		}
		else                            // If the guess is incorrect and it is the last
		{                               // guess, the losingStatements function is 
			losingStatements(ranNum);   // called.
		}
	}

	score(ranNum, input, winScore, loseScore); //The score function is called
}

// This is the function defintion for the guessNum function. This function determines
// which the number of guess that the user is on.
void guessNum(int guesses)
{
	switch (guesses)            // This switch statement takes the number of guess
	{                           // and determine which statement should be oututted.
	case 1: cout << "first";
		break;
	case 2: cout << "second";
		break;
	case 3: cout << "third";
		break;
	case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
	case 12: case 13: case 14: case 15: case 16: case 17: case 19: case 20:
			cout << guesses << "th";
		break;
	default: cout << "error";
	}
}

// This is the function definition for the winningStatements function. This function
// chooses a winning statement to be outputted.
void winningStatements()
{
	srand(unsigned int(time(NULL)));   // A random number generator is used to pick
	int ranWin = rand() % 10 + 1;      // an output statment for the user when they win.
	switch (ranWin)                    // A switchstatement is used for the selection
	{                                  // of 10 winning statements.
	case 1:  cout << "\nCongratulations you won";
		break;
	case 2:  cout << "\nGood job, your'e good at this";
		break;
	case 3:  cout << "\nhuh... you... actually won?";
		break;
	case 4:  cout << "\nWoah you won, that's pretty impressive";
		break;
	case 5:  cout << "\nYou are the winner";
		break;
	case 6:  cout << "\nToday is your lucky day, you just won";
		break;
	case 7:  cout << "\nNice job, next step try the lottery";
		break;
	case 8:  cout << "\nGood guess, you got it right";
		break;
	case 9:  cout << "\nToo easy that was nothing for you ";
		break;
	case 10: cout << "\nThe force is with you young one ";
		break;
	default: cout << "fix random number generator";
	}
}

// This is the function definition for the losingStatements function. This function
// chooses a losing statement to be outputted.
void losingStatements(int ranNum)
{
	srand(unsigned int(time(NULL)));   // A random number generator is used to pick
	int ranLoss = rand() % 10 + 1;     // an output statment for the user when they.
	switch (ranLoss)                   // Lose. A switchstatement is used for the 
	{                                  // selection of 10 losing statements.
	case 1:  cout << "\nToo bad you lost, the correct answer was " << ranNum;
		break;
	case 2:  cout << "\nAww shucks you didn't guess it, the correct answer was " << ranNum;
		break;
	case 3:  cout << "\noopsie poopsie your'e all out of guesses, the correct answer was " << ranNum;
		break;
	case 4:  cout << "\nLooks like you can't beat the odds, the correct answer was " << ranNum;
		break;
	case 5:  cout << "\nToday is not your lucky day, the correct answer was " << ranNum;
		break;
	case 6:  cout << "\nBetter luck next time bucko, the correct answer was " << ranNum;
		break;
	case 7:  cout << "\nYou didn't win? Really? It's easy, you should've just guessed " << ranNum;
		break;
	case 8:  cout << "\nDon't worry there is alway next time, the correct answer was " << ranNum;
		break;
	case 9:  cout << "\nWow... your'e bad, the correct answer was " << ranNum;
		break;
	case 10: cout << "\nCome back once you are one with the force, the correct answer was " << ranNum;
		break;
	default: cout << "fix random number generator";
	}
}

// This is the function definition for the score function. This function
// keeps track of the score by using pass by reference variables.
void score(int ranNum, int input, int& winScore, int& loseScore)
{
	if (input == ranNum)
	{
		winScore++; // If the user won winScore will add one to its original value.
	}
	else
	{
		loseScore++; // If the user lossed then loseScore will add one to its original
	}                // value.
}

// This is the function definition for the playAgainPrompt function. This function
// chooses a promt for the use to choose to play again.
void playAgainPrompt()
{                                      // A random number generator is used to pick
	srand(unsigned int(time(NULL)));   // an output statment for the user to prompt
	int ranPrompt = rand() % 10 + 1;   // them to play again.  A switchstatement is 
	switch (ranPrompt)                 // used for the selection of  10 prompts.
	{
	case 1:  cout << "\n\nDo you want to play again? Input 1 for yes and 2 for no: ";
		break;
	case 2:  cout << "\n\nNow wasn't that fun? If you want to play again input 1 if not input 2: ";
		break;
	case 3:  cout << "\n\nHaven't had enough? Input 1 to play again and 2 to exit: ";
		break;
	case 4:  cout << "\n\nIf you want to play again press 1 and if you want to quit press 2: ";
		break;
	case 5:  cout << "\n\nYour'e not done yet are you? If you are input 2 if not input 1: ";
		break;
	case 6:  cout << "\n\nDon't stop now. Input 1 to play again and 2 to stop: ";
		break;
	case 7:  cout << "\n\nIf you play again you have a the same chance to win. Input 1 to play and 2 to stop: ";
		break;
	case 8:  cout << "\n\nIf you lost you can always play again. Input 1 to play and 2 to exit: ";
		break;
	case 9:  cout << "\n\nThis game is free so play to your heart's content. Input 1 to keep going and 2 if your'e done ";
		break;
	case 10: cout << "\n\nCONTINUE? 5..4..3..2..1.. Input 1 for yes and 2 for no: ";
		break;
	default: cout << "fix random number generator";
	}
}