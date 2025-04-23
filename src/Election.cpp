#include "Election.h"
#include <fstream>

void Election::castVote(const std::string &candidateId)
{
    std::ofstream out(resultsFile, std::ios::app);
    out << candidateId << "\n";
}

std::map<std::string, int> Election::countVotes() const
{
    std::ifstream in(resultsFile);
    std::map<std::string, int> counts;
    std::string id;
    while (std::getline(in, id))
    {
        if (id.empty())
            continue;
        counts[id]++;
    }
    return counts;
}

void Election::resetResults()
{
    std::ofstream out(resultsFile, std::ios::trunc);
}
