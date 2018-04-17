#include <iostream>
#include <string>
using namespace std;

void show_menu_top();
void show_menu_customer_info();
void show_munu_main_selection();
void show_menu_options();
void show_menu_payment();
void clear_all_options();
void not_valid();
bool order_complete();
string get_name();
string get_address();
int get_number();
int get_card_number();



int main()
{
    string name = "", address_number = "", address_street = "", address_st_abbr = "";
    string missing_info = "";
    int payment_method = 0;
    int card_number = 0;
    int tel_number = 0;
    int villa_selection = 0;
    int choice;
    int subchoice;
    double total = 0;
    bool complete = false, food = false, spa = false, mass = false;
    bool skin = false, nail = false;


    do
    {
        show_menu_top();
        cin >> choice;
        switch(choice)
        {
            case 1:
                show_menu_customer_info();
                cin >> subchoice;
                switch(subchoice)
                {
                    case 1:
                        name = get_name();
                        break;
                    case 2:
                        tel_number = get_number();
                        break;
                    case 3:
                        get_address();
                        cin >> address_number;
                        cin >> address_street;
                        cin >> address_st_abbr;
                        break;
                    case 4:
                        break;
                    default:
                        not_valid();

                }
                break;
            case 2:
                show_menu_main_selection();
                cin >> subchoice;
                switch(subchoice)
                {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        villa_selection = subchoice;
                        break;
                    case 5:
                        break;
                    default:
                        not_valid();
                }
                break;
            case 3:
                show_menu_options();
                cin >> subchoice;
                switch(subchoice)
                {
                    case 1:
                        food = true;
                        break;
                    case 2:
                        spa = true;
                        break;
                    case 3:
                        mass = true;
                        break;
                    case 4:
                        skin = true;
                        break;
                    case 5:
                        nail = true;
                        break;
                    case 6:
                        food = false;
                        spa = false;
                        mass = false;
                        skin = false;
                        nail = false;
                        break;
                    case 7:
                        break;
                    default:
                        not_valid();
                }
                break;
            case 4:
                show_menu_payment();
                cin >> subchoice;
                switch(subchoice)
                {
                    case 1:
                    case 2:
                        card_number = get_card_number();
                    case 3:
                        payment_method = subchoice;
                        break;
                    case 4:
                        break;
                    default:
                        not_valid();
                }
                break;
            case 5:
                if order_complete(payment_method, villa_selection, tel_number)

            case 6:
                break;
            default:
                not_valid();


        }

    } while(choice != 6);

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
         << "6. Clear all options\n"
         << "7. Main Menu\n";
}

void show_menu_payment()
{
    cout << "Please show payment type:\n"
         << "1. Visa\n"
         << "2. MasterCard\n"
         << "3. Cash\n"
         << "4. Main Menu\n";
}

void not_valid()
{
    cout << "Not a valid choice...\n";
}

string get_name()
{
    string new_name = "";
    cout << "What is your name?: \n";
    cin >> new_name;

    return new_name;
}

int get_number()
{
    int new_num;
    cout << "What is your phone number (ex: 3235555555)?";
    cin >> new_num;
}

int get_card_number()
{
    int card;
    cout << "What is the card number?: ";
    cin >> card;
    return card;
}

// string get_address()
// {

// }

// double process_main_selection(double villa)
// {
//     const double TAX = .1025
// }

