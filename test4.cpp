//求从N开始最少累加几步可以到M，且每次累加的值为当前值的一个约数
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//将1-M个石板看作一个结果数组stepnum，每个stepnum[i]存储
//从起点到这一步最小的步数，其中0表示不能到达
//计算约数，计算除了1和本身的约数
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
		//N的所有约数，即为从本身这个点开始能走的数量
		vector<int> divNum;

		if(stepNum[i]==0)
			continue;//表示这个点不能到

		//求出所有能走的步数存储在divNum的容器中
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