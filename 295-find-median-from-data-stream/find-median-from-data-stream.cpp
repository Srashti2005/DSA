class MedianFinder {
public:
    priority_queue<int>left_maxH;
    priority_queue<int,vector<int>,greater<int>>right_minH;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_maxH.empty()||num<left_maxH.top())
        {
            left_maxH.push(num);
        }
        else
        {
            right_minH.push(num);
        }
        //check if the difference between minH and maxh>1 and both the sixe are equal
        //we want ki maxh mein zyda elements ho
        if(left_maxH.size()>right_minH.size()+1)
        {
            right_minH.push(left_maxH.top());
            left_maxH.pop();
        }
        if(left_maxH.size()<right_minH.size())
        {
            left_maxH.push(right_minH.top());
            right_minH.pop();
        }
    }
    
    double findMedian() {
        if(left_maxH.size()==right_minH.size())
        {
            return(left_maxH.top()+right_minH.top())/2.0;
        }
        
            return (left_maxH.top());
        
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */