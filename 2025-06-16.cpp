class Solution {
  public:
    int calcCost(vector<int>& heights, vector<int>& cost, int target) {
        int c = 0;
        for (int i=0; i<heights.size(); i++) {
            c += (abs(heights[i]-target)*cost[i]);
        } return c;
    }
    pair<int, int> validate(vector<int>& heights, vector<int>& cost, int mid) {
        int c1 = calcCost(heights, cost, mid-1);
        int c2 = calcCost(heights, cost, mid);
        int c3 = calcCost(heights, cost, mid+1);
        if (c1>=c2 && c3>=c2) return {c2, 0};
        else if (c1<=c2 && c2<=c3) return {c2, -1};
        else return {c2, 1};
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int start = 1, end = INT_MIN, ans = INT_MAX;
        for (int i: heights) end = max(end, i);
        while (start <= end) {
            int mid = start+(end-start)/2;
            pair<int, int> res = validate(heights, cost, mid);
            ans = min(ans, res.first);
            if (res.second == -1) {
                end = mid-1;
            } else if (res.second == 1) {
                start = mid+1;
            } else {
                return ans;
            }
        } return ans;
    }
};
