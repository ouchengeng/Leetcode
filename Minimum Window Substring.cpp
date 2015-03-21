class Solution {
public:
string minWindow(string S, string T) {
	if(S.length() == 0 || T.length() == 0 || S.length() < T.length())
		return "";
	int start = -1, end = S.length() + 2, num=0;
	int hash[128], base[128];
    memset(hash, 0, sizeof(hash));
    memset(base, 0, sizeof(base));
	for(int i = 0; i < T.length(); i++)
	{
		base[T[i]]++;
		if(hash[T[i]] == 0)
		{
			num++;
			hash[T[i]] = 1;
		}
	}
	for(int i = 0; i < 128; i++)
	{
		if(hash[i] == 0)
			hash[i] = S.length() + 1;
		else
			hash[i] = 0;
	}
	int head = 0, tail = 0, cur = 0;
	while(head < S.length() && tail < S.length())
	{
		while(tail < S.length() && cur < num)
		{
			hash[S[tail]]++;
			if(base[S[tail]] != 0 && hash[S[tail]] == base[S[tail]])
				cur++;
			tail++;
		}
		if(tail == S.length() && cur != num)
			break;
		while(head < S.length())
		{
		    if(base[S[head]] != 0 && hash[S[head]] < base[S[head]])
				break;
			else if(hash[S[head]] == base[S[head]] && cur == num)
			{
				if((tail - head - 1) < (end - start))
				{
					end = tail - 1;
					start = head;
				}
				cur--;
			}
			else if(hash[S[head]] == (base[S[head]]))
				break;
			hash[S[head]]--;
			head++;
		}
	}
	if(start == -1)
		return "";
	return S.substr(start, end - start + 1);

}
};