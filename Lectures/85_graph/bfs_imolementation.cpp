#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;
// template <typename T>

class Graph{
    public:
    // unordered_map for mapping of node and its adjecent nodes in a list.
    unordered_map<int, list<int>> adj;

    void addEdge(int v, int u, bool direction){
        adj[u].push_back(v);
        if (direction == 0)
        { // if graph is not direction make v -- u path
            adj[v].push_back(u);
        }
    }

    // function to print the node and its adjecent lists.

    void printAdjList(){
        for (auto i : adj){
            cout << i.first <<  "-> " ;
            for(auto j : i.second){
                cout << j << ", ";
            }
            cout << endl; 
        }
    }
};

vector<int> bfs(int start, unordered_map<int, list<int>> &adjList){
    unordered_map<int , bool> visited; 
    vector<int> ans; 
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto neighbor : adjList[frontNode]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return ans;
}

int main(){

    Graph g; 
    int n , m; 
    cout << "Enter the numbers of nodes : " ;
    cin >> n;
    cout << "\nEnter the numbers of edges : " ;
    cin >> m;

    cout << "Adjecent edge of the graph." << endl;

    for(int i = 0; i < m; i++){
        int u , v;
        cin >> u  >> v;
        g.addEdge(u, v, 0);
    }
    // g.printAdjList();


    unordered_map<int, list<int>> adjList = g.adj;
    vector<int> result =  bfs(0, adjList );

    cout << "Bradth first search." << endl;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " " ;
    }

}
