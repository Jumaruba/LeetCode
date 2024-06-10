#include <iostream>
#include <vector> 
#include <unordered_map>
using namespace std; 

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
      if (hand.size() % groupSize != 0) return false; 
      
      unordered_map<int, int> um; 
      vector<int> minHeap; 
      sort(hand.begin(), hand.end());

      for(int i = 0; i < hand.size(); i++) {
        if (um.find(hand[i]) != um.end()){
          um.insert(hand[i], 1);
          minHeap.push_back(hand[i]);
        }
        else um[hand[i]] += 1;
      }
      
      for (int i = 0; i < minHeap.size(); i++) {
        if (!isSequence(um, minHeap[i], groupSize)) return false; 
        minHeap.erase(minHeap.begin(), minHeap.begin()+groupSize);        
      }
      return true; 
    }


    bool isSequence(unordered_map<int,int>& um, int start, int size) {
      for (int i = start; i < size; i++){
        if (um.find(i) != um.end())
          return false;
        else um[i]--;
        if (um[i] == 0) um.erase(um.find(i));
      }
      return true; 
    }
};
