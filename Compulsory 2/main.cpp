#include "Orginaiser.h"

int main() {
	system("color a");
	logIn();

	std::vector<Card> cards{}; 
	cardDeck(cards); 
	Menu();
	Black_jack(cards); 
	return 0; 
}

void logIn() {
	std::vector<User> users{}; 

	while (correctPassWord == 0) {
		system("cls");

		std::cout << "  ~~~~ Welcome To GameBox ~~~~\n";
		std::cout << "  We will suprise you ~ Player 32909876556 ~  with a game ~ ^^ ~ \n";
		std::cout << "  Player press 1 to make a password. \n";
		std::cout << "  Finished making a password? Press the 2 key.\n";


		up = _getch();

		if (up == '1') {
			system("cls");
			createUser(users);
		}
		if (up == '2') { 
			if (users.size() == 0) {
				std::cout << "  Please make an account first :)";
				Sleep(1000);
			}
			else {
				
				std::cout << "  Type in Your Player Nr. :" << std::endl;
				std::getline(std::cin, PlayerNR);
				std::cout << std::endl;

				for (int logInLoop = 0; logInLoop < users.size(); logInLoop++) {
					if (PlayerNR == users[logInLoop].PlayerNR) {

						for (int i = 0; i < 3; i++) { 
							if (i == 3) {
								std::cout << "  Yeah that was your last chance :/ \n";
								exit(0);
							}
							std::cout << "  Now type in your awezome password CX :\n";
							std::getline(std::cin, PassWord);
							if (PassWord == users[logInLoop].passWord) {
								std::cout << "  Yupp that's right !" << users[logInLoop].PlayerNR << '\n';
								std::cout << "  Your all set to play! Yey!\n";
								correctPassWord = 1;
								Sleep(2000);
								break; 
							}
							std::cout << std::endl;
							clearCin();
						}
					}
				}
			}
		}
	}
}

// username and password CREATOR
void createUser(std::vector<User>& users) {
	User temp_user{};

	std::cout << "  Now what will you Player Number be? \n";
	std::cin >> temp_user.PlayerNR;
	std::cout << std::endl << std::endl << "  Aha so your user name is " << temp_user.PlayerNR << "  I think 1654354843154464651 is much cooler tho...\n";

	std::cout << "  Now make an awezome password CX :\n";
	std::cin >> temp_user.passWord;
	std::cout << "  WoWiiii your awezome password is " << temp_user.passWord << " !!\n";

	users.push_back(temp_user);
	clearCin();
	Sleep(1000);
}

// CardDeck Vector
void cardDeck(std::vector<Card>& cards) {
	Card temp_card{};

	for (int j = 1; j <= 4; j++) { // For the suit
		for (int i = 1; i <= 13; i++) { // For the court/number

			// This part decides which Rank the card has and also what point value it will have in JackBlack
			if (i == 1) {
				temp_card.cardValue = 1;
				temp_card.cardRank = "Ace";
			}
			if (i == 11) {
				temp_card.cardValue = 10;
				temp_card.cardRank = "Jack";
			}
			if (i == 12) {
				temp_card.cardValue = 10;
				temp_card.cardRank = "Queen";
			}
			if (i == 13) {
				temp_card.cardValue = 10;
				temp_card.cardRank = "King";
			}
			if (i >= 2 && i <= 10) { 
				temp_card.cardValue = i;
				temp_card.cardRank = std::to_string(i); 
			}

			// This part decides which suit the card has	
			if (j == 1) {
				temp_card.cardSuit = " of Spades";
			}
			if (j == 2) {
				temp_card.cardSuit = " of Hearts";
			}
			if (j == 3) {
				temp_card.cardSuit = " of Diamonds";
			}
			if (j == 4) {
				temp_card.cardSuit = " of Clubs";
			}

			// Seeing if every card are created correctly 
			std::cout << "Card: " << temp_card.cardRank << temp_card.cardSuit << "\tCard score value : " << temp_card.cardValue << "\t"; // What card we just made
			cards.push_back(temp_card);
			std::cout << "This is card #" << cards.size() << std::endl; // Check how many cards have been made so far
		}
	}
}

// The Starting Menu
void Menu() {
	system("cls");

	std::cout << "  Welcome to JackBlack ~ ^^ ~ \n\n";

	std::cout << "  In this game you wanna get as close to 21 as you can.\n";
	std::cout << "  If you go over 21 you lose the round.\n\n";

	std::cout << "  Numbers from 2 to 10 will have the same value as the number. \n";
	std::cout << "  Knights, Queens and Kings will have the value of 10. \n";
	std::cout << "  When you get Ace you have to choose whitch value you wanna use.\n\n";

	std::cout << "  You play until you're out of money.\n\n";

	std::cout << "  So, ready to play? \n";
	std::cout << "    1. Yes\n";
	std::cout << "    2. No\n";

	Start = _getch();
	switch (Start) {
	case '1':
		std::cout << "  Ait let's start ^^ ";
		break;
	case '2':
		std::cout << "  Oh... Okey.. Bai then ;-;\n";
		break;
	default:
		break;
	}
}

// The Game
void Black_jack(std::vector<Card>& cards) {

	while (1) {

		while (player.money != 0 && dealer.money != 0) {
			restock(cards); // Restock the order of cards

			while (bet < 10 || bet > dealer.money || bet > player.money) { // Loops here until bet amount is acceptable

				system("cls");

				std::cout << "  You have " << player.money << "$ " << "\t The Dealer has " << dealer.money << "$\n"; 
				std::cout << "  The Bet Bowl: " << BetBowl << "$\n";

				std::cout << "  How much would you would like to bet? \n";
				std::cin >> bet;
				clearCin();

				if (bet < 10) 
				{
					std::cout << "  You need to bet at least 10$.\n";
				}

				if (bet > dealer.money) {
					std::cout << "  I cannot match that bet.";
					
				}
				else if (bet > player.money) {
					std::cout << "  You don't have enough money for that.";
				}
			}

			player.money = player.money - bet;
			dealer.money = dealer.money - bet;

			
			system("cls");
		
			std::cout << "  You have " << player.money << "$ " << "\t The Dealer has " << dealer.money << "$\n";
			BetBowl = bet * 2;
			std::cout << "  The Bet Bowl: " << BetBowl << "$\n\n";

			std::cout << "  You bet " << bet << "$\n";
			std::cout << "  Winner of this round receives " << BetBowl << "$\n";

			Sleep(2000);
			system("cls");

			// Player's turn
			for (turnCount; turnCount < cards.size(); turnCount++) {
				drawCard = 'y';
				if (drawCard == 'y') {
					system("cls");
					cards[turnCount];
					
					std::cout << "  You drew card " << cards[turnCount].cardRank << cards[turnCount].cardSuit << '\n';

		    // Choose Aces value.
					if (cards[turnCount].cardRank == "Ace") {
						std::cout << "  Do you want the value to be 1 or 11 ?\n";
						std::cout << "    1. Value of 1 \n";
						std::cout << "    2. Value of 11 \n";
						
						std::cin >> Choice;

						while (Choice != '1' || Choice == '2') {

							Choice = _getch();

							switch (Choice) {
							case '1':
								cards[turnCount].cardValue = 1;
								break;
							case '2':
								cards[turnCount].cardValue = 11;
								break;
							default:
								std::cout << "  Sry having some problem with that on try the other key. -.- ...\n";
								break;
								clearCin();
							}
						}
						std::cout << "  Your total is " << cards[turnCount].cardValue << " points\n";
					}
					else {
						std::cout << "  The cards gives " << cards[turnCount].cardValue << " points\n";
					}
				}
				player.points = player.points + cards[turnCount].cardValue;

			
				if (player.points > 21) {
					std::cout << "  You got " << player.points << " and have lost this round.\n";
					dealerWon = 1;
					break;
				}

				std::cout << "\n  You currently have " << player.points << " points \n";
				std::cout << "  Do you want to draw another card? y/n \n";

				drawCard = _getch();
				drawCard = tolower(drawCard);

			
				if (drawCard == 'n') {
					break;
				}

			}

			Sleep(1000);
		
		    //Dealer
			if (player.points <= 21) {

			
				while (dealer.points <= player.points) {
					system("cls");
					turnCount++;
					cards[turnCount];
					std::cout << "  Dealer drew card " << cards[turnCount].cardRank << cards[turnCount].cardSuit << '\n';

					
					if (cards[turnCount].cardRank == "Ace") {
						if (dealer.points > 10) {
							cards[turnCount].cardValue = 1;
						}
						else {
							cards[turnCount].cardValue = 11;
						}
					}

					std::cout << "  Dealer total is " << cards[turnCount].cardValue << " points\n" << std::endl;

					dealer.points = dealer.points + cards[turnCount].cardValue;
					std::cout << "  Dealer now have " << dealer.points << " points.\n";


				
					if (dealer.points > 21) {
						std::cout << "  Ah I got " << dealer.points << " points, you've won this round\n";
						playerWon = 1;
						break;
					}
			
					else if (dealer.points == player.points) {
						std::cout << "  We both got " << dealer.points << " so this round is a tie\n";
						break;
					}
				
					else if (dealer.points > player.points) {
						std::cout << "  Dealer've got " << dealer.points << " points and won this round.\n";
						dealerWon = 1;
						break;
					}

					Sleep(1500);

				}
			}



			// Giving money to the winner
			if (playerWon == 1) {
				player.money = player.money + BetBowl;
				Sleep(5000);
			}
			if (dealerWon == 1) {
				dealer.money = dealer.money + BetBowl;
			    Sleep(5000);
			}

			

  // A tie: the money goes back to the owner.
			else if (playerWon == 0 && dealerWon == 0) {
				player.money = player.money + bet;
				dealer.money = dealer.money + bet;
			}
			
		
  // Resetting values.
			drawCard = 'y';
			turnCount = 0;

			bet = 0;
			BetBowl = 0;

			player.points = 0;
			dealer.points = 0;

			playerWon = 0;
			dealerWon = 0;
		}

		// One of you lost all of their money
		if (player.money == 0) {
			std::cout << "  Sry... No mony, no game.\n";
			std::cout << "  You wanna cash out another 100$ ?\n";
			std::cout << "  1. Yes Pleace \n";
			std::cout << "  1. Nah, not gonna wasted more money... \n";

			std::cin >> MoreMoney;
			switch (MoreMoney) {
			case '1':
				system("cls");
				std::cout << "  Nice a 100$ more in ^^\n";
				player.money = 100;
				Sleep(3000);
				break;

			case '2' :
				system("cls");
				std::cout << "  Aww ;-; \n";
				std::cout << "  Another time then? \n";
			    Sleep(3000);
				exit;

			default :
				break;
			}
			
		}
		if (dealer.money == 0) {
			system("cls");
			std::cout << "  Oh, you won all of my Money.\n";
			std::cout << "  It's fine I'll cash out another 100$ to play some more ^^\n";
			dealer.money = 100;
			Sleep(3000);
		}

		EndGame();
	}
}

// Shuffle Deck
void restock(std::vector<Card>& cards) {

	unsigned seed = (std::chrono::system_clock::now().time_since_epoch().count());

	std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

// Clear buffer from cin
void clearCin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}

void EndGame() {
	
	system("cls");

	std::cout << "  Good Game ~ ^^ ~ \n";
	std::cout << "  Thankz for joining a round of BlackJack!\n";
	std::cout << "  See you next time ^^\n";
 
	exit;
	
}

