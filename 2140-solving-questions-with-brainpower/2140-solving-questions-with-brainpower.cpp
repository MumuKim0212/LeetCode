/*
아이디어:
뒤에서부터 앞으로 순회하며 문제를 풀거나 건너뛰는 경우를 계산
최댓값을 벡터에 저장

문제:

해결:

*/

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> pointVec(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int point = questions[i][0];
            int brainpower = questions[i][1];

            // 풀었을 때의 최대 점수
            int next = i + brainpower + 1;
            long long solve = point + (next < n + 1 ? pointVec[next] : 0);

            // 건너뛰었을 때의 최대 점수
            long long skip = pointVec[i + 1];

            pointVec[i] = max(solve, skip);
        }

        return pointVec[0];
    }
};