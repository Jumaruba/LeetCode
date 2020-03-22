// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long int low = 0, high = n, mid; 
        
        while (true){
            mid = (low+high)/2; 
            
            if (guess(mid) == 0)
                return mid; 
            else if(guess(mid) == 1)
                low = mid+1; 
            else if (guess(mid) == -1)
                high = mid-1;
        }
    }
};
