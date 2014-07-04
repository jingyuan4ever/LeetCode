#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
	void sortColors(int A[], int n) {
		int p0 = 0;
		int p2 = n - 1;
		for (int i = 0; i <= p2; ){
			if (A[i] == 0){
				swap(A[i], A[p0]);
				p0++;
				i++;
			}
			else if (A[i] == 2){
				swap(A[i], A[p2]);
				p2--;
			}
			else{
				i++;
			}
		}
	}
};