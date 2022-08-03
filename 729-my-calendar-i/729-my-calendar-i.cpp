class MyCalendar {
public:

    vector<vector<int>> bookingTimes;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        bool succeds = false;

        if(bookingTimes.size()==0)
        {
            succeds = true;
        }
        
        for(auto &vect: bookingTimes)
        {
            int currStart = vect[0];
            int currEnd = vect[1];
            
            if( (start<currStart && end<=currStart) || (start>=currEnd && end> currEnd))
            {
                succeds = true;
            }else
            {
                succeds = false;
                break;
            }
        }
  
        if(succeds)
        {
            bookingTimes.push_back({start,end});
            
            return true;
        }else { return false;}
        
    }
}; 

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */