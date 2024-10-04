#include "pch.h"

// �� Ǯ��
// ���� �迭�� ������ �޴� �Լ��� �޾� 
// merge_sort���� �ش� ���� ��ŭ�� �迭�� ����
// �� ��, arr�� k��° ���� ����


// �ٽ� Ǭ Ǯ��
// tmp(temp)��� command�� ������ �ش��ϴ� arr�� ��Ҹ� �����ϱ� ���� �迭 ����
// tmp�� sort �Լ��� ���� ����(sort�Լ��� intro sort algorithm�� �����, �߰����� �޸� ���� ������ �� �ִ� ���� ���� �Լ�)
// tmp�迭���� k�� �ش��ϴ� ���� ����

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