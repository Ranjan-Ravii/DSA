#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

class Graph {
    public: 
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction){
        adjList[u].push_back(v);
        if(direction == 0){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        cout << "printing adjList" << endl;
        for(auto i : adjList){
            cout << i.first <<  "-> " ;
            for(auto j : i.second){
                cout << j << ", " ;
            }
            cout << endl ;
        }
    }
};



bool cycleDetectionDFS(int start, int parent, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited ){
    visited[start] = true;

    for(auto neighbor : adjList[start]){
        if(!visited[neighbor]){
            bool cycleDetected = cycleDetectionDFS(neighbor, start, adjList, visited);
            if(cycleDetected){
                return true;
            }
        }
        else if(parent != neighbor){
            return true;
        }
    }

    return false;
}

bool isCyclic(unordered_map<int, list<int>>& adjList) {
    unordered_map<int, bool> visited;

    for (auto& pair : adjList) {
        int node = pair.first;
        if (!visited[node]) {
            if (cycleDetectionDFS(node, -1, adjList, visited)) {
                return true;
            }
        }
    }
    return false;
}


int main(){

    Graph g; 
    int n , m; 
    cout << "Enter the numbers of nodes : " ;
    cin >> n;
    cout << "\nEnter the numbers of edges : " ;
    cin >> m;

    cout << "Give Adjecent edge of the graph." << endl;
    for(int i = 0; i < m; i++){
        int u , v;
        cin >> u  >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();
    unordered_map<int, list<int>> adjecencyList = g.adjList;

    bool hasCycle = isCyclic(adjecencyList);

    if(hasCycle){
        cout << "The graph is cyclic." << endl;
    }
    else{
        cout << "The graph is not cyclic." << endl;
    }

}