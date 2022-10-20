#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    int t;
    long int a, b,n, j = 0;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cin >> a >> b;
        n = sqrt(b);

        bool check_primes[n + 1];   //including 0
        memset(check_primes, true, n+1);
        bool print_primes[b - a + 1];
        memset(print_primes, true, b - a + 1);

        if (a == 1)
            print_primes[0] = false;

        for (long int i = 2; i <= n; i++)
        {
            if (check_primes[i] == true)
            {
                for (long int j = i * i; j <= n; j += i)
                {
                    check_primes[j] = false;
                }
                for( int x=a;x<=b;x++)
                {
                    if(x%i==0 and x!=i)
                    {
                        print_primes[x-a]=false;
                        x+=(i-1);
                    }
                }
            }
        }
        for (int l = 0; l <= b - a; l++)
        {
            if (print_primes[l] == true)
                cout << l + a << "\n";
        }
    }
    return 0;
}