//
// Created by monica on 8/4/19.
//

#include <vector>

#ifndef BOWLINGGAME_BOWLINGGAME_H
#define BOWLINGGAME_BOWLINGGAME_H
class BowlingGame {



    int rollsAfterStrike{};
    int totalScore{};
    bool isStrike{false};
    bool isSpare{false};
    bool allowBonusRoll{false};
    std::vector <int> scoresPerFrame{ };
    std::vector<int> rolls;
    std::vector <int> strikes{},spares{};
    std::vector <int> frames{0};



public:

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


