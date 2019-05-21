#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

/*
 * rollDie() rolls a 6 sided die and returns the result as an int
 * Inputs: none
 * Outputs: int roll - the value that was rolled
 */

int rollDie(){
    int roll = (rand() % 6) + 1;
    return roll;
}

/*
 * playGame inputs the user's guess and plays a single round of the game.
 * A boolean value is treturned for whether or not they won.
 * Inputs: int guess - the user's guess
 * Outputs: bool win - whether the user won (1) or lost (0)
 *                  The variable win is not actually used.
 *                  Instead, returns of 0 and 1 are used directly.
 */

bool playGame(int guess){
    int roll;
    for(int i = 0; i < 3; i++){
        roll = rollDie();
        cout << "Roll #" << i + 1 << " is " << roll << endl;
        if(roll==guess){
            cout << " ** You Win! **" << endl;
            return 1;
        }
    }
    cout << " ** You Lose **" << endl;
    return 0;
}

/*
 * verifyBet take the user's current bet and balance and verifies
 * whether their bet is valid.
 * A bet is invalid if it is less than 0, greater than 100, or if
 * their current balance is less than 100, greater than their current
 * balance.
 * A bet of 0 is considered valid and is interpreted elsewhere
 * to mean that the user wishes to exit the game.
 * Inputs: int bet - the user's current bet
 *         int bank - the user's current bank balance
 * Outputs: bool valid - returns 1 if the user's bet is valid and 0 if it is not
 */

bool verifyBet(int bet, int bank){
    bool valid;
    if(bank > 100){
        if(bet >= 0 && bet <= 100){
            valid = 1;
        } else {
            cout <<"Error: You must wager between $1 and $100 (0 to exit): $";
            valid = 0;
        }
    } else {
        if(bet >= 0 && bet <= bank){
            valid = 1;
        } else {
            cout <<"Error: You must wager between $1 and $" << bank << " (0 to exit): $";
            valid = 0;
        }
    }
    return valid;
}

/*
 * getBet continually inputs a bet from the user, then calls
 * verifyBet to determine if the bet is valid.
 * The user is continually prompted to enter a bet until a valid
 * one is entered.
 * Inputs: int bank - the user's current bank balance. This value is passed to verifyBet
 * Outputs: int bet - the user's valid bet
 */

int getBet(int bank){
    int bet;
    do{
        cin >> bet;
    }while(verifyBet(bet, bank));
    return bet;
}

/*
 * getGuess continually prompts the user for a valid guess.
 * A guess is valid if it is between 1 and 6 inclusive, as
 * these are the only numbers on a 6 sided die.
 * If the guess is not valid, the user is prompted to enter a new guess.
 * Inputs: none
 * Outputs: int g - the user's valid guess
 */

int getGuess(){
    int g;
    cout << "\nEnter your point value (1 - 6): ";
    cin >> g;
    while(!(g >= 1 && g <= 6)){
        cout << "Error: Enter your point value, must be between 1 and 6: ";
        cin >> g;
    }
    return g;
}

// The main function. This is where the magic happens.

int main(){
    //declaration of variables
    const int maxGames = 100; //maxGames dictates how many times the user is permited to play. This helps avoid gambling addictions.
    int guess, bet; //guess - the user's guess | bet - the user's bet
    int bank = 100; //bank - the user's current bank balance. Starts at $100
    int wins = 0; //wins - counts the number of times the user has won
    int games = 0; //games - counts the number of games the user has played, regardless of the outcome
    double winPerc = 0; //winPerc - the percentage of wins the user had

    srand(time(NULL));

    //primary loop
    //this loops runs either maxGames times or until the user quits by entering a bet of 0
    do{
        //Tell the user their current balance and prompt for a bet
        cout << "Your current balance is: $" << bank << endl;
        cout << "Wager (0 to exit): $";

        //call to getBet to input the user's bet
        bet = getBet(bank);

        //checks to see if the user wants to quit (bet is 0)
        if (bet == 0) break;

        //call to getGuess to input the user's guess
        guess = getGuess();

        //a call to playGame determines whether the user won or lost
        //if the user won, their bet is added to their balance and wins is incremented
        //if the user lost, their bet is subtracted from their balance and wins is not incremented
        if(playGame(guess)){
            bank += bet;
            wins ++;
        } else {
            bank -= bet;
        }

        //increment total number of games
        //this is used to calculate winPerc later
        //when games becomes >= maxGames, the loop ends
        //      this functionality is used to avoid infinite loops
        games++;

        //if the user is out of money, the loop breaks and the user
        //     is informed they are out of money
        if(bank <= 0){
            cout << "Game Over!\n You're out of money.\nBetter luck next time." << endl;
            break;
        }
        //while statement of the loop.
        //the use of maxGames as opposed to simply while(true) helps avoid an unintentional infinite loop
        //maxGames is intentionally set very high as the user will likely never play that many games
        //if the loop exits due to the user playing maxGames games, the user is informed of this and asked to seek help
        //     as they likely have a gambling problem.
    }while(games < maxGames);

    //if the game is ending becuase maxGames was reached, the user is informed of this and asked to seek help
    if(games >= maxGames){
        cout << "You have played " << maxGames << " games.\nYou have a problem and are being cut off.\nPlease go seek help." << endl;
    }

    //output the user's final balance
    cout << "Your final balance is: $" << bank << endl;

    //calculate the user's win percentage (winPerc)
    //if the user did not play any games, an if statement is used to
    //     set winPerc to 0, so that a runtime error is avoided
    winPerc = static_cast<double>(wins) / static_cast<double>(games) * 100;
    if (games == 0){
        winPerc = 0;
    }

    //outputs the user's win percentage to the user
    cout << "You won " << wins << " times out of " << games << " for a winning percentage of "
         << fixed << setprecision(2) << winPerc << "%" << endl;

    //return 0
    return 0;
}
