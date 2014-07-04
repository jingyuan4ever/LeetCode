using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 0 || n == 1)
			return 1;
		int s1 = 1, s2 = 1;
		int ret = 0;
		while (n-->1){
			ret = s1 + s2;
			s1 = s2;
			s2 = ret;
		}
		return ret;
	}
};
