
//
// Created by monica on 8/2/19.
//


#include "BowlingGame.h"
#include <iostream>
#include <vector>
#include <iomanip>


// Store number of pins knocked down at every roll, and find their score
void BowlingGame::roll(int pins) {
    rolls.push_back(pins);
    evaluateRoll();
}


// Calculate value of every roll
void BowlingGame::evaluateRoll() {

    if(isSpare) {                                   // Spare bonus if previous roll was a spare
        addToTotal(10 + spareBonus());
        set(isSpare,false);
    }

    if(isStrike || rollsAfterStrike==1) {           // Strike bonus if previous roll was a strike
        rollsAfterStrike++;
        if(rollsAfterStrike==2) {
            addToTotal(10 + strikeBonus());
            if (checkConsecutiveStrikes()){         // Keep track in case of two or more successive strikes
                rollsAfterStrike --;
            } else {
                set(rollsAfterStrike,0);
            }
        }
        set(isStrike,false);
    }

    if (checkStrike()) {                            // for every roll, check if it is a strike/spare/2nd roll in the frame
        set(isStrike, true);
        frameReset();
    } else {
        if (!bonusRoll) {                           // for rolls after spare or strike in frame 10, ignore this block

            if (checkFrameComplete()) {
                if (checkSpare()){
                    set(isSpare, true);
                } else{
                    addToTotal(addLastTwo());
                }

                frameReset();
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
        bonusRollCheck();
        return true;
    }
    return false;
}

bool BowlingGame::checkStrike() {
    if (*std::prev(rolls.end()) == 10) {
        strikes.push_back(rolls.size() - 1);
        bonusRollCheck();
        return true;
    }
    return false;
}

bool BowlingGame::checkConsecutiveStrikes() {
    if( *(std::prev(rolls.end(),2)) == 10) {
        return true;
    }
    return false;
}

// If extra rolls will be necessary in the 10th frame, set bonusRoll to true.
void BowlingGame::bonusRollCheck() {
    if (frames.size() == 10) set(bonusRoll, true);
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
    if(!bonusRoll)
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
    return bonusRoll;
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
    std::cout<<"Final score : "<<totalScore;
    return totalScore;
}
