#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <exception>

using namespace std;
namespace menu_gui
{
    //text above options selection     to add use 'add_top_text(string)'
    void add_top_text(string input);
    //text below options selection     to add use 'add_bottom_text(string)'
    void add_option(string input);
    //user's options to choose from    to add use 'add_option(string)'
    void add_bottom_text(string input);
    //reseting top_text, bottom_textand all options   'reset()'
    void reset();
    //show menu_gui, RETURNs index of choosen option(0, 1, 2..)
    //to navigate thru menu use arrows(up, down->choose option) (right, enter->accept)
    int display(int position_in = 0);
}