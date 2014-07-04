using namespace std;

class Solution {
public:
	int sqrt(int x) {
		if (x <= 0)
			return 0;
		if (x == 1)
			return 1;
		double sr = 1.0;
		double sr2 = (sr + x / sr) / 2;
		while (int(sr2) - int(sr)){
			sr = sr2;
			sr2 = (sr + x / sr) / 2;
		}
		return int(sr);
	}
};