#include <bits/stdc++.h>
using namespace std;

class Threads
{
	public:
		long long int time;
		int thread_id;

		Threads()
		{
			this->time = 0;
		}
};

int leftchild(int i)
{
  return (2*i) + 1;
}

int rightchild(int i)
{
  return (2*i)+2;
}

void Siftdown(int i, vector <Threads> &threads_number)
{
	int index = i;
	int left = leftchild(i);

	if(left < static_cast<int>(threads_number.size()) && threads_number[left].time == threads_number[index].time)
	{
		int temp_original_id = threads_number[index].thread_id;
		int temp_left_id = threads_number[left].thread_id;

		if(temp_original_id > temp_left_id)
			index = left;
	}

	else if(left < static_cast<int>(threads_number.size()) && threads_number[left].time < threads_number[index].time)
		index = left;

	int right = rightchild(i);

	if(right < static_cast<int>(threads_number.size()) && threads_number[right].time == threads_number[index].time)
	{
		int left_id = threads_number[index].thread_id;
		int right_id = threads_number[right].thread_id;

		if(left_id > right_id)
			index = right;
	}

	else if(right < static_cast<int>(threads_number.size()) && threads_number[right].time< threads_number[index].time)
	  index = right;

	if(i!=index)
	{
	  swap(threads_number[i], threads_number[index]);
	  Siftdown(index,threads_number);
	}
} 
void ChangePriority(int i, long long int new_priority, vector <Threads> &threads_number)
{
	threads_number[0].time = new_priority;

	Siftdown(0,threads_number);
}

void start(vector <long long int> &jobs, vector <Threads> &threads_number)
{
	vector <pair <int ,long long int> > results;
	results.resize(jobs.size());

	for(int i=0; i<jobs.size(); i++)
	{
		results[i] = make_pair(threads_number[0].thread_id, threads_number[0].time);
		if(jobs[i] != 0)
			ChangePriority((int)0,threads_number[0].time + jobs[i], threads_number);
	}


	for(int i=0; i<results.size(); i++)
		cout << results[i].first << " " << results[i].second << endl;
}


int main()
{
	int n,m;
	cin >> n >> m;

	vector <long long int> jobs;
	jobs.resize(m);

	for(int i=0; i<m; i++)
		cin >> jobs[i];

	vector <Threads> threads_number;
	threads_number.resize(n);

	for(int i=0; i<n; i++)
		threads_number[i].thread_id = i;

	start(jobs,threads_number);
	return 0;
}