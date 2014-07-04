class Solution {
public:
    int singleNumber(int A[], int n) {
        int count[32]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                count[j]+=(A[i]>>j)&1;
            }
        }
        int ret = 0;
        for(int j=0;j<32;j++){
            ret|=(count[j]%3)<<j;
        }
        return ret;
    }
};