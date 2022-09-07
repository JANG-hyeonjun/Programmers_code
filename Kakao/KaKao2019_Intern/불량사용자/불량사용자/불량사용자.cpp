#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

std::vector<int> checkList(8);
std::set<std::string> inferiorityUserNameSet;

void DFS(std::vector<std::string>& user_id, std::vector<std::string>& banned_id, int count)
{
    if (count == banned_id.size())
    {
        std::string storeUserName = "";
        for (int userIndex = 0; userIndex < user_id.size(); ++userIndex)
        {
            if (checkList[userIndex])
                storeUserName += user_id[userIndex];
        }
        inferiorityUserNameSet.insert(storeUserName);
        return;
    }

    else
    {
        for (int normalUserIdx = 0; normalUserIdx < user_id.size(); ++normalUserIdx)
        {
            bool isSame = true;
            
            if (checkList[normalUserIdx])
                continue;
            
            if (user_id[normalUserIdx].length() != banned_id[count].length())
                continue;

            for (int j = 0; j < user_id[normalUserIdx].size(); ++j)
            {
                if (banned_id[count][j] == '*')
                {
                    continue;
                }
                
                if (banned_id[count][j] != user_id[normalUserIdx][j])
                {
                    isSame = false;
                    break;
                }
            }

            if (isSame)
            {
                checkList[normalUserIdx] = true;
                DFS(user_id, banned_id, count + 1);
                checkList[normalUserIdx] = false;
            }
        }
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int count = 0;
    DFS(user_id, banned_id, count);
    return inferiorityUserNameSet.size();
}

int main()
{
    std::cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "abc1**" }) << std::endl;
    inferiorityUserNameSet.clear();
    std::cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "*rodo", "******", "******" }) << std::endl;
    inferiorityUserNameSet.clear();
    return EXIT_SUCCESS;
}