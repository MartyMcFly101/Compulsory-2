#include <iostream>
#include <conio.h> 
#include <Windows.h>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm> 
#include <random>
#include <chrono>
#include <cstdlib>
#pragma once


struct User {
	std::string PlayerNR;  
	std::string passWord;  
};

struct Card {
	int cardValue{};	
	std::string cardRank{};	
	std::string cardSuit{}; 
};

struct Player {
	std::vector <Card> hand{}; 
	unsigned int money{ 100 }; 
	unsigned int points{};
} player, dealer;


// Task 1 
void logIn(); 
    char up{};	
	std::string PlayerNR{"32909876556"};
	std::string PassWord{}; 


void createUser(std::vector<User>&); 

    int logInLoop{};
    int correctPassWord = 0;


// Task 2 relevant 
void cardDeck(std::vector<Card>&); // Make the cards

void Menu(); 
    char Start{};

// Main jack black function	
void Black_jack(std::vector<Card>&); 
    unsigned int bet{};
	unsigned int BetBowl{}; 
	char drawCard{ 'y' }; 
	int playerWon{};
	int dealerWon{};
	int turnCount{};
    char Choice{};
	char MoreMoney{};

void restock(std::vector<Card>&); // Randomize cards

// Misc. global stuff
void clearCin();

void EndGame();
    char Again;

