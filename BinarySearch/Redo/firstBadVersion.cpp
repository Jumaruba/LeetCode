// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    // 1 2 3 4 5B 6B 7B
    int firstBadVersion(int n) {

        //special cases ----------------------
        //1

        if (n == 1) return 1; 
        if (isBadVersion(1)) return 1; 

        int low = 1, high = n, mid; 
        while (low < high){
            mid = low +(high-low)/2; 

            if (isBadVersion(mid+1) && !isBadVersion(mid)) return mid+1; 
            if (isBadVersion(mid)) high = mid; 
            else if (!isBadVersion(mid)) low = mid+1; 
        }

        if (high == low) return mid+1; 
        return mid; 
    }
};

//1
//1 2 (2)

//1 2 3 (2)  high = 1, low = 1

//1 2 3 4 (2)

