class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false; 
        vector<int> freq(26); 
        vector<int> current(26); 
        
        for (char c: s1) freq[c-'a']++;  

        int pb = 0, pf = 0; 

        for (pf; pf < s1.size(); pf++) current[s2[pf]-'a'] ++; 
        pf--; 
        
        while(pf < s2.size()-1){
            if (freq == current) return true; 
            pb++; 
            current[s2[pb-1]-'a'] --; 
            pf++; 
            current[s2[pf]-'a']++;            
        }
        
        return freq == current; 
        
    }
};
