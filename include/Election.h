#ifndef ELECTION_H
#define ELECTION_H

#include <string>
#include <map>

class Election
{
public:
    void castVote(const std::string &candidateId);
    std::map<std::string, int> countVotes() const;
    void resetResults();

private:
    const std::string resultsFile = "data/results.txt";
};

#endif // ELECTION_H