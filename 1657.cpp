#include<iostream> 
#include<unordered_map>
#include<vector> 
using namespace std; 


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1 (26,0);
        vector<int> freq2 (26,0);
        vector<int> c1 (26,0);
        vector<int> c2 (26,0);

        getFrequencyChars(freq1, c1, word1);
        getFrequencyChars(freq2, c2, word2);
        sort(freq1.begin(), freq1.end()) ;
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2 && c1 == c2; 
    }

    void getFrequencyChars(vector<int>& freq, vector<int>& chars, string w){
        for(auto c: w)
        {
            freq[c-'a'] ++;
            chars[c-'a'] = 1;
        }
    }


};