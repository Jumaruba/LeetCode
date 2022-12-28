class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int r = 0, a1, a2; 
        priority_queue<int> p = {}; 
        for (int rock: piles) {
            r += rock; 
            p.push(rock); 
        }

        for (int i = 0 ; i < k; i++) {
            a1 = floor((float)p.top()/2.0);
            a2 = p.top() - a1;
            r-= a1;
            p.pop();
            p.push(a2);
        }

        return r;
    }
};
