#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<double> maxH;
    priority_queue<double,vector<double>,greater<double>> minH;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(!maxH.empty() && num>maxH.top()){
            // right side push
            minH.push(num);
        }else{
            //left side push
            maxH.push(num);
        }
        
        int szDiff = maxH.size() - minH.size();
        if(abs(szDiff)>1){
            // if diff is more than 1, we shift
            if(maxH.size()>minH.size()){
                double temp=maxH.top();
                maxH.pop();
                minH.push(temp);
            }else{
                double temp=minH.top();
                minH.pop();
                maxH.push(temp);
            }
        }
        
    }
    

    double findMedian() {
        int totalSize = minH.size()+maxH.size();
        double median;
        
        if(minH.size()==maxH.size()){
            median = (maxH.top()+minH.top())/2;
        }else{
            //unequal
            if(minH.size()>maxH.size()){
                median= minH.top();
            }else{
                median= maxH.top();
            }
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */