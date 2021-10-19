#include "dictionary.h"
Dictionary::Dictionary()
{
    std::ifstream dic("dictionary.txt");
    dic >> this->word_count;
    capacity = word_count + 3;
    std::string* diction = new std::string [capacity];
    for(size_t i = 0; i < word_count; i++)
        dic >> diction[i];
    dic.close();
}
void Dictionary::copy(std::string *arr)
{
    for(size_t i = 0; i < word_count; i++)
        arr[i] = main_arr[i];
}
int Dictionary::equal(std::string &a, std::string &b)
{
    size_t size = a.length() > b.length() ? b.length() : a.length(),
    eql = 0;
    for(size_t i = 0; i < size; i++)
        if(tolower(a[i]) == b[i])
            eql++;
    
    return eql;

}
std::string Dictionary::find_word(std::string &word)
{
    int max = 0;
    std::string poss_word;
    for(int i = 0; i < this->word_count; i++)
    {
        int tmp = equal(main_arr[i], word);
        if(tmp == word.length())
            return tmp;
        
    }

}
void Dictionary::add_word(std::string &word)
{
    std::string *tmp;
    word_count++;
    if(capacity == word_count)
    {
        capacity += 3;
        tmp = new std::string [capacity];
    }
    copy(tmp);
    delete [] main_arr;
    main_arr = tmp;
    main_arr[word_count] = word;
    tmp = nullptr;
}

Dictionary::~Dictionary()
{
    std::ofstream fout("dictionary.txt");

    for(size_t i = 0; i < word_count; i++)
        fout << main_arr[i];
    
    delete [] main_arr;
    main_arr = nullptr;
}