#include "ElectionCommission.h"
#include "Voter.h"
#include "Candidate.h"
#include <iostream>
#include <fstream>

void ElectionCommission::registerVoter()
{
    std::string id, name;
    std::cout << "Enter Voter ID: ";
    std::cin >> id;
    std::cout << "Enter Voter Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::ofstream out("data/voters.txt", std::ios::app);
    out << id << "," << name << "\n";
    std::cout << "Voter registered.\n";
}

void ElectionCommission::registerCandidate()
{
    std::string id, name;
    std::cout << "Enter Candidate ID: ";
    std::cin >> id;
    std::cout << "Enter Candidate Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::ofstream out("data/candidates.txt", std::ios::app);
    out << id << "," << name << "\n";
    std::cout << "Candidate registered.\n";
}

void ElectionCommission::startElection()
{
    Election election;
    std::string voterId, candidateId;
    while (true)
    {
        std::cout << "Enter Voter ID (or 'q' to quit): ";
        std::cin >> voterId;
        if (voterId == "q")
            break;
        std::cout << "Enter Candidate ID to vote for: ";
        std::cin >> candidateId;
        election.castVote(candidateId);
        std::cout << "Vote recorded.\n";
    }
}

void ElectionCommission::showResults()
{
    std::ifstream fin("data/candidates.txt");
    std::map<std::string, std::string> candidates;
    std::string line;
    while (std::getline(fin, line))
    {
        if (line.empty())
            continue;
        auto pos = line.find(',');
        std::string id = line.substr(0, pos);
        std::string name = line.substr(pos + 1);
        candidates[id] = name;
    }

    Election election;
    auto counts = election.countVotes();

    std::cout << "Election Results:\n";
    for (const auto &p : counts)
    {
        std::cout << candidates[p.first] << " (" << p.first << "): " << p.second << "\n";
    }
}

void ElectionCommission::deleteResults()
{
    Election election;
    election.resetResults();
    std::cout << "Results cleared.\n";
}
