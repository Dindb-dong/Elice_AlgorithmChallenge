#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> depth;
vector<int> result;

void dfs(int node, int d)
{
    depth[node] = d;
    bool isLeaf = true;
    for (int child : tree[node])
    {
        if (depth[child] == -1)
        {
            isLeaf = false;
            dfs(child, d + 1);
        }
    }
    if (isLeaf)
    {
        result[node] = (d % 2 == 0) ? 1 : 0;
    }
    else
    {
        result[node] = (d % 2 == 0) ? 1 : 0;
    }
}

int main()
{
    int N;
    cin >> N;

    tree.resize(N + 1);
    depth.assign(N + 1, -1);
    result.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= N; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}