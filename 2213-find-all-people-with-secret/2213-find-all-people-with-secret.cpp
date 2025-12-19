class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &m : meetings) {
            adj[m[0]].push_back({m[1], m[2]});
            adj[m[1]].push_back({m[0], m[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<long long> time(n, LLONG_MAX);

        time[0] = 0;
        time[firstPerson] = 0;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            if (t > time[u]) continue;

            for (auto [v, mt] : adj[u]) {
                if (mt >= t && mt < time[v]) {
                    time[v] = mt;
                    pq.push({mt, v});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (time[i] != LLONG_MAX)
                ans.push_back(i);
        }
        return ans;
    }
};
