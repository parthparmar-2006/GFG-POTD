class Solution {
  public:
    int countStrings(string &s) {
        // code here
        unordered_map<int, int> mp;
        for (char ch: s) mp[ch]++;
        int cnt = 0;
        for (auto i: mp) {
            if (i.second>1) {
                cnt++;
                break;
            }
        }
        for (int i=0; i<s.size(); i++) {
            cnt += (s.size()-mp[s[i]]-i);
            mp[s[i]]--;
        } return cnt;
    }
};
