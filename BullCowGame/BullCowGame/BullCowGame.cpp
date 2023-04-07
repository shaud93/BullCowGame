// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once 
#include "pch.h"
#include <string>
#include "FBullCowGame.h"
#include <iostream>

using FText = std::string;
using Int32 = int;

FText Guess = " ";

// Methods
void PrintIntro();
void PrintGameSummery();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();

//class instance
FBullCowGame BCGame;

//instance for struct
	BCCount BC;

int main()
{
	do 
	{
	
		PrintIntro();

		PlayGame();

	
	} while (AskToPlayAgain());
	
	


}

void PrintIntro()
{

	// INTRODUCE THE GAME
    std::cout << "\n \nWelcome to Bulls and Cow" << std::endl; 
	std::cout << "Can you guess The " << BCGame.GetHiddenWordlenth() << " letter isogram I'm thinking of?" << std::endl << std::endl;
	return;
}

void PrintGameSummery()
{
	if (BC.Bulls == BCGame.GetHiddenWordlenth())
	{
		std::cout << "Congrats! You Won" << std::endl;
	}
	    else
	    {
		std::cout << "Sorry You Lose" << std::endl;

	    }

}



void PlayGame()
{
	BCGame.reset();

	Int32 Number_Of_Turns = BCGame.GetMaxTries();

	

	//loop for number of guess
	//loop ends early if game won
	while(BCGame.IsGameWon(BC) && BCGame.GetCurrentTry() <= BCGame.GetMaxTries())
	{
		GetGuess(); 

			

				//Submit Guess to game
		BC = BCGame.SubmitValidGuess(Guess);

		

	            //Print Bulls and Cow
		std::cout << "Bulls: " << BC.Bulls << "  Cows: " << BC.Cows << std::endl << std::endl;
	}
	
	
	PrintGameSummery();

	
	BC.Bulls = 0;
	BC.Cows = 0;
}

bool AskToPlayAgain()
{
	FText PlayAgain = " ";

	std::cout << "Do You Want To Play Again? [Y/N] ";
	std::getline(std::cin, PlayAgain);

	return ((PlayAgain[0] == 'Y') || (PlayAgain[0] == 'y'));
	
	
}
FText GetGuess()
{
	Int32 Current_Try = BCGame.GetCurrentTry();
	EGuessStatus status = EGuessStatus::Not_Valid;

	// GET THE GUESS FROM PLAYER
do
	{	
		std::cout << "Try:" << Current_Try << " Please Enter Your Guess  ";
		std::getline(std::cin, Guess);
		std::cout << std::endl;

		//Checks is User Guess is Valid
		 status = BCGame.CheckGuessValidity(Guess);

		switch (status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "[ERROR] Please enter a Word without repeating letters" << std::endl << std::endl; //TODO WRITE FUNCTION
			break;
		case EGuessStatus::Wrong_Lenth:
			std::cout << "[ERROR] Please enter a " << BCGame.GetHiddenWordlenth() << " letter Word" << std::endl << std::endl;
			break;
		case EGuessStatus::Upper_Case:
			std::cout << "[ERROR] Please enter all lowercase letters " << std::endl << std::endl;//TODO WRITE FUNCTION
			break;
		default:
			break;

		}
	} while (status != EGuessStatus::ok);
	return Guess;
}	