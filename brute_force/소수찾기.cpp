#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<int> se;
bool check[7];
string st_num = "";

void find_number(int num)
{
    if(num == 1 || num == 0)
        return;
    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
        {
            return;
        }
    }
    se.insert(num);
}

void permutation(string numbers,int start,int end)
{
    if(start == end)
    {
        find_number(stoi(st_num));
        return;
    }
    for(int i = 0; i < numbers.length(); i++ )
    {
        if(check[i])
            continue;
        check[i] = true;
        st_num += numbers[i];
        //std::cout << st_num << std::endl;
        permutation(numbers,start+1,end);
        //std::cout << i << std::endl;
        check[i] = false;
        st_num.pop_back();
        //std::cout << st_num << std::endl;
    }

}

int solution(string numbers) {
    int answer = 0;
   
    for(int i =0; i < numbers.length(); i++)
    {
        find_number(numbers[i] - '0');
        if(i != 0)
        {
            //std::cout << i << std::endl;
            permutation(numbers,0,i+1);
        }
    }
    
    answer = se.size();
    return answer;
}