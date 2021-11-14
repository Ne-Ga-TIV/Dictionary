#include "dictionary.h"
#ifndef INCLUDE
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#endif

enum size_handler{
    in_capacity = 1000
};

void in_size_update(size_t count, std::string **arr)
{
    std::string *tmp = new std::string[count+250];
    
    for(int i = 0; i < count; i++)
        tmp[i] = (*arr)[i];
    

    delete [] *arr;

    *arr = tmp;

}
bool get_answer()
{
    char symbol;
    std::cout << "Please, enter y(yes) or n(no): ";
    do
    {
        std::cin >> symbol;
        if(std::cin.fail() || (symbol != 'y' && symbol != 'n' &&  symbol != 'Y' &&  symbol != 'N'))
            std::cout << "Please, enter y(yes) or n(no): ";
        else
            break;
    }while (true);

    if(symbol == 'y')
        return true;
    
    return false;
}
void check_word(std::string &word, Dictionary &dic)
{
    std::string poss_word = dic.find_word(word);
    if(poss_word == word)
        return;
    
    std:: cout << "An error was found in the word " << word <<". Perhaps you meant "<< poss_word << "?\n";
    
    if(get_answer())
    {
        word = poss_word;
        return;
    }
    std::cout << "Do you want to add this word to the dictionary?\n";
        if(get_answer())
            dic.add_word(word);


}
int main()
{
    std::string file_name, *words = new std::string[in_capacity];
    //std::cin.sync_with_stdio(false);
    size_t per_word_count = 0;
    std::ifstream fin;
    bool file_n_open = true;
    Dictionary dic;

    std::cout << "Enter the name of the file for which the check will be performed\n";
    do
    {
        //reading the filename and trying to open
        std::cin >> file_name;
        fin.open(file_name);
        if(!fin.is_open())
            // print message if file not open
            std::cout << "Sorry, but file is not open, try again please\n";
        else
            file_n_open = false;
    } while (file_n_open);  // while file not open
    

    while (!fin.eof())
    {
        // reading text into array for validation
        fin >> words[per_word_count++];
        if(per_word_count == 1000)
            in_size_update(per_word_count, &words);
    }
    
    std::cout << "Validation start!\n";

    for(size_t i = 0; i < per_word_count; i++)
    {

       try
       {
           //stoi(words[i]); // check word is not number
       }
       catch(std::exception &ex)
       {
           continue;
       }
        check_word(words[i], dic);

       
    }
    
    
    

}