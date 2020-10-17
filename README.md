# Group 89
## Aditya Gupta - 3035662297 & Aayush Batwara - 

The game we are trying to create is an electronic version of blackjack. In this game, the player can play the game blackjack against the dealer, choosing their own bet amount to try and win as much money as possible against the casino. 

### Game Rules
1. In Blackjack, the player has to try to beat the dealer without going bust.
2. Numbered cards are worth their actual value, face cards are all worth 10, and Aces are worth either 1 or 11, whichever leads to a better hand.
3. The player begins with 2 faceup cards while the dealer receives one facedown and one faceup card.
4. If the sum of the values of the players cards exceeds 21, they go "bust" and automatically lose the round.
5. The player can either "hit" or "stand" on each turn. If they "hit" then they receive another card. If they stand, they do not want more cards and the round is over.
6. If you receive an Ace and a face card as your first two cards, then you have received Blackjack and you automatically receive your bet plus 1.5 times your bet back.
7. If you win a round normally, you receive your original bet plus an amount equal to your original bet back.
8. After you stand, it is now the dealers turn. The dealer will hit until their score is 17 or higher, after which they will stand. The winner of the round is the individual with the score closest to 21, but not more than 21.


### Proposed Gameplay
1. User places bet for a given round
2. 2 cards are dealt to the user and computer. User has both face up, computer has 1 face up and 1 face down 
3. User’s turn (unless User was dealt a blackjack). User’s turn will go on until user chooses to stand or user goes bust. 
    1. Hit: draw one more card
    2. Stand: end turn
4. Dealer’s turn
    1. If the dealer’s total is less than 17, then dealer must hit. This process repeats until the dealer’s hand either totals to 17 or more or busts (goes above 21).
    2. However, if the player has already gone bust then the dealer does not need to draw any more cards, even if the score is less than 17 
    3. If there is a draw then no money is exchanged
5. The user’s chip count is updated, and if there is a sufficient balance then the new round can be clicked. If not, then it is game over for this user 


### Features and Functions vis-a-vis given code requirements
* Generation of random game sets or events
    * Each hand dealt to the user and dealer will always be random, but each card must be unique. Would need functions like DrawCard() (static?) arrays like Deck 
* Data structures for storing game status
    * Can use a combination of pass by reference vs pass by value to alter the game status as the game progresses 
    * There will be a centralized function which will call secondary functions to run the different parts of the game - e.g. main() will benign the came but DrawCard() will help draw the cards and EvaluateWinner() will Evaluate the winner 
* Dynamic memory management
    * 
* File input/output (e.g., for loading/saving game status)
    * Each new user will be given a random alphanumeric code of 6 digits which will be their ‘key’ 
    * The game will autosave after each round
    * User can load the game by inputting their ‘key’ after launching the program 
* Program codes in multiple files
    * We can separate the code into front end files (which will be responsible for board generation), backend game processing files and dealer AI files 
* Proper indentation and naming styles
    * 
* In-code documentation
    * 


#### References
