//HASH MAP APPROACH --------------------------------------------
// TIME: 83.55% || STORAGE: 58.51% 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; 
        map<int, int> m; 
        for (int i = 0 ; i < nums.size(); i++){
            auto pos_int = m.find(int(target - nums[i])); 
            if (pos_int != m.end()){
                ans.push_back(pos_int->second);
                ans.push_back(i);
                return ans; 
            }
            auto k = m.insert(pair<int,int>(nums[i], i)); 
            if (k.second == false && nums[i]*2 == target){
                ans.push_back(m.find(nums[i])->second); 
                ans.push_back(i);
                return ans; 
            }
        
        }
        return {};
    } 

};

//BINARY SEARCH APPROACH  ---------------------------------
//TIME: 83.55% || STORAGE: 81.33%

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums2(nums.begin(), nums.end()); 
        sort(nums2.begin(), nums2.end()); 
        for (int i = 0 ; i < nums.size(); i++){
            if (binarySearch(nums2, target -nums[i], nums[i])) {
                int pos = 0; 
                for (int j = 0 ; j < nums.size() ; j++){
                    if (nums[j] == target-nums[i] && j!= i){
                        pos = j; 
                        return {min(pos,i), max(pos,i)}; 
                    }
                }     
                
                
            }
        }
        return {}; 
    } 
    
    int binarySearch(vector<int>& nums2, int target, int& actual){
        int begin = 0, end = nums2.size()-1, mid; 
        while(begin <= end){
            mid = (end-begin)/2 + begin; 
            if (nums2[mid] == target) return 1; 
            if (nums2[mid] > target) end = mid-1; 
            else if (nums2[mid] < target) begin = mid +1; 
        }
        return 0; 
    }

};
