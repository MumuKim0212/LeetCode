/*
아이디어:
짝수이니 반드시 앞에서부터 2개씩 같은 숫자여야함
두칸씩 건너뛰며 다음 문자와 다르면 수정

문제:

해결:

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != s[i + 1]) {
                count++;
            }
        }
        return count;
    }
};