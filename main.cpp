#include "dictionary.h"
#ifndef INCLUDE
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#endif

   
char get_answer()
{
    char symbol;
    do
    {
        std::cin >> symbol;
        if(std::cin.fail() || (symbol != 'y' && symbol != 'n' &&  symbol != 'Y' &&  symbol != 'N'))
            std::cout << "Please, enter y(yes) or n(no).\n";
        else
            return symbol;
   }while (true);
}
std::string check_word(std::string &word, Dictionary &dic)
{
    
}
int main()
{
    std::string file_name, words[1000];
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
    }
    std::cout << "Validation start!\n";
    for(int j = 0; j < per_word_count; j++)
    {
       try
       {
           stoi(words[j]); // check word is not number
       }
       catch(std::exception &ex)
       {

       }
       
    }
    
    
    

}