#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "Voter.h" // Already contains Person
using namespace std;

class Candidate : public Person
{
public:
    Candidate(const string &id, const string &name);
};

#endif // CANDIDATE_H