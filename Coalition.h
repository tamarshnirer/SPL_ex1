#pragma once
#include "/home/spl211/Downloads/SPL/include/Graph.h"
#include <string>
#include <vector>
using std::string;

class Coalition
{
public:
    Coalition(int id , int currMandates , int numOfParties );
    void coalitionJoin(Party & party) ; //gets the party ID that join the coalition and updates: numOfMandates, BiggestCoalition(for JoinPolicy),
                              // counterJoined (checks how many parties already joined (for 'shouldTerminate method) .
    int getMandates();
    bool getOfferCoalitionMade(int id);
    void setOfferedMadeByParty(int partyId);

private:
    int coalitionID ;
    int numOfMandates ;
    int numOfPTotalParties ;

    vector<bool> offersCoalitionMade ;  //if the coalition made an offer to 'i' party , then offersCoalitionMade[i]=true , after the iniztialize 
    vector<Party&> coalitionParties ;
};





