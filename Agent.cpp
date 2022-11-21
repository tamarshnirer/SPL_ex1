#include "/home/spl211/Downloads/SPL/include/Agent.h"
#include "/home/spl211/Downloads/SPL/include/Simulation.h"
#include "/home/spl211/Downloads/SPL/include/SelectionPolicy.h"
#include "/home/spl211/Downloads/SPL/include/Party.h"

#include <iostream>
using namespace std;


#include "Agent.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}

Agent::~Agent ()
{
    if (mSelectionPolicy)
    {
        delete mSelectionPolicy;
    }
}

//Copy Constructor:
Agent::Agent(const Agent & other)
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mCoalition = other.mCoalition;

   // mSelectionPolicy = other.mSelectionPolicy->policyClone(); //after define "policyClone" at selection policy class - creates a deep copy of selection policy
    //update the list of nominees (ex: nominees = other.nominees; )
    //coalitionPtr = other.coalitionPtr   ---->if well get a coalition pointer
}

//Move Constructor:
Agent::Agent (Agent && other) {
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mCoalition = other.mCoalition;
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    //nominees = other.nominees;
    //coalitionPtr = other.coalitionPtr   --> if well get a coalition pointer
    //other.coalition = nullptr;    --> if well get a coalition pointer

}

//Copy Assignment Operator:
Agent& Agent::operator=(const Agent & other)
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mCoalition = other.mCoalition;
    //mSelectionPolicy = other.mSelectionPolicy->clonePolicy(); //after define "policyClone" at selection policy class - creates a deep copy of selection policy
    //nominees = other.nominees;
    return *this;
}

//Move Assignment Operator :
Agent & Agent::operator=(Agent && other) {
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mCoalition = other.mCoalition;
   // nominees = other.nominees;
//    if(mSelectionPolicy) {
//        delete mSelectionPolicy;
//    }
//    if(coalition) {
//        delete coalition;
//    }
//    coalition = other.coalition;
//    other.coalition = nullptr;
//    mSelectionPolicy = other.mSelectionPolicy->clonePolicy();
//    other.mSelectionPolicy = nullptr;

    return *this;
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
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
    mPartyId = newId;
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