class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> res(queries.size(), 0); 
        sort(nums.begin(), nums.end());
        int s, count ;
        for (int i = 0 ; i < queries.size(); i++){
            s = 0; count = 0; 
            for (int num: nums) {
                if (s+num > queries[i]) break;
                s+=num; 
                count++;
            }
            res[i] = count;
        }

        return res; 
    }
};
