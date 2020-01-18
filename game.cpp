#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
using namespace std;

void on_start();
void open_menu();
void render_menu(vector<string>, int line);


int main() 
{
    on_start();
    open_menu();



    return 0;
}




void on_start()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string TEXT = "Нажмите, чтобы продолжить..";

    
    cout << TEXT << "\n";
}

void open_menu()

{
    vector<string> menu_options = {"Загрузить уровень", "Настройки", "Выйти"};


    char input = ' ';
    int line = 0;
    while (input = getch())
    {
        switch (input) //changes line at which the cursor points
        {
            case 'W': case 'w': case 'ц': case 'Ц': if (line > 0) --line; break;
            case 'S': case 's': case 'Ы': case 'ы': if (line < menu_options.size()-1) ++line; break;
            case 13: return;   //CR символ
            default: break;
        }
        system("cls");
        render_menu(menu_options, line);



    }
    

}

void render_menu(vector<string> menu_options, int line)
{
    for (int i = 0; i < menu_options.size(); ++i) 
    {
        if (line == i) cout << "> ";    
        cout << menu_options[i] << "\n";
    }

}