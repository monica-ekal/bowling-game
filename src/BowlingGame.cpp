
//
// Created by monica on 8/2/19.
//


#include "BowlingGame.h"
#include <iostream>
#include <vector>
#include <iomanip>


// Record pins hit at every roll
void BowlingGame::roll(int pins) {

    rolls.push_back(pins);
    evaluateRoll();
}


// Calculate value of every roll
void BowlingGame::evaluateRoll() {

    if(isSpare) {
        addToTotal(10 + spareBonus());
        set(isSpare,false);
    }

    if(isStrike || rollsAfterStrike==1) {
        rollsAfterStrike++;
        if(rollsAfterStrike==2) {
            addToTotal(10 + strikeBonus());
            if (checkConsecutiveStrikes()){
                rollsAfterStrike --;
            } else {
                set(rollsAfterStrike,0);
            }
        }
        set(isStrike,false);
    }

    if (checkStrike()) {
        set(isStrike, true);
        if (frames.size() == 10) set(allowBonusRoll, true);
        else frameReset();
    } else {
        if (!allowBonusRoll) {
            if (checkFrameComplete()) {
                if (checkSpare()){
                    set(isSpare, true);
                    if (frames.size() == 10) set(allowBonusRoll, true);}
                else
                    addToTotal(addLastTwo());
                if(!allowBonusRoll) frameReset();
            }
        }
    }


}


/*
 * Functions for calculating the score
 */

// Calculate bonuses for spares and strikes and scores per frame

int BowlingGame::spareBonus(){
    return *std::prev(rolls.end());
}

int BowlingGame::strikeBonus(){
    return addLastTwo();
}

int BowlingGame::addLastTwo() {
    return *std::prev(rolls.end()) + *std::prev(rolls.end() - 1);
}

// Keep a running total of the score

void BowlingGame::addToTotal(int score) {
    totalScore+=score;
    scoresPerFrame.push_back(totalScore);
}


/*
 * Functions for checking if the roll results in a strike or spare
 */

bool BowlingGame::checkSpare() {
    if(addLastTwo() == 10) {
        spares.push_back(rolls.size()-1);
        return true;
    }
    return false;
}

bool BowlingGame::checkStrike() {
    if (*std::prev(rolls.end()) == 10) {
        strikes.push_back(rolls.size() - 1);
        return true;
    }
    return false;
}

bool BowlingGame::checkConsecutiveStrikes() {
    if( *(std::prev(rolls.end())-1) == 10) {
        return true;
    }
    return false;
}



/*
 * Functions for keeping track of the frames
 */

// Check if there have been two rolls in the current frame
bool BowlingGame::checkFrameComplete() {
    return (rolls.size() - 1 == frames.back() + 1);

}

// store the first roll of this frame
void BowlingGame::frameReset() {
    frames.push_back(rolls.size());
}




/*
 * Setting functions for changing isSpare, isStrike and allowBonusRoll
 */

void BowlingGame::set(int& var, int value){
    var = value;
}

void BowlingGame::set(bool& var, bool value){
    var = value;
}


/*
 * Functions for main.cpp to access properties form Bowling Game
 */

bool BowlingGame::getIsStrike() {
    return isStrike;
}

bool BowlingGame::getExtraRoll() {
    return allowBonusRoll;
}





/*
 * Functions to display the scores on the console
*/
void BowlingGame::displayScore() {

    std::cout<<"\n";

    for (int index = 0; index<rolls.size(); index++)
    {
        if(checkVector(index, frames)) {

            std::cout<<" | ";
            if(checkVector(index, strikes)) std::cout<<"      x";
            else {
            std::cout << rolls[index];
            std::cout<<"    ";}

        } else {
            if(checkVector(index, strikes)) std::cout<<" x";
            else if (checkVector(index, spares)) std::cout << " /";
            else std::cout<<" "<<rolls[index];
        }


    }
    if(scoresPerFrame.size()==10) std::cout<<" | ";
    std::cout<<"\n ";

    // printing scores

    for (auto scoreIt = scoresPerFrame.begin(); scoreIt != scoresPerFrame.end(); scoreIt++){
        std::cout<<"|";std::cout<<"___";
        if(*scoreIt>100)std::cout<<*scoreIt;
        else if(*scoreIt>10) std::cout<<"_"<<*scoreIt;
        else std::cout<<"_"<<*scoreIt<<"_";
        std::cout<<"___";
    }
    if(scoresPerFrame.size()==10)std::cout<<"|";


    std::cout<<"\n\n";

}


bool BowlingGame::checkVector(int index, std::vector <int> vec) {

    for(auto  it = vec.begin();it!=vec.end();it++){
        if (index==*it) return true;

    }
    return false;
}


// Return the final score
int BowlingGame::getScore() {
    std::cout<<"Final score : "<<totalScore<<"\n";
    return totalScore;
}
