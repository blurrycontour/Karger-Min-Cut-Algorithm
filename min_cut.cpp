#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

vector<vector<int>> edges;
vector<vector<int>> edges_;

void swap(int i,int j)
{
	edges_[i] = edges_[j];
	edges_[j] = { 0, 0 };
	return;
}

int main(int argc, char* argv[])
{
	ifstream data;
	data.open("kmc_data.txt");
	int N = 200;
	int N_ = N;
	int Iter = 100;
	srand(time(NULL));
	
	

	while (!data.eof())
	{
		string line;
		getline(data, line);
		istringstream ss(line);
		int p1, p2;
		ss >> p1;
		while (ss >> p2)
		{
			if (p1 < p2)
				edges.push_back({p1,p2});
		}
	}
	int M = edges.size();
	int M_ = M;
	

	while (Iter > 0)
	{
		edges_ = edges;
		M_ = M;
		N_ = N;

		while (N_ > 2)
		{
			int e = rand() % M_;
			int a = edges_[e][0];
			int b = edges_[e][1];
			for (int i = 0; i < M_; i++)
			{
				if (edges_[i][0] == b)
					edges_[i][0] = a;
				else if (edges_[i][1] == b)
					edges_[i][1] = a;
			}
			int j = M_ - 1;
			for (int i = 0; i < M_ && i <= j;)
			{
				if (edges_[i][0] == edges_[i][1])
				{
					swap(i, j);
					j--;
				}
				else
					i++;
			}
			edges_.resize(j + 1);
			M_ = j + 1;
			N_--;
		}
		Iter--;
		cout << "Min Cut : " << edges_.size() << "\n\n";
	}
	
	
	
	/*for (int i = 0; i < edges.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << edges[i][j] << "	";
		}
		cout << "\n";
	}*/

	system("pause");
	return 0;
}
