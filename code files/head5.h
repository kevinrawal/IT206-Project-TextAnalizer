#include<bits/stdc++.h>
using namespace std;
#define b 256


	//rabin karp algorithm
	
    bool search(string ss, string text, int q)             //ss->sub string 
{
	int M = ss.length();
	int N = text.length();
	int i, j;
	int p,t,h;
     p = 0; // hash value for pattern
     t = 0; // hash value for text
     h = 1;

	// The value of h would be "pow(b, M-1)%q"  , q is prime number 
	for (i = 0; i < M - 1; i++)
		h = (h * b) % q;
	
	for (i = 0; i < M; i++)
	{
		p = (b * p + ss[i]) % q;
		t = (b * t + text[i]) % q;
	}

	for (i = 0; i <= N - M; i++)
	{
		if ( p == t )
		{

			for (j = 0; j < M; j++)
			{
				if (text[i+j] != ss[j])
					break;
			}
						
			if(j==M){
				return 1;
			}
			
		}
		//assign new value to t
		if ( i < N-M )
		{
			t = (b*(t - text[i]*h) + text[i+M])%q;

			if (t < 0)
			t = (t + q);
		}
	}

	return 0;
}         