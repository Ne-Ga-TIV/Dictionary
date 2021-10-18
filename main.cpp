#include <iostream>
#include <fstream>
#include <exception>
#include <string>

using namespace std;


   
char get_answer()
{
    char symbol;
    do
    {
        cin >> symbol;
        if(cin.fail() || (symbol != 'y' && symbol != 'n' &&  symbol != 'Y' &&  symbol != 'N'))
            cout << "Please, enter y(yes) or n(no).\n";
        else
            return symbol;
   }while (true);
}
string check_word(string &word, string *dic, int word_c)
{
   
    }
    if(max_eq != 0)
    {
        cout << "An error was found in this word:" << word << ", maybe you meant "<< poss_word
            << " [y/n] ? ";
        char answer = get_answer();
        if(answer == 'Y' || answer == 'y')
            return poss_word;
        else
        {
            cout << "Maeby you want this word in dictionary [y/n] ?";
            answer = get_answer();
            if(answer == 'Y' || answer == 'y')
            {
                add_word(word, wor);
                return word;
            }
            else
                return word;
        }
    }
    else
        return word;  

         
}
int main()
{
    ifstream fin;
    int word_count, i = 0, append = 0;
    string file_name, words[1000], *dictionary;
    dictionary = fill_dictionary(word_count);
    bool file_n_open = true;
    cout << "Enter the name of the file for which the check will be performed\n";
    do
    {
        cin >> file_name;
        fin.open(file_name);
        if(!fin.is_open())
            cout << "Sorry, but file is not open, try again please\n";
        else
            file_n_open = false;
    } while (file_n_open);
    
    cout << "Performed start!\n";

    while (!fin.eof())
    {
        fin >> words[i++];
    }
    for(int j = 0; j < i; j++)
    {
       try
       {
           stoi(words[j]);
       }
       catch(exception &ex)
       {
            words[j] = check_word(words[j], dictionary, word_count);
       }
       
    }
    
    
    

}