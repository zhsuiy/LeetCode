#include <iostream>
class Solution {
public:
	int addDigits(int num) {
		int sum = INT_MAX;
		while (sum >= 10)
		{
			sum = 0;
			while (num >= 10)
			{
				sum += (num % 10);
				num /= 10;
			}
			sum += num;
			num = sum;
		}
		return sum;
	}
};

void main()
{
	Solution s;
	std::cout << s.addDigits(10);


}