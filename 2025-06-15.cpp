class Solution {
  public:
    bool validate(vector<int>& arr, int k, int mid) {
        int cnt = 0;
        for (int i=0; i<arr.size(); i++) {
            cnt += arr[i]/mid;
            cnt += arr[i]%mid!=0;
        } return cnt<=k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int start = 1, end = INT_MIN, ans = -1;
        for (int i: arr) end = max(end, i);
        while (start <= end) {
            int mid = start+(end-start)/2;
            if (validate(arr, k, mid)) {
                ans = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        } return ans;
    }
};
