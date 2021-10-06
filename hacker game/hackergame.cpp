#include <iostream>
#include <ctime>


void PrintIntroduction(int Difficulty)
{
    // Main entrance
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room... \nEnter the correct code to continue... \n\n";
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    // Declare 3 number code 
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
  
    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << "\n";
    
    
    int GuessA, GuessB, GuessC;

    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player guess is correct 
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** You have cracked the level "  << Difficulty << " system. Nice job! Lets move the next one ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You got stabbed from back by a security guard! ***";
        return false;
    }
}



int main()
{
    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // Loop game until all levels completed
    {
        

        bool bLevelComplete = PlayGame(LevelDifficulty); 
        std::cin.clear(); // Clears any errors
        std::cin.ignore();  // Discards the buffer

        if (bLevelComplete)
        {
            //increase the level diffuculty
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "\n*** Sharp skills you got there! Our mission is done, I'll be waiting you at the hideout. ***";
    return 0;
}