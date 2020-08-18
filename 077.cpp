//not a very good approach, but it works :P 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> visited(n);        
        vector<vector<int>> ans; 
        for (int i = 0 ; i < n; i++){
            visited[i] = 1; 
            rec(ans, visited, 1, k); 
            visited[i] = 2; 
        }
        return ans; 
    }
    
    void rec(vector<vector<int>>& ans, vector<int> visited, int depth, int& k){
        vector<int> temp; 
        for (int i = 0 ; i < visited.size();  i++){
            if (depth == k && visited[i] == 1)
                temp.push_back(i+1);  
                
            else if (!visited[i]){
                visited[i] = 1; 
                rec(ans, visited, depth+1, k); 
                visited[i] = 2; 
            }
        } 
        
        if (depth == k) {
            ans.push_back(temp);
            return; 
        } 
    }
};

//---------------------------------------------------------------------- recursive ans organized

class Solution {
public:
    int k_, n_; 
    vector<vector<int>> combine(int n, int k) {
        k_ = k; n_ = n; 
        vector<vector<int>> ans; 
        bc(ans, 2, {}); 
        bc(ans, 2, {1}); 
        
        return ans; 
    } 
    
    
    void bc(vector<vector<int>> & ans, int cur, vector<int> temp){
        if (temp.size() + (n_ - cur) +1 < k_) return; 
        if (temp.size() == k_){
            ans.push_back(temp); 
            return ; 
        }
        bc(ans, cur+1, temp); 
        temp.push_back(cur); 
        bc(ans, cur+1, temp); 
    }
};

//--------------------------------------------------------------------- interative

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
         
		vector<vector<int>> ans; 
		vector<int>p(k,0); 
		int i = 0 ; 
		while( i >=0){
 			p[i] ++; 

            if (p[0] > n-k+1) return ans; 
			else if (p[i] > n ) i--; 
			else if (i == k-1) ans.push_back(p);  
			else{ 
				i++; 
				p[i] = p[i-1];  
			} 
		} 
		return ans; 
    }
};
