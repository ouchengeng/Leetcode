class Solution {
public:
    int findMedian(vector<int> &nums1, int l1, int r1, vector<int> &nums2, int l2, int r2, int k)
    {
        //the k-th largest
        if(r1 - l1 < r2 - l2)
            return findMedian(nums2, l2, r2, nums1, l1, r1, k);
        if(r2 < l2)
            return nums1[l1+k-1];
        if(k == 1)
            return min(nums1[l1], nums2[l2]);
        
        int split2 = min(k/2, (r2-l2+1));
        int split1 = k - split2;
        
        if(nums1[l1 + split1 - 1] < nums2[l2 + split2 - 1])
            return findMedian(nums1, l1+split1, r1, nums2, l2, r2, k -split1);
        return findMedian(nums1, l1, r1, nums2, l2+split2, r2, k-split2);
            
    };
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if((n + m) % 2 != 0)
            return findMedian(nums1, 0, n - 1, nums2, 0, m - 1, (n + m)/2 + 1);
        else
            return (findMedian(nums1, 0, n - 1, nums2, 0, m - 1, (n + m)/2) + findMedian(nums1, 0, n - 1, nums2, 0, m - 1, (n + m)/2+1) )/ 2.0;
    }
};