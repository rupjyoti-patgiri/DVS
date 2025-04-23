#ifndef VOTER_H
#define VOTER_H

#include <string>
using namespace std;

// Base class
class Person
{
protected:
    string id;
    string name;

public:
    Person(const string &id, const string &name);
    string getId() const;
    string getName() const;
};

// Voter inherits from Person
class Voter : public Person
{
public:
    Voter(const string &id, const string &name);
};

#endif // VOTER_H