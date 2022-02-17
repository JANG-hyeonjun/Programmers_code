#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    
    int result = brown + yellow;
    
    for(int i = 1; i < result; i++)
    {
        if(result % i == 0)
        {
            int h = result / i; 
            int w = i;
            int predict = ((result / i) - 2) * (i - 2);
            if(predict == yellow)
            {
                answer.push_back(result / i);
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}