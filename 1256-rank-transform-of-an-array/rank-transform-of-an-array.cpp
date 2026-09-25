class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back(arr[i]);
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        int rate=1;
        for(int i=0;i<temp.size();i++)
        {
            if(mp.find(temp[i])==mp.end())
            {
                mp[temp[i]]=rate;
                rate++;
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=mp[arr[i]];
        }
        return arr;
        
    }
};