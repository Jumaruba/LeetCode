class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans; 
        vector<int> tmp; 
        for (int i = 0; i<  groupSizes.size(); i++){    //run all vector O(n)
            int element = groupSizes[i];                
            if (element!= -1){                          //must be different from -1 
               tmp.clear(); 
                tmp.push_back(i);                       //adds the element to the tmp vector
                groupSizes[i] = -1;                    //now it's -1
                for (int j = 0 ; j < groupSizes.size(); j++){
                    if (tmp.size() == element) break;   
                    if (groupSizes[j] == element){ 
                        tmp.push_back(j);
                        groupSizes[j] = -1; 
                    }
                }
                ans.push_back(tmp);
            }
            
        }
        return ans; 
    }
};

https://leetcode.com/contest/weekly-contest-166/problems/group-the-people-given-the-group-size-they-belong-to/
