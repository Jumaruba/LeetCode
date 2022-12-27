class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<tuple<int,int>> v(rocks.size()); 
        int res = 0, aux;
        for (int i = 0; i < rocks.size(); i++) v[i] = {rocks[i], capacity[i]};
        
        sort(v.begin(), v.end(), [](const tuple<int,int>& t1, const tuple<int,int>& t2) -> bool{
            return abs(get<0>(t1) - get<1>(t1)) < abs(get<0>(t2) - get<1>(t2)); 
        });

        for (auto t: v){
            if (get<0>(t) == get<1>(t)) res++; 
            else if (!additionalRocks) return res;
            else {
                aux = min(additionalRocks, get<1>(t) - get<0>(t));
                additionalRocks -= aux;
                res += aux == get<1>(t) - get<0>(t) ? 1: 0; 
            }
        }
        return res; 
    }
}
