class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& a) {
        int v = a.size();
        vector<int>adj[v + 1];
		for (int i = 0; i<a.size(); i++) {
			for(auto it : a[i]){
                adj[it].push_back(i);
            }
		}
		vector<int>indegree(v, 0);
		for (int i = 0; i<v; i++) {
			for (auto it : adj[i])
				indegree[it]++;
		}
		queue<int>q;
		for (int i = 0; i<v; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}
		vector<int>topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0)
					q.push(it);
			}
		}
        sort(topo.begin(),topo.end());
		return topo;
    }
};