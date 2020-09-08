class Solution {
public:
    bool rotateString(string s1, string s2) {
        if (s1.size() != s2.size()) return false; 
        if (s1.size() == 0 && s2.size() == 0) return true; 
        int p2 = 0, p1 = 0; 
        //find the first letter of s1 in s2 
        for (int i = 0 ; i < s2.size(); i++){ 
            p2 = i; 
            while(s2[p2] == s1[p1]){
                p2 = p2 == s2.size()-1? 0: p2+1; 
                p1++;  
                if (p2 == i) return true;  
            }  
            p1 = 0; 
        }  
        return false;
        }
};
