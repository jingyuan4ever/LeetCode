#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		string ret;
		int aLength = a.length();
		int bLength = b.length();
		int carry = 0;
		int sum = 0;
		while (aLength&&bLength){
			sum = a[--aLength] - '0' + b[--bLength] - '0' + carry;
			carry = sum >> 1;
			ret.push_back(sum % 2 + '0');
		}
		while (aLength){
			sum = a[--aLength] - '0' + carry;
			carry = sum >> 1;
			ret.push_back(sum % 2 + '0');
		}
		while (bLength){
			sum = b[--bLength] - '0' + carry;
			carry = sum >> 1;
			ret.push_back(sum % 2 + '0');
		}
		if (carry){
			ret.push_back('1');
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};