#include <iostream>
#include <vector>
#include <stack>
#include <omp.h>
using namespace std;

vector<int> graph[100];
bool visitedDFS[100];

void dfs(int start) 
{
    stack<int> s;
    s.push(start);

    while (!s.empty()) 
    {
        int u;
        #pragma omp critical
        { 
            u = s.top(); 
            s.pop(); 
        }

        if (visitedDFS[u]) continue;
        visitedDFS[u] = true;
        cout << u << " ";

        #pragma omp parallel for
        for (auto v :   graph[u]) {
            if (!visitedDFS[v]) {
                #pragma omp critical
                s.push(v);
            }
        }
    }
}

int main() {
    int n, m, start;
    cout << "Enter number of nodes, edges and starting node: ";
    cin >> n >> m >> start;
    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << "DFS Traversal:\n";
 dfs(start);
}