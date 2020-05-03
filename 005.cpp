class Solution {
public:
string palinPoint(string s1, int right, int left){
	string s; 
	if(right - left == 2) 
		s = s1[right-1] ; 

	while (left >= 0 && right <= s1.size()-1){ 
		if (s1[left] == s1[right]) s = s1[left--]+ s + s1[right++] ; 
		else break; 
	}
	
	return s; 

} 


string longestPalindrome(string s1){
	string bs; 
	string bs2; 
	string result ; 
	if (s1.size() == 1) return s1 ;
    //check if is already a palindrome 
    string s2 = s1; 
    reverse(s2.begin(), s2.end()); 
    if (s2 == s1) return s1; 
	//get the palindromes with one center 
	int size = s1.size(); 
	for (int i = 0; i < size; i ++){
		if (i+1 < size)bs = palinPoint(s1, i+1, i-1); 		//if have a center 
		bs2 = palinPoint(s1, i, i-1); 
		result = bs.size() > result.size()? bs: result; 
		result = bs2.size() >result.size() ? bs2: result; 
	}	
	 return result ; 
} 

};
