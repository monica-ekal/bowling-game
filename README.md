# bowling-game
A bowling score calculator on a frame-by-frame basis.

Test-driven development (TDD) was used to develop this code. The test sections in /tests/ are from the [Bowling Game Kata](http://butunclebob.com/ArticleS.UncleBob.TheBowlingGameKata) by Robert C. Martin (Uncle Bob). While the code in Uncle Bob's slides calculates the total score after all rolls, this program makes a running total of the score. 

## Scoring in bowling (from the Bowling Game Kata slides)

The game consists of 10 frames. In each frame the player has two opportunities to knock down 10 pins.  The score for the frame is the total number of pins knocked down, plus bonuses for strikes and spares.

A spare (denoted by /) is when the player knocks down all 10 pins in two tries.  The bonus for that frame is the number of pins knocked down by the next roll. So in frame 3 above, the score is 10 (the total number knocked down) plus a bonus of 5 (the number of pins knocked down on the next roll.)

A strike (denoted by x) is when the player knocks down all 10 pins on his first try.  The bonus for that frame is the value of the next two balls rolled.

In the tenth frame a player who rolls a spare or strike is allowed to roll the extra balls to complete the frame.  However no more than three balls can be rolled in tenth frame.

## Instructions
1. Run in Console/Terminal using-

`./bin/BowlingGame`

2. Enter the number of pins knocked down at each roll as prompted.

## An example of the console output
![alt text](/media/output_example.png)






