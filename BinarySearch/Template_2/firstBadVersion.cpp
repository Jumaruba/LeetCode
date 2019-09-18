// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 1) return 1;
        int low = 1, high = n, mid;
        while (low < high){
            mid = low + (high-low)/2; 
            
            if(isBadVersion(mid)){
                if (high-low>= 2 && !isBadVersion(mid-1))
                    return mid; 
                high = mid; 
            } 
            else if (!isBadVersion(mid)) low = mid+1;
            
            
        }
        
        if(low == high) return low; 
        return -1; 
    }
};