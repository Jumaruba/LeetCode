class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        n = hasFactor(n, 2); 
        n = hasFactor(n, 3);
        n = hasFactor(n, 5); 
        
        return n == 1; 
    }

    int hasFactor(int n, int d){
        while (n%d == 0) {
            n /= d; 
        }
        return n; 
    }
};
