#pragma once
#include "/home/spl211/Downloads/SPL/include/Coalition.h"
#include "/home/spl211/Downloads/SPL/include/Simulation.h"
#include "/home/spl211/Downloads/SPL/include/Party.h"
//#include "JoinPolicy.h"
//#include "SelectPolicy.h"



Coalition :: Coalition(int id , int currMandates , int numParties ) : coalitionID(id) , numOfMandates(currMandates) , numOfPTotalParties(numParties) {  //constructor
    for (int i = 0; i < numOfParties; i++) {
        offersCoalitionMade.push_back(false) ;
    }
}

void Coalition::coalitionJoin (Party & party)
{
    numOfMandates = numOfMandates + party.getMandates() ;   //update the number of mandates of the coalition
    coalitionParties.push_back(party) ;
}

bool Coalition::getOfferCoalitionMade(int id) {
    return offersCoalitionMade[id];
}

void Coalition::setOfferedMadeByParty(int partyId) 
{
    offersCoalitionMade[partyId] = true;
}


int Coalition::getMandates()
{
    return numOfMandates;
}
