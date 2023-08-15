#include <unordered_map>
#include <string>

class Logger {
private:
    std::unordered_map<std::string, int> msgDict;

public:
    /** Initialize your data structure here. */
    Logger() {
        msgDict = std::unordered_map<std::string, int>();
    }

    /**
     * Returns true if the message should be printed in the given timestamp, otherwise returns false.
     */
    bool shouldPrintMessage(int timestamp, std::string message) {

        if (msgDict.find(message) == msgDict.end()) {
            msgDict[message] = timestamp;
            return true;
        }

        int oldTimestamp = msgDict[message];
        if (timestamp - oldTimestamp >= 10) {
            msgDict[message] = timestamp;
            return true;
        } else
            return false;
    }
};



/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */