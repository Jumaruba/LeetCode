class Solution {
public:
    int next_num(int n){
        int next = 0;
        int inter; 
        while(n!= 0){
            inter = n%10; 
            next += (inter*inter); 
            n /=10; 
        }
        return next; 
    }
    //applying floyd's cycle
    bool isHappy(int n) {
        int slow = n;
        int fast = next_num(n); 
        while(true){
            cout << "fast "<<fast << endl; 
            cout << "slow "<<slow << endl; 
            if (fast == 1 || slow == 1) return true; 
            if (slow == fast) return false;   
            fast = next_num(next_num(fast));
            slow = next_num(slow); 
        }
    }
};
