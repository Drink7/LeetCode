class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // dfs to find ans
        // build adjancency list
        int n = equations.size();
        unordered_map<string, unordered_map<string, double>> dict;
        for (int i = 0; i < n; i++) {
            dict[equations[i][0]][equations[i][1]] = values[i];
            dict[equations[i][1]][equations[i][0]] = 1.0 / values[i];
            dict[equations[i][0]][equations[i][0]] = 1.00;
            dict[equations[i][1]][equations[i][1]] = 1.00;
        }

        vector<double> result;
        for (int i = 0; i < queries.size(); i++) {
            double sum = 1.0;
            unordered_set<string> visited;
            if (dfs(dict, visited, sum, 1.0, queries[i][0], queries[i][1])) {
                result.push_back(sum);
            } else {
                result.push_back(-1.0);
            }
        }
        return result;
    }

  bool dfs(unordered_map<string, unordered_map<string, double>>& dict, 
        unordered_set<string>& visited,
        double& result, double tmpResult, string src, string dst) {
        if (dict.count(src) < 1) {
            return false;
        }

        if (src == dst) {
            result = tmpResult;
            return true;
        }

        if (visited.count(src) > 0) {
            return false;
        }

        visited.insert(src);

        // dfs all possible
        bool isValid = false;
        for (auto const& [neigh, val] : dict[src]) {
            if (dfs(dict, visited, result, tmpResult * val, neigh, dst)) {
                return result;
            }
        }
        return false;
    }
};