#include <iostream>  // cin은 표준 입력(키보드)으로부터 입력을 받을 때 사용, cout은 표준 출력(화면)에 출력할 때 사용
#include <vector>    // vector는 동적 배열을 제공하는 표준 라이브러리
#include <algorithm> // algorithm은 다양한 알고리즘 함수들을 제공하는 라이브러리, 여기서는 sort 함수 사용

using namespace std; // 표준 네임스페이스(std)를 사용하겠다는 선언.
// std::cin, std::cout, std::vector 대신 간단히 cin, cout, vector로 사용 가능

int main()
{
    int n, m;
    cin >> n >> m; // 입력으로부터 두 개의 정수를 받아 각각 n과 m에 저장
    // n은 배열의 크기, m은 k씨가 일을 한 횟수

    vector<int> arr(n);         // 크기가 n인 정수형 벡터 arr를 선언
    for (int i = 0; i < n; ++i) // 0부터 n-1까지 반복
    {
        cin >> arr[i]; // 입력으로부터 n개의 정수를 받아 arr 벡터에 저장
    }
    vector<int> results;        // 결과를 저장할 벡터
    for (int t = 0; t < m; ++t) // 0부터 m-1까지 반복하는 루프: k씨가 일을 한 횟수만큼 반복
    {
        int i, j, k;
        cin >> i >> j >> k; // i와 j는 범위의 시작과 끝 인덱스, k는 선택할 위치

        // 부분 배열 추출
        vector<int> subArr(arr.begin() + i - 1, arr.begin() + j);
        // arr 벡터의 i-1부터 j까지의 부분 배열을 추출하여 subArr 벡터에 저장: {k_a}
        // C++에서 벡터는 0-based 인덱스를 사용하므로(like Python), 1-based 인덱스를 맞추기 위해 i-1로 조정

        sort(subArr.begin(), subArr.end()); // 오름차순 정렬
        results.push_back(subArr[k - 1]);   // k도 1-based 인덱스이므로, 0-based 인덱스로 접근하기 위해 k-1로 조정
    }
    for (int result : results)
    {
        cout << result << endl; // 결과 출력
    }

    return 0;
}