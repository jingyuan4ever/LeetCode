using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int y = 0;
		int copyX = x;
		while (copyX){
			y = y * 10 + copyX % 10;
			copyX /= 10;
		}
		return x == y;
	}
};