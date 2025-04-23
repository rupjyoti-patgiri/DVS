#include "Candidate.h"
using namespace std;

Candidate::Candidate(const string &id, const string &name)
    : id(id), name(name) {}

string Candidate::getId() const { return id; }
string Candidate::getName() const { return name; }
