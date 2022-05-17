class Solution {
public:
    vector<vector<int> > G;
    vector<vector<int> > T;
    vector<int> dfn;
    vector<int> low;
    vector<int> stk;
    vector<int> minv;
    int N, M, cnt;
    int dfc;
    int tp;
    void Tarjan(int u) {
        // printf("  Enter : #%d\n", u);
        low[u] = dfn[u] = ++dfc;                // low 初始化为当前节点 dfn
        stk[++tp] = u;                          // 加入栈中
        for (int v : G[u]) {                    // 遍历 u 的相邻节点
            if (!dfn[v]) {                        // 如果未访问过
            Tarjan(v);                          // 递归
            low[u] = std::min(low[u], low[v]);  // 未访问的和 low 取 min
            if (low[v] == dfn[u]) {  // 标志着找到一个以 u 为根的点双连通分量
                // printf("  Found a New BCC #%d.\n", cnt - N);
                // 将点双中除了 u 的点退栈，并在圆方树中连边
                for (int x = -1; x != v; --tp) {
                x = stk[tp];
                T[cnt].push_back(x);
                T[x].push_back(cnt);
                // printf("    BCC #%d has vertex #%d\n", cnt - N, x);
                }
                // 注意 u 自身也要连边（但不退栈）
                T[cnt].push_back(u);
                T[u].push_back(cnt);
                // printf("    BCC #%d has vertex #%d\n", cnt - N, u);
                cnt++;                 // 增加方点个数
            }
            } else
            low[u] = std::min(low[u], dfn[v]);  // 已访问的和 dfn 取 min
        }
        // printf("  Exit : #%d : low = %d\n", u, low[u]);
        // printf("  Stack:\n    ");
        // for (int i = 1; i <= tp; ++i) printf("%d, ", stk[i]);
        // puts("");
    }
    long long minimumCost(vector<int>& cost, vector<vector<int>>& roads) {
        N = cost.size();
        M = roads.size();
        G.resize(2 * N);
        T.resize(2 * N);
        low.resize(N);
        dfn.resize(N);
        stk.resize(2 * N + 1);
        minv.resize(2 * N);
        fill(minv.begin(), minv.end(), 0x3f3f3f3f);
        dfc = 0;
        tp = 0;
        cnt = N;
        for (int i = 0; i < M; i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        Tarjan(0);
        for (int i = 0; i < N; i++)
        {
            if (T[i].size() == 1)
            {
                minv[T[i][0]] = min(minv[T[i][0]], cost[i]);
                // cout << i << " " << T[i][0] << " " << cost[i] << endl;
            }
        }
        long long sum = 0, mx = 0;
        for (int i = N; i < cnt; i++)
        {
            int deg = 0;
            for (int j : T[i])
            {
                if (T[j].size() > 1)
                {
                    deg++;
                }
            }
            // cout << i << " " << deg << " " << minv[i] << endl;
            if (deg == 1)
            {
                sum += minv[i];
                mx = max(mx, (long long)minv[i]);
            }
            if (deg == 0)
            {
                return minv[i];
            }
        }
        return sum - mx;
    }
};