#include "/home/spl211/Downloads/SPL/include/Agent.h"
#include "/home/spl211/Downloads/SPL/include/Simulation.h"
#include "/home/spl211/Downloads/SPL/include/SelectionPolicy.h"
#include "/home/spl211/Downloads/SPL/include/Party.h"

#include <iostream>
using namespace std;


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
}

Agent::~Agent ()   //Deconstructor 
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
    coalitionPtr = other.coalitionPtr ;
   // mSelectionPolicy = other.mSelectionPolicy->policyClone(); //after define "policyClone" at selection policy class - creates a deep copy of selection policy
       //and more if needed or added

}

//Move Constructor:
Agent::Agent (Agent && other) {
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    coalitionPtr = other.coalitionPtr;
    other.coaltionPtr = nullptr ;
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    
    //and more if needed or added

}  

//Copy Assignment Operator:
Agent& Agent::operator=(const Agent & other)
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mCoalition = other.mCoalition;
    //mSelectionPolicy = other.mSelectionPolicy->clonePolicy(); //after define "policyClone" at selection policy class - creates a deep copy of selection policy
    
        //and more if needed or added

    return *this;
}

//Move Assignment Operator :
Agent & Agent::operator=(Agent && other) {
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mCoalition = other.mCoalition;

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
    
    
        //and more if needed or added


    return *this;
}



void Agent::newAgentClone(Simulation& s, int partyID) {
    int agentNewId = s.getAgentVector()->size();
    s.getAgentVector()->push_back(Agent(agentNewId ,partyID, mSelectionPolicy));
    Agent newAgent = s.getAgentVector()->back();
    newAgent.coalition = coalition;
}



Coalition & Agent::getCoalition()
{
    return &mCoalition
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
    Party *chosen = this->getSelectionPolicy()->select(sim.getGraph(), *this);
    if (chosen!=nullptr) {
        chosen->sendOffer(*this);
        mCoalition->setOfferedMadeByParty(chosen->getId());
    }
}
