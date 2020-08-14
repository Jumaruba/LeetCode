class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> c(256,-1); 
        int b = 0, ans = 0; 
        if (s.size() == 1) return 1; 
        if (s.size() == 0) return 0; 
        c[s[0]] = 0;
        for (int e = 1 ; e < s.size(); e++){
            if (c[s[e]] != -1 ) {
                ans = e-b > ans? e-b: ans; 
                do {
                    c[s[b]] = -1; 
                    b++; 
                }while(b <= c[s[e]]);
                c[s[e]] = e;
            }
            else if (e == s.size()-1) ans = e-b+1 > ans? e-b+1: ans; 
            c[s[e]] = e;   
        }
        return ans; 
    }
};
