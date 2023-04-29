#include<iostream>
#include<string>
#include<vector>

int IsKPeriodic(std::string text, int k)
{
	if (text.size() % k != 0) return 0; // �������� ��������� �� ����� �������������

	std::vector<char> text_on; // ������ ������
	std::vector<char> sub_string; // ������ ���������
	int period = 0; // ������� �������������

	for (int i = 0; i < text.size(); ++i)
	{
		text_on.push_back(text[i]);
	}

	for (int i = 0; i < k; ++i)
	{
		sub_string.push_back(text[i]);
	}
	for (int i = 0; i < text_on.size(); i += k)
	{
		for (int j = 0; j < k; ++j)
		{
			if (text_on[i + j] != sub_string[j]) // ������������ ��������� ����� ������ � ���������
			{
				return 0;
			}
		}
		++period;
	}
	return period;
}

int main()
{
	while (true)
	{
		std::cout << "Enter text:" << std::endl;
		std::string text;
		std::cin >> text;
		std::cout << "Enter multiplicity:" << std::endl;
		int k;
		std::cin >> k;
		if (k <= 0)
		{
			std::cout << "Enter a multiplicity greater than 0" << std::endl;
		}
		else if (IsKPeriodic(text, k) == 0)
		{
			std::cout << "Not a multiple" << std::endl;
		}
		else
		{
			std::cout << "Multiple with peroidicity " << IsKPeriodic(text, k) << std::endl;
		}
	}
	return 0;



}