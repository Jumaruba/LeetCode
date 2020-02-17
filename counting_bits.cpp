class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0); 
        int cont_prim = 1;
        int cont_sec = 0; 
        for (int i = 1; i < num+1; i++){
            if (cont_prim == cont_sec){
                cont_sec = 0; 
                cont_prim = i; 
            }
            dp[i] = dp[i-cont_prim] + 1; 
            cont_sec++; 
            
        }
        return dp; 
    }
};
