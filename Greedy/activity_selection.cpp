/* Used Greedy approach is get the schedule of jobs that can be completed without conflict */
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Pair
{
    int start, finish;
};

void schedule(const vector<Pair> &jobs)
{
    set<int> s;
    s.insert(0);

    int k =0;

    for (int i=1; i < jobs.size(); i++)
    {
        if (jobs[i].start >= jobs[k].finish) {
            s.insert(i);
            k = i;
        }
    }

    for(auto &i : s) {
      cout << "{" << jobs[i].start << "," << jobs[i].finish << "}" << endl;
    }
}

int main()
{
    vector<Pair> jobs = {
	    {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
		{6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };

    sort(jobs.begin(), jobs.end(), [ ](Pair &lhs, Pair &rhs) {
        return lhs.finish < rhs.finish;
    });

    schedule(jobs);
    return 0;
}