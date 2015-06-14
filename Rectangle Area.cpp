class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	int area1 = (C-A) * (D-B);
    	int area2 = (G-E) * (H-F);
    	int top = min(D,H);
    	int bottom = max(F, B);
    	int left = max(A,E);
    	int right = min(G,C);
    	int overlap = 0;
    	if(right > left && top > bottom)
    		 overlap = (right - left) * (top - bottom);
    	return area1 + area2 - overlap;
    }
};