#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int nCandyCnt = 0;
        int nSeqLen = 0;
        int nPreCanCnt = 1;
        int nMaxCntInSeq = nPreCanCnt;
        if(ratings.begin() != ratings.end())
        {
            nCandyCnt++;
            for(vector<int>::iterator i = ratings.begin()+1; i!= ratings.end(); i++)
            {
                if(*i < *(i-1))
                {
                    nSeqLen++;
                    if(nMaxCntInSeq == nSeqLen)
                    {
                        nSeqLen++;
                    }
                    nCandyCnt+= nSeqLen;
                    nPreCanCnt = 1;
                }
                else
                {
                    if(*i > *(i-1))
                    {
                        nPreCanCnt++;
                    }
                    else
                    {
                        nPreCanCnt = 1;
                    }
                    nCandyCnt += nPreCanCnt;
                    nSeqLen = 0;
                    nMaxCntInSeq = nPreCanCnt;
                }
            }
        }
        return nCandyCnt;
    }
};