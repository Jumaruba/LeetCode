class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int contador = 0;
        s.push(stoi(tokens[contador]));

        while (contador!= tokens.size()-1){
            contador ++;
            string v = tokens[contador];
            if (v[0]>= '0' && v[0]<='9' || (v.size()>= 2 && v[0] == '-'))
                s.push(stoi(v));
            else{
                int v1 = s.top();
                s.pop();
                int v2 = s.top();
                s.pop();
                if (v == "+")
                    s.push(v1+v2);
                else if (v == "*")
                    s.push(v1*v2);
                else if (v  == "-")
                    s.push(v2-v1);
                else if (v == "/")
                    s.push(v2/v1);
            }
        }
        return s.top();
}

};
