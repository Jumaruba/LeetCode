//(i+1)*(i+2)/2 is the sum of all bulbs until that moment
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        unsigned long long int ans = 0, total_sum = 0; 
        
        for (unsigned long long int i = 0; i < light.size(); i++){
            total_sum += light[i]; 
            if (total_sum == (i+1)*(i+2)/2) ans++; 
        }
        
        return ans; 
    }
};

/**class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        priority_queue<int, vector<int>, greater<int>> q; 
        int expected = 1, result = 0; 
        for (int i = 0; i < light.size(); i++){
            q.push(light[i]); 
            while(q.top() == expected){
                expected ++; 
                q.pop(); 
            }
            if (q.empty()) result++; 
        }
        return result; 
    }
};**/
