class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> umap; 
        for (char i: s) umap[i] ++; 
        
        priority_queue<pair<int, char>> pq; 

        for (auto it = umap.begin() ; it != umap.end(); it++) pq.push({it->second, it->first});
        
        int counter = 0; 
        string ans; 
        while(counter < s.size()){  
            for (int i = 0 ; i < pq.top().first; i++){
                ans+= pq.top().second; 
                counter ++; 
            }
            pq.pop(); 
        }
        return ans; 
    }
};


// Another terrible soltuion 

class Ch {
    public: 
    string s; 
    int times; 
    char c; 
    Ch(char c){
        times = 1; 
        s = ""; 
        s.push_back(c);
        this->c = c; 
    }

    void inc(){
        times++; 
        s.push_back(c); 
    }

    friend bool operator<(const Ch& ch1, const Ch& ch2){
        return ch1.times < ch2.times;
    }

};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, Ch> map; 
        string res(""); 
        for (char c: s){
            if (map.find(c) == map.end()){
                Ch m(c); 
                map.insert({c, m}); 
            } else {
                map.at(c).inc();
            }
        }

        priority_queue<Ch> pq; 
        for (auto& it: map){
            pq.push(it.second);  
        }
    	
        while(!pq.empty()){
            res = res + pq.top().s; 
            pq.pop();
        }
        return res ;
    }
};
