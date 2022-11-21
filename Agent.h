#pragma once

#include <vector>
#include "/home/spl211/Downloads/SPL/include/Graph.h"
#include "/home/spl211/Downloads/SPL/include/Coalition.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    virtual ~ Agent();                        //Destructor
    Agent(const Agent & other);               //CopyConstructor
    Agent(Agent && other);                    //MoveConstructor
    Agent & operator=(const Agent & other);   //CopyAssignment
    Agent & operator=(Agent && other);        //MoveAssignment
    int getPartyId() const;
    int getId() const;
    SelectionPolicy* getSelectionPolicy() const;
    void step(Simulation &);
    Agent& operator=(const Agent &other);
    void setPartyId(int newId);
    void setId(int newId);
    Coalition & getCoalition();

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Coalition *mCoalition;
};
