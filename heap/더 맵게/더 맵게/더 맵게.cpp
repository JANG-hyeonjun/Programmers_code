// 더 맵게.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int count = 0;
    int answer = 0;
    std::priority_queue<int,vector<int>,greater<int>> PQ;

    for (int i = 0; i < scoville.size(); i++)
    {
        PQ.push(std::move(scoville[i]));
    }
    

    while (PQ.top() < K)
    {
        int first = PQ.top();
        PQ.pop();
        int second = PQ.top();
        PQ.pop();
        PQ.push(std::move(first + (second * 2)));
        count++;
    }
    
    return count;
}

int main()
{
    std::cout << solution({ 1,2,3,9,10,12 }, 7);


}

