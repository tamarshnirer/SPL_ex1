#pragma once

#include <vector>

#include "/home/spl211/Downloads/SPL/include/Graph.h"
#include "/home/spl211/Downloads/SPL/include/Agent.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    void addAgent(Agent newAgent);



//should add all methods for party and agents   ----> Tamar


private:
    Graph mGraph;
    vector<Agent> mAgents;

    //two fields that give information about the terminates:
    int counterJoined ;  //checks how many parties already joined  --> needs to be initialized at the beginning of the simulation.
    int biggestCoalition ; //checks what is the number of mandates of the biggest coalition
    vector<bool> joinedParties; // initialize the simulation with the parties that already joined to coalition  ---> maybe vector better
    int numOfParties;
    vector<Coalition> coalitions;
};
