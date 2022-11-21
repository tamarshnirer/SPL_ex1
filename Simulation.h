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

private:
    Graph mGraph;
    vector<Agent> mAgents;
};
