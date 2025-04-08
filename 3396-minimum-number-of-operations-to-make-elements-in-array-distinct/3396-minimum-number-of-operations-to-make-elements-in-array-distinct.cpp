/*
아이디어:
1. 크기가 100인 중복체크 배열을 생성
2. 배열의 크기가 3개 미만이면 종료
3. 중복체크
4. 중복이 있으면 벡터의 앞에서부터 3개 제거
5. 제거한 횟수를 반환

문제:

해결:

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minimumOperations(vector<int>& nums) {
		int arr[101] = { 0, };
		int position = 0, count = 0;
		while (true) {
			if (position == nums.size()) break;
			if (arr[nums[position]] == 0) {
				arr[nums[position]] = 1;
				position++;
			}
			else {
				count++;
				if (nums.size() <= 3) break;

				for (int i = 0; i < 3; i++) {
					arr[nums[i]] = 0;
				}
				nums.erase(nums.begin(), nums.begin() + 3);
				position = max(0, position - 3);
			}
		}
		return count;
	}
};