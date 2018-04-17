#include <iostream>
#include <string>
using namespace std;

void show_menu_top();
void show_menu_customer_info();
void show_munu_main_selection();
void show_menu_options();
void show_menu_payment();
bool order_complete();
string get_name();


int main()
{
    string name = "", address_number = "", address_street = "", address_st_abbr = "";
    string missing_info = "";
    string payment_method = "";
    int card_number;
    int tel_number;
    int choice;
    int subchoice;

    do
    {
        show_menu_top();
        cin >> choice;
        switch(choice)
        {
            case 1:
                name = get_name();
                break;
            case 2:


        }

    }

    return 0;
}

void show_menu_top()
{
    cout << "Welcome\n\n"
         << "Please select the number of the option you would like:\n"
         << "1. Input Customer Information\n"
         << "2. Main Selection\n"
         << "3. Options\n"
         << "4. Payment Method\n"
         << "5. Display Order Confirmation\n"
         << "6. Exit\n";
}

void show_menu_customer_info()
{
    cout << "Please input the number of the option you would like:\n"
         << "1. Name\n"
         << "2. Phone Number\n"
         << "3. Address\n"
         << "4. Main Menu";
}

void show_menu_main_selection()
{
    cout << "Please select one of our four gorgeous villas:\n"
         << "1. Superior Villa ($9285)\n"
         << "2. Deluxe Villa ($8770)\n"
         << "3. Premium Villa ($8592)\n"
         << "4. Presidential Villa ($7812)\n"
         << "5. Main Menu\n";
}

void show_menu_options()
{
      cout << "Please select as many of our five options as you'd like:\n"
         << "1. Food and Wine ($479.89)\n"
         << "2. Spa ($291.20)\n"
         << "3. Massage ($262.99)\n"
         << "4. Skin Care ($188.29)\n"
         << "5. Nail Care ($123.45)\n"
         << "6. Main Menu\n";
}

void show_menu_payment()
{
    cout << "Please show payment type:\n"
         << "1. Visa\n"
         << "2. MasterCard\n"
         << "3. Cash\n"
         << "4. Main Menu\n";
}

string get_name()
{
    string new_name = "";
    cout << "What is your name?: \n";
    cin >> new_name;

    return new_name;
}
