#pragma once
#include "/home/spl211/Downloads/SPL/include/Simulation.h"
#include "/home/spl211/Downloads/SPL/include/Party.h"
#include "/home/spl211/Downloads/SPL/include/Graph.h"

class SelectionPolicy {
    public:
        SelectionPolicy();
        virtual Party *select();
 };

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        virtual Party *select();
        
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        virtual Party *select();
 };