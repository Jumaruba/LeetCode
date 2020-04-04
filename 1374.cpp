class Solution {
public:
    string generateTheString(int n) {
        string ans(n-1, ' '); 
        if (n % 2 == 0) {
            fill(ans.begin(), ans.begin()+n-1, 'x');
            ans.push_back('z'); 
        }
        else {
            fill(ans.begin(), ans.end(), 'x');
            ans.push_back('x');
        }
        return ans; 
    }
};
