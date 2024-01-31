#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> C(n + 1), D(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> C[i] >> D[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [cost, city] = pq.top();
        pq.pop();
        if (cost > dist[city])
            continue;
        for (const int &next_city : adj[city])
        {
            if (dist[next_city] > cost + C[city])
            {
                dist[next_city] = cost + C[city];
                pq.push({dist[next_city], next_city});
            }

            int cur_city = next_city;
            for (int i = 1; i < D[city] && !adj[cur_city].empty(); ++i)
            {
                for (const int &next : adj[cur_city])
                {
                    if (next == city)
                        continue;
                    if (dist[next] > cost + C[city])
                    {
                        dist[next] = cost + C[city];
                        pq.push({dist[next], next});
                    }
                }
                cur_city = adj[cur_city][0];
            }
        }
    }

    if (dist[n] == LLONG_MAX)
        cout << -1;
    else
        cout << dist[n];

    return 0;
}
