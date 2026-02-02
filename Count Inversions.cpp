class Solution {
    int merge(vector<int> &arr, int l, int m, int r) {
        vector<int> left, right;
        left.assign(arr.begin() + l, arr.begin() + m + 1);
        left.push_back(2e9 + 8);
        right.assign(arr.begin() + m + 1, arr.begin() + r + 1);
        right.push_back(2e9 + 8);
        int now = 0, i = 0, j = 0, k = l;
        int ll = m - l + 1;
        int rr = r - m;
        while (k <= r) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                now += (ll - i);
                arr[k++] = right[j++];
            }
        }
        return now;
    }
    
    int count(vector<int> &arr, int l, int r) {
        int n = r - l + 1;
        if (n <= 1) {
            return 0;
        }
        int m = l + (r - l) / 2;
        int left = count(arr, l, m);
        int right = count(arr, m + 1, r);
        int now = merge(arr, l, m, r);
        return now + left + right;
    }
  public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return count(arr, 0, n - 1);
    }
};
