#include "/home/spl211/Downloads/SPL/include/Party.h"
#include "/home/spl211/Downloads/SPL/include/JoinPolicy.h"

#include <vector>

Party::Party(int id, string name, int mandates, JoinPolicy *jp) {
    this->mId = id; 
    this->mName = name; 
    this->mMandates = mandates; 
    this->mJoinPolicy =jp; 
    this->mState = Waiting;
    this->mOffers = {}; 
    int timer = 0;
}



std::vector<Agent> Party::getOffers() 
{
    return this->mOffers;
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

const int & Party::getId() {
    return mId;
}

void Party::step(Simulation &s)
{
    if ((mState == 0) && (this->getOffers().size() != 0)) {
        this->setState(CollectingOffers);
        this->timer = 1;
    }
    if (1<=this->timer<3) {
        this->timer +=1;
    }
    if (this->timer == 3) {
        Agent *chosen = mJoinPolicy->join(this);
        Agent newAgent(chosen);
        newAgent.setPartyId(this->mId);
        int nextAgent = s.getAgents().size()-1;
        newAgent.setId(nextAgent);
        newAgent.setPartyId(this->mId);
        chosen->getCoalition().coalitionJoin(*this);
        s.addAgent(newAgent);
    }

}



void Party::sendOffer(Agent &offerer) {
    this->mOffers.push_back(offerer);
}