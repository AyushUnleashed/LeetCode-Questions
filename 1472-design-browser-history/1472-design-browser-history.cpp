class Node{
    public:
    string url;
    Node* next;
    Node* prev;
    Node(string url){
        this->url = url;
        next=NULL;
        prev=NULL;
    }
};

class BrowserHistory {
    Node* currPage=NULL;
public:
    BrowserHistory(string homepage) {
        currPage = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newPage = new Node(url);
        Node* temp = currPage->next;
        delete temp;
        Node* prevPage = currPage;
        currPage->next = newPage;
        currPage = newPage;
        currPage->prev=prevPage;
    }
    
    string back(int steps) {
        while(currPage->prev!=NULL && steps>0){
            currPage=currPage->prev;
            steps--;
        }
        return currPage->url;
    }
    
    string forward(int steps) {
         while(currPage->next!=NULL && steps>0){
            currPage=currPage->next;
            steps--;
        }
        return currPage->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */