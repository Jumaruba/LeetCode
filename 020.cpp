class Solution {
public:
    bool isValid(string s) {
        // 1 = (; -1 = ) 
        // 2 = [; -2 = ] 
        // 3 = {; -3 = }
        if (s.size() == 0) return true; 
        stack<int> st; 
        for (int i = 0 ; i < s.size() ; i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{' ) st.push(s[i]); 
            else{
                if (st.empty()) return false; 
                char bracket = st.top(); 
                st.pop(); 
                if (s[i] == ')' && bracket != '(') return false; 
                else if (s[i] == ']' &&  bracket != '[') return false; 
                else if (s[i] == '}' && bracket != '{') return false; 
                
            }
        }
        return st.empty() ? true: false; 
    }
};
