#pragma once

#include <vector>
#include "/home/spl211/Downloads/SPL/include/Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    int getPartyId() const;
    int getId() const;
    SelectionPolicy* getSelectionPolicy() const;
    void step(Simulation &);
    Agent& operator=(const Agent &other);
    void setPartyId(int newId);
    void setId(int newId);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;
};
