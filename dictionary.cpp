#include "dictionary.h"
Dictionary::Dictionary()
{
    std::ifstream dic("dictionary.txt");
    dic >> this->word_count;

    capacity = word_count + 3;
    main_arr = new std::string [capacity];

    for(size_t i = 0; i < word_count; i++)
        dic >> main_arr[i];

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
        int tmp = equal(word, main_arr[i]);

        if(tmp == main_arr[i].length()){
            return word;
        }
        if(tmp > max)
        {
            max = tmp;
            poss_word = main_arr[i];
        }
    }
    return poss_word;

}
void Dictionary::add_word(std::string &word)
{
    std::string *tmp;

    if(capacity == word_count+1)
    {
        capacity += 3;
        tmp = new std::string [capacity];
        copy(tmp);
        delete [] main_arr;
        main_arr = tmp;
    }
    main_arr[word_count] = word;
    word_count++;
    
}

Dictionary::~Dictionary()
{
    std::ofstream fout("dictionary.txt");
    fout << word_count << '\n';
    for(size_t i = 0; i < word_count; i++)
        fout << main_arr[i] << ' ';
    
    delete [] main_arr;
    main_arr = nullptr;
}