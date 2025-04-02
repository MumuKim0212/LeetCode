/* 정답
아이디어:
두 문자열이 같은 패턴이라면 두 문자열을 합쳤을 때 순서와 상관 없이 동일해야함
동일한 문자열이라면 같은 패턴을 갖고 있음
이때 두 문자열 길이의 최대공약수가 패턴

문제:

해결:

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // 두 문자열이 같은 패턴으로 구성되어 있는지 확인
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // 두 문자열 길이의 최대공약수 계산
        int gcdLength = gcd(str1.length(), str2.length());

        // 최대공약수 길이만큼의 접두사 반환
        return str1.substr(0, gcdLength);
    }

    // 유클리드 알고리즘으로 최대공약수 계산
    int gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

/*
아이디어:
만약 나눠진다면 문자열의 길이는 패턴의 배수
각각의 문자열을 패턴과 비교하며 순회

문제:

해결:

*/
/*
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // 짧은 문자열을 기준으로 순회
        string& shorter = str1.size() <= str2.size() ? str1 : str2;
        string& longer = str1.size() > str2.size() ? str1 : str2;

        for (int len = shorter.size(); len > 0; len--) {
            // 길이가 짧은 문자열의 길이의 약수인 경우만 확인
            if (shorter.size() % len != 0 || longer.size() % len != 0)
                continue;

            string pattern = shorter.substr(0, len);
            bool isAnswer = true;

            // shorter가 패턴으로 구성되어 있는지 확인
            for (int i = 0; i < shorter.size(); i += len) {
                if (shorter.substr(i, len) != pattern) {
                    isAnswer = false;
                    break;
                }
            }

            // longer가 패턴으로 구성되어 있는지 확인
            if (isAnswer) {
                for (int i = 0; i < longer.size(); i += len) {
                    if (longer.substr(i, len) != pattern) {
                        isAnswer = false;
                        break;
                    }
                }
            }

            if (isAnswer) return pattern;
        }

        return "";
    }
};
*/
