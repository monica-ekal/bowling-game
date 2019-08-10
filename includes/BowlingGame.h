// A console based bowling score calculator
// Monica Ekal, 2019.

#ifndef BOWLINGGAME_BOWLINGGAME_H
#define BOWLINGGAME_BOWLINGGAME_H
#include <vector>
#include "Interface.h"

class BowlingGame {

    int rollsAfterStrike, totalScore;
    bool isStrike, isSpare, bonusRoll;
    std::vector <int> scoresPerFrame, rolls, strikes, spares, frames;

public:

    BowlingGame(): isStrike{false}, isSpare{false}, bonusRoll{false}, frames{0}, totalScore{0}, rollsAfterStrike{0}{};

    bool checkFrameComplete();

    bool checkStrike();

    bool checkSpare();

    bool checkConsecutiveStrikes();

    bool getIsStrike() const ;

    bool isExtraRoll() const ;

    int getScore() const;

    int addLastTwo();

    int spareBonus();

    int strikeBonus();

    void roll(int pins);

    void evaluateRoll();

    void set(int &variable, int value);

    void set(bool &variable, bool value);

    void addToTotal(int score);

    void bonusRollCheck();

    void frameReset();

    friend void Interface::displayScore(const BowlingGame& game);

};
#endif //BOWLINGGAME_BOWLINGGAME_H