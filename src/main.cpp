#include "ElectionCommission.h"
#include <iostream>

int main()
{
    ElectionCommission ec;
    int choice;
    do
    {
        std::cout << "\n1. Register Voter\n"
                  << "2. Register Candidate\n"
                  << "3. Start Election\n"
                  << "4. Show Results\n"
                  << "5. Delete Results\n"
                  << "6. Exit\n"
                  << "Enter choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            ec.registerVoter();
            break;
        case 2:
            ec.registerCandidate();
            break;
        case 3:
            ec.startElection();
            break;
        case 4:
            ec.showResults();
            break;
        case 5:
            ec.deleteResults();
            break;
        case 6:
            std::cout << "Exiting.\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}

// To run

// g++ -std=c++11 -Iinclude `
// src\Voter.cpp ` src\Candidate.cpp ` src\Election.cpp ` src\ElectionCommission.cpp ` src\main.cpp ` - o OnlineVotingSystem.exe
                                                                                                         
// .\OnlineVotingSystem.exe
