class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n==0){
            return 0;
        }
        int count=1;
        bool flag=true;
        for(int i=1;i<n;i++){
            if(A[i]==A[i-1]){
                if(flag){
                    flag=false;
                    A[count]=A[i];
                    count++;
                }
            }else{
                flag=true;
                A[count]=A[i];
                count++;
            }
        }
        return count;
    }
};