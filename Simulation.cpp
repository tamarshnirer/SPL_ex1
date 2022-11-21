#include "/home/spl211/Downloads/SPL/include/Simulation.h"
#include "/home/spl211/Downloads/SPL/include/Graph.h"
class graph;

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    numOfParties = graph.getNumVertices() ;
    joinedParties[numOfParties] = {0};  //initialize the array with all 0 (false)
    for (Agent agent : agents) {
        joinedParties[agent.getPartyId()] = true ;
        //should set here the nominees of each agent

        //here we should init all actions on agent ---> with Tamar
    }
}


//   methods for agents and parties



void Simulation::step()
{
    for (int i = 0; i < numOfParties; i++)  //party steps
    {
        mGraph.getParty(i).step(*this);
    }
    for (Agent a: mAgents){  //agent steps
        a.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    if(biggestCoalition > 0  || counterJoined == numOfParties ){
        return true ;
    }
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}



//should add all methods for party and agents   ----> Tamar

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> ret ;

    //after well make the coalition pointer
    for(Coalition c : coalitionPtr){
        vector<int> vec;
        for(party& p : c.coalitionParties) {
            vec.push_back(p.getId());
        }
        ret.push_back(vec) ;
    }
    return ret ;
}
