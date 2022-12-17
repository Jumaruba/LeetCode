class Solution {
public:
    bool isValid(string s) {
        stack<char> st = stack<char>(); 
        char aux; 
        for (char c: s){
            if (c == '(') st.push(')'); 
            else if (c == '[') st.push(']');
            else if (c == '{') st.push('}');
            else {
                if (st.empty()) return false; 
                aux = st.top(); 
                st.pop(); 
                if (aux != c) return false; 
            }
        }
        return st.empty(); 
    }

};
