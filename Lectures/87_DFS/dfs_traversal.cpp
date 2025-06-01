#include <iostream>
#include <vector>
#include <list>
#include <queue>
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

void dfsHelper(int start, unordered_map<int, bool> &visited, 
    unordered_map<int, list<int>>& adjList, vector<int> &ans ){

    visited[start] = true;
    ans.push_back(start);

    for(auto it : adjList[start]){
        if(!visited[it]){
            dfsHelper(it, visited, adjList, ans);
        }
    }
}

vector<int> dfs(int root, unordered_map<int, list<int>>& adjList ){
    unordered_map<int, bool> visited; 
    vector<int> ans;
    
    dfsHelper(root, visited, adjList, ans);

    return ans;
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

    unordered_map<int, list<int>> adj = g.adjList;
    vector<int> res = dfs(1, adj);
    cout << "DFS traversal : " << endl;
    for(auto it : res){
        cout << it << " " ;
    }
    cout << endl ;
    

}