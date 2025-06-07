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

bool cycleDetectionBFS(int start, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited){
    
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto neighbor : adjList[frontNode]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = frontNode;
            }

            else if(visited[neighbor] && parent[frontNode] != neighbor){
                return true;
            }
        }
    }

    return false;
}

bool isCyclic(unordered_map<int, list<int>>& adjList) {
    unordered_map<int, bool> visited;

    for (auto& pair : adjList) {
        int node = pair.first;
        if (!visited[node]) {
            if (cycleDetectionBFS(node, adjList, visited)) {
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