#include <iostream> 
#include <string>
#include <vector>
using namespace std; 


int main(){
    vector<string> s = {"t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"}; 
    
    //we must do it without allocating extra space (wtf?)

    //reverse the hole string and then reverse each word

    //reversing the vector
    int size = s.size();
    for (int i = 0; i < size/2; i++)
    	swap(s[i], s[size-i-1]);
   	

    //reversing each string
    int begin = 0;                              //begin of a string
    int end = 0;                                //end of a string 
    int size_string = 0;                        //size of the string

    for (int i = 0; i < size; i++){
        if (s[i] == " " || i==size-1){
            size_string = i - begin; 
            
            //two cases: the end of the string and not the end 
            if (i != size-1) end = i-1;          //the position of the end of the string
            else {
                end = i;
                size_string = i - begin +1;
            } 

            for (int j = 0; j < size_string/2; j++)
                swap(s[j + begin], s[end - j]);
            begin = end+2;      //new begin
        } 
    }

    //print the vector
    for (string m: s)
        cout << m; 
    
}

