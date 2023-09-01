class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        
        string hostname = getHostname(startUrl);
        vector<string> result;
        unordered_set<string> visited;
        queue<string> toVisit;
        mutex mtx;
        condition_variable cv;
        int working = 0;

        // Add the startUrl to the queue and mark it as visited
        toVisit.push(startUrl);
        visited.insert(startUrl);

        // Define the worker thread function
        auto worker = [&]() {
            while (true) {
                string url;
                {
                    // Lock the mutex before accessing shared data
                    unique_lock<mutex> lock(mtx);
                    // Wait until there is a URL to visit or all threads are done working
                    cv.wait(lock, [&]() { return !toVisit.empty() || working == 0; });
                    // If there are no URLs to visit, exit the thread
                    if (toVisit.empty()) {
                        return;
                    }
                    // Get the next URL to visit and remove it from the queue
                    url = toVisit.front();
                    toVisit.pop();
                    // Increment the working counter
                    ++working;
                }
                // Get the URLs on the page
                vector<string> urls = htmlParser.getUrls(url);
                {
                    // Lock the mutex before accessing shared data
                    lock_guard<mutex> lock(mtx);
                    // For each URL on the page, if it has not been visited and it has the same hostname, add it to the queue and mark it as visited
                    for (const string& url : urls) {
                        if (visited.find(url) == visited.end() && getHostname(url) == hostname) {
                            visited.insert(url);
                            toVisit.push(url);
                        }
                    }
                    // Decrement the working counter
                    --working;
                }
                // Notify other threads that a URL has been processed
                cv.notify_all();
            }
        };

        // Create a number of worker threads equal to the number of cores on the machine
        vector<thread> workers;
        for (int i = 0; i < thread::hardware_concurrency(); ++i) {
            workers.emplace_back(worker);
        }
        // Wait for all worker threads to finish
        for (thread& worker : workers) {
            worker.join();
        }

        // Return the visited URLs
        return vector<string>(visited.begin(), visited.end());
    }

private:
    // Helper function to extract the hostname from a URL
    string getHostname(const string& url) {
        size_t pos = string("http://").size();
        pos = url.find('/', pos);
        if (pos == string::npos) {
            return url;
        }
        return url.substr(0, pos);
    }
};