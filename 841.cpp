class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> s;
        s.push(0); 
        unordered_set<int> st;
        int aux; 

        while (!s.empty()) {
            aux = s.top();
            s.pop();
            if (st.find(aux) == st.end()) {
                for (int  i: rooms[aux])  s.push(i);
            } 
            st.insert(aux); 
        }
        return st.size() == rooms.size(); 
    }
};
