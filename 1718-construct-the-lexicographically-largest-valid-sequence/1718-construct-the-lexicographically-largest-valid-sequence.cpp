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