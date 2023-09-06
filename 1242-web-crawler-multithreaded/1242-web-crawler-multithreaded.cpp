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
        auto idx = std::size_t(0);
        for (auto n = 0; n != (3 - 1); ++n) {
            idx = url.find_first_of('/', idx) + 1;
        }
        idx = url.find_first_of('/', idx);

        if (idx == std::string_view::npos) {
            return std::string{ url };
        }
        else {
            return std::string{ url.substr(0, idx) };
        }
    }

    void getUrls(HtmlParser& htmlParser, std::string&& urlParent)
    {
        auto urls = htmlParser.getUrls(urlParent);

        const std::lock_guard<std::mutex> lk(mMutex);
        for (auto& url : urls) {
            mQueue.push(std::move(url));
        }
    }

    void checkBreath(HtmlParser& htmlParser, const string& hostname, std::size_t n)
    {
        std::vector<std::thread> threads;
        threads.reserve(n);

        while (n-- != 0) {

            const auto url = mQueue.front();
            mQueue.pop();

            if (getHostname(url) != hostname) {
                continue;
            }

            {
                const std::lock_guard<std::mutex> lk(mMutex);

                if (mHashSet.find(url) != mHashSet.end()) {
                    continue;
                }

                mHashSet.insert(url);
            }
            
            threads.push_back(std::thread{ &Solution::getUrls, this, std::ref(htmlParser), std::move(url) });
            
        }

        for (auto& thread : threads) {
            thread.join();
        }
    }

  public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser)
    {
        const auto hostname = getHostname(startUrl);

        mQueue.push(startUrl);

        while (mQueue.empty() == false) {

            checkBreath(htmlParser, hostname, mQueue.size());
        }

        return std::vector<std::string>(mHashSet.begin(), mHashSet.end());
    }
};