class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        // sort(arr.begin(), arr.end());
        vector<int> mp(10, 0);
        string n1, n2;
        for (int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        } 
        bool toggle = true;
        for (int d=1; d <= 9; ++d) {
            while (mp[d]--) {
                if (toggle) {
                    n1 += (d + '0');
                } else {
                    n2 += (d + '0');
                }
                toggle = !toggle;
            }
        }
        string res;
        int i=n1.size()-1, j=n2.size()-1, carry=0;
        while (i>=0 && j>=0) {
            int v1 = n1[i]-'0';
            int v2 = n2[j]-'0';
            res.push_back(((v1+v2+carry)%10)+'0');
            carry = (v1+v2+carry)/10;
            i--;
            j--;
        }
        if (i>=0) {
            int v1 = n1[i]-'0';
            res.push_back(((v1+carry)%10)+'0');
            carry = (v1+carry)/10;
        }
        if (j>=0) {
            int v2 = n2[j]-'0';
            res.push_back(((v2+carry)%10)+'0');
            carry = (v2+carry)/10;
        }
        if (carry!=0) res.push_back(carry+'0');
        reverse(res.begin(), res.end());
        return res;
    }
};
