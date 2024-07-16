#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int count=0;

// Function to generate computer's choice
string generateComputerChoice() 
{
    int randomNum = rand() % 3;
    if (randomNum == 0)
        return "rock";
    else if (randomNum == 1)
        return "paper";
    else if(randomNum == 2)
        return "scissors";
}

// Function to determine the winner
string determineWinner(string userChoice, string computerChoice) 
{
    if (userChoice == computerChoice)
        return "\n\tIt's a tie!";
        
    else if ((userChoice == "rock" && computerChoice == "scissors") ||
             (userChoice == "paper" && computerChoice == "rock") ||
             (userChoice == "scissors" && computerChoice == "paper"))
    {
        count=count+1;	
        return "\n\tYou win!";
	}
    
	else
        return "\n\tComputer wins!";
}

int main() 
{
	char playAgain;
    srand(time(nullptr)); //random number generator
    
    cout <<"\n    Welcome to Rock, Paper, Scissors Game!   " << endl;
    cout<<"\t(Press 'x' to exit)"<<endl;
    
    cout<<"\n\tYou have three choices:";
    cout<<"\n\t\t~ Rock";
    cout<<"\n\t\t~ Paper";
    cout<<"\n\t\t~ Scissors"<<endl;
    

    do {
        cout << "\n\tEnter your choice: ";
        string userChoice;
        cin >> userChoice;

        // Check if the user wants to exit
        if (userChoice == "x")
            break;

        // Validate user input
        if (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") 
		{
            cout << "\tInvalid choice! Please enter either rock, paper, or scissors." << endl;
            continue;
        }

        // Generate computer's choice
        string computerChoice = generateComputerChoice();

        cout << "\n\tYou chose: " << userChoice << endl;
        cout << "\tComputer chose: " << computerChoice << endl;

        // Determine the winner
        cout << determineWinner(userChoice, computerChoice) << endl;
        
        cout << "\n\tPlay again? (y/n): ";
        cin >> playAgain;

    } while (playAgain != 'n' && playAgain != 'N');
    
    cout<<"\n\tScore = "<<count;
    cout << "\n\tThanks for playing!" << endl;

    return 0;
}
