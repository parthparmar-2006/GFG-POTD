#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int sum = 0, maxi = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i=0; i<arr.size(); i++) {
            if (arr[i]>k) sum+=1;
            else sum-=1;
            if (sum>0) maxi = max(maxi, i+1);
            if (mp.find(sum-1) != mp.end()) {
                maxi = max(maxi, i-mp[sum-1]);
            }
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        } return maxi;
    }
};