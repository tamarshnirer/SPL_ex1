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


Party::~Party ()
{
    if (this->mJoinPolicy)
    {
        delete mJoinPolicy;
    }
}

//Copy Constructor:
Party::Party(const Party & other)
{
    mId = other.mId;
    mJoinPolicy =other.mJoinPolicy;
    mCoalition = other.mCoalition;
    mState = other.mState;
    mOffers = other.mOffers;
    mName =other.mName;
    timer = other.timer;
    mMandates = other.mMandates;
    return *this;
}

//Move Constructor:
Party::Party (Party && other) {
    mId = other.mId;
    mJoinPolicy =other.mJoinPolicy;
    mCoalition = other.mCoalition;
    mState = other.mState;
    mOffers = other.mOffers;
    mName =other.mName;
    timer = other.timer;
    mMandates = other.mMandates;
    return *this;

}

//Copy Assignment Operator:
Party& Party::operator=(const Party & other)
{
    mId = other.mId;
    mJoinPolicy =other.mJoinPolicy;
    mCoalition = other.mCoalition;
    mState = other.mState;
    mOffers = other.mOffers;
    mName =other.mName;
    timer = other.timer;
    mMandates = other.mMandates;
    return *this;
}

//Move Assignment Operator :
Party & Party::operator=(Party && other) {
    mId = other.mId;
    mMandates = other.mMandates;
    mState = other.mState;
    mOffers = other.mOffers;
    if(mJoinPolicy) {
        delete mJoinPolicy;
    }
    if(mCoalition) {
        delete mCoalition;
    }
    mCoalition = other.mCoalition;
    other.mCoalition = nullptr;
    mJoinPolicy = other.mJoinPolicy->clonePolicy();
    other.mJoinPolicy = nullptr;

    return *this;
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
        Agent ag = new Agent(*chosen);
        ag.setPartyId(this->mId);
        int nextAgentId = s.getAgents().size()-1;
        ag.setId(nextAgentId);
        chosen->getCoalition().coalitionJoin(*this);
        s.addAgent(ag);
        s.setCounterJoined();
        s.updateBiggestCoalition(ag.mCoalition/getMandates())
    }

}



void Party::sendOffer(Agent &offerer) {
    this->mOffers.push_back(offerer);
}