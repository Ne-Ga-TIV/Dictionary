#include "dictionary.h"
Dictionary::Dictionary()
{
    std::ifstream dic("dictionary.txt");
    dic >> this->word_count;
    capacity = word_count + 3;
    std::string* diction = new std::string [capacity];
    for(int i = 0; i < word_count; i++)
        dic >> diction[i];
    dic.close();
}
void Dictionary::copy(std::string *arr)
{
    for(int i = 0; i < word_count; i++)
        arr[i] = main_arr[i];
}
int Dictionary::equal(std::string &a, std::string &b)
{
    int size = a.length() > b.length() ? b.length() : a.length(),
    eql = 0;
    for(int i = 0; i < size; i++)
        if(tolower(a[i]) == b[i])
            eql++;
    
    return eql;

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
    
    
    delete [] main_arr;
}