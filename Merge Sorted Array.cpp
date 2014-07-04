class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for(int i=m-1, j=m+n-1; i>=0; i--,j--){
            A[j]=A[i];
        }
        int i=0,j=0,k=n;
        while(j<n&&k<m+n){
            if(A[k]<B[j]){
                A[i]=A[k];
                k++;
                i++;
            }else{
                A[i]=B[j];
                i++;
                j++;
            }
        }
        while(j<n){
            A[i]=B[j];
            i++;
            j++;
        }
        while(k<m+n){
            A[i]=A[k];
            k++;
            i++;
        }
    }
};