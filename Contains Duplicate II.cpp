class Solution {
public:
   struct node
    {
      int pos, value; 
      node *next;
      node(int p, int v){
          pos = p;
          value = v;
          next = NULL;
      }
    };
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int mod = 9973;
        vector<node *> hash(mod, NULL);
        for(int i = 0; i < nums.size(); i++)
        {
            int slot = (nums[i] > 0 ? nums[i] : (-nums[i])) % mod;
            if(hash[slot] == NULL)
                hash[slot] = new node(i, nums[i]);
            else
            {
                node *p = hash[slot];
                while(p != NULL)
                {
                    if(p->value == nums[i] && abs((p->pos - i)) <= k)
                        return true;
                    p = p->next;
                }
                node *next = hash[slot];
                hash[slot] = new node(i, nums[i]);
                hash[slot]->next = next;
            }
        }
        return false;
    }
};