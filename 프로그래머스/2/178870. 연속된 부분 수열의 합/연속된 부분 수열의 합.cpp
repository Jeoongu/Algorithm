#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
투포인터로 생각하고 문제 풀이
*/

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 0};
    int len = sequence.size()+1; // 부분수열의 길이 
    int sum = sequence[0];
    int start = 0;
    int end = 0;
    
    while(start <= end && end < sequence.size()){
        if(sum<k){
            end++;
            sum+=sequence[end];
            continue;
        }
        else if(sum == k){
            if(end-start+1 < len){
                len = end-start+1;
                answer[0] = start;
                answer[1] = end;
            }
            else if(end-start+1==len){
                if(answer[0] > start){
                    answer[0]=start;
                    answer[1]=start;
                }
            }
            
        }
        sum-=sequence[start];
        start++;
    }
    
    return answer;
}