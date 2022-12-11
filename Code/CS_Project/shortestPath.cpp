#include "shortestPath.h"

double shortestPath::shortestDistance(VP shortestPath) {
    double dist = 0;
    for (unsigned i = 0; i < shortestPath.size(); i++) {
        dist += shortestPath.at(i).second;
    }
    return dist;
}

//shortestPath:
//
VP shortestPath::Dijkastra(TravelGraph graph, TravelGraph::airport source, TravelGraph::airport destination) {
    VP distances;
    vector<TravelGraph::airport> v;                 //vector for airports
    vector<double> dist;  
    priority_queue<pair<double, TravelGraph::airport>, vector<pair<double, TravelGraph::airport>>, greater<pair<double, TravelGraph::airport>>> Q;
    bool found = false;

    vector<pair<TravelGraph::airport, VP>> adjlist = graph.getAdjLists();
    vector<pair<TravelGraph::airport, double>> adj;
    int l = 0;
    for (unsigned i = 0; i < adjlist.size(); i++){
        adj = graph.getAdjacent(source);
        if (adj[l].first.id == i){
            v.push_back(source);                //airport = null
            dist.push_back(adj[l].second);
            pair<double, TravelGraph::airport> abc(dist[i], TravelGraph::airport());
            //Q.push(abc);

            //Q.push(make_pair(dist[i],adj[l].first));
            l++;
        }
        else if(i == source.id){
            v.push_back(TravelGraph::airport());
            dist.push_back(0);
            pair<double, TravelGraph::airport> abc(dist[i], TravelGraph::airport());
            //Q.push(abc);
            //Q.push(make_pair(dist[i],TravelGraph::airport()));
        }
        else{
            v.push_back(TravelGraph::airport());                //airport = null
            dist.push_back(-1);
        } 
    }

    pair<double, TravelGraph::airport> prev = Q.top();
    pair<double, TravelGraph::airport> step;
    double distance;

    Q.pop();

    while(!Q.empty()){
        step = Q.top();
        
        if(step.second.id == destination.id) 
            found = true;
    
        adj.clear();
        adj = graph.getAdjacent(step.second);
        for (int i = 0; i < adj.size(); i++){
            //v[adj[i].first.id] = step.second;
            distance = step.first + adj[i].second;
            Q.push(make_pair(distance,adj[i].first));
            if (dist[adj[i].first.id] == -1 || distance < dist[adj[i].first.id]){
                dist[adj[i].first.id] = distance;
                v[adj[i].first.id] = prev.second;
            }
        }   
        if (found)
            break;   
        else prev = step;    
    }
    distances.push_back(make_pair(destination,dist[destination.id] - dist[v[destination.id].id]));
    int temp_airport = destination.id;
    while(temp_airport != source.id){
        distances.push_back(make_pair(*(graph.find(temp_airport)).first, dist[temp_airport] - dist[v[temp_airport].id]));
        temp_airport = v[temp_airport].id;
    }
    reverse(distances.begin(),distances.end());
    return distances;
}


double shortestPath::betweennessCentrality(TravelGraph graph, TravelGraph::airport node) {
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
            VP path = shortestPath::shortestPath(graph, source, dest);
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
