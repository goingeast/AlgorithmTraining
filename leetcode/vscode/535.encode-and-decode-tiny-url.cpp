/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 *
 * https://leetcode.com/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (75.85%)
 * Total Accepted:    66.9K
 * Total Submissions: 88.2K
 * Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
 *
 * Note: This is a companion problem to the System Design problem: Design
 * TinyURL.
 * 
 * TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such
 * as http://tinyurl.com/4e9iAk.
 * 
 * Design the encode and decode methods for the TinyURL service. There is no
 * restriction on how your encode/decode algorithm should work. You just need
 * to ensure that a URL can be encoded to a tiny URL and the tiny URL can be
 * decoded to the original URL.
 * 
 */
class Solution {
public:
    Solution() {
        dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-.";
        short2long.clear();
        long2short.clear();
        srand(time(NULL));
    }
    string generateKey(){
        string randStr;
        for (int i = 0; i < 8; ++i) 
            randStr.push_back(dict[rand() % 64]);
        return randStr;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long2short.count(longUrl)) {
            return "http://tinyurl.com/" + long2short[longUrl];
        }
    
        string randStr = generateKey();
    
        while (short2long.count(randStr)) {
            randStr = generateKey();
        }
        short2long[randStr] = longUrl;
        long2short[longUrl] = randStr;
        return "http://tinyurl.com/" + randStr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string randStr = shortUrl.substr(shortUrl.find_last_of("/") + 1);
        return short2long.count(randStr) ? short2long[randStr] : shortUrl;
    }
    
private:
    unordered_map<string, string> short2long, long2short;
    string dict;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

