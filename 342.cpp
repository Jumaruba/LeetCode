class Solution {
public:
    bool isPowerOfFour(int num) {
        int lastNumber = 0; 
        int counter = 0 ;
        if (num <= 0) return false; 
        if (num == 1 ) return true; 
        while(lastNumber == 0){
            lastNumber = num & 1; 
            num >>= 1;
            counter = lastNumber == 0? counter +1 : counter; 
        }        
        if (num != 0) return false; 
        if (counter != 0 && counter%2 == 0) return true; 
        return false; 
    }
};
