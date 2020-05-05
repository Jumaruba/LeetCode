class Solution {
public:
    int firstUniqChar(string s){
	int resp;
	int c[26]; 
	memset(c, 0, sizeof(c)); 

	for (int i = 0; i < s.size(); i++) {
		c[s[i] - 'a'] ++; 
	} 	
	for (int i = 0; i < s.size(); i++){
		if (c[s[i] - 'a' ] == 1) return i; 
	} 
	return -1; 
	
} 


};
