
#include <iostream>
#include "BowlingGame.h"
#include "Display.h"

int nextRoll();
void prepareNextRoll();

BowlingGame game;
int rollNumber = 1;
int prevRoll;



int main (int argc, char *argv[]) {


    int pins;
    while(rollNumber<21 ||(rollNumber==21&&game.getExtraRoll())) {

        pins = nextRoll();
        game.roll(pins);
        game.displayScore();
        prepareNextRoll();


    }

    game.getScore();
    return 0;
}


/*
 * Functions dealing with user input
 */


/*
 * Ensure that the number of pins is valid: The total pins knocked down in each frame can be at most 10.
 */
int nextRoll(){
    if(rollNumber%2!=0 || game.getIsStrike()) prevRoll = 0 ;
    int pins{};
    std::cout<<"Enter number of Pins Knocked down from";
    for (int i = 0; i<11;i++)
        if(i+prevRoll<=10) std::cout<<"  "<<i;
    std::cout<<": ";
    std::cin>>pins;
    while(pins+prevRoll>10){
        std::cout<<"Please enter a number from the above choices: ";
        std::cin>>pins;
    }
    prevRoll = pins;
    return pins;
}

/*
 * Keep track of the number of rolls.
 * The maximum number is 21, if roll number 20 is a spare, or roll number 19 is a strike)
 * [Through frames 1-9, a strike is counted as two rolls because no more pins are left for that frame]
 *
 */
void prepareNextRoll(){

        if(rollNumber>=19 && game.getExtraRoll()) {
            rollNumber++;
        } else {
        game.getIsStrike() ? rollNumber += 2 : rollNumber++;

    }


}


