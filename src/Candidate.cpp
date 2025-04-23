#include "Candidate.h"

Candidate::Candidate(const std::string &id, const std::string &name)
    : id(id), name(name) {}

std::string Candidate::getId() const { return id; }
std::string Candidate::getName() const { return name; }
