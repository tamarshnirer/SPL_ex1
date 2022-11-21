#pragma once
#include "/home/spl211/Downloads/SPL/include/Simulation.h"
#include "/home/spl211/Downloads/SPL/include/JoinPolicy.h"

JoinPolicy::JoinPolicy() : {};

Agent *JoinPolicy::join(Party mParty ) {return nullptr;}        

Agent *MandatesJoinPolicy::join(Party mParty ) {
    int max_mandates = -1;
    Agent *chosen = nullptr; 
    for (int i = 0; i<mParty.getOffers().size(); i++)  {
        if (mParty.getOffers()[i].getCoalition().getMandates() > max_mandates) {
            max_mandates =mParty.getOffers()[i].getCoalition().getMandates();
            *chosen = mParty.getOffers()[i];
        }
    }
    return chosen;

}; 

Agent *LastOfferJoinPolicy::join(Party mParty) {
    return &mParty.getOffers()[mParty.getOffers().size()-1];
}
