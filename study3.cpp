#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct User // 구조체 정의
{
    int age;
    string name;
    int order;
};

bool sorting(const User &a, const User &b) // 정렬함수 (비교함수)
{
    if (a.age == b.age)
    {
        return a.order < b.order; // 나이가 같을 때, 먼저 들어오는게 더 빠르면 true 반환(사실 당연한 얘기)
    }
    return a.age < b.age; // 먼저 들어오는 유저의 나이가 적으면 true 반환.
}

int main()
{
    int N;
    cin >> N;
    vector<User> users(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> users[i].age >> users[i].name; // 입력되는 대로 저장
        users[i].order = i;                   // 가입 순서 저장
    }

    sort(users.begin(), users.end(), sorting); // 비교함수가 true면 첫번째 인자가 두번째 인자보다 작다고 판단 (오름차순)

    for (int i = 0; i < N; ++i)
    {
        cout << users[i].age << " " << users[i].name << endl;
    }

    return 0;
}