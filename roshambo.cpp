#include "pch.h"
#include <iostream>
#include <random>
#include <string>


char winner(int playerChoice, int compChoice);
int computerChoice();
void announceWinner(char winner);
void announceChoices(int playerChoice, int compChoice);
void playAgain();

int main()
{
	int choice; 
	int const compChoice = computerChoice();

	std::cout << "Welcome to Tic Tac Toe\n";
	std::cout << "What will you choose?\n\n";
	do {
		std::cout << "\n1 - Rock\n";
		std::cout << "\n2 - Paper\n";
		std::cout << "\n3 - Scissors\n\n";
		std::cout << "Choice: ";
		std::cin >> choice;
	} while (choice == 0);

	announceChoices(choice, compChoice);
	announceWinner(winner(choice, compChoice));
	playAgain();

}


char winner(int playerChoice, int compChoice) {

	if (playerChoice == compChoice) {
		return 'D';
	}
	if (playerChoice == 1 && compChoice == 3 ||
		playerChoice == 2 && compChoice == 1 ||
		playerChoice == 3 && compChoice == 2) {
		return 'W';
	}
	else return 'L';

}

void announceWinner(char winner) {
	if (winner == 'W') {
		std::cout << "\nYou win!\n\n";
	}
	else if (winner == 'L') {
		std::cout << "\nYou lost!\n\n";
	}
	else
		std::cout << "\nDraw!\n\n";
}

void announceChoices(int playerChoice, int compChoice) {
	std::string pWeapon;
	std::string cWeapon;

	if (playerChoice == 1) pWeapon = "Rock";
	else if (playerChoice == 2) pWeapon = "Paper";
	else if (playerChoice == 3) pWeapon = "Scissors";

	if (compChoice == 1) cWeapon = "Rock";
	else if (compChoice == 2) cWeapon = "Paper";
	else if (compChoice == 3) cWeapon = "Scissors";

	std::cout << "\nYou chose " << pWeapon;
	std::cout << "\nComputer chose " << cWeapon;
}

int computerChoice(){

	std::random_device dev; // intializes
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist3(1, 3); // distribution in range [1, 3]

	return (dist3(rng));

}

void playAgain() {
	char choice;
	std::cout << "\nWould you like to play again? (y/n) ";
	std::cin >> choice;
	if (choice == 'y') {
		main();
	}
}
