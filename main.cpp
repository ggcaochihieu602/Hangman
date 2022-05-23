#include <iostream>
#include <string>
#include <cstring>
#include <ctime>


#define MAX_BAD_GUESSES 7
using namespace std;

const string FIGURE[] = {
         "\n"
         "\n"
         "\n"
         "\n"
         "\n"
         "   -------------    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "\n"
         "\n"
         "\n"
         "\n"
         "\n"
         "   -------------    \n"
         "   |           |    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "\n"
         "\n"
         "\n"
         "\n"
         "\n"
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "\n"
         "\n"
         "\n"
         "\n"
         "\n"
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |           |    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "\n"
         "\n"
         "\n"
         "\n"
         "\n"
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "\n"
         "\n"
         "\n"
         "\n"
         "\n"
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
         "\n"
         "\n"
         "\n"
         "\n"
         "\n"
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          /     \n"
         "   |     \n"
         " -----   \n",

         "\n"
         "\n"
         "\n"
         "\n"
         "\n"
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          / \\  \n"
         "   |     \n"
         " -----   \n",
};

struct Game{
    string secretWord;
    string guessWord;
    int badGuessCount;
};

string words[] = {"cat", "dog", "chicken", "hello", "baba", "bedroom"};
//the loai va do kho
void tolower(string &word)
{
    for (int i=0; i< word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
}

void initGame(Game &game){
    game.badGuessCount = 0;
    int index = rand() % (sizeof(words)/sizeof(string)) ;
    // 6 phai dc thay bang sl
    game.secretWord = words[index];
    tolower(game.secretWord);
    game.guessWord = string(game.secretWord.length(), '-');
}

void display(const Game &game){
    cout << FIGURE[game.badGuessCount]<<endl;
    cout << "Number of wrong guesses: " << game.badGuessCount <<endl;
    cout << "Try your best to guess: " << game.guessWord << endl;

}
bool contains(const string &word, char c)
{
    for (int i = 0; i< word.length(); i++){
        if (word[i] == c) return true;
    }
    return false;
}
void updateGame(char input, Game &game)
{
    if (contains(game.secretWord, input))
    {
        for (int i = 0; i < game.guessWord.length(); i++){
            if (game.secretWord[i] == input) game.guessWord[i] = input;
        }
    }
    else game.badGuessCount++;
}

bool gameOver(Game &game)
{
    return (game.secretWord == game.guessWord  || game.badGuessCount >= MAX_BAD_GUESSES);
}

void displayResult(const Game& game)
{
    if (game.badGuessCount >= MAX_BAD_GUESSES)
    {
         cout << FIGURE[MAX_BAD_GUESSES] <<endl;
         cout << "You lost! \n";
    }

    else
        cout << "You won! \n";
    //hien thi gi do vui ve
}

char getInput(){
    string input;
    cin >> input;
    //if same character, bo qua
    return tolower(input[0]);
}


int main()
{
    cout << "Are you ready to play hangman? yes or no:";
    string cf;
    getline(cin, cf);
    while (cf=="yes"){
        srand(time(0));
        Game game;
        initGame(game);

        do {
            display(game);
            char input = getInput();
            updateGame(input, game);
        } while (!gameOver(game));
        displayResult(game);
      cout << endl;
      cout << "Ban co muon tiep tuc choi? yes or no:" << endl;
      cin >> cf;
    }
    return 0;
}
