class Solution {
public:
    
    vector<int> partitionLabels(string s) {
        map<char,int> m; 
        int size = s.size(); 
        vector<int> ans; 
        //setting the map
        for (int i = 0; i < size; i++) {
            if ( m.insert(pair<char,int>(s[i], i)).second == false)
                m[s[i]] = i; 
        }
        int b = 0, e = 0; 
        for (int i = 0; i < size; i++){
            if (e < m[s[i]]) e = m[s[i]]; 
            else if (e == i){
                ans.push_back(e-b+1); 
                b = i+1; 
                e = i+1;
            }
        }
        return ans; 
    }
};  