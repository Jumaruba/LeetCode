class RandomizedSet {
public:
	unordered_map<int,int> map; 
	vector<int> l; 
    bool insert(int val) {
		if (map.count(val)) return false;  
		map[val] = l.size();  
        l.push_back(val); 
		return true; 
    }
    
    bool remove(int val) {
		if (map.count(val) == 0) return false;
        int swapElem = l[l.size()-1]; 
        l[l.size()-1] = val; 
        l[map[val]] = swapElem; 
        map[swapElem] = map[val]; 
		map.erase(val);
        l.pop_back();
		return true; 
    }
    
    int getRandom() {
		return l[rand() % l.size()]; 
    }
};
