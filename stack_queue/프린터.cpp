#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int j;
int i;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    vector<pair<int, int>> Queue;

    for (int i = 0; i < priorities.size(); i++)
    {
        Queue.push_back(make_pair(priorities[i], i));
    }
    int len = Queue.size();

    for (i = 0; i <= Queue.size(); i++)
    {
        bool flag = false;
        pair<int, int>temp = Queue.front();
        Queue.erase(Queue.begin());

        for (j = 0; j < Queue.size(); j++)
        {
            if (temp.first < Queue[j].first)
            {
                flag = true;
            }
        }

        if (flag == true)
        {
            std::cout << "in " << temp.first << ", " << temp.second << std::endl;
            Queue.push_back(make_pair(temp.first, temp.second));
            i = 0;
            j = 0;
        }
        else
        {
            std::cout << temp.first << ", " << temp.second << std::endl;
            answer++;
            if (temp.second == location)
            {
                break;
            }
            i = 0;
            j = 0;
        }
    }
    return answer;
}