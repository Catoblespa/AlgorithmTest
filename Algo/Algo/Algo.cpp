#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <bitset>

using namespace std;


#define X00	1<<0//0		// 2 진수로 0
#define X01	1<<1//1		// 2 진수로 10
#define X02	1<<2//2		// 2 진수로 100
#define X03	1<<3//4		// 2 진수로 1000
#define X04	1<<4//8		// 2 진수로 10000
#define X05	1<<5//16		// 2 진수로 100000
#define X06	1<<6//32		// 2 진수로 1000000
#define X07	1<<7//64		// 2 진수로 10000000
#define X08	1<<8//128		// 2 진수로 100000000
#define X09	1<<9//256		// 2 진수로 1000000000
#define X10	1<<10//512		// 2 진수로 10000000000
#define X11	1<<11//1024	// 2 진수로 100000000000
#define X12	1<<12//2048	// 2 진수로 1000000000000
#define X13	1<<13//4096	// 2 진수로 10000000000000
#define X14	1<<14//8192	// 2 진수로 100000000000000
#define X15	1<<15//16384	// 2 진수로 1000000000000000
#define X16	1<<16//32768	// 2 진수로 10000000000000000
#define X17	1<<17//65536	// 2 진수로 100000000000000000
#define X18	1<<18//131072	// 2 진수로 1000000000000000000
#define X19	1<<19//262144	// 2 진수로 10000000000000000000
#define X20	1<<20//524288	// 2 진수로 100000000000000000000
static int bitArray[20] = { X00,X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19 };




int solution(vector<int> numbers, int target) {
	int answer = 0;

	//	const int maxBit = (numbers.size() << 1) - 1; //
	/*
	* 	1 0 0 0 0 0  -1
		0 1 1 1 1 1
	*/
	//bitset<20> _curbet;	
	auto realsize = numbers.size();
	int curBit = (1 << numbers.size());
	int sum = 0;
	int idx = 0;

	bitset<20> _bitset;
	//bitset<20> _temp;;

	while (curBit != 0)
	{
		_bitset = curBit;
		//_temp = _bitset;
		//memcpy(&_temp, &_bitset, sizeof(_temp));
		sum = 0;//ZeroMemory(&sum, sizeof(int));
		idx = 0;//ZeroMemory(&idx, sizeof(int));

		for (idx = 0; idx < realsize; ++idx)
		{
			sum += _bitset.test(idx) /*pow(2, idx)*/ ? numbers[idx] : -numbers[idx];
		}

		if (sum == target)
		{
			answer++;
			//cout <<" : " << answer << "!" << endl;;
		}

		curBit--;
	}

	//bitArray[realsize -1]

	return answer;

}

void main()
{
	vector<int> numbers = { 1,1,1,1,1 };

	auto result = solution(numbers, 3);

	numbers = { 1,1,1,1,1 };
	auto result = solution(numbers, 3);



	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "!!" << result << endl;

	//Sleep(1000);
}