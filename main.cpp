//Author Richard Rosenthal
//Date 01/02/2021

#include <iostream>
#include <ctime>
using namespace std;

bool newLevel();
bool isWinner();

int main() {

    bool alive = true;



    string playerName; //To hold the player's name
    int generatedNumber; //The computer will pick a random number based on seed created.
    int falseNumber1; //holds a false number for the user to pick
    int falseNumber2; // holds a false number for the user to pick
    int userGuess; // to hold the user guess

    int month = 1;
    int score = 0; // hold the players score
    int difficulty = 10; //increases the range of random numbers

    cout << "Welcome to escape 2020!" << endl;
    cout << "What is your name?" << endl;
    cin >> playerName;
    cout << "Hello " << playerName << "! You must correctly guess the answer in order to survive each month!" << endl;
    cout << "If you make it to 2021 you win!" << endl;
    cout << "You will be given a hint each round. Good Luck " << playerName << "!" << endl;

    while (alive){

        unsigned seed = time(0); //create a seed based on the computer's time
        srand (seed);

        //generate random numbers
        generatedNumber = rand() % difficulty + 1;
        falseNumber1 = generatedNumber + (rand () % 5 + 1);
        falseNumber2 = generatedNumber - falseNumber1;


        //this will initalize an array with the answers at random positions
        int choiceArray[3];
        for (int i = 0; i < 3; i++){
            int randomChoice = rand () % 3 + 1;
            if (randomChoice == 1){
                choiceArray[i] = generatedNumber;
            }
            else if (randomChoice == 2){
                choiceArray[i] = falseNumber1;
            }
            else if (randomChoice == 3){
                choiceArray[i] = falseNumber2;
            }
            else {
                choiceArray[i] = 2020; //this should never be assigned if I coded everything correctly.
            }

        }

        cout << "Welcome to month #" << month << "! of 2020" << endl;
        cout << "You must select the correct answer in order to make it to the next month." << endl;
        cout << "What is the correct answer? A:" << choiceArray[0] << " B:" << choiceArray[1] << " C: " << choiceArray[2] << endl;
        cout << "Type in the exact number that you think is correct. " << endl;
        cin >> userGuess;

        if (userGuess == generatedNumber){
            alive = true;
            score++;
            difficulty++;
            month++;
            if (month > 12){
                alive = false;
            }
        } else {
            alive = false;
        }

    }

    cout << "Your final score is " << month << endl;
    if (month > 12){
        cout << "Congratulations!! You escaped the year 2020! What a relief!" << endl;
    } else {
        cout << "Ughhh you're stuck in 2020" << endl;
    }
    return 0;
}
