class LFUCache {
    int cap;
    int timer = 0;

    map<int, set<pair<int, int>>> freqToKeys;
    map<int, int> keyToValue;                 
    map<int, int> keyToFreq;                  
    map<int, int> keyToTime;                  

public:
    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (keyToValue.find(key) == keyToValue.end())
            return -1;
        int freq = keyToFreq[key];
        int time = keyToTime[key];
        freqToKeys[freq].erase({time, key});
        if (freqToKeys[freq].empty()) freqToKeys.erase(freq);
        freq++;
        timer++;
        keyToFreq[key] = freq;
        keyToTime[key] = timer;
        freqToKeys[freq].insert({timer, key});

        return keyToValue[key];
    }

    void put(int key, int value) {
        if (keyToValue.find(key) != keyToValue.end()) {
            keyToValue[key] = value;
            get(key); 
            return;
        }
        if (keyToValue.size() == cap) {
            auto it = freqToKeys.begin();
            int minFreq = it->first;
            auto oldest = *(it->second.begin()); 
            int keyToEvict = oldest.second;

            freqToKeys[minFreq].erase(oldest);
            if (freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);
            keyToValue.erase(keyToEvict);
            keyToFreq.erase(keyToEvict);
            keyToTime.erase(keyToEvict);
        }
        timer++;
        keyToValue[key] = value;
        keyToFreq[key] = 1;
        keyToTime[key] = timer;
        freqToKeys[1].insert({timer, key});
    }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */