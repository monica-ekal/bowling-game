// A console based bowling score calculator
// Monica Ekal, 2019.
#include <vector>

#ifndef BOWLINGGAME_BOWLINGGAME_H
#define BOWLINGGAME_BOWLINGGAME_H
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

    int addLastTwo();

    int spareBonus();

    int strikeBonus();

    int getScore() const;

    void roll(int pins);

    void evaluateRoll();

    void set(int &variable, int value);

    void set(bool &variable, bool value);

    void addToTotal(int score);

    void bonusRollCheck();

    void frameReset();

    std::vector<int> getAllStrikes() const;

    std::vector<int> getAllSpares() const;

    std::vector<int> getScoresPerFrame() const;

    std::vector<int> getFrames() const;

    std::vector<int> getRolls() const;

};
#endif //BOWLINGGAME_BOWLINGGAME_H


