#pragma once
#include "Graph.h"
#include <string>
#include <vector>
using std::string;

class Coalition
{
public:
    Coalition(int id , int currMandates, int size ) : coalitionID(id) , numOfMandates(currMandates) , offersCoalitionMade({}); //constructor  (check if we initialize bool array like that)
    void coalitionJoin(int PartyID) ; //gets the party ID that join the coalition and updates: numOfMandates, BiggestCoalition(for JoinPolicy),
                              // counterJoined (checks how many parties already joined (for 'shouldTerminate method) .

private:
    int coalitionID ;
    int numOfMandates ;
    vector<bool> offersCoalitionMade;  //if the coalition made an offer to 'i' party , then offersCoalitionMade[i]=true    --->TAMAR
    vector<Party&> coalitionParties ;
};





