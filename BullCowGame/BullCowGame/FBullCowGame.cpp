#include "pch.h"
#include "FBullCowGame.h"


FBullCowGame::FBullCowGame()
{
	reset();
}

void FBullCowGame::reset()
{
	MyCurrentTry = 0;
	MyMaxTries = 10;
	HiddenWord = "capstone";
}

//calculates Bull and cow 
BCCount FBullCowGame::SubmitValidGuess(FString guess)
{
	BCCount BC;
	
	MyCurrentTry++;

	for (int i = 0; i < HiddenWord.length(); i++)
	{
		if (guess[i] == HiddenWord[i])
		{
			BC.Bulls++;
		}

		else
		{
			for (int j = 0; j < HiddenWord.length(); j++)
			{
				if (guess[i] == HiddenWord[j])
				{
					BC.Cows++;
				}
			}
		}
	}

	return BC;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words like an isogram
	if(Word.length() < 2)
	{
		return true;
	}
	//setup map
	TMap<char, bool> LetterSeen;

	//loop through each letter
	for (auto Letter : Word) 
	{
		//Changes letter to lowercase
		Letter = tolower(Letter);

		//end loop early if letter repeats
		if(LetterSeen[Letter])
		{
			return false;
		}
		else
		{
        //add letter to map
		LetterSeen[Letter] = true;
		}
		

			
		    
			
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString guess) const
{
	//exit if the word have zero letters 
	if (guess.length() == 0)
	{
		return true;
	}

	//checks if each letter lowercase
	for(auto Letter : guess) 
	{
		//if letter is not lowercase exit
		if (!islower(Letter))
		{
			return false;
		}

		return true ;
	}
	
}

int FBullCowGame::GetMaxTries() const
{
	TMap<Int32, Int32> Difficulty{ { 3,4 }, { 4,5 }, { 5,6 }, { 6,7 }, { 7,8 } };
	return Difficulty[GetHiddenWordlenth()];
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

Int32 FBullCowGame::GetHiddenWordlenth() const
{
	return HiddenWord.length();
}

bool FBullCowGame::IsGameWon(BCCount name) const
{
	if (name.Bulls == GetHiddenWordlenth())
	{
		return false;
	}
	return true;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (!IsIsogram(guess))
	{
		return EGuessStatus::Not_Isogram;
	}

	else if (!IsLowerCase(guess))
	{
		return EGuessStatus::Upper_Case;
	}

	else if (guess.length() != GetHiddenWordlenth())
	{
		return EGuessStatus::Wrong_Lenth;
	}

	else
	{
		return EGuessStatus::ok;
	}
	
}




