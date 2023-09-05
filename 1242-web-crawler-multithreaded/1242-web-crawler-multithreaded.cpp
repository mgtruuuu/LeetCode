/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
  private:
    std::mutex mMutex;
    std::queue<std::string> mQueue;
    std::unordered_set<std::string> mHashSet;

    std::string getHostname(std::string_view url) const
    {
        const auto idx_slash = url.find('/', 7);
        
        if (idx_slash == std::string_view::npos) {
            return std::string{ url }.substr(7);    
        }
        
        return std::string{ url }.substr(7, idx_slash - 7);
    }

    void getUrls(HtmlParser& htmlParser, const string& hostname, const std::string urlParent)
    {
        const auto urls = htmlParser.getUrls(urlParent);
        
        std::cout << "urls length : " << urls.size() << std::endl;
        for (const auto url : urls) {

            std::cout << "\turl: " << url << std::endl;
            std::cout << "\thostname : " << hostname << std::endl;
            
            if (getHostname(url) != hostname) {
                continue;
            }

            const std::lock_guard<std::mutex> lk(mMutex);

            if (mHashSet.find(url) != mHashSet.end()) {
                continue;
            }

            //mHashSet.insert(url);
            mQueue.push(url);
        }
    }

    void checkBreath(HtmlParser& htmlParser, const string& hostname, std::size_t n)
    {
        std::vector<std::thread> threads;
        threads.reserve(n);

        std::cout << "checkBreath() called --- n : " << n << std::endl;        
        
        while (n-- != 0) {

            const auto url = mQueue.front();
            mQueue.pop();

            std::cout << "url : " << url << std::endl;

            
            if (getHostname(url) != hostname) {
                continue;
            }
            
            {
                const std::lock_guard<std::mutex> lk(mMutex);

                if (mHashSet.find(url) != mHashSet.end()) {
                    continue;
                }
                
                mHashSet.insert(url);
                // mQueue.push(url);
                
                
                std::cout << "thread() will be calling" << std::endl;
                threads.push_back(std::thread{ &Solution::getUrls, this, std::ref(htmlParser), std::cref(hostname), url });
            }
            

        }
        
        std::cout << "size of threads:" << threads.size() << std::endl;
        for (auto& thread : threads) {
            thread.join();
        }
        std::cout << "thread through" << std::endl;
        std::cout << "length of mQueue : " << mQueue.size() << std::endl;
    }

  public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser)
    {
        const auto hostname = getHostname(startUrl);
        
        //mHashSet.insert(startUrl);
        mQueue.push(startUrl);
        
        while (mQueue.empty() == false) {

            std::cout << "====checkBreath() will be calling" << std::endl;
            checkBreath(htmlParser, hostname, mQueue.size());
        }

        std::vector<std::string> res;

        for (auto itr = mHashSet.begin(); itr != mHashSet.end(); ++itr) {
            res.push_back(*itr);
        }

        return res;
    }
};