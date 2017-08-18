#include<iostream>
#include <list>
#include <queue>
#include "questions.h"

using namespace std;

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
    visited = new bool[V];
    for (int i = 0; i < V; i ++) {
        visited[i] = false;
        distances.push_back(GraphDistance{});
    }
}
 
void Graph::AddEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {

    deque<int> queue;
    queue.push_back(s);
    visited[s] = true;
    distances[s].distance = 0;

    while(!queue.empty()) {

        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (int adjacent: adj[s]) {
            if (!visited[adjacent]) {
                distances[adjacent].distance = distances[s].distance + 1;
                distances[adjacent].predecessor = s;
                visited[adjacent] = true;
                queue.push_back(adjacent);

            }
        }

    }

}

void BFS::Process() {
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);    
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);

    g.BFS(2);

    cout << endl;

    for (int i = 0; i < 4; i ++) {
        cout << "vertex " << i << " distance " << g.distances[i].distance << " predecessor " << g.distances[i].predecessor << endl;
    }
}