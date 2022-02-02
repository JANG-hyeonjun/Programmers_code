#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue <int> release_list;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for(int i = 0; i < speeds.size(); i++)
    {
        int need_time = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] > 0)
        {
            need_time++;
            release_list.push(need_time);
        }
        else
        {
            release_list.push(need_time);
        }
    }
    
    int answer_count = 1;
    int log_time = release_list.front();
    while(!release_list.empty())
    {
        if(release_list.size() == 1)
            break;
        
        release_list.pop();
        if(log_time < release_list.front())
        {
            log_time = release_list.front();
            //std::cout << log_time <<std::endl;
            answer.push_back(answer_count);
            answer_count = 1;
        }
        else
        {
            answer_count++;
        }
    }
    answer.push_back(answer_count);
    return answer;
}