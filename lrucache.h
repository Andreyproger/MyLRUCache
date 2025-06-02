#include <iostream>
#include <list>
#include <unordered_map>

template <typename Key, typename Value, size_t MaxSize>
class LRUCache {
private:
    using List = std::list<std::pair<Key, Value>>;
    using Map = std::unordered_map<Key, typename List::iterator>;

    List cache_list;
    Map cache_map;

    /*!
     * \brief evict
     * \details метод вытеснения первого элемента последовательности
     */
    void evict() {
        if (cache_list.empty()) return;

        auto last = cache_list.back();
        cache_map.erase(last.first);
        cache_list.pop_back();
    }

public:
    void put(const Key& key, const Value& value) {
        auto it = cache_map.find(key);
        if (it != cache_map.end()) {
            cache_list.erase(it->second);
            cache_map.erase(it);
        }
        else if (cache_list.size() >= MaxSize) {
            evict();
        }

        cache_list.emplace_front(key, value);
        cache_map[key] = cache_list.begin();
    }

    Value get(const Key& key) {
        auto it = cache_map.find(key);
        if (it == cache_map.end()) {
            return "";
        }

        cache_list.splice(cache_list.begin(), cache_list, it->second);
        return it->second->second;
    }

    bool contains(const Key& key) const {
        return cache_map.find(key) != cache_map.end();
    }

    size_t size() const {
        return cache_list.size();
    }

    // void print() const {
    //     std::cout << "LRUCache (size: " << size() << "/" << MaxSize << "): ";
    //     for (const auto& pair : cache_list) {
    //         std::cout << "{" << pair.first << ":" << pair.second << "} ";
    //     }
    //     std::cout << std::endl;
    // }
};
