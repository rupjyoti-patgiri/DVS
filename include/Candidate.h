#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>
using namespace std;

class Candidate
{
public:
    Candidate(const string &id, const string &name);
    string getId() const;
    string getName() const;

private:
    string id;
    string name;
};

#endif // CANDIDATE_H