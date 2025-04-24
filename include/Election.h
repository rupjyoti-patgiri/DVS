#ifndef ELECTION_H
#define ELECTION_H

#include <string>
#include <map>
using namespace std;

class Election
{
public:
    void castVote(const string &candidateId);
    map<string, int> countVotes() const;
    void resetResults();

private:
    const string resultsFile = "data/results.txt";
};

#endif // ELECTION_H