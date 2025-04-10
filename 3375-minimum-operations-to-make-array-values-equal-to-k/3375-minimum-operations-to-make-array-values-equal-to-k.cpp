/*
아이디어:
1. 배열을 만들어 중복체크
2. k보다 작은 수가 있으면 -1 반환
3. k부터 가장 큰 수까지의 수를 더함 => 그냥 갯수를 세면 됨

문제:

해결:

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minOperations(vector<int>& nums, int k) {
		int check[101] = { 0 };
		int count = 0;
		for (int num : nums) {
			if (num < k) return -1;
			if (check[num] == 0) {
				check[num] = 1;
				count++;
			}
		}
		return check[k] == 1 ? count - 1 : count;
	}
};