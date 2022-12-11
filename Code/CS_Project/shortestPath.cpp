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
   vector<TravelGraph::airport> v;                 //vector for airports
    vector<double> dist;                //vector for distances FROM SOURCE
    //bool found = false;
    priority_queue<pair<double, TravelGraph::airport>> Q;
    //double distance;
    vector<pair<TravelGraph::airport, VP>> adjlist = graph.getAdjLists();
    for (int i = 0; i < adjlist.size(); i++){       //iterate through all the airports on the graph
        if (adjlist[i].first.id != source.id){
            v.push_back(TravelGraph::airport());                //airport = null
            dist.push_back(-1);             //distance = infinity
        }//distances.push_back(vertex);
        Q.push(make_pair(graph.distanceBetween(source, adjlist[i].first), adjlist[i].first));
    }
    dist[0] = 0;                        //source airport dist = 0
    v[0] = source;                      //source airport = source

    //TravelGraph path;
    pair<double, TravelGraph::airport> temp = Q.top();
    Q.pop();    //pop the source airport
    bool valid_step;
    pair<double, TravelGraph::airport> step;
    while(!Q.empty() && step.second.id != destination.id){
        step = Q.top();
        vector<pair<TravelGraph::airport, double>> adj = graph.getAdjacent(temp.second);
        valid_step = false;
        int i;
        for (i = 0; i < adj.size(); i++)
            if (step.second.id == adj[i].first.id) {
                valid_step = true;
                break;
            }
        if (valid_step){
            distances.push_back(adj[i]);
            temp = step;
        }
        double x;
        for (int j = 0; j < adj.size(); j++){
            x = adj[j].second + step.first;
            if (x < dist[step.second.id] && dist[step.second.id] != -1){
                dist[step.second.id] = x;
                v[step.second.id] = temp.second;
            }
        }
        Q.pop();
    }
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
