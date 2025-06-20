class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        if (k==1) return true;
        if (arr.size()%k!=0) return false;
        map<int, int> mp;
        for (int i: arr) mp[i]++;
        for (auto i: mp) {
            int val = i.first;
            int freq = i.second;
            if (freq == 0) continue;
            for (int i=1; i<k; i++) {
                int nextVal = val+i;
                if (mp[nextVal] < freq) return false;
                mp[nextVal] -= freq;
            }
        } return true;
    }
};
