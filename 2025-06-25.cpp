class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int> freq(26, 0);
        for (char ch: s) {
            freq[ch-'a']++;
        }
        unordered_map<int, int> mp;
        for (int i: freq) {
            if (i!=0) mp[i]++;
        }
        if (mp.size()==1) return true;
        if (mp.size()>2) return false;
        pair<int, int> v1 = {-1, -1}, v2;
        for (auto i: mp) {
            if (i.first==1) return true;
            if (v1.first==-1) {
                v1 = i;
            } else v2 = i;
        } 
        return ((v1.first-v2.first==1 && v1.second==1) || (v2.first-v1.first==1 && v2.second==1));
    }
};
