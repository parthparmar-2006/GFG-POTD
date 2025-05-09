#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        for (int i=0; i<s.size(); i++) {
            if (k==0) break;
            int maxi = s[i];
            int idx = -1;
            for (int j=i+1; j<s.size(); j++) {
                if (s[j] > maxi || s[j]==maxi && idx!=-1) {
                    maxi = s[j];
                    idx = j;
                }
            }
            if (idx != -1) {
                swap(s[i], s[idx]);
                k--;
            }

        } return s;
    }
};