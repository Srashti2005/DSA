class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(int i=0;i<tasks.size();i++)
        {
            freq[tasks[i]-'A']++;
        }
        priority_queue<int>pq;
        int time=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
                pq.push(freq[i]);
        }
        while(!pq.empty())
        {
            vector<int>temp;
            for(int i=1;i<=n+1;i++)
            {
                if(!pq.empty()){
                int frq=pq.top();
                pq.pop();
                frq--;
                temp.push_back(frq);
                }
            }
            for(auto f:temp)
            {
                if(f>0)
                {
                    pq.push(f);
                }
            }
            if(pq.empty())
        {
            time+=temp.size();

        }
        else
        {
            time+=n+1;
        }
        

        }
        
        return time;
    }
};