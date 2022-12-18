class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<vector<int>> arr(101, vector<int>());
        vector<int> ans(temp.size(), 0);
        for (int i = 0 ; i < temp.size(); i++) { 
            // Update all the previous positions
            for (int j = 30; j < temp[i]; j++){
                if (!arr[j].empty()) {
                    for (int m = 0; m < arr[j].size(); m++){
                        ans[arr[j][m]] = i-arr[j][m];
                    }
                    arr[j].clear();
                }
            }
            arr[temp[i]].push_back(i);
        }
        return ans; 
    }

};
