/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
    int T, test_case;

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
        int n, k;
        cin >> n >> k;

        vector<int> A(n);
        vector<int> B(n);
		
		for(int i = 0; i < n; ++i) cin >> A[i];
		for(int i = 0; i < n; ++i) cin >> B[i];
		
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

        A.resize(k);
        B.resize(k);


		auto a_iter = A.begin();
		auto b_iter = B.rbegin();

        while(k--){
            Answer = max(Answer, (*a_iter++) + (*b_iter++));
        }
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
