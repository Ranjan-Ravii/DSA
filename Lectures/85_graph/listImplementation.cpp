#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
template <typename T>

class Graph
{

public:
    // unordered_map for mapping of node and its adjecent nodes in a list.
    unordered_map<T, list<T>> adj;

    void addEdge(T v, T u, bool direction)
    {

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

int main(){

    Graph<int> g; 

    int n , m; 
    cout << "Enter the numbers of nodes : " ;
    cin >> n;
    cout << "\nEnter the numbers of edges : " ;
    cin >> m;

    for(int i = 0; i < m; i++){
        int u , v;
        cin >> u  >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

}
