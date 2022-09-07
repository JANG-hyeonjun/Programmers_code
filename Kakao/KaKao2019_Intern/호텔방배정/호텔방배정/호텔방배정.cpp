#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<long long, long long> roomStateMap;

long long find_ValidRoom(long long wantRoomNumber)
{
    if (roomStateMap[wantRoomNumber] == 0)
    {
        roomStateMap[wantRoomNumber] = wantRoomNumber + 1;
        return wantRoomNumber;
    }
    else
    {
        return roomStateMap[wantRoomNumber] = find_ValidRoom(roomStateMap[wantRoomNumber]);
    }
}

vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;

    for (auto wantRoomNumber : room_number)
    {
        answer.emplace_back(find_ValidRoom(wantRoomNumber));
    }
    return answer;
}

int main()
{
    solution(6, { 2,2,2,3 });
    return 0;
}