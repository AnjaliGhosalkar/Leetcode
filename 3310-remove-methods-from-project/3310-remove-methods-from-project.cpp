class Solution {
public:

    vector<int> ans;

    void check(int k, vector<vector<int>>& v, vector<int>& visited) {

        ans.push_back(k);

        for (int i = 0; i < v[k].size(); i++) {

            int next = v[k][i];

            if (visited[next] == -1) {

                visited[next] = 1;

                check(next, v, visited);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Create graph
        vector<vector<int>> v(n);

        for (auto it : invocations) {

            int a = it[0];
            int b = it[1];

            v[a].push_back(b);
        }

        // Find suspicious methods
        vector<int> visited(n, -1);

        visited[k] = 1;

        check(k, v, visited);

        // Check if a normal method calls
        // a suspicious method
        for (auto it : invocations) {

            int a = it[0];
            int b = it[1];

            if (visited[a] == -1 && visited[b] == 1) {

                // Cannot remove suspicious methods
                vector<int> ret;

                for (int i = 0; i < n; i++) {
                    ret.push_back(i);
                }

                return ret;
            }
        }

        // Remove suspicious methods
        vector<int> ret;

        for (int i = 0; i < n; i++) {

            if (visited[i] == -1) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};