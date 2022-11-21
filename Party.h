#pragma once

#include <string>
#include <vector>

using std::string;

class JoinPolicy;
class Simulation;
class Agent;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    ~Party() {if (mJoinPolicy) delete mJoinPolicy;};
    Party(Party&& other);
    Party& operator=(const Party& other);
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    void sendOffer(Agent &offerer);
    std::vector<Agent> getOffers();
    const int & getId();

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    std::vector<Agent> mOffers;
    int timer;
    int mCoalitionID;
};
