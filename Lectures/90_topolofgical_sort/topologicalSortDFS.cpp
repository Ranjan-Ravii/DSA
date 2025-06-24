#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <unordered_map>
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

void topologicalHelper(int node, unordered_map<int, list<int>>& adjList,
        unordered_map<int, bool>& visited, stack<int>& st){
    visited[node] = true;   

    for(auto neighbor : adjList[node]){
        if(!visited[neighbor]){
            topologicalHelper(neighbor, adjList, visited, st);
        }
    }

    st.push(node);
}

void topologicalSortDFS(unordered_map<int, list<int>>& adjList, stack<int>& st){
    unordered_map<int, bool> visited;
    
    for(auto it : adjList){
        int node = it.first;
        if(!visited[node]){
            topologicalHelper(node, adjList, visited, st);
        }
    }
}


/* 

// ****************** using DFS ***********************
int main(){

    Graph g; 
    int u, v;
    cout << "Enter the number of Nodes : " ; 
    cin >> u;
    cout << "Enter the number of Edges : ";
    cin >> v; 

    for(int i = 0; i < v; i++){
        int x, y;
        cin >> x >> y;
        g.addEdges(x , y, 1);
    }
    g.printGraph();
    

    stack<int> st;
    topologicalSortDFS(g.adjList, st);

    //print topological order
    cout << "Printing the topological sorted order" << endl;
    while (!st.empty()){
        int top = st.top();
        st.pop();
        cout << top << " " ;
    }

}
*/


// *************************** using Kahn's algorithm   ************************
int main(){
    Graph g2;
    int x, y; 
    cout << "Enete Number of Nodes : ";
    cin >> x;
    cout << "Enter Number of Edges : "; 
    cin >> y; 

    for(int i = 0; i < y; ++i){
        int u, v; 
        cin >> u, v;
        g2.addEdges(u, v, 1);
    }
    g2.printGraph();

    
    

}
