#include "shortestPath.h"

double shortestDistance(VP shortestPath) {
    double dist = 0;
    for (unsigned i = 0; i < shortestPath.size(); i++) {
        dist += shortestPath.at(i).second;
    }
    return dist;
}

VP shortestPath(TravelGraph graph, TravelGraph::airport source, TravelGraph::airport destination) {

}


double betweennessCentrality(TravelGraph graph, TravelGraph::airport node) {
    // for all sources and destinations (where s != d != node), centrality is the ratio:
    // shortest paths containing node/ total shortest paths
    vector<pair<TravelGraph::airport, VP>> adjLists = graph.getAdjLists;
    double nodeCount = 0; 
    double totalCount = 0;

    for (unsigned i = 0; i < adjLists.size(); i++) { // source airport
        TravelGraph::airport source = adjLists.at(i).first;
        if (node.id == source.id) {
            continue;
        }
        for (unsigned j = 0; j < adjLists.size(); j++) { // desination airport
            TravelGraph::airport dest = adjLists.at(j).first;
            if (node.id == dest.id || source.id == dest.id) {
                continue;
            }
            VP path = shortestPath(graph, source, dest);
            for (unsigned k = 0; k < path.size(); k++) {
                if (path.at(k).first.id == node.id) {
                    nodeCount++;
                    break;
                }
            }
            totalCount++;
        }
    }
    return (nodeCount/totalCount);
}