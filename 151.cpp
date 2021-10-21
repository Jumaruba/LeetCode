
class Solution {
public:
    int size; 
    string reverseWords(string s) {  
	this->size = s.size();  
	int p = 0; 
	// Reverse entire string  
	for (int i = 0 ; i < size/2; i++) { 
		swap(s[i], s[this->size-1-i]); 
	}       
	for (int i = 0; i < this->size; i++){ 
		if (s[i] == ' ') {
			this->reverseString(s, p, i-1);    
			p = i+1; 
		} 
	}   
	reverseString(s, p, this->size-1);      
	removeDoubleSpaces(s);   
	trim(s); 
	return s;
    } 

    void reverseString(string& s, int b, int e){ 
	if (b - e == 1) return;
	int middle = (e - b)/2 + b;  
	while (b <= middle){
		swap(s[b], s[e]);  
		b++; 
		e--; 
	}    
    }   

    void removeDoubleSpaces(string& s){  
	    auto pos = s.find("  ");  
	    while ( pos != std::string::npos){
		s.replace(pos, 2, " ");  
		pos = s.find("  ");  
	    }  
    }  

    void trim(string& s){   
	    int pos = 0;  
	    for (int i = 0 ;i < s.size();i++) {
		if (s[i] != ' ') break;  
		pos++; 
	    }     
	    s.erase(s.begin() , s.begin() + pos); 
        pos = s.size(); 
	    for (int i = s.size() -1; i >= 0; i--) {
		if (s[i] != ' ') break; 
		pos --; 
	    }  

	    s.erase(s.begin() + pos, s.end()); 
    }

};
