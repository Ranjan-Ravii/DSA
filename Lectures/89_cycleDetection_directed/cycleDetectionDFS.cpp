#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adjList;
    void addEdges(int u, int v, bool isDirected){
        adjList[u].push_back(v);
        if(!isDirected){
            adjList[v].push_back(u);
        }        
    }

    void printAdj(){
        for(auto it : adjList){
            cout << it.first << " -> " ;
            for(auto neighbor : it.second){
                cout << neighbor << " " ;
            }
            cout << endl;
        }
    }
};

bool dfs(int start,unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, bool> dfsVisited){
    visited[start] = true; 
    dfsVisited[start] = true; 

    for(auto neighbor : adjList[start]){
        if(!visited[neighbor]){
            bool cycleDetected = dfs(neighbor, adjList, visited, dfsVisited);
            if(cycleDetected){
                return true;
            }
        }
        else if (dfsVisited[neighbor]){
            return true;
        }
    }
    dfsVisited[start] = false;
    return false;
}

bool isCyclic(unordered_map<int, list<int>> &adjList){
    unordered_map<int, bool> visited; 
    unordered_map<int, bool> dfsVisited; 

    for(auto it : adjList){
        int node = it.first;
        if(!visited[node]){
            bool cycleDetected =  dfs(node, adjList, visited, dfsVisited);
            if(cycleDetected) return true;
        }
    }
    return false;
}


int main(){

    Graph g;
    int m, n; 
    cout << "Enter number of nodes : " ;
    cin >> m; 
    cout << "Enter number of edges : " ;
    cin >> n; 

    for(int i = 0; i < n; ++i){
        int u , v;
        cin >> u  >> v;
        g.addEdges(u, v, 1);
    }
    g.printAdj();


    bool result = isCyclic(g.adjList);
    cout << "is cyclic : " << result << endl;

}

