class Solution {
public:
    vector<int> partitionLabels(string s) {
        size_t size = s.size(); 
        int e = 0, b = 0; 
        int e_ = 0; 
        vector<int> result; 
        for (int i = 0; i< size; i++){
            if (i > e) {
                result.push_back(e - b + 1); 
                b = i; 
            }
            //we must find the end
            for (int j = b; j < size; j++){
                if (s[i] == s[j]) e_ = j; 
                if (e_ > e) e = e_;
            }
        }
        result.push_back(e - b + 1); 
        return result;
    }
};