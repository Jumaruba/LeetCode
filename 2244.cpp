class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> um; 
        int n = 0; 
        for (int i: tasks) um[i] ++; 
        for (auto i: um){
            if (i.second == 1) return -1; 
            else if (i.second % 3 == 0){
                n += i.second/3;
            } else if (i.second % 3 == 2) {
                n += (i.second - 2)/3;
                n ++; 
            } else if (i.second % 3 == 1) {
                n += (i.second - 4) / 3; 
                n += 2;
            }
        }

        return n;
    }
};
