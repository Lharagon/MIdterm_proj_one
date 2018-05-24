#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

const int MAX_CAPACITY = 10;
void show_menu();
void do_choice(int choice, int arr[], int& active, int& length);
bool is_emptee(int length);
void read_array(int arr[], ifstream& in_stream, int& length, int& active);
void show_array(const int arr[MAX_CAPACITY], int length, int active);
void select_down(int& active, int length, bool jumping);
void select_up(int& active, int length, bool jumping);
void move_down(int arr[], int& active, int length);
void move_up(int arr[], int& active, int length);
void delete_at(int arr[], int& active, int& length);
void insert_at(int arr[], int& active, int& length);
void sortt(int arr[], int& active, int length);
void jump_from(int arr[], int& active, int old_active, int& length);
void jump_to(int arr[], int& active, int& old_active);
void set_old_active(int& old_active, int active);
void write_array(const int arr[], ofstream& of_stream, int length, int active);


int main()
{
    int length, active, arr[MAX_CAPACITY];
    ifstream in_stream;
    ofstream out_stream;
    int choice;
    bool running = true;

    read_array(arr, in_stream, length, active);

    while(running) {
//        system("CLS");
        show_menu();
        cout << endl << endl;
        show_array(arr, length, active);
        cout << endl << endl;
        cin >> choice;
        if(choice != 55)
        {
            do_choice(choice, arr, active, length);
        }
        else
            running = false;
    }

    write_array(arr, out_stream, length, active);

    return 0;
}

void show_menu()
{
    cout << "Select Down .... \"1\" or \"Down Arrow\" key" << endl;
    cout << "Select Up ...... \"2\" or \"Up Arrow\" key" << endl;
    cout << "Move Down ...... \"3\" or \"Page Down\" key" << endl;
    cout << "Move up ........ \"4\" or \"Page Up\" key" << endl;
    cout << "Insert ......... \"5\" or \"Insert\" key" << endl;
    cout << "Delete ......... \"6\" or \"Delete\" key" << endl;
    cout << "Sort ........... \"7\" or \"F2\" key" << endl;
    cout << "Jump from ...... \"8\" or \"Right Arrow\" key" << endl;
    cout << "Jump to ........ \"9\" or \"Left Arrow\" key" << endl;
    cout << "Cancel Jump .... \"q\" or \"Esc\" key" << endl;
    cout << "Exit ........... \"x\" or \"F1\" key" << endl;
}

void do_choice(int choice, int arr[], int& active, int& length)
{
    bool jumping = false;
    switch(choice)
    {
        case 1:
            select_down(active, length, jumping);
            break;
        case 2:
            select_up(active, length, jumping);
            break;
        case 3:
            move_down(arr, active, length);
            break;
        case 4:
            move_up(arr, active, length);
            break;
        case 5:
            insert_at(arr, active, length);
            break;
        case 6:
            delete_at(arr, active, length);
            break;
        case 7:
            sortt(arr, active, length);
            break;
        case 8:
            jump_from(arr, active, active, length);
            break;
        default:
            break;
    }
}

bool is_emptee(int length)
{
    if(length == 0)
    {
        return true;
    }
    return false;
}

void read_array(int arr[], ifstream& in_stream, int& length, int& active)
{
    in_stream.open("test.txt");
    in_stream >> length;
    in_stream >> active;

    for(int i = 0; i < length; i++)
    {
        in_stream >> arr[i];
    }

    in_stream.close();
}

void show_array(const int arr[MAX_CAPACITY], int length, int active)
{
    for(int i = 0; i < length; i++)
    {
        if(i != active)
        {
            cout << "        " << right << setw(6) << arr[i] << endl;
        }
        else
        {
            cout << "  --->  " << right << setw(6) << arr[i] << endl;
        }
    }
    cout << endl;
}

void select_down(int& active, int length, bool jumping)
{
    if(length >= 1)
    {
        if(active == length - 1)
        {
            active = 0;
        }
        else
        {
            active++;
        }
    }
}

void select_up(int& active, int length, bool jumping)
{
    if(length > 1)
    {
        if(active == 0)
        {
            active = length - 1;
        }
        else
        {
            active--;
        }
    }
}

void move_down(int arr[], int& active, int length)
{
    int temp;
    if(active != length - 1 && length > 1)
    {
        temp = arr[active];
        arr[active] = arr[active + 1];
        arr[++active] = temp;
    }
}

void move_up(int arr[], int& active, int length)
{
    int temp;
    if(active != 0 && length > 1)
    {
        temp = arr[active];
        arr[active] = arr[active - 1];
        arr[--active] = temp;
    }
}

void delete_at(int arr[], int& active, int& length)
{
    if(!is_emptee(length))
    {
        for(int i = active; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[length - 1] = 0;
        length--;
        if(active == length)
        {
            active--;
        }
    }
}

void insert_at(int arr[], int& active, int& length)
{
    if(length != MAX_CAPACITY)
    {
        int value;
        cout << "What value would you like to input: ";
        cin >> value;
        if(is_emptee(length))
        {
            arr[length] = value;
            active++;
        }
        else
        {
            for(int i = length; i > active; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[active] = value;
        }

        length++;
    }
}

void sortt(int arr[], int& active, int length)
{
    int active_value = arr[active];
    int temp;
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++) {
            if(arr[i] > arr[j]) {
                // swapping
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int number = 0;
    while(arr[number] != active_value)
    {
        number++;
    }

    active = number;
}

void jump_from(int arr[], int& active, int old_active, int& length)
{
    bool jumping = true;
    while(jumping)
    {
        show_menu();
        cout << endl << endl << "Jumping :] - current active - " << active << "\n";
        show_array(arr, length, active);
        cout << endl << endl;
        int subchoice;
        cin >> subchoice;
        switch(subchoice)
        {
        case 1:
            select_down(active, length, jumping);
            break;
        case 2:
            select_up(active, length, jumping);
            break;
        case 9:
            jump_to(arr, active, old_active);

            break;
        case 10:
            jumping = false;
            break;
        }
    }
    cout << "Out of the loop\n";
}

void jump_to(int arr[], int& active, int& old_active)
{
    cout << "Came into jump_to: active - " << active << " old-active: " << old_active << endl;
    int temp;
    temp = arr[active];
    arr[active] = arr[old_active];
    arr[old_active] = temp;
    set_old_active(old_active, active);
}

void set_old_active(int& old_active, int active)
{
    old_active = active;
}

void write_array(const int arr[], ofstream& of_stream, int length, int active)
{
    of_stream.open("test.txt");

    of_stream << length << '\n';
    of_stream << active << '\n';
    for(int i = 0; i < length; i++)
    {
        of_stream << arr[i] << ' ';
    }

    of_stream.close();
}
