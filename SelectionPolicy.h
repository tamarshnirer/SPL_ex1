#pragma once
#include "/home/spl211/Downloads/SPL/include/Simulation.h"
#include "/home/spl211/Downloads/SPL/include/Party.h"

class SelectionPolicy {
    public:
        SelectionPolicy() {};
        virtual Party *select(Simulation &s, int agentID, int partyID) {return nullptr;}        
 };

class MandatesSelectionPolicy: public SelectionPolicy{
    public:    
        virtual Party *select(Simulation &s, int agentID, int partyID) {
            Party *chosen = nullptr;
            int max_mandates = -1;
            for  (int i = 0; i<s.getGraph().getNumVertices(); i++) {
                if ((i!=partyID) & (s.getGraph().getParty(i).getState()!=2)) {
                    if (s.getGraph().getParty(i).getMandates() > max_mandates) {
                        max_mandates = s.getGraph().getParty(i).getMandates();
                        *chosen = s.getGraph().getParty(i);
                    }
                }
            }
            return chosen;
        }
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:    
        virtual Party *select(Simulation &s, int agentID, int partyID) {
            Party *chosen = nullptr;
            int max_weight = -1;
            for  (int i = 0; i<s.getGraph().getNumVertices(); i++) {
                if ((i!=partyID) && (s.getGraph().getParty(i).getState()!=2)) {
                    if (s.getGraph().getEdgeWeight(partyID, i) > max_weight) {
                        max_weight = s.getGraph().getEdgeWeight(partyID, i);
                        *chosen = s.getGraph().getParty(i);
                    }
                }
            }
            return chosen;
        }
 };