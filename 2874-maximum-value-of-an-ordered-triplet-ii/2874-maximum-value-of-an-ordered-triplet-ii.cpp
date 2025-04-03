/* 답
아이디어:
nums[i] - nums[j]가 양수이면 가장 큰 nums[k]를 구하기

문제:
배열의 최대 길이가 10^5이므로 On으로 끝내야함

해결:
배열을 순회하며 해당 자리까지의 nums[i] - nums[j] 중 최대값을 저장
다시 배열을 순회하며 해당 값의 다음 자리 값을 곱함
위 과정을 한번에 진행

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0, imax = 0, dmax = 0;
        for (int k = 0; k < n; k++) {
            res = max(res, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, static_cast<long long>(nums[k]));
        }
        return res;
    }
};
