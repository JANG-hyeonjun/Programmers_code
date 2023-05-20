#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
    int ans = 0;
    vector<int> usage;
    
    usage.emplace_back(0);
    usage.emplace_back(1);
    usage.emplace_back(1);
  
    int count = 0;
    
    for(int idx = 3; idx <= 10; ++idx)
    {
       int number = idx;
        
        if(number % 2 == 0)
           usage.emplace_back(usage[number / 2]);
        else
        {
        
            number = number - 1;
            number = number / 2;
            usage.emplace_back(usage[number] + 1);
        }
    }
   
    while(n >= 10)
    {
        if(n % 2 == 0)
            n = n / 2;
        else
        {
            n = n - 1;
            count++;
        }    
    }

    ans = usage[n] + count;
    
    return ans;
}