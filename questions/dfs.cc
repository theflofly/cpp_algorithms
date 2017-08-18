#include<iostream>
#include <list>
#include <queue>
#include "questions.h"

using namespace std;

void Graph::DFS(int s, int distance) {

    visited[s] = true;
    cout << s << " ";
    distances[s].distance = distance;
    for (int edge: adj[s]) {
        if (visited[edge] == false) {
           visited[edge] = true;
           distances[edge].predecessor = s;
           DFS(edge, distance + 1);
        }
    }

}

void DFS::Process() {
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);    
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);

    g.DFS(2, 0);

    cout << endl;

    for (int i = 0; i < 4; i ++) {
        cout << "vertex " << i << " distance " << g.distances[i].distance << " predecessor " << g.distances[i].predecessor << endl;
    }
}