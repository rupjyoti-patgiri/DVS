#ifndef VOTER_H
#define VOTER_H

#include <string>
using namespace std;

class Voter
{
public:
    Voter(const string &id, const string &name);
    string getId() const;
    string getName() const;

private:
    string id;
    string name;
};

#endif // VOTER_H