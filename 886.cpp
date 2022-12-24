class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> neigh(n, vector<int>());
        vector<short int> colors(n);  // 0: no color, 1: color1, 2: color2
        int a1, a2; 
        for (int i = 0 ; i < dislikes.size(); i++){
            a1 = dislikes[i][0] - 1;
            a2 = dislikes[i][1] - 1;
            neigh[a1].push_back(a2);
            neigh[a2].push_back(a1);
        }


        for (int i = 0 ; i < n; i++) {
            if (!colors[i]){
                colors[i] = 1;
                if (!dfs(i, neigh, colors)) return false;
            }
        }
        
        return true; 
    }

    bool dfs(int node, vector<vector<int>>& neigh, vector<short int> &colors){
        for (int i: neigh[node]){
            if (colors[i] == colors[node]) return false;
            if (colors[i] == 0){
                colors[i] = colors[node] == 1? 2: 1; 
                if (!dfs(i, neigh, colors)) return false;
            } 
        }
        return true; 
    }
}
