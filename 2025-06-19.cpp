class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        for (char ch: s) {
            if (islower(ch)) lower[ch-'a']++;
            else upper[ch-'A']++;
        }
        int j=25, k=25; 
        for (int i=s.size()-1; i>=0; i--) {
            while (lower[j]==0) j--;
            while (upper[k]==0) k--;
            if (islower(s[i])) {
                s[i] = (j+'a');
                lower[j]--;
            } else {
                s[i] = (k+'A');
                upper[k]--;
            }
        } return s;
    }
};
