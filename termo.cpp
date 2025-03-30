#include<iostream>
#include<string>
#include<fstream>

int main(){
    using namespace std;

    ifstream arquivo("palavras.txt");
    if (!arquivo) 
    {
        cerr << "ERRO" << endl;
    }
    int nummax;
    arquivo >> nummax;  // nummax gets from the first line the number of words in the file
    int n;
    cin >> n; // n gets the line of the word that the user will try to guess

    string chave;
    for (int i = 0; i < n; i++)
    {
        arquivo >> chave;  // chave gets the word the user will try to guess
    }

    int i = 0;
    string tentativa;
    string letras;

    while (i < 5)
    {
        cin >> tentativa; // user guess a word
        string exibicao = ""; // string to show the results
        for (int j = 0; j < 5; j++)
        {
            if (chave[j] == tentativa[j]) // if the letter is in the right position, it will add the letter at the result string without changes
            {
                exibicao += tentativa[j];
            }
            else
            {
                bool existe = false; // bool variable to set the if condition for when the letter is not in the word
                for (int m = 0; m < 5; m++) // for to see if the letter appears elsewhere in the word
                {
                    if (tentativa[j] == chave[m]) // if the letter appears it will show up on exibicao, but in lower case
                    {
                        exibicao += tolower(tentativa[j]);
                        existe = true; // sets the bool variable to true
                        break;
                    }   
                }
            
                if (!existe)  // if the letter does not appear, it will add a "*" in the display string and add the letter to a string that contains all the letters that do not appear in the word and you tried to guess
                {
                    exibicao += "*";
                    if (letras.find(tentativa[j]) == string::npos) // if to see if the letter has already been added to the string
                    {
                        letras += tentativa[j];
                    }
                }
            }
        }
        cout << exibicao << " (" << letras << ")" << endl; // show the string on display

        if (exibicao == chave) // if you get all the letters right, a text will appear saying you won
        {
            cout << "GANHOU!" << endl;
            return 0;
        }
        i++;
    }
    
    cout << "PERDEU! ZEBRA" << endl; // if you dont get the word right in five attempts, a text will appear saying you lose
    return 0;

}

