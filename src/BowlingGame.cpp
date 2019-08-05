//
// Created by monica on 8/4/19.
//

//
// Created by monica on 8/2/19.
//


#include "BowlingGame.h"
#include <iostream>


// Record pins hit at every roll
void BowlingGame::roll(int pins) {

    rolls[currentRoll] = pins;
    evaluateRoll();
    currentRoll++;

}

// Calculate value of the roll
void BowlingGame::evaluateRoll() {


    if(isSpare) {
        totalScore += 10 + spareBonus(currentRoll);
        set(isSpare,false);
    }


    if(isStrike) {
        rollsAfterStrike++;
        if(rollsAfterStrike==2) {
            totalScore += 10 + strikeBonus(currentRoll);

            if (checkConsecutiveStrikes()){
                rollsAfterStrike --;
            } else {
                set(isStrike,false);
                set(rollsAfterStrike,0);
            }

        }
    }



    if(checkStrike(currentRoll)) {
        set(isStrike,true);
        startNewFrame();
    } else {
        if(isFrameComplete()){
            startNewFrame();
            if(checkSpare())
                set(isSpare,true);
            else
                totalScore+=addLastTwo(currentRoll);
        }
    }

}

// Return total score
int BowlingGame::getScore() {
    displayScore();
    return totalScore;
}


// Helper functions
int BowlingGame::spareBonus(int rollIndex){
    return rolls[rollIndex];
}

int BowlingGame::strikeBonus(int rollIndex){
    return addLastTwo(rollIndex);
}


int BowlingGame::addLastTwo(int rollIndex) {
    return rolls[rollIndex] + rolls[rollIndex-1];
}

bool BowlingGame::checkSpare() {
    return (addLastTwo(currentRoll) == 10);
}

bool BowlingGame::checkStrike(int rollIndex){
    return(rolls[rollIndex]==10);
}

bool BowlingGame::isFrameComplete() {
    return(currentRoll == firstRollOfFrame+1 );
}

bool BowlingGame::checkConsecutiveStrikes() {
    return checkStrike(currentRoll-1);
}


void BowlingGame::startNewFrame() {
    firstRollOfFrame = currentRoll+1;
}

void BowlingGame::set(int& var, int value){
    var = value;
}

void BowlingGame::set(bool& var, bool value){
    var = value;
}

void BowlingGame::displayScore() {
    std::cout<<"Final score: "<<totalScore<<" points!\n";
}




