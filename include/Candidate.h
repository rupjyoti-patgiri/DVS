#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "Voter.h" // Already contains Person

class Candidate : public Person
{
public:
    Candidate(const std::string &id, const std::string &name);
};

#endif // CANDIDATE_H