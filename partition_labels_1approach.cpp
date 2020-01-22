class Solution {
public:
    //time complexity O(n^2)
    //extra space complexity: basically there is no extra space
    vector<int> partitionLabels(string s) {
        unordered_set <char> u; 
        size_t size = s.size(); 
        int e = 0, b = 0; 
        int e_ = 0; 
        vector<int> result; 
        for (int i = 0; i< size; i++){
            if (i > e) {
                result.push_back(e - b + 1); 
                b = i; 
                u.clear(); 
            }
            //we must find the end
            for (int j = e; j < size; j++){
                if (u.find(s[i]) != u.end()) break; 
                if (s[i] == s[j]) e_ = j; 
            }
            u.insert(s[i]); 
        }
        result.push_back(e - b + 1); 
        return result;
    }
};
