class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        unordered_map<int, int> mp;
        for (int i: arr) mp[i]++;
        stack<int> st;
        vector<int> res(arr.size());
        for (int i=arr.size()-1; i>=0; i--) {
            while (!st.empty() && mp[st.top()]<=mp[arr[i]]) st.pop();
            res[i] = st.empty()? -1: st.top();
            st.push(arr[i]);
        } return res;
    }
};
