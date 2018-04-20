#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void show_menu_top();
void show_menu_customer_info();
void show_menu_main_selection();
void show_menu_options();
void show_menu_payment();
void clear_all_options();
void not_valid();
void display_order();
void get_address();
bool order_complete(int pay, int vil, string tel, string name,
                    string add_num, string add_str, string add_abbr, string crd_num);
void get_order_confirmation(int villa, bool food, bool spa, bool mass, bool skin, bool nail);
void get_customer_information(string name, string tel, string add_num, string add_st, string add_abbr, int pay, string card_num);
void show_options(bool food, bool spa, bool mass, bool skin, bool nail);
double get_total(double totale);
string get_name();
string get_number();
string get_card_number();
string get_gifts(int opt_count);



int main()
{
    string name = "", address_number = "", address_street = "", address_st_abbr = "", tel_number = "";
    string card_number = "";
    int payment_method = 0;
    int villa_selection = 0;
    int choice;
    int subchoice;
    double total;
    bool complete = false, food = false, spa = false, mass = false;
    bool skin = false, nail = false;

    cout << "Welcome";

    do
    {
        show_menu_top();
        cin >> choice;
        switch(choice)
        {
            case 1:
                do
                {
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
                } while ( subchoice != 4);
                break;
            case 2:
                do
                {
                    if ( villa_selection != 0 )
                        cout << "\nYou have chosen option " << villa_selection << ".\n";
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
                } while( subchoice != 5 );
                break;
            case 3:
                do
                {
                    show_options(food, spa, mass, skin, nail);
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
                } while( subchoice != 7 );
                break;
            case 4:
                do
                {
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
                } while( subchoice != 4 );
                break;
            case 5:
                if (order_complete(payment_method, villa_selection, tel_number, name, address_number, address_street, address_st_abbr, card_number)) {
                    get_order_confirmation(villa_selection, food, spa, mass, skin, nail);
                    get_customer_information(name, tel_number, address_number, address_street, address_st_abbr, payment_method, card_number);
                    choice = 6;
                }
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
    cout << "\n\nPlease select the number of the option you would like:\n"
         << "1. Input Customer Information\n"
         << "2. Main Selection\n"
         << "3. Options\n"
         << "4. Payment Method\n"
         << "5. Display Order Confirmation\n"
         << "6. Exit\n";
}

void show_menu_customer_info()
{
    cout << "\nPlease input the number of the option you would like:\n"
         << "1. Name\n"
         << "2. Phone Number\n"
         << "3. Address\n"
         << "4. Main Menu\n";
}

void show_menu_main_selection()
{
    cout << "\nPlease select one of our four gorgeous villas:\n"
         << "1. Superior Villa ($9285)\n"
         << "2. Deluxe Villa ($8770)\n"
         << "3. Premium Villa ($8592)\n"
         << "4. Presidential Villa ($7812)\n"
         << "5. Main Menu\n";
}

void show_menu_options()
{
    cout << "\nPlease select as many of our five options as you'd like:\n"
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
    cout << "\nPlease show payment type:\n"
         << "1. Visa\n"
         << "2. MasterCard\n"
         << "3. Cash\n"
         << "4. Main Menu\n";
}

void not_valid()
{
    cout << "\nNot a valid choice...\n";
}

string get_name()
{
    string new_name = "";
    cout << "\nWhat is your name?: ";
    cin.ignore();
    getline(cin, new_name);

    return new_name;
}

string get_number()
{
    string new_num;
    cout << "\nWhat is your phone number (ex: (323)555-5555)?: ";
    cin >> new_num;
    return new_num;
}

string get_card_number()
{
    string card;
    cout << "\nWhat is the card number?: ";
    cin >> card;
    return card;
}

bool order_complete(int pay, int vil, string tel, string name,
                    string add_num, string add_str, string add_abbr, string crd_num)
{
    bool complete = true;
    string error_message = "\n\nThe following information is missing:\n";
    if(!pay)
        error_message += "Payment Method\n";
    if(!vil)
        error_message += "Main selection\n";
    if(tel == "")
        error_message += "Telephone Number\n";
    if(name == "")
        error_message += "Name\n";
    if(add_num == "")
        error_message += "Address Number\n";
    if(add_str == "")
        error_message += "Address Street\n";
    if(add_abbr == "")
        error_message += "Address Street Abbreviation\n";

    if(error_message != "\n\nThe following information is missing:\n")
        complete = false;

    if(complete)
        return true;
    cout << error_message;
    return false;
}

void get_order_confirmation(int villa, bool food, bool spa, bool mass, bool skin, bool nail)
{
    string options_selected = "", main_sel = "", gifts;
    int option_count = 0;
    double totale = 0.00;

    switch(villa)
    {
        case 1:
            totale += 9285;
            main_sel = "Superior Villa ($9285)\n";
            break;
        case 2:
            totale += 8770;
            main_sel = "Deluxe Villa ($8770)\n";
            break;
        case 3:
            totale += 8592;
            main_sel = "Premium Villa ($8592)\n";
            break;
        case 4:
            totale += 7812;
            main_sel = "Presidential Villa ($7812)\n";
    }

    if(food) {
        totale += 479.89;
        options_selected += "Food and Wine ($479.89)\n";
        option_count++;
    }
    if(spa) {
        totale += 291.20;
        options_selected += "Spa ($291.20)\n";
        option_count++;
    }
    if(mass) {
        totale += 262.99;
        options_selected += "Massage ($262.99)\n";
        option_count++;
    }
    if(skin) {
        totale += 188.29;
        options_selected += "Skin Care ($188.29)\n";
        option_count++;
    }
    if(nail) {
        totale += 123.45;
        options_selected += "Nail Care ($123.45)\n";
        option_count++;
    }

    // Apply tax
    totale = get_total(totale);

    gifts = get_gifts(option_count);

    cout << "\n\nYou have placed an order for:\n"
         << main_sel;
    if(option_count)
        cout << "With the following options:\n"
             << options_selected;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << endl << "Total price: $" << totale << endl << endl;

    if (gifts != "") {
        cout << "Congratulations. You will get the following free gift with your order:\n";
        cout << gifts << endl;
    }

}

void get_customer_information(string name, string tel, string add_num, string add_st, string add_abbr, int pay, string card_num)
{
    cout << "Sold to: " << name << endl;
    cout << "Telephone: " << tel << endl;
    cout << "Address: " << add_num << " " << add_st << " " << add_abbr << endl;
    cout << "Paid by: ";

    if (pay == 1)
        cout << "Visa number " << card_num << endl;
    else if (pay == 2)
        cout << "Mastercard number " << card_num << endl;
    else
        cout << "Cash" << endl;

}

string get_gifts(int opt_count)
{
    switch(opt_count)
    {
        case 0:
        case 1:
            return "";
        case 2:
            return "Fruit basket\n";
        case 3:
            return "Flower basket\n";
    }

    return "Wine basket\n";
}

void show_options(bool food, bool spa, bool mass, bool skin, bool nail)
{
    string opt_str = "\nYou have the following options:\n";
    if(food)
        opt_str += "Food and Wine ($479.89)\n";
    if(spa)
        opt_str += "Spa ($291.20)\n";
    if(mass)
        opt_str += "Massage ($262.99)\n";
    if(skin)
        opt_str += "Skin Care ($188.29)\n";
    if(nail)
        opt_str += "Nail Care ($123.45)\n";

    if(opt_str != "\nYou have the following options:\n")
        cout << opt_str;
}

void get_address()
{
    cout << "\nWhat is your address? (ex. 333 Fake St.): ";
}

double get_total(double totale)
{
    totale += (totale *= .1025);
    return totale;
}
