class Solution {
public:
    string intToRoman(int num)
    {
    	 string roman[4][11] = {  
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},  //0-9
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},  //10-90
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  
                {"", "M", "MM", "MMM"}  
            };
    	 int pos = 0;
    	 string ans;
    	 while(num > 0)
    	 {
    		 int remainder = num % 10;
    		 ans = roman[pos][remainder] + ans;
    		 num /= 10;
    		 pos++;
    	 }
    	 return ans;
    }
};