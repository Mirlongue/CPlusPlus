#include <iostream>
#include <string>

#include <sstream>
#include <fstream>

#include <iterator>

struct DumpOS{
    std::string prefix = "D:/Reposity_github/CPlusPlus/trick/dump/build/";
    std::ostringstream oss;
    void clear() {oss.str("");}
    template<class T>
    DumpOS & operator << (const T & st) {
        oss << st << " ";
        return * this;
    }
    template<class T>
    DumpOS & operator >> (const T & st) {
        oss << st << std::endl;
        return * this;
    }
    void dump(const std::string name) {
        std::string path = prefix + name + ".txt";
        std::string st = oss.str();
        std::ofstream ofs(path, std::ios::binary);
        if (ofs) {
            std::copy(st.c_str(), st.c_str() +st.length(), std::ostream_iterator<char>{ofs});
            ofs.close();
        }
    }
};


void dump_buff(char * p, int size, std::string name) {
    std::string prefix = "D:/Reposity_github/CPlusPlus/trick/dump/build/";
    std::string path = prefix + name + ".bin";
    std::ofstream ofs(path, std::ios::binary);
    if (ofs) {
        std::copy(p, p + size, std::ostream_iterator<char>{ofs});
    }
    ofs.close();

}

int main() {
    DumpOS oss;
    oss << "hellow" >> "world";
    oss.dump("test");

    char st[11] = "0123456789";
    dump_buff(st, 10, "st");

    return 0;
}