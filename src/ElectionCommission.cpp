#include "ElectionCommission.h"
#include "Voter.h"
#include "Candidate.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
using namespace std;

void ElectionCommission::registerVoter()
{
    string id, name;

    // ✅ Step 1: Load existing voter IDs
    set<string> existingVoterIds;
    ifstream vin("data/voters.txt");
    string vline;
    while (getline(vin, vline))
    {
        if (vline.empty())
            continue;
        auto pos = vline.find(',');
        string existingId = vline.substr(0, pos);
        existingVoterIds.insert(existingId);
    }
    vin.close();

    // ✅ Step 2: Input and check for duplicates
    cout << "Enter Voter ID: ";
    cin >> id;
    if (existingVoterIds.find(id) != existingVoterIds.end())
    {
        cout << "Voter ID already exists. Registration failed.\n";
        return;
    }

    cout << "Enter Voter Name: ";
    cin.ignore();
    getline(cin, name);
    ofstream out("data/voters.txt", ios::app);
    out << id << "," << name << "\n";
    cout << "Voter registered.\n";
}

void ElectionCommission::registerCandidate()
{
    string id, name;

    // ✅ Step 1: Load existing candidate IDs
    set<string> existingCandidateIds;
    ifstream cinf("data/candidates.txt");
    string cline;
    while (getline(cinf, cline))
    {
        if (cline.empty())
            continue;
        auto pos = cline.find(',');
        string existingId = cline.substr(0, pos);
        existingCandidateIds.insert(existingId);
    }
    cinf.close();

    // ✅ Step 2: Input and check for duplicates
    cout << "Enter Candidate ID: ";
    cin >> id;
    if (existingCandidateIds.find(id) != existingCandidateIds.end())
    {
        cout << "Candidate ID already exists. Registration failed.\n";
        return;
    }

    cout << "Enter Candidate Name: ";
    cin.ignore();
    getline(cin, name);
    ofstream out("data/candidates.txt", ios::app);
    out << id << "," << name << "\n";
    cout << "Candidate registered.\n";
}

void ElectionCommission::startElection()
{
    // Load registered voters
    ifstream vfin("data/voters.txt");
    set<string> voters;
    string vline;
    while (getline(vfin, vline))
    {
        if (vline.empty())
            continue;
        auto pos = vline.find(',');
        voters.insert(vline.substr(0, pos));
    }
    vfin.close();

    // Display candidates
    ifstream cfin("data/candidates.txt");
    string cline;
    map<string, string> candidates;
    cout << "\n*** Candidates List ***\n";
    while (getline(cfin, cline))
    {
        if (cline.empty())
            continue;
        auto pos = cline.find(',');
        string id = cline.substr(0, pos);
        string name = cline.substr(pos + 1);
        candidates[id] = name;
        cout << "ID: " << id << " | Name: " << name << "\n";
    }
    cfin.close();
    cout << "\n\n";

    Election election;
    string voterId, candidateId;
    set<string> castedVote;

    while (true)
    {
        cout << "Enter Voter ID (or 'q' to quit): ";
        cin >> voterId;
        if (voterId == "q")
            break;
        if (voters.find(voterId) == voters.end())
        {
            cout << "Invalid Voter ID. Please register first.\n";
            continue;
        }

        if (castedVote.find(voterId) != castedVote.end()) {
            cout << "You have already voted!\n";
            continue;
        }

            cout << "Enter Candidate ID to vote for: ";
        cin >> candidateId;
        if (candidates.find(candidateId) == candidates.end())
        {
            cout << "Invalid Candidate ID. Please try again.\n";
            continue;
        }

         
        election.castVote(candidateId);
        castedVote.insert(voterId);     
        cout << "Vote recorded.\n";
    }
}

void ElectionCommission::showResults()
{
    // load candidates with their name and id in a map
    ifstream fin("data/candidates.txt");
    map<string, string> candidates;
    string line;
    while (getline(fin, line))
    {
        if (line.empty())
            continue;
        auto pos = line.find(',');
        candidates[line.substr(0, pos)] = line.substr(pos + 1);
    }
    fin.close();

    Election election;
    auto counts = election.countVotes();

    cout << "Election Results:\n";
    for (auto &p : counts)
    {
        cout << candidates[p.first] << " (" << p.first << "):Votes- " << p.second << "\n";
    }
}

void ElectionCommission::deleteResults()
{
    Election election;
    election.resetResults();
    cout << "Results cleared.\n";
}