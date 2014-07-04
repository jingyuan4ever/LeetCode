#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	int atoi(const char *str) {
		long long ret = 0;
		bool sign = false;
		bool start = false;
		if (str == nullptr)
			return ret;
		while (*str == ' ')
			str++;
		while (*str){
			if (*str == '+'){
				if (start)
					return 0;
				str++;
				start = true;
			}
			else if (*str == '-'){
				if (start)
					return 0;
				sign = true;
				start = true;
				str++;
			}
			else if (isdigit(*str)){
				ret = ret * 10 + *str - '0';
				str++;
				if (!sign&&ret > 2147483647){
					return INT_MAX;
				}
				if (sign&&ret > 2147483648){
					return INT_MIN;
				}
			}
			else{
				break;
			}
		}
		if (sign)
			return -ret;
		return ret;
	}
};
