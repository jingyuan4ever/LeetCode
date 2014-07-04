#include <vector>
#include <string>
using namespace std;
class Solution {
private:
	bool isCharMatch(const char &c1, const char &c2){
		if (!c1 || !c2)
			return false;
		if (c2 == '.')
			return true;
		return c1 == c2;
	}
public:
	bool isMatch(const char *s, const char *p) {
		while (*s && *p){
			bool repeat = false;
			char now = *p;
			p++;
			if (*p == '*'){
				repeat = true;
				p++;
			}
			if (repeat){
				while (isCharMatch(*s, now)){
					s++;
				}
			}
			else if (isCharMatch(*s, now)){
				s++;
			}
			else{
				return false;
			}
		}
		return !(*s || *p);
	}
};