#pragma once
#include "/home/spl211/Downloads/SPL/include/Simulation.h"
#include "/home/spl211/Downloads/SPL/include/Party.h"
#include "/home/spl211/Downloads/SPL/include/Graph.h"

class SelectionPolicy { };

class MandatesSelectionPolicy: public SelectionPolicy{ };

class EdgeWeightSelectionPolicy: public SelectionPolicy{ };