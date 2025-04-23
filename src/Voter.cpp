#include "Voter.h"
using namespace std;

Voter::Voter(const string &id, const string &name)
    : id(id), name(name) {}

string Voter::getId() const { return id; }
string Voter::getName() const { return name; }
