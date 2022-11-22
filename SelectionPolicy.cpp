#pragma once
#include "/home/spl211/Downloads/SPL/include/Simulation.h"
#include "/home/spl211/Downloads/SPL/include/Party.h"
#include "/home/spl211/Downloads/SPL/include/Graph.h"
#include "/home/spl211/Downloads/SPL/include/SelectionPolicy.h"

SelectionPolicy::SelectionPolicy() {};
Party *SelectionPolicy::select(Graph g, Agent &agent) {return nullptr;}        

Party *MandatesSelectionPolicy::select(Graph g, Agent &agent) {
    Party *chosen = nullptr;
    int max_mandates = -1;
    for  (int i = 0; i<g.getNumVertices(); i++) {
        if ((i!=agent.getPartyId()) && (g.getParty(i).getState()!=2) && (g.getEdgeWeight(agent.getPartyId(),i)>0) && agent.getCoalition().getOfferCoalitionMade(i)==true) {
            if (g.getParty(i).getMandates() > max_mandates) {
                max_mandates = g.getParty(i).getMandates();
                *chosen = g.getParty(i);
            }
        }
    }
    return chosen;
}


SelectionPolicy* MandatesSelectionPolicy::clonePolicy() {

    MandatesSelectionPolicy* CMPolicy = new MandatesSelectionPolicy(this->getPartyID());
    return CMPolicy;
}



 Party *EdgeWeightSelectionPolicy::select(Graph g, Agent &agent) {
    Party *chosen = nullptr;
    int max_weight = -1;
    for  (int i = 0; i<g.getNumVertices(); i++) {
        if ((i!=agent.getPartyId()) && (g.getParty(i).getState()!=2 && (g.getEdgeWeight(agent.getPartyId(),i)>0) && agent.getCoalition().getOfferCoalitionMade(i)==true)) {
            if (g.getEdgeWeight(agent.getPartyId(), i) > max_weight) {
                max_weight = g.getEdgeWeight(agent.getPartyId(), i);
                *chosen = g.getParty(i);
            }
        }
    }
    return chosen;
}




SelectionPolicy* EdgeWeightSelectionPolicy::clonePolicy() {
    EdgeWeightSelectionPolicy* CWPolicy = new EdgeWeightSelectionPolicy (this->getPartyID());
    return CWPolicy ;
}




