class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if( n == 0) return;
        if( m == 0){
            nums1 = nums2;
            return;
        }
        int ptr1 = 0, ptr2 = 0;
        while(ptr2 < n){
            if(ptr1 < m + ptr2){
                if(nums1[ptr1] >= nums2[ptr2]){
                    nums1.insert(nums1.begin() + ptr1, nums2[ptr2] );
                    ptr1 ++;
                    ptr2 ++;
                }else{
                    ptr1 ++;
                }
            }else{
                int bd = n - ptr2;
                for(; ptr2 < n; ptr2 ++){
                    nums1.insert(nums1.begin() + ptr1, nums2[ptr2]);
                    ptr1++;
                }
            }
        }
        if(nums1.size() > m + n){
            nums1.erase(nums1.begin() + m + n, nums1.end());
        }
    }
};
