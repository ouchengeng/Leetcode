class Solution {
public:

string fractionToDecimal(int numerator1, int denominator1){
	// numerator / denominator
	//if()

	long long numerator = (long long)(numerator1);
	long long denominator = (long long)(denominator1);
	ostringstream os;
	if(numerator * denominator < 0)
		os<<"-";
	numerator = numerator > 0 ? numerator : (-numerator);
	denominator = denominator > 0 ? denominator : (-denominator);
	long long zhengshu = numerator / denominator;
	long long  remains = numerator - zhengshu * denominator;
	os<<zhengshu;
	if(remains == 0)
		return os.str();
	int shang;
	vector<int> ans;
	int counter = 0;
	int flag = false;
	map<long long, int> pos; 
	map<long long, int>::iterator it; 
	int position;
	while(remains != 0)
	{
		remains *= 10;

		it = pos.find(remains);
		if(it != pos.end())
		{
			position = it->second;
			flag = true;
			break;
		}
		shang = remains  / denominator;
		ans.push_back(shang);
		pos.insert(make_pair(remains, counter++));
		remains = (remains) - (shang * denominator);
	}
	os<<".";
	for(int i = 0; i < ans.size(); i++)
	{
		if(i == position && flag)
			os<<"(";
		os<<ans[i];
	}
	if(flag)
		os<<")";
	return os.str();
}
};