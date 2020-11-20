# Group 89
## Aditya Gupta - 3035662297 & Aayush Batwara - 3035660433

The game we have created is an electronic version of blackjack. In this game, the player can play the game blackjack against the dealer, choosing their own bet amount to try and win as much money as possible against the casino. 

### Game Rules
1. In Blackjack, the player has to try to beat the dealer without going bust.
2. Numbered cards are worth their actual value, face cards are all worth 10, and Aces are worth either 1 or 11, whichever leads to a better hand.
3. The player begins with 2 faceup cards while the dealer receives one facedown and one faceup card.
4. If the sum of the values of the players cards exceeds 21, they go "bust" and automatically lose the round.
5. The player can either "hit" or "stand" on each turn. If they "hit" then they receive another card. If they stand, they do not want more cards and the round is over.
6. The player can also choose to "double". If the player "doubles", then they double their original bet, but can only receive one more card before their turn is over.
7. If you receive an Ace and a face card as your first two cards, then you have received Blackjack and you automatically receive your bet plus 1.5 times your bet back.
8. If you win a round normally, you receive your original bet plus an amount equal to your original bet back.
9. After you stand, it is now the dealers turn. The dealer will hit until their score is 17 or higher, after which they will stand. The winner of the round is the individual with the score closest to 21, but not more than 21. 

### Gameplay
1. The user places a bet for a given round.
2. Two cards each are dealt to the user and dealer. The user's cards are both face up while the dealer has one face up and one face down card.
3. It is first the user’s turn (unless the user is dealt a blackjack). The user continues to play until they choose to stand or go bust. Their options are:
    1. Hit: draw one more card
    2. Double: double initial bet and draw one last card
    3. Stand: end turn
4. Dealer’s turn
    1. If the dealer’s total is less than 17, then the dealer must hit. This process repeats until the dealer’s hand either totals to 17 or more or busts (goes above 21).
    2. However, if the player has already gone bust then the dealer does not need to draw any more cards, even if the score is less than 17.
    3. If there is a draw then no money is exchanged.
5. The user’s chip count is updated, and if there is a sufficient balance then the new round can begin. If not, then it is game over for this user.

### Features and Functions vis-a-vis given code requirements

### 1. Generation of random game sets or events
    • Each hand dealt to the user and dealer is always random, and each card is unique. Imported libraries like stdlib.h and ctime are used to randomly shuffle Deck arrays.
### 2. Data structures for storing game status
    • We have used a combination of pass by reference vs pass by value to alter the game status as the game progresses.
    • There is  a centralized function which calls secondary functions to run the different parts of the game - for example, main() begins the game but printBoard() prints the cards and winner() evaluates winner.
    • A Deck array is used, and in each round the array is re-shuffled. 
    • --------SOMETHING ABOUT CLASSES WITH SAVE/LOAD------
### 3. Dynamic memory management
    • Pointers and Dynamic Memory Management will be used primarily in the operations relating to the deck.
    • The deck values are  stored in an array which are retrieved using pointers.
    • Pass by values are used to alter the game status. For example, wallet (cash available to user) is updated depending on a win or a loss using pass by reference to a function called winner().
### 4. File input/output (e.g., for loading/saving game status)
    • Each new user is given a random alphanumeric code of 6 digits which serves as their ‘key’.
    • The game autosaves after each round.
    • A user can play the game, then quit the game, and then load the game by relaunching the game and inputting their original ‘key’.
### 5. Program codes in multiple files
    • The program code will be separated into multiple front end and back end files of .h and .cpp. Examples include winner.h, winner.cpp, user.h, and user.cpp.
    • We will use makefile to link up the relevant file dependencies based on how the files are divided in the final project.

### C/C++ Libraries used
#### iostream
    • 
#### unistd
    • For creating time delay when dealer draws cards
#### string
    • For using string types
#### iomanip
    • ??
#### random
    •  ??
#### sstream
    • ??
#### stdlib
    • For random number generation
#### ctime
    • For random number generation
#### 
    •  
    
 
### Compilation and Execution Instructions
1. Download the files from the github repository
2. Launch terminal and change the directory of the terminal to corresponding folder containing all the game files
3. Put terminal on full screen
4. Enter the command 'make main' followed by './main' 
5. Follow the prompts on screen to play the game. 

Note: Do not enter any invalid inputs or the program will not run as expected

#### References
https://www.contrib.andrew.cmu.edu/~gc00/reviews/pokerrules
