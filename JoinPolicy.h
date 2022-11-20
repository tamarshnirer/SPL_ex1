#pragma once
#include "/home/spl211/Downloads/SPL/include/Simulation.h"

class JoinPolicy {
    public:
        JoinPolicy() {};
        virtual Agent *join(Simulation &s, Party mParty ) {return nullptr;}        
 };
class MandatesJoinPolicy : public JoinPolicy {
    public:
        virtual Agent *join(Simulation &s, Party mParty ) {
            int max_mandates = -1;
            Agent *chosen = nullptr; 
            for (int i = 0; i<mParty.getOffers().size(); i++)  {
                if (s.getParty(mParty.getOffers()[i].getPartyId()).getMandates() > max_mandates) {
                    max_mandates = s.getParty(mParty.getOffers()[i].getPartyId()).getMandates();
                    *chosen = mParty.getOffers()[i];
                }
            }
            return chosen;
        }

}; //subclass of JoinPolicy

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        virtual Agent *join(Simulation &s, Party mParty) {
            return &mParty.getOffers()[mParty.getOffers().size()-1];
        }
}; //subclass of JoinPolicy