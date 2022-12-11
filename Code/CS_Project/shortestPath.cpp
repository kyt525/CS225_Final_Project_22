#include "shortestPath.h"

double shortestDistance(VP shortestPath) {
    double dist = 0;
    for (unsigned i = 0; i < shortestPath.size(); i++) {
        dist += shortestPath.at(i).second;
    }
    return dist;
}

VP shortestPath(TravelGraph graph, TravelGraph::airport source, TravelGraph::airport destination) {
   VP distances;                       //return vector
    //pair<airport,double> vertex;        //list of airports in path

    // vector<TravelGraph::airport.id> v;                 //vector for airports
    // vector<double> dist;                //vector for distances FROM SOURCE
    // //bool found = false;
    // priority_queue<pair<double, TravelGraph::airport>> Q;
    // //double distance;

    // for (TravelGraph::airport node : graph){       //iterate through all the airports on the graph
    //     if (node.id != source.id){
    //         v.push_back(-1);                //airport = null
    //         dist.push_back(-1);             //distance = infinity
    //     }//distances.push_back(vertex);
    //     Q.push(make_pair(distanceBetween(source, node), node));
    // }
    // dist[0] = 0;                        //source airport dist = 0
    // v[0] = source;                      //source airport = source

    // //TravelGraph path;
    // pair<double, airport> temp = Q.top();
    // Q.pop();    //pop the source airport
    // bool valid_step;
    // pair<double, airport> step;
    // while(!Q.empty() && step.id != destination.id){
    //     step = Q.top();
    //     vector<pair<airport, double>> adj = getAdjacent(temp.second);
    //     valid_step = false;
    //     int i;
    //     for (i = 0; i < adj.size(); i++)
    //         if (step.second.id == adj[i].first.id) {
    //             valid_step = true;
    //             break;
    //         }
    //     if (valid_step){
    //         distances.push_back(adj[i]);
    //         temp = step;
    //     }
    //     int x;
    //     for (int j = 0; j < adj.size(); j++){
    //         x = adj[j].second + step.first;
    //         if (x < dist[step.id] && dist[step.id] != -1){
    //             dist[step.second.id] = x;
    //             v[step.second.id] = temp;
    //         }
    //     }
    //     Q.pop();
    // }
    return distances;

}


double betweennessCentrality(TravelGraph graph, TravelGraph::airport node) {
    // for all sources and destinations (where s != d != node), centrality is the ratio:
    // shortest paths containing node/ total shortest paths
    vector<pair<TravelGraph::airport, VP>> adjLists = graph.getAdjLists();
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
