class Logger {
  private:
    std::unordered_map<std::string, int> message2timestamp;
    
  public:
    Logger()
    {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message)
    {
        const auto p = message2timestamp.find(message);
        
        if (p == message2timestamp.end()) {
            message2timestamp[message] = timestamp;
            
            return true;
        }
        
        if (timestamp - p->second < 10) {
            return false;
        }
        else {
            p->second = timestamp;
            
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */