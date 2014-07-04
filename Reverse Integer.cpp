#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		long long ret=0;
		bool sign = false;
		if (x < 0){
			sign = true;
			x = -x;
		}
		while (x){
			ret = ret * 10 + x % 10;
			x /= 10;
		}
		if (sign){
			ret = -ret;
		}
		return ret;
	}
};

int main(){
	Solution s;
	cout << s.reverse(12321312);
	int i;
	cin >> i;
	return 0;
}