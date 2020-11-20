#Compile files here

saveload.o: saveload.cpp saveload.h
	g++ -pedantic-errors -std=c++11 -c saveload.cpp

printDealerCards.o: printDealerCards.cpp printDealerCards.h
	g++ -pedantic-errors -std=c++11 -c printDealerCards.cpp

printPlayerCards.o: printPlayerCards.cpp printPlayerCards.h
	g++ -pedantic-errors -std=c++11 -c printPlayerCards.cpp

numberofDigits.o: numberofDigits.cpp numberofDigits.h
	g++ -pedantic-errors -std=c++11 -c numberofDigits.cpp

printBoard.o: printBoard.cpp printBoard.h printDealerCards.h printPlayerCards.h numberofDigits.h
	g++ -pedantic-errors -std=c++11 -c printBoard.cpp

findNumberofCards.o: findNumberofCards.cpp findNumberofCards.h
	g++ -pedantic-errors -std=c++11 -c findNumberofCards.cpp

readScore.o: readScore.cpp readScore.h findNumberofCards.h
	g++ -pedantic-errors -std=c++11 -c readScore.cpp

winner.o: winner.cpp winner.h
	g++ -pedantic-errors -std=c++11 -c winner.cpp

displayInstructions.o: displayInstructions.cpp displayInstructions.h
	g++ -pedantic-errors -std=c++11 -c displayInstructions.cpp

user.o: user.cpp user.h findNumberofCards.h readScore.h
	g++ -pedantic-errors -std=c++11 -c user.cpp

dealer.o: dealer.cpp dealer.h findNumberofCards.h readScore.h printBoard.h
	g++ -pedantic-errors -std=c++11 -c dealer.cpp

main.o: main.cpp
	g++ -pedantic-errors -std=c++11 -c main.cpp

# Make sure to link file to main (if required)
main: main.o displayInstructions.o winner.o readScore.o findNumberofCards.o user.o dealer.o printBoard.o printDealerCards.o printPlayerCards.o numberofDigits.o saveload.o
	g++ -pedantic-errors -std=c++11 main.o displayInstructions.o winner.o readScore.o findNumberofCards.o user.o dealer.o printBoard.o printDealerCards.o printPlayerCards.o numberofDigits.o saveload.o -o main

# BELOW is the main: target but without linking the printDealerCards, printPlayerCards, numberofDigits' .o files (this doesn't work tho)
# main: main.o displayInstructions.o winner.o readScore.o findNumberofCards.o user.o dealer.o printBoard.o
# 	g++ -pedantic-errors -std=c++11 main.o displayInstructions.o winner.o readScore.o findNumberofCards.o user.o dealer.o printBoard.o -o main


clean:
	rm -f *.o main

.PHONY: clean
