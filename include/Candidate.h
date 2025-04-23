#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>

class Candidate
{
public:
    Candidate(const std::string &id, const std::string &name);
    std::string getId() const;
    std::string getName() const;

private:
    std::string id;
    std::string name;
};

#endif // CANDIDATE_H