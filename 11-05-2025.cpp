#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        vector<int> prefix(arr.size()+1, 0);
        for (int i=0; i<arr.size(); i++) {
            prefix[i+1] = prefix[i]+arr[i];
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=0; i<arr.size(); i++) {
            for (int j=i; j<arr.size(); j++) {
                pq.push(prefix[j+1]-prefix[i]);
                if (pq.size()>k) pq.pop();
            }
        } return pq.top();
        
    }
};
