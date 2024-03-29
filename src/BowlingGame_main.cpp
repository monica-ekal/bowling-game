// A console based bowling score calculator
// Monica Ekal, 2019.

#include <iostream>
#include "../include/BowlingGame.h"

int main (int argc, char *argv[]) {
    BowlingGame game;                       // Score calculation class
    Interface console;                      // Class for requesting output and displaying score
    int pins;
    // Player gets 20 rolls unless a spare or strike is rolled in the last frame, when it is 21.
    while (console.getRollNumber() < 21 || (console.getRollNumber() == 21 && game.isExtraRoll())) {
        pins = console.nextRoll(game);
        game.roll(pins);
        console.displayScore(game);
        console.prepareNextRoll(game);
    }
    console.getScore(game);
    return 0;
}
