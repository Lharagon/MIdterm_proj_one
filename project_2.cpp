#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void show_menu();
void do_choice();
void read_array(int arr[], ifstream& in_stream, int& length, int& active);
void show_array(const int arr[10], int length, int active);
void move_arrow_down(int& active, int length);
void move_arrow_up(int& active, int length);

int main()
{
	int length, active, arr[10];
	ifstream in_stream;
	ofstream out_stream;

	show_menu();
	cout << endl << endl;
	read_array(arr, in_stream, length, active);
	cout << endl << endl;
	show_array(arr, length, active);
	move_arrow_down(active, length);
	show_array(arr, length, active);
	move_arrow_up(active, length);
	move_arrow_up(active, length);
	move_arrow_up(active, length);
	move_arrow_up(active, length);
	show_array(arr, length, active);
	move_arrow_down(active, length);
	show_array(arr, length, active);

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

void do_choice()
{
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

void show_array(const int arr[10], int length, int active)
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

void move_arrow_down(int& active, int length) 
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

void move_arrow_up(int& active, int length) 
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