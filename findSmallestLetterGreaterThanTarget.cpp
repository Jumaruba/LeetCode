#include <bits/stdc++.h>

using namespace std;


// c f f j
// target a OUTPUT c
// target c OUTPUT f
// casos normais: entre o inicio e o final
// caso anormal: letra entre o final e o incial

char binarySearch(vector<char>&letters, char target){
    int high = letters.size()-1, low = 0, mid;

    while (low < high){
        mid = low + (high-low)/2;

        if (letters[mid+1] > target && letters[mid] <= target) return letters[mid+1];
        if (letters[mid+1] <= target) low = mid+1;
        else if (letters[mid+1] > target && letters[mid] > target) high = mid;

    }

    if (target < letters[low]) return letters[low];
    else return letters[high];
}
char nextGreatestLetter(vector<char>& letters, char target) {
    int size = letters.size();

    if (target >= letters[size-1] || target < letters[0])
        return letters[0];
    else return binarySearch(letters, target);

}

int main(){
    vector<char> letters = {'c','f','f','j'};
    char target = 'k';
    cout << nextGreatestLetter(letters, target) << endl;
}