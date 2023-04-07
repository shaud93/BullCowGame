#pragma once
#include <string>
#include <map>
#define TMap std::map

using FString = std::string;
using Int32 = int;

struct BCCount 
{
	Int32 Bulls = 0;
	Int32 Cows = 0;
};

enum class EGuessStatus
{
	ok,
	Not_Isogram,
	Wrong_Lenth,
	Upper_Case,
	Not_Valid

};

class FBullCowGame
{
public:

	FBullCowGame(); // Constructer

	Int32 GetMaxTries() const;
	Int32 GetCurrentTry() const;
	Int32 GetHiddenWordlenth() const;

	bool IsGameWon(BCCount) const;
	EGuessStatus CheckGuessValidity(FString) const;

	void reset(); // TODO make a more rich return value

	BCCount SubmitValidGuess(FString);


private:
	// Go to Constructor To Change Values
	Int32 MyCurrentTry;
	Int32 MyMaxTries;
	FString HiddenWord;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;

};

