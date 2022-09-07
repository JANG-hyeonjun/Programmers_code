// 크레인인형뽑기게임.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>


//std::vector<std::queue<int>> Crain_state;

const int MAX = 35;

std::queue<int>crain[MAX];
std::vector<int> result;

int solution(std::vector<std::vector<int>> board, std::vector<int> moves) {
    int answer = 0;


    for (std::vector<std::vector<int>>::iterator itr = board.begin(); itr != board.end(); itr++)
    {
       // std::queue<int>push_to_crain;
        //std::cout << itr->size() << std::endl;
        for(int i = 0; i < itr->size(); i++)
        {
            if (itr->at(i) != 0)
            {
                crain[i].push(itr->at(i));
            }
        }    
        //Crain_state.push_back(push_to_crain);
        //std::cout << std::endl;
    }
    

    for (std::vector<int>::iterator itr = moves.begin(); itr != moves.end(); itr++)
    {
       
        if (!crain[*itr - 1].empty())
        {
            if (result.size()!= 0 && crain[*itr -1].front() == result[result.size() -1])
            {
                result.pop_back();
                crain[*itr - 1].pop();
                answer += 2;
            }
            else
            {
                result.push_back(crain[*itr - 1].front());
                crain[*itr - 1].pop();
            }

        }
       
    }


    /*
    for (int i = 0; i < board.size(); i++)
    {
        int size = crain[i].size();
        for (int j = 0; j < size; j++)
        {
            std::cout << crain[i].front() << " ";
            crain[i].pop();
        }
        std::cout << std::endl;
    }

    
    */




    return answer;
}

int main()
{

    solution({ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1 } }, { 1, 5, 3, 5, 1, 2, 1, 4 });
    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
