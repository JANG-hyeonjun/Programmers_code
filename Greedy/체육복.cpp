#include <string>
#include <vector>
#include <iostream>
using namespace std;


int student[33];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer =  0;

    for(int lost_num : lost) student[lost_num] += -1;
    for(int reverse_num : reserve) student[reverse_num] += 1;
    
    for(int i = 1; i<=n; i++)
    {
        if(student[i] == -1)
        {
            if(student[i - 1] == 1)
            {
                student[i - 1] = student[i] = 0;
            }    
            else if(student[i + 1] == 1)
            {
                student[i + 1] = student[i] = 0;   
            }
        }
    }
    
    for(int i = 1; i <= n ; i++)
    {
        if(student[i] != -1) 
        {
            answer++;
        }
    }
    return answer;
}