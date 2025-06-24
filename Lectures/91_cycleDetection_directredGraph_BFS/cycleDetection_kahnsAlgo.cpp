#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    // create a adjList
    unordered_map<int, list<int>> adjList;
    for (auto node : edges)
    {
        int u = node.first;
        int v = node.second;

        adjList[u].push_back(v);
    }

    // make a indegree List
    vector<int> indegree(n + 1, 0);
    for (auto node : adjList)
    {
        for (auto neighbor : node.second)
        {
            indegree[neighbor]++;
        }
    }

    // insert nodes in queue whose indegree is 0
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // perform the BFS now

    int count = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        count++;

        for (auto neighbor : adjList[front])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    if (count == n)
    {
        return 0;
    }

    return 1;
}

int main()
{

    int n;
    cout << "Enter number of Nodes : ";
    cin >> n;
    int m;
    cout << "Enter number of Edges : ";
    cin >> m;

    cout << "Enter Edeges in pair" << endl;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int ans = detectCycleInDirectedGraph(n, edges);
    if (ans){
        cout << "Cycle is present" << endl;
    }
    else{
        cout << "Cycel is not present" << endl;
    }

    return 0;
}
