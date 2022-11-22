#pragma once
#include "/home/spl211/Downloads/SPL/include/Coalition.h"
#include "/home/spl211/Downloads/SPL/include/Simulation.h"
#include "/home/spl211/Downloads/SPL/include/Party.h"
//#include "JoinPolicy.h"
//#include "SelectPolicy.h"



 Coalition(int id , int currMandates ) : coalitionID(id) , numOfMandates(currMandates) {}; //constructor

void Coalition::coalitionJoin (Party & party)
{
    int mandates = party.getMandates() ;
    numOfMandates = numOfMandates + mandates ;   //update the number of mandates of the coalition
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
