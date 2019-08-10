// A console based bowling score calculator
// Monica Ekal, 2019.
/*
 * This class consists of methods that keep the score after every roll
 */
#include "BowlingGame.h"

//----Store number of pins knocked down at every roll, and find their score----//

void BowlingGame::roll(int pins) {
    rolls.push_back(pins);
    evaluateRoll();
}

void BowlingGame::evaluateRoll() {

    if(isSpare) {                                   // Spare bonus if previous roll was a spare
        addToTotal(10 + spareBonus());
        setVar(isSpare,false);
    }

    if(isStrike || rollsAfterStrike==1) {           // Strike bonus if previous roll was a strike
        rollsAfterStrike++;
        if(rollsAfterStrike==2) {
            addToTotal(10 + strikeBonus());
            if (checkConsecutiveStrikes()){         // Keep track in case of two or more successive strikes
                rollsAfterStrike --;
            } else {
                setVar(rollsAfterStrike,0);
            }
        }
        setVar(isStrike,false);
    }

    if (checkStrike()) {                            // for every roll, check if it is a strike/spare/2nd roll in the frame
        setVar(isStrike, true);
        frameReset();
    } else {
        if (!bonusRoll) {                           // for rolls after spare or strike in frame 10, ignore this block

            if (checkFrameComplete()) {
                if (checkSpare()){
                    setVar(isSpare, true);
                } else{
                    addToTotal(addLastTwo());
                }

                frameReset();
            }
        }
    }
}

//----Helper functions for calculating the score----//

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

//----Functions for checking if the roll results in a strike or spare----//

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
    if (frames.size() == 10) setVar(bonusRoll, true);
}

//----Functions for keeping track of the frames----//

// Check if there have been two rolls in the current frame
bool BowlingGame::checkFrameComplete() {
    return (rolls.size() - 1 == frames.back() + 1);

}
// store the first roll of this frame
void BowlingGame::frameReset() {
    if(!bonusRoll)
        frames.push_back(rolls.size());
}

//----Setting functions for changing isSpare, isStrike and allowBonusRoll----//

template <typename T>
void BowlingGame::setVar(T& var, T value ){
    var = value;
}

//----Functions for main and Class Interface to access properties form Bowling Game----//

int BowlingGame::getScore() const{
    return totalScore;
}

bool BowlingGame::getIsStrike() const{
    return isStrike;
}

bool BowlingGame::isExtraRoll() const{
    return bonusRoll;
}