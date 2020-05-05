class Solution {
public:
 int longestCommonSubsequence(string s, string ss) {
	int sizes = s.size(); 
	int sizess = ss.size(); 
	int b = 0;
	int m[sizes+1][sizess+1]; 
	memset(m, 0 , sizeof(m)); 
	for (int i = 1;i <=  sizes; i++) {
		for (int j = 1; j <= sizess; j++){
			if (s[i-1] == ss[j-1])
				m[i][j] = m[i-1][j-1]+1; 
			else{
				m[i][j] = max(m[i-1][j], m[i][j-1]); 
			}
		   b = m[i][j] > b? m[i][j]: b; 	
		} 

	} 
	return b ; 
        
 }
};
