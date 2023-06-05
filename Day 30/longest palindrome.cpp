class Solution
{
public:
    string longestPalindrome(string s)
    {
        
        string t;
        t.push_back('#');
        for (int i = 0; i < s.size(); i++)
        {
            t.push_back(s[i]);
            t.push_back('#');
        }

        swap(s, t);
        int n = s.size();
        vector<int> p(n);

        
        int l = 0, r = -1;
        for (int i = 0; i < n; i++)
        {
            int k;
            if (i > r)
                k = 1;
            else
                k = min(p[i], r - l);

            
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
                k++;

            p[i] = k;

            
            if (i + k > r)
            {
                
                l = i - k;
                r = i + k;
            }
        }

        
        int mx = 0, idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i] > mx)
            {
                mx = p[i];
                idx = i;
            }
        }

        string cur = s.substr(idx - mx + 1, 2 * p[idx] - 1);
        string ans;
        for (auto i : cur)
            if (i != '#')
                ans.push_back(i);
        return ans;
    }
};