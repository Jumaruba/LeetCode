class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v = {0, 1}; 
        int vsize = 1; 
        solve(v, n, vsize); 
        return v; 
    }


    void solve(vector<int> &v, int&t, int&vsize) {
        if (vsize == t ){
            return; 
        }
        vector<int> r(v); 
        reverse(r.begin(), r.end()); 
        v.insert(v.end(), r.begin(), r.end());
        for (int i= v.size()/2 ; i < v.size(); i++) v[i] = v[i] | 1<<vsize ; 
        vsize++;
        solve(v, t, vsize); 
    }
};
