#include "pch.h"

// 내 풀이
// 기존 배열을 참조로 받는 함수를 받아 
// merge_sort통해 해당 범위 만큼의 배열을 정렬
// 이 후, arr의 k번째 원소 추출


// 다시 푼 풀이
// tmp(temp)라는 command의 범위에 해당하는 arr의 요소를 복사하기 위한 배열 생성
// tmp를 sort 함수를 통해 정렬(sort함수는 intro sort algorithm을 사용해, 추가적인 메모리 없이 정렬할 수 있는 좋은 정렬 함수)
// tmp배열에서 k에 해당하는 원소 추출

int main()
{
    vector<int> arr{ 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> command{ {2, 5, 3}, { 4, 4, 1}, { 1, 7, 3 } };
    vector<int> answer;
    for (const auto& i : command)
    {
        auto start{ i[0] - 1 };
        auto end{ i[1]};
        auto idx{ (i[2] - 1)};
        vector<int> tmp{ arr.begin() + start, arr.begin() + end };
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[idx]);
    }

    for (auto i : answer) cout << i << " ";
}