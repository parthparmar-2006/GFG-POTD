class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        int n = s.size(), cnt = 0;
        unordered_map<char, int> mp;
        for (int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }
        for (auto i: mp) {
            cnt += (i.second*(i.second+1))/2;
        }
        return cnt;
    }
};
