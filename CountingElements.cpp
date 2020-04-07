
//this is a problem from leetcode 30 day challenge
class Solution {
public:
    int countElements(vector<int>& arr) {
        int currentNumber = -1; 
        int currentSum = 0; 
        int totalSum = 0; 
        sort(arr.begin(), arr.end()); 
        for (int i = 0; i < arr.size(); i++){
            if (currentNumber == -1){ 
                currentNumber = arr[i];
                currentSum ++; 
            }
            else if (arr[i] == currentNumber){
                currentSum ++; 
            }
            else{
                if (arr[i] == currentNumber+1) totalSum += currentSum; 
                currentSum = 1; 
                currentNumber = arr[i];
            }
        }
        return totalSum; 
    }
};
