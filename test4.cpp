//���N��ʼ�����ۼӼ������Ե�M����ÿ���ۼӵ�ֵΪ��ǰֵ��һ��Լ��
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//��1-M��ʯ�忴��һ���������stepnum��ÿ��stepnum[i]�洢
//����㵽��һ����С�Ĳ���������0��ʾ���ܵ���
//����Լ�����������1�ͱ����Լ��
void divisorNum(int n, vector<int> &divNum)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n%i == 0)
		{
			divNum.push_back(i);
			if (n/i != i)
				divNum.push_back(n / i);
		}
	}
}
int Jump(int N,int M)
{
	vector<int> stepNum(M + 1, 0);
	stepNum[N] = 1;

	for (int i = N; i < M; ++i)
	{
		//N������Լ������Ϊ�ӱ�������㿪ʼ���ߵ�����
		vector<int> divNum;

		if(stepNum[i]==0)
			continue;//��ʾ����㲻�ܵ�

		//����������ߵĲ����洢��divNum��������
		divisorNum(i, divNum);

		for (int j = 0; j < divNum.size(); ++j)
		{
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1);
			else if ((divNum[j] + i) <= M)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
	}
	if (stepNum[M] == 0)
		return -1;
	else
		return stepNum[M] - 1;
}
int main()
{
	int N, M;
	cin >> N >> M;
	cout << Jump(N, M) << endl;
	return 0;
}