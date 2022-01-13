#include <string>
#include <iostream>
#include <conio.h>
using namespace std;
/*
INFO:

usage:
    top_text    -> text above options selection     to add use 'add_top_text(string)'
    bottom_text -> text below options selection     to add use 'add_bottom_text(string)'

    options     -> user's options to choose from    to add use 'add_option(string)'
    reset       -> reseting top_text, bottom_text and all options   'reset()'

    display     -> show menu_gui, RETURNs index of choosen option (0,1,2..)

    to navigate thru menu use arrows (up, down -> choose option) (right, enter -> accept)
*/
namespace menu_gui {
    string version = "0.9.0";
    string top_text[100];
    int top_text_counter = 0;
    string options[100];
    int options_counter = 0;
    string bottom_text[100];
    int bottom_text_counter = 0;
    int position = 0;

    void add_top_text(string input)
    {
        top_text[top_text_counter] = input;
        top_text_counter++;
    }

    void add_option(string input)
    {
        options[options_counter] = input;
        options_counter++;
    }

    void add_bottom_text(string input)
    {
        bottom_text[bottom_text_counter] = input;
        bottom_text_counter++;
    }

    void reset()
    {
        for (size_t i = 0; i < top_text_counter; i++)
            top_text[i] = "";
        top_text_counter = 0;
        for (size_t i = 0; i < options_counter; i++)
            options[i] = "";
        options_counter = 0;
        for (size_t i = 0; i < bottom_text_counter; i++)
            bottom_text[i] = "";
        bottom_text_counter = 0;
    }

    int display(int position_in)
    {
        position = position_in;
        int temp;
        for (;;)
        {
            system("cls");
            for (size_t i = 0; i < top_text_counter; i++)
                cout << top_text[i] << endl;
            for (size_t i = 0; i < options_counter; i++)
            {
                if (i == position)
                    cout << "==";
                cout << "> " << options[i] << endl;
            }
            for (size_t i = 0; i < bottom_text_counter; i++)
                cout << bottom_text[i] << endl;

            temp = _getch();
            if (temp == 224)
            {
                switch (_getch())
                {
                case 72:
                    if (position > 0)
                        position--;
                    else
                        position = options_counter - 1;
                    break;
                case 75:
                    //left
                    break;
                case 77:
                    return position;
                    break;
                case 80:
                    if (position < options_counter - 1)
                        position++;
                    else
                        position = 0;
                    break;
                default:
                    break;
                }
            }
            else if (temp == 13)
                return position;
            else if (temp == 113)
                return -1;
        }
    }
}