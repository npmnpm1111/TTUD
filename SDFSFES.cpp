#include <iostream>
#include <vector>
#include <algorithm>

class DisjointSet
{
private:
    std::vector<int> parent, rank;

public:
    DisjointSet(int size) : parent(size + 1), rank(size + 1, 0)
    {
        for (int i = 0; i <= size; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[u] = v;
        }
        if (rank[u] == rank[v])
        {
            rank[v]++;
        }
    }
};

int main()
{
    // (node1, node2, weight)
    std::vector<std::tuple<int, int, int>> edges = {
        {1, 2, 1},
        {1, 3, 1},
        {1, 6, 4},
        {2, 3, 1},
        {2, 5, 2},
        {2, 6, 2},
        {4, 5, 3},
        {4, 6, 5},
        {5, 6, 2}};

    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), [](const std::tuple<int, int, int> &a, const std::tuple<int, int, int> &b)
         { return std::get<2>(a) < std::get<2>(b); });

    DisjointSet ds(6); // 6 đỉnh
    int mst_weight = 0;
    std::vector<std::tuple<int, int, int>> mst_edges;

    for (const auto &edge : edges)
    {
        int u = std::get<0>(edge);
        int v = std::get<1>(edge);
        int weight = std::get<2>(edge);

        if (ds.find(u) != ds.find(v))
        {
            ds.merge(u, v);
            mst_weight += weight;
            mst_edges.push_back(edge);
        }
    }

    std::cout << "Các cạnh trong cây khung nhỏ nhất:" << std::endl;
    for (const auto &edge : mst_edges)
    {
        std::cout << "(" << std::get<0>(edge) << ", " << std::get<1>(edge) << ") = " << std::get<2>(edge) << std::endl;
    }
    std::cout << "Trọng số của cây khung nhỏ nhất: " << mst_weight << std::endl;

    return 0;
}
