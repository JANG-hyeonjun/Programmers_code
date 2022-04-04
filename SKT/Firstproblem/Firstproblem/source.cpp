#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

//using namespace std;
std::map<int, int> Coin_Map;
std::map<int, int, std::greater<int>> temp;
int solution(int money, std::vector<int> costs) {
    int answer = 0;
    int Min = 2000000;
    int default_money[] = { 1,5,10,50,100,500,1000};
    Coin_Map.clear();

    for (int i = 0; i < costs.size(); i++)
    {
        Coin_Map.insert(std::make_pair(costs[i], default_money[i]));
    }
    
    int j = 0;
    while (j != costs.size())
    {
        int i = 0;
        temp.clear();
        answer = 0;
        for (std::map<int, int>::iterator itr = Coin_Map.begin(); i <= j; itr++,i++)
        {
            //std::cout << itr->first << " " << itr->second << std::endl;   
            temp.insert(std::make_pair(itr->first, itr->second));

            //key = 생산단가 value = 실제 금액 
        }
        int targetMoney = money;
        for (std::map<int, int>::iterator itr = temp.begin(); itr != temp.end(); itr++)
        {
            //std::cout << itr->first << " " << itr->second << std::endl;
    
            answer += itr->first * (targetMoney / itr->second);
            targetMoney = targetMoney % itr->second;
        }
        j++;
        std::cout << "make_money: " << answer << std::endl;
        if (answer <= Min) Min = answer;
        //std::cout << std::endl;
    }
    


    return Min;
}


int main()
{
    std::cout << solution(4578, { 1,4,99,35,50,1000}) <<  std::endl;
    std::cout << solution(1999, { 2,11,20,100,200,600}) << std::endl;

    return 0;
}