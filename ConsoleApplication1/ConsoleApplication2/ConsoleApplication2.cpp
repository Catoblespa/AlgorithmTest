#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(vector<int> numbers, int target) {
    int answer = 0;

	const int maxBit = (numbers.size() << 1) -1; ///만약 size가 9면  1 1 1 1 1 1 1 1 1 1 가 만들어짐.
	auto realsize = numbers.size();
    int bit = 0;


    int count = 0;

   

	int result = 0;

	do {
		int sum = 0;

		for (int idx = 0; idx < realsize; idx++)
			sum = bit & (1 << idx) ? -numbers[idx] : numbers[idx];
		
		cout << sum << " ";
		if (sum == target)
		{
			answer++;
			cout << answer << " ";

		}


		++bit;
	} while ((bit != maxBit)); // 


    return answer;
}


void main()
{
	vector<int> numbers = { 1,1,1,1,1 };

	auto result = solution(numbers, 3);



	cout << result << endl;

	//Sleep(1000);
}