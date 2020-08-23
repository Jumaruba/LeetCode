
class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n); 
        int count = 0; 
        for (int i = s.size()-1 ; i >= 0; i--) {
            count ++; 
            if (count == 3 && i !=0){
                s.insert(s.begin() + i,'.'); 
                count  = 0; 
            }  
        }
        return s; 
    }
}
