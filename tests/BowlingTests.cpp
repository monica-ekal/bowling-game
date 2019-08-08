// Tests from http://butunclebob.com/ArticleS.UncleBob.TheBowlingGameKata


#include <iostream>
#include <gtest/gtest.h>
#include "../src/BowlingGame.h"

using namespace std;


class BOWLINGtest : public ::testing::Test{
public:

protected:
    BowlingGame game;
    void manyRolls(int rolls,int pins){
        for (int i = 0; i<rolls;i++){
            game.roll(pins);
        }
    }

    void rollSpare(){
        game.roll(5);
        game.roll(5);
    }

    void rollStrike(){
        game.roll(10);
    }
};


/*
TEST(BOWLINGtest, SimpleAssert){

    ASSERT_TRUE(true);
}

TEST(BOWLINGtest, canInstantiateBowlingGame){

    BowlingGame game;
}
 */

TEST_F(BOWLINGtest, canComputeScoreAllZeros){

    manyRolls(20,0);
    ASSERT_EQ(game.getScore(),0);
}

TEST_F(BOWLINGtest, canComputeScoreAllOnes){

    manyRolls(20,1);
    ASSERT_EQ(game.getScore(),20);

}


TEST_F(BOWLINGtest, canHandleSpares){

    rollSpare();
    game.roll(1);
    manyRolls(17,0);
    ASSERT_EQ(game.getScore(),12);

}


TEST_F(BOWLINGtest, canHandleStrikes){

    rollStrike();
    game.roll(1);
    game.roll(1);
    manyRolls(17,0);
    ASSERT_EQ(game.getScore(),14);

}



TEST_F(BOWLINGtest, canHandlePerfectGame){
    manyRolls(12,10);
    ASSERT_EQ(game.getScore(),300);
}