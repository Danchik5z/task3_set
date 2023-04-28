#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class Set {
public:
    Set() {}
    
    void insert(const T& elem) {
        if (!contains(elem)) {
            elems.push_back(elem);
            std::sort(elems.begin(), elems.end());
        }
    }
    
    void erase(const T& elem) {
        auto it = std::find(elems.begin(), elems.end(), elem);
        if (it != elems.end()) {
            elems.erase(it);
        }
    }
    
    bool contains(const T& elem) const {
        return std::find(elems.begin(), elems.end(), elem) != elems.end();
    }
    
    size_t size() const {
        return elems.size();
    }
    
    Set<T> operator+(const Set<T>& other) const {
        Set<T> result;
        for (const T& elem : elems) {
            result.insert(elem);
        }
        for (const T& elem : other.elems) {
            result.insert(elem);
        }
        return result;
    }
    
    Set<T> operator-(const Set<T>& other) const {
        Set<T> result;
        for (const T& elem : elems) {
            if (!other.contains(elem)) {
                result.insert(elem);
            }
        }
        return result;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Set<T>& s) {
        os << "{";
        for (size_t i = 0; i < s.size(); i++) {
            os << s.elems[i];
            if (i < s.size() - 1) {
                os << ", ";
            }
        }
        os << "}";
        return os;
    }
    
private:
    std::vector<T> elems;
};

int main() {
    // Пример для int
    Set<int> s1, s2;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s2.insert(2);
    s2.insert(3);
    s2.insert(4);
    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "s1 + s2 = " << s1 + s2 << std::endl;
    std::cout << "s1 - s2 = " << s1 - s2 << std::endl;

    // Пример для string
    Set<std::string> s3, s4;
    s3.insert("apple");
    s3.insert("banana");
    s4.insert("banana");
    s4.insert("cherry");
    std::cout << "s3 = " << s3 << std::endl;
    std::cout << "s4 = " << s4 << std::endl;
    std::cout << "s3 + s4 = " << s3 + s4 << std::endl;
    std::cout << "s3 - s4 = " << s3 - s4 << std::endl;
    
    return 0;
}
