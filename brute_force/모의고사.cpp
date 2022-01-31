#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector <int> answer_count = {0,0,0};
//전역 초기화시 0으로 무조건 초기화 

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    //1. 먼저 수포자들의 배열을 미리 초기화 왜? 그렇게 만 계속 찍으니까
    vector<int> person1 = {1,2,3,4,5};
    vector<int> person2 = {2,1,2,3,2,4,2,5};
    vector<int> person3 = {3,3,1,1,2,2,4,4,5,5};
    
    //2. 들어오는 정답들과 비교하며 현재 맞춘 정답을 계속 기록하며 로직 진행 
    for(int i =0; i < answers.size(); i++)
    {
        if(answers[i] == person1[i % 5]) answer_count[0]++;
        if(answers[i] == person2[i % 8]) answer_count[1]++;
        if(answers[i] == person3[i % 10]) answer_count[2]++;
    }
    int max = *max_element(answer_count.begin(), answer_count.end());
    //3. vector가 완성되었다면 max값 찾아주고 비교하며 정답 완성후 반환 
    for(int i =0; i < 3; i++)
    {
        if(max == answer_count[i])
        {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}