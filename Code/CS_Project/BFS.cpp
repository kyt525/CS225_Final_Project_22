#include "BFS.h"

BFS::BFS(const vector<pair<TravelGraph::airport, vector<pair<TravelGraph::airport, double>>>> adj) {
    adjLists = adj;
}

pair<TravelGraph::airport, vector<pair<TravelGraph::airport, double>>>* BFS::find(const int a1) {
    for(unsigned i = 0; i < adjLists.size(); i++) {
        TravelGraph::airport a2 = adjLists.at(i).first;
        if(a1 == a2.id)
            return &adjLists.at(i);
    }
}

vector<int> BFS::allAirports(TravelGraph::airport source) {
    // get the number of vertices
    int vertices = adjLists.size();
    // a boolean map to store whether the vertex has been visited
    unordered_map<int, bool> visited;
    // a queue to maintain queue of vertices whose adjacency list is to be checked
    queue<int> queue;
    // get the id of source airport
    int curr = source.id;
    // the result vector
    vector<int> result;

    // initialize all airports to not visited
    for(int i = 0; i < vertices; i++) 
        visited[adjLists[i].first.id] = false;

    // add the source airport
    visited[curr] = true;
    queue.push(curr);

    while(!queue.empty()) {
        // enqueue a vertex from queue and add it to the result vector
        curr = queue.front();
        result.push_back(curr);
        queue.pop();
 
        // get all adjacent vertices of the dequeued vertex. 
        // if an adjacent vertex has not been visited, then mark it visited and enqueue it
        pair<TravelGraph::airport, vector<pair<TravelGraph::airport, double>>>* airport = find(curr);
        vector<pair<TravelGraph::airport, double>> list = (*airport).second;
        for(int i = 0; i < list.size(); i++) {
            // get the id of the i-th adjacent airport
            int adjAirport = list[i].first.id;
            if (!visited[adjAirport]) {
                visited[adjAirport] = true;
                queue.push(adjAirport);
            }
        }
    }

    // return the result vector containing all airport id's after BFS
    return result;
}
