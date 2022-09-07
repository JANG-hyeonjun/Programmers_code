#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
std::map<int, std::pair<int, int>> keyPadMap;
std::pair<int, std::pair<int, int>> leftHand;
std::pair<int, std::pair<int, int>> rightHand;


int ComputeDistnace(std::pair<int, int> hand, std::pair<int, int> target)
{
    return abs(hand.first - target.first) + abs(hand.second - target.second);
}

void Initialize()
{
    int x = 0;
    int y = 0;

    for (int number = 1; number <= 9; ++number)
    {
        if (number % 3 == 1 && number != 1)
        {
            x++;
            y = 0;
            keyPadMap[number] = std::pair<int, int>{ x,y };
        }
        keyPadMap[number] = std::pair<int, int>{ x,y };
        y++;
    }

    keyPadMap[0] = { 3,1 };

    leftHand.first = 10;
    leftHand.second = { 3,0 };

    rightHand.first = 11;
    rightHand.second = { 3,2 };
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    Initialize();

    for (auto wantKeypress : numbers)
    {
        if (wantKeypress == 1 || wantKeypress == 4 || wantKeypress == 7)
        {
            answer.append("L");
            leftHand.first = wantKeypress;
            leftHand.second = keyPadMap[wantKeypress];
        }
        else if (wantKeypress == 3 || wantKeypress == 6 || wantKeypress == 9)
        {
            answer.append("R");
            rightHand.first = wantKeypress;
            rightHand.second = keyPadMap[wantKeypress];
        }
        else
        {
            int leftDistance = ComputeDistnace(leftHand.second, keyPadMap[wantKeypress]);
            int rightDistance = ComputeDistnace(rightHand.second, keyPadMap[wantKeypress]);

            if (rightDistance < leftDistance)
            {
                answer.append("R");
                rightHand.first = wantKeypress;
                rightHand.second = keyPadMap[wantKeypress];
            }
            else if (rightDistance > leftDistance)
            {
                answer.append("L");
                leftHand.first = wantKeypress;
                leftHand.second = keyPadMap[wantKeypress];
            }
            else
            {
                if (hand.compare("left") == 0)
                {
                    answer.append("L");
                    leftHand.first = wantKeypress;
                    leftHand.second = keyPadMap[wantKeypress];
                }
                else
                {
                    answer.append("R");
                    rightHand.first = wantKeypress;
                    rightHand.second = keyPadMap[wantKeypress];
                }
            }
        }
    }
    return answer;
}