class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n == 0)
    		return n;
    	int pos = 1;
    	for(int i = 1; i < n; i++)
    		if(A[i] != A[i - 1])
    		    A[pos++] = A[i];
    	return pos;
    }
};