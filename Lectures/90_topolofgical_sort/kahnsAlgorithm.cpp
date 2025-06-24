#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<int>> adjList;
    void addEdges(int u, int v, bool hasDirection){
        if(!hasDirection){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }else{
            adjList[u].push_back(v);
        }
    }

    void printGraph(){
        cout << "Adjecency List" << endl;
        
        for(auto it : adjList){
            cout << it.first << " -> " ;
            for(auto neighbor : it.second){
                cout << neighbor << " " ;
            }
            cout << endl ;
        }
    }
};


vector<int> topologicalSort(unordered_map<int, list<int>>& adjList, int noOfNodes , int noOfEdges){

    // find all indegree of the adjecent list. 
    vector<int> indegree(noOfNodes+1);
    for(auto node : adjList){
        for(auto neighbor: node.second){
            indegree[neighbor]++;

        }
    }

    // put 0 indegree nodes into the queue
    queue<int> q; 
    for(int i = 1; i < noOfNodes; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // do simple BFS
    vector<int> ans;
    while (!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbor : adjList[front]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 0){
                q.push(neighbor); 
            }
        }
    }
    
    return ans;
};

int main(){
    Graph g;
    int node, edge; 
    cout << "Enete Number of Nodes : ";
    cin >> node;
    cout << "Enter Number of Edges : "; 
    cin >> edge; 

    for(int i = 0; i < edge; i++){
        int u, v; 
        cin >> u >> v;
        g.addEdges(u, v, 1);
    }
    g.printGraph();

    vector<int> ans = topologicalSort(g.adjList, node, edge);

    if(ans.size() != node) {
    cout << "Cycle detected. Topological sort not possible." << endl;
    }

    for(auto it : ans){
        cout << it << " " ;
    }

}