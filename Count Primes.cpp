class Solution {
public:
    int countPrimes(int n) {
        if(n <= 0)
            return 0;
    	bool *prime = new bool[n];
    	memset(prime, false, sizeof(bool) * n);
    
    	for(int i = 2; i < n; i++)
    	{
    		if(prime[i] == false)
    			for(int j = i + i; j < n; j += i)
    				prime[j] = true;
    	}
    	int size = 0;
    	for(int i = 2; i < n; i++)
    		if(!prime[i])
    			size++;
    	delete []prime;
    	return size;
    }
};