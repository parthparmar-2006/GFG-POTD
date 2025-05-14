class Solution {
  public:
    string countAndSay(int n) {
        // code here
        string s = "1";
        int row = 1;
        while (row<n) {
            string res; 
            for (int i=0; i<s.size();) {
                char ch = s[i];
                int cnt = 0;
                while (i<s.size() && s[i]==ch) {
                    cnt++;
                    i++;
                }
                res.push_back(cnt+'0');
                res.push_back(ch);
            } row++;
            s = res;
        } return s;
    }
};
