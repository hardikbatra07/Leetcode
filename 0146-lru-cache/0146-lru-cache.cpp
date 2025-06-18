class LRUCache {
    map<int,int> m1,m2,m3;
    int timer=0;
    int cap;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m2.find(key)==m2.end()) return -1;
        else{
            m1.erase(m3[key]);
            m3[key]=timer;
            m1[timer]=key;
            timer++;
            return m2[key];
           
        }
     
    }
    
    void put(int key, int value) {
        if(m2.find(key)!=m2.end()){
            m2[key]=value;
            m1.erase(m3[key]);
            m1[timer]=key;
            m3[key]=timer;
        }
       else {
        if (m2.size() == cap) {
            auto x = m1.begin(); 
            int old_key = x->second;
            m2.erase(old_key);
            m3.erase(old_key);
            m1.erase(x);
        }
        m1[timer] = key;
        m2[key] = value;
        m3[key] = timer;
    }
    timer++;
}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */