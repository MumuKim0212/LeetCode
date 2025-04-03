/*
아이디어:
nums[i] - nums[j]가 양수이면 가장 큰 nums[k]를 구하기

문제:
배열의 최대 길이가 10^5이므로 On으로 끝내야함

해결:
배열을 순회하며 해당 자리까지의 nums[i] - nums[j] 중 최대값을 저장
다시 배열을 순회하며 해당 값의 다음 자리 값을 곱함

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxResult = 0;

        // 각 위치까지의 최대 (nums[i] - nums[j]) 값을 계산
        vector<int> maxDiff(n, 0);
        int maxSoFar = nums[0];

        for (int i = 1; i < n - 1; i++) {
            maxDiff[i] = max(maxDiff[i - 1], maxSoFar - nums[i]);
            maxSoFar = max(maxSoFar, nums[i]);
        }

        // 각 k 위치에 대해 최대값 계산
        for (int j = 2; j < n; j++) {
            long long val = (long long)maxDiff[j - 1] * nums[j];
            maxResult = max(maxResult, val);
        }

        return maxResult;
    }
};