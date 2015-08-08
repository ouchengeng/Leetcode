class Solution {
public:
void reverse(string &s, int i, int j)
{
	for(; i < j; i++, j--)
	{
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
void reverseWords(string &s)
{
	int start = 0, end = s.length() - 1;
	while(start < s.length() && s[start] == ' ') start++;
	while(end >= 0 && s[end] == ' ') end--;
	if(start >= s.length() || end < 0)
	{
		s = "";
		return;
	}
	int words = 0;
	int len = 0, space = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == ' ')
			space++;
		else if(i == 0 || s[i - 1] == ' ')
			words++;
	}
	len = s.length() - space + (words - 1);
	int pos = 0;
	for(int i = start; i <= end; i++)
	{
	    if(i != start && s[i] == ' ' && s[i - 1] == ' ')
	        continue;
	    s[pos++] = s[i];
	}
	s = s.substr(0, len);
	for(int i = 0; i < s.length(); )
	{
		int j = i;
		while(j < s.length() && s[j] != ' ')
			j++;
		reverse(s, i, j - 1);
		i = j + 1;
	}
	reverse(s, 0, s.length()-1);
}
};