//A bowling score calculator that keeps track of the score in each frame.


#include <vector>

#ifndef BOWLINGGAME_BOWLINGGAME_H
#define BOWLINGGAME_BOWLINGGAME_H
class BowlingGame {



    int rollsAfterStrike, totalScore;
    bool isStrike, isSpare, allowBonusRoll;
    std::vector <int> scoresPerFrame, rolls, strikes, spares, frames;


public:

    BowlingGame(): isStrike{false}, isSpare{false}, allowBonusRoll{false}, frames{0}, totalScore{0}, rollsAfterStrike{0}{};

    void roll(int pins);

    int addLastTwo();

    int getScore();

    bool checkStrike();

    bool checkSpare();

    int spareBonus();

    int strikeBonus();

    void evaluateRoll();

    bool checkFrameComplete();

    void set(int &variable, int value);

    void set(bool &variable, bool value);

    bool checkConsecutiveStrikes();

    void addToTotal(int score);

    bool getIsStrike();

    void frameReset();

    bool getExtraRoll();

    //Display functions

    void displayScore();

    bool checkVector(int index, std::vector <int> vec);



};
#endif //BOWLINGGAME_BOWLINGGAME_H


