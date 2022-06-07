// Dijkstra's algorithm
#include <bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// define functions...

void dispAdjList(int v, vector<pair<int, int>> adj[])
{
    cout << "\n"
         << "The adjacency list for the given graph: " << endl;
    for (int i = 1; i <= v; i++)
    {
        cout << i << ": ";
        for (auto it : adj[i])
        {
            cout << "{" << it.first << "," << it.second << "} ";
        }
        cout << endl;
    }
}

vector<int> DijkstraSAlgo(int v, vector<pair<int, int>> adj[], int src)
{
    vector<int> parent(v, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int distn[v + 1];
    for (int i = 1; i <= v; i++) // Setting distance for each element to infinity
    {
        distn[i] = INT_MAX;
    }

    distn[src] = 0;
    pq.push(make_pair(0, src)); // Pushing a pair of (dist, vertex ) into the queue
    parent[src] = src;

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // vector<pair<int, int>>::iterator it;    // Conventional way of declaring an iterator
        for (auto it : adj[node])
        {
            if (distn[node] + it.second < distn[it.first])
            {
                distn[it.first] = distn[node] + it.second;
                pq.push({distn[it.first], it.first});
                parent[it.first] = node;
            }
        }
    }

    cout << "\n"
         << "Shortest path according to Dijkstra's algorithm: "
         << "\n";
    for (int i = 1; i <= v; i++)
    {
        cout << distn[i] << " ";
    }
    cout << endl;

    return parent;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // Write your code here....
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> adj[v + 1];
    for (int i = 1; i <= e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    dispAdjList(v, adj); // Displaying the adjacency list

    int src = 1;
    vector<int> parent = DijkstraSAlgo(v, adj, src); // Calling the func.

    for (int i = 1; i <= v; i++)
    {
        cout << "Route for " << i << " from source(" << src << "): ";
        int par = parent[i];
        while (true)
        {
            if (par == src)
            {
                cout << par << endl;
                break;
            }
            else
            {
                cout << par << "->";
                par = parent[par];
            }
        }
        cout << endl;
    }
    //   for (int x = 1; x <= v; x++)                // Displaying the parent 
    //   {
    //       cout<<parent[x]<<" ";
    //   }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}