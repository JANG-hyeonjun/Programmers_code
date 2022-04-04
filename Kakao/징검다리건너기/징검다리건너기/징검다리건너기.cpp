// 징검다리건너기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 200000000;
int max_result;



bool Can_to_Cross(vector<int> stones,int k,int m)
{
    int Zero_Stone = 0;
    //m-1까지 건넜다 가정 만약 못건넜으면 false 반환 아니면 true
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] - (m - 1) <= 0)
        {
            Zero_Stone++;
            if (Zero_Stone == k)
            {
                return false;
            }
        }
        else
        {
            Zero_Stone = 0;
        }
    }
    return true;
}

void Binary_Search(vector<int> stones, int k, int left, int right)
{
    //풀이 방법은 다음과 같다. m번째 사람이 건널수 있다는건 m-1번째 사람도 건넜다는것이다.
    //만약 m번째 사람이 건너지 못했다면 m-1번째 사람은 건넜는데 m번째 사람만 못건넜거나
    // m-1번째 사람도 못건넜거나 이다. 그런데 이를 순차적으로 찾으면 2억번을 돌아야하니 
    //매개변수성 이진 탐색을 진행. 

    while (left <= right)
    {
        int mid = (left + right) / 2;

        //true 건넜다. false 못건넜다.
        bool IsValid = Can_to_Cross(stones, k, mid);

        if (IsValid)
        {
            if (max_result < mid) max_result = mid;

            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}

int solution(vector<int> stones, int k) 
{
    int answer = 0;
    Binary_Search(stones, k, 1, MAX);
    
    answer = max_result;    
    return answer;
}


int main()
{
   std::cout << solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3) << std::endl;
   return 0;
}

