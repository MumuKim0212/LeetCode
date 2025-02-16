/*
아이디어:브루트포스
재귀로 모든 step마다
숫자를 배치할 수 있는지 확인 (처음 나오는 수인지, 거리조건이 맞는지)
배치가 가능하면 answer에 추가
answer이 최종 길이가 되면 종료

문제:
n = 11부터 Time Limit Exceeded 발생
모든 수에 대해서 체크하기 때문에 시간이 너무 오래걸림
플래그로 두번 사용된 수를 제외해도 시간초과 발생

해결:
숫자가 처음 위치하면 두번째 위치는 확정되므로 두 위치에 동시에 숫자를 넣음

*/

class Solution {
    vector<int> first;
    vector<int> answer;
    vector<bool> check; 
    int n;

    bool IsValid(int num, int step){
        if(check[num]) return false;
        if(num == 1){
            return first[num] == 0; 
        }
        if(first[num] == 0){
            if(step + num >= 2*n-1) return false;
            if(answer[step + num] != 0) return false;
            return true;
        }
        return step - first[num] + 1 == num;
    }
    bool Work(int step){
        if(step == 2*n-1) return true;
        if(answer[step] != 0) return Work(step+1);
        for(int i = n; i >= 1; i--){
            if(IsValid(i,step)){
                answer[step] = i;
                if(i != 1) answer[step + i] = i;
                if(first[i] == 0){
                    first[i] = step+1;
                }
                else{
                    check[i] = true;
                }
                if(Work(step+1)) return true;
                answer[step] = 0;
                if(i != 1) answer[step + i] = 0;
                if(first[i] == step+1){
                    first[i] = 0;
                }
                else{
                    check[i] = false;
                }
            }
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        this->n = n;
        first.assign(n+1,0);
        check.assign(n+1,false);
        answer.assign(n*2-1,0);
        Work(0);
        return answer;
    }
};
