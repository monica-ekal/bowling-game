//
// Created by monica on 8/4/19.
//

#ifndef BOWLINGGAME_BOWLINGGAME_H
#define BOWLINGGAME_BOWLINGGAME_H

#endif //BOWLINGGAME_BOWLINGGAME_H


class BowlingGame {


    int rolls[21];
    int currentRoll{}, firstRollOfFrame{}, rollsAfterStrike{};
    int totalScore{};
    bool isStrike{false};
    bool isSpare{false};

public:

    void roll(int pins);

    void startNewFrame();

    int addLastTwo(int rollIndex);

    int getScore();

    bool checkStrike(int rollIndex);

    bool checkSpare();

    int spareBonus(int rollIndex);

    int strikeBonus(int rollIndex);

    void evaluateRoll();

    bool isFrameComplete();

    void set(int &variable, int value);

    void set(bool &variable, bool value);

    bool checkConsecutiveStrikes();

    void displayScore();

};