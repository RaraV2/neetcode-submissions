class TimeMap {
   private:
    unordered_map<string, vector<pair<int, string>>> keyValueStore;
    int size{}, l{}, r{}, mid{};

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyValueStore[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (keyValueStore.find(key) == keyValueStore.end()) {
            return "";
        }

        size = keyValueStore[key].size();
        l = 0;
        r = size - 1;

        if (size == 1) {
            // if it doesn't exist we return
            // the most recent timeStamp anyways
            if (timestamp < keyValueStore[key][l].first) {
                return "";
            }

            return keyValueStore[key][l].second;
        }

        else {
            int foundTimestamp{};
            while (l <= r) {
                mid = l + (r - l) / 2;
                foundTimestamp = keyValueStore[key][mid].first;

                if (timestamp == foundTimestamp) {
                    return keyValueStore[key][mid].second;
                } else if (timestamp > foundTimestamp) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (r >= 0) {
                return keyValueStore[key][r].second;
            }

            return "";
        }
    }
};
