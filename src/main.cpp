#include "ElectionCommission.h"
#include <iostream>
using namespace std;

int main()
{
    ElectionCommission ec;
    int choice;
    do
    {
        cout << "\n1. Register Voter\n"
             << "2. Register Candidate\n"
             << "3. Start Election\n"
             << "4. Show Results\n"
             << "5. Delete Results\n"
             << "6. Exit\n"
             << "Enter choice: ";
        cin >> choice;
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
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}