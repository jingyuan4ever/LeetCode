class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0){
            return 0;
        }
        int count=1;
        for(int i=1;i<n;i++){
            if(A[i]!=A[i-1]){
                A[count]=A[i];
                count++;
            }
        }
        return count;
    }
};