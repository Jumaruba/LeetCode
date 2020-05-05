class Solution {
public:
  bool canConstruct(string rn, string mg){
      int let[26];
      memset(let, 0, sizeof(let));
  
      for (int i = 0; i < mg.size(); i++)
          let[mg[i] - 'a'] ++;
      for (int i = 0; i< rn.size(); i++){
          int pos = rn[i] - 'a';
          let[pos]--;
          if (let[pos]< 0) return false;
  
      }
      return true;
  } 
};
