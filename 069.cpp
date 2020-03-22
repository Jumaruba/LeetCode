class Solution {
public:
    bool isAns(long long int m, int target){
        if (m*m<= target && (m+1)*(m+1)>target)
            return true; 
        else 
            return false; 
    }
    int mySqrt(int x) {
        long long int low = 0, high = x,  mid, square; 
        while (1){
            mid = (low+high)/2; 
            
            if (isAns(mid,x)) return mid; 
            else if(isAns(low,x)) return low; 
            else if(isAns(high,x)) return high; 
            
            square = mid*mid; 
            if (square > x)
                high = mid-1; 
            else if (square < x)
                low = mid+1; 
        }

    }

};


/*
//better solution!

int mySqrt(int x) {
        long long int low = 0, high = x, mid, square; 

    while (low+1 < high){
        mid = (high+low)/2; 
        square = mid*mid; 
        if (square == x)
            return mid; 
        else if(square > x)
            high = mid-1; 
        else low = mid; 
    }

    if (high*high<= x) return high; 
    else return low; 
}
 */
