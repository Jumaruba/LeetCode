class Solution {
public:
    bool isPalindrome(string s) {
        string normalized;  
        for (int i = 0 ; i < s.size() ; i++ ){
            if (s[i] == ' ') continue; 
            if (s[i] >= 65  && s[i] <= 90) normalized += (s[i]  + 32); 
            else if (s[i] >= 97 && s[i] <= 122) normalized += s[i]; 
            else if (s[i]>= 48 && s[i] <= 57) normalized += s[i]; 
        }
        string copy = normalized; 
        reverse(copy.begin(), copy.end()); 
        cout << normalized << endl; 
        cout<< copy << endl ;
        if (copy == normalized) return true; 
        return false; 
    }
};
