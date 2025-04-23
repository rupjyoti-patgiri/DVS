#include "Election.h"
#include <fstream>
using namespace std;

void Election::castVote(const string &candidateId)
{
    ofstream out(resultsFile, ios::app);
    out << candidateId << "\n";
}

map<string, int> Election::countVotes() const
{
    ifstream in(resultsFile);
    map<string, int> counts;
    string id;
    while (getline(in, id))
    {
        if (id.empty())
            continue;
        counts[id]++;
    }
    return counts;
}

void Election::resetResults()
{
    ofstream out(resultsFile, ios::trunc);
}