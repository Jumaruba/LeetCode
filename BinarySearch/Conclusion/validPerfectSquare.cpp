class Solution {
public:
    
    // 0 high = 0, low = 0, mid = 0 (ok)
    // 1 high = 0, low = 0, mid = 0
    // 2 high = 1, low = 0, mid = 0, square = 0, square < num, low = 1, square = 1, square < num, return false
    // 3 high = 1, low = 0 return false
    // 4 high = 2, low = 0, mid = 1, square = 1, low = 2, 
    
    bool isPerfectSquare(int num) {
        //special cases ------------------
        
        if (num == 1) return true; 
    
        
        
        long long int high = num/2, low = 0, mid; 
        
        while (low < high){
            mid = low+(high-low)/2; 
            long long int square = mid*mid; 
            
            if(square == num) return true; 
            
            if (square > num) high = mid-1; 
            else if(square < num){
                long long int square_1 = (mid+1)*(mid+1); 
                if (square_1 > num) return false; 
                else low = mid+1; 
            } 
            
        }
        if (low*low != num) return false;
        return true; 
    }
};