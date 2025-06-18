class Solution {
  public:
    bool validate(string temp) {
        for (int i = 0; i < temp.size() / 2; i++) {
            if (temp[i] != temp[temp.size() - i - 1]) return false;
        } return true;
    }

    void backtrack(int i, string temp, vector<string> curr, string& s, vector<vector<string>>& res) {
        if (i == s.size()) {
            if (temp.empty()) res.push_back(curr);
            return;
        }

        temp.push_back(s[i]);
        if (validate(temp)) {
            vector<string> new_curr = curr;
            new_curr.push_back(temp);
            backtrack(i + 1, "", new_curr, s, res);  
        }
        backtrack(i + 1, temp, curr, s, res); 
    }

    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(0, "", curr, s, res);
        return res;
    }
};
