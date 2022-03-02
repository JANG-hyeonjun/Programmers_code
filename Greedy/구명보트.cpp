#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    
   int answer = 0;
   sort(people.begin(),people.end());
   int begin_idx = 0;
   int final_idx = people.size() - 1; 
   
    while(begin_idx <= final_idx)
    {
       int sum = people[begin_idx] + people[final_idx];
       //std::cout << sum <<", " << limit << std::endl;
        if(begin_idx != final_idx-- && sum <= limit) 
       {
            begin_idx++;
       }
        answer++;
    } 
   return answer;
}