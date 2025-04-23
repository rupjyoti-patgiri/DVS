CXX = g++
CXXFLAGS = -std=c++11

SRC = src/Voter.cpp src/Candidate.cpp src/Election.cpp src/ElectionCommission.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
INC = -Iinclude

all: OnlineVotingSystem

OnlineVotingSystem: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o OnlineVotingSystem

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ) OnlineVotingSystem