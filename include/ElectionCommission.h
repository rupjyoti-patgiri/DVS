#ifndef ELECTIONCOMMISSION_H
#define ELECTIONCOMMISSION_H

#include "Election.h"
#include <string>

class ElectionCommission
{
public:
    void registerVoter();
    void registerCandidate();
    void startElection(); // now shows candidates before voting
    void showResults();
    void deleteResults();
};

#endif // ELECTIONCOMMISSION_H