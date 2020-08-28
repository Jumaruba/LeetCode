class Solution {
public:
    string digits_; 
    vector<string> ans;
    vector<string> letters; 
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ans; 
        letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        digits_ = digits; 
        string current_string = ""; 
        back_tracking(current_string, 0);
        
        return ans; 
    }
    
    void back_tracking(string current_string, int start){
        if (current_string.size() == digits_.size()){
            ans.push_back(current_string); 
            return; 
        }
        
        current_string += letters[digits_[start]-'0'][0]; 
        for (char i: letters[digits_[start]-'0']){
            current_string[start] = i; 
            back_tracking(current_string, start +1); 
        }
    }
};
