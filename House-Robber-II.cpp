class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }
        int exc1=0;
        int incl1=nums[0];
        int newExc1;
        for(int i=1;i<n-1;i++){
            newExc1=max(exc1,incl1);
            incl1=nums[i]+exc1;
            exc1=newExc1;
        }
        int max1=max(incl1,exc1);

        int exc2=0;
        int incl2=nums[1];
        int newExc2;
        for(int i=2;i<n;i++){
            newExc2=max(exc2,incl2);
            incl2=nums[i]+exc2;
            exc2=newExc2;
        }
        int max2=max(incl2,exc2);
        return max(max1,max2);
    }
};
