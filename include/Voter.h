#ifndef VOTER_H
#define VOTER_H

#include <string>

class Voter
{
public:
    Voter(const std::string &id, const std::string &name);
    std::string getId() const;
    std::string getName() const;

private:
    std::string id;
    std::string name;
};

#endif // VOTER_H