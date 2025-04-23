#include "Voter.h"

Voter::Voter(const std::string &id, const std::string &name)
    : id(id), name(name) {}

std::string Voter::getId() const { return id; }
std::string Voter::getName() const { return name; }
