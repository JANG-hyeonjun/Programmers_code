// SecondProblem.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <string>
#include <vector>
#include <iostream>

const int MAX = 1005;
int board[MAX][MAX];
int drawNumber = 1;



void Clock_wise_LT(int n)
{
    int can_draw = n - 2;
    int start_i = 0, start_j = 0;
    int number = 1;
    for (int i = start_i; i <= can_draw; i++)
    {
        board[start_i][start_j + i] = number++;
    }

    start_i = start_i + 1;
    can_draw--;
    for (int i = start_i; i <= can_draw; i++)
    {
        board[start_i+i][start_j] = number++;
    }


}

void Clock_wise_RT(int n)
{
    int strat_i = 0, start_j = n - 1;


}

void Clock_wise_LB(int n)
{
    int strat_i = n-1, start_j = 0;

}

void Clock_wise_RB(int n)
{
    int strat_i = n - 1, start_j = n-1;

}



std::vector<std::vector<int>> solution(int n, bool clockwise) {
    std::vector<std::vector<int>> answer;

    if (clockwise == true)
    {
        //시계
        //left_top
        Clock_wise_LT(n);
        //right_top
        Clock_wise_RT(n);
        //Left_top
        Clock_wise_LB(n);
        //right_bottom
        Clock_wise_RB(n);
    }
    else
    {
        //반시계
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }


    return answer;
}

int main()
{
    solution(5, true);


    return 0;
}

