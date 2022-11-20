#include "/home/spl211/Downloads/SPL/include/Agent.h"
#include "/home/spl211/Downloads/SPL/include/Simulation.h"
#include "/home/spl211/Downloads/SPL/include/SelectionPolicy.h"
#include "/home/spl211/Downloads/SPL/include/Party.h"

#include <iostream>
using namespace std;


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{

}


int Agent::getId() const
{
    return mAgentId;
}

void Agent::setId(int newId) 
{
    mAgentId = newId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::setPartyId(int newId) 
{
    mPartyId =  newId;
}


SelectionPolicy* Agent::getSelectionPolicy() const
{
    return mSelectionPolicy;
}

void Agent::step(Simulation &sim)
{
    Party *chosen = this->getSelectionPolicy()->select(sim, this->getId(), this->getPartyId());
    if (chosen!=nullptr) {
        chosen->sendOffer(*this);
    }
}

Agent& Agent::operator=(const Agent &other) {
    *mSelectionPolicy = (*(other.getSelectionPolicy()));
    mCoalitionId = other.mCoalitionId;
    return *this;
}