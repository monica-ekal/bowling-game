
#include "Interface.h"
#include <iostream>


//Functions dealing with user input
//Ensure that the number of pins is valid: The total pins knocked down in each frame can be at most 10.
int Interface::nextRoll(const BowlingGame& game){
    if(rollNumber%2!=0 || game.getIsStrike()) prevRoll = 0 ;
    int pins{};
    std::cout<<"Enter number of pins knocked down from";
    for (int i = 0; i<11;i++)
        if(i+prevRoll<=10) std::cout<<"  "<<i;
    std::cout<<": ";
    std::cin>>pins;
    while(pins+prevRoll>10){
        std::cout<<"Please enter a number from the above choices: ";
        std::cin>>pins;
    }
    prevRoll = pins;
    return pins;
}

/*
* Keep track of the number of rolls.
* The maximum number is 21, if roll number 20 is a spare, or roll number 19 is a strike)
* [Through frames 1-9, a strike is counted as two rolls because no more pins are left for that frame]
*
*/
void Interface::prepareNextRoll(const BowlingGame& game){

    if(rollNumber>=19 && game.isExtraRoll()) {
        rollNumber++;
    } else {
        game.getIsStrike() ? rollNumber += 2 : rollNumber++;

    }


}

int Interface::getRollNumber () const{
    return rollNumber;
}


//Functions to display the scores on the console
void Interface::displayScore(const BowlingGame& game) {
    std::cout<<"\n";
    // printing the number of bottles knocked down
    for (int index = 0; index<game.getRolls().size(); index++)
    {
        if(checkVector(index, game.getFrames())) {

            std::cout<<" | ";
            if(checkVector(index, game.getAllStrikes())) std::cout<<"      x";
            else {
                std::cout << game.getRolls()[index];
                std::cout<<"    ";}

        } else {

            if(checkVector(index, game.getAllStrikes())) std::cout<<" x";
            else if (checkVector(index, game.getAllSpares())) std::cout << " /";
            else std::cout<<" "<<game.getRolls()[index];
        }
    }
    if(game.getScoresPerFrame().size()==10) std::cout<<" | ";
    std::cout<<"\n ";

    // printing scores
    std::vector <int> scoresPerFrame = game.getScoresPerFrame();
    for (auto scoreIt = scoresPerFrame.begin(); scoreIt != scoresPerFrame.end(); scoreIt++){
        std::cout<<"|";std::cout<<"___";
        if(*scoreIt>100)std::cout<<*scoreIt;
        else if(*scoreIt>10) std::cout<<"_"<<*scoreIt;
        else std::cout<<"_"<<*scoreIt<<"_";
        std::cout<<"___";
    }
    if(game.getScoresPerFrame().size()==10)std::cout<<"|";
    std::cout<<"\n\n";
}

bool Interface::checkVector(int index, std::vector <int> vec) {
    for(auto  it = vec.begin();it!=vec.end();it++){
        if (index==*it) return true;
    }
    return false;
}

// Return the final score
void Interface::getScore(const BowlingGame& game) const{
    std::cout<<"Final score : "<<game.getScore();
}