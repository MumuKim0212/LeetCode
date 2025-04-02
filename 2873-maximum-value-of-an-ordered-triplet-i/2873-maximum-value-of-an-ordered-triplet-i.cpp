/*
아이디어:
전부 시도해도 10^6번이니 전부 시도해도됨

문제:

해결:

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        for (int i = 0; i < nums.size() - 2;i++) {
            for (int j = i + 1; j < nums.size() - 1;j++) {
                long long value = nums[i] - nums[j];
                if (value > 0) {
                    for (int k = j + 1; k < nums.size();k++) {
                        result = max(value * nums[k], result);
                    }
                }
            }
        }
        return result;
    }
};