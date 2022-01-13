#include "include.h"

int main()
{
   cout << "Hello World!\n";

   //test of menu_gui usage
   menu_gui::add_top_text("Testowy pokaz dzialania menu_gui");
   menu_gui::add_top_text("wybierz opcje A");
   menu_gui::add_top_text("poruszaj sie po menu strzalkami, zatwierdz enterem");
   menu_gui::add_top_text(""); //taktyczny odstêp
   menu_gui::add_option("Opcja A");
   menu_gui::add_option("Opcja B");
   menu_gui::add_option("Opcja C");
   menu_gui::add_bottom_text(""); //taktyczny odstêp
   menu_gui::add_bottom_text("no dalej ...");

   switch (menu_gui::display())
   {
   case 0:
	   cout << "brawo!\n";
	   break;
   default:
	   cout << "opcja A, pamietasz?\n";
	   break;
   }



   return 0x0;
}
