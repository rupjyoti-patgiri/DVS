#include "Voter.h"
using namespace std;

// ✅ Implementing base class methods
Person::Person(const string &id, const string &name)
    : id(id), name(name) {}

string Person::getId() const { return id; }
string Person::getName() const { return name; }

// ✅ Voter constructor uses base class constructor
Voter::Voter(const string &id, const string &name)
    : Person(id, name) {}