#ifndef INCLUDE
#include <string>
#include <fstream>
#define INCLUDE
#endif
class Dictionary
{
private:
    std::string *main_arr;
    size_t word_count = 0;
    size_t capacity = 0;

public:
    Dictionary();
    size_t get_word_coutn();
    int equal(std::string &a, std::string &b);
    void add_word(std::string &word);
    std::string find_word(std::string &word);
    void copy(std::string *arr);
    ~Dictionary();
};

