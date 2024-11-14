    bool possible(int maxi, int n, vector<int> arr) {
        int cnt = 0;
        for (int i : arr) cnt += ceil((1.0 * i) / maxi);

        if (cnt <= n) return 1;
        return 0;
    }
    int minimizedMaximum(int n, vector<int>& arr) {
        int low = 1, high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(mid, n, arr)) {
                ans =mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        return ans;
    }
