#include <bits/stdc++.h>
#include <cmath>
using namespace std;

//binary search to find the closest number
int binarySearch(std::vector<int> v, int x){
    int low = 0, high = v.size()-1, minDiff = 10001, closest = -1;
    while(low <=high){
        int mid = (low+high)/2;

        if(abs(v[mid]-x) < minDiff){
            minDiff = abs(v[mid]-x);
            closest = mid;
        }

        if (v[mid] == x)
            return mid;
        else if (v[mid] < x)
            low = mid+1;
        else high = mid-1;

    }
    return closest;
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int size = arr.size();
    int begin, end;
    //if the x is lower than the first element
    if(x<= arr[0]){
        begin = 0;
        end = k-1;
    }

    else if (x>arr[size-1]){
        end = size-1;
        begin = size-k;
    }

    else {
        int index = binarySearch(arr, x);
        //pra que isso?
        //if (index < 0)
        //    index = -index -1;
        int low = max(0, index-k-1), high = min(size-1, index+k-1);

        while(high-low> k-1){
            if(low < 0 || abs(x-arr[low]) <= abs(arr[high] -x))
                high--;
            else if((high > size-1) || (abs(x-arr[low])> abs(arr[high] -x) ))
                low++;
        }

        begin = low;
        end = high;
    }

    std::vector<int> v(k);
    int counter = 0;
    for (int i = begin; i <= end; ++i)
    {
        v[counter] = arr[i];
        counter++;
    }

    return v;
}

int main(){
    vector<int> v = {1,2,3,4,5};
    vector<int> ans;

    ans = findClosestElements(v,4,3);
    for (vector<int>::iterator i = ans.begin(); i < ans.end(); i++)
        cout << *i << endl;

    cin.ignore();
    cin.ignore();

}