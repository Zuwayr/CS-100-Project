#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <limits>

using namespace std;


struct item

{
    string name;
    double price;
    int quantity;
    int serial;
};



vector<item> vec;

item add_item()
{
    item temp;

    vector<item> vec;

    cout << "--------Add item menu--------" << endl;
    cout << endl;

    for (;;)
    {
        cout << "Enter name of item: "<< endl;
        if (cin >> temp.name)
        {
            break;
        }
        else
        {
        cout << "Please enter a valid name, illegal input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (;;)
    {
        cout << "Enter item price: "<< endl;
        if (cin >> temp.price)
        {
            break;
        }
        else
        {
        cout << "Please enter a valid number, illegal input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (;;)
    {
        cout << "Enter item quantity: "<< endl;
        if (cin >> temp.quantity)
        {
            break;
        }
        else
        {
        cout << "Please enter a valid number, illegal input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (;;)
    {
        cout << "Enter item serial: "<< endl;
        if (cin >> temp.serial)
        {
            break;
        }
        else
        {
        cout << "Please enter a valid number, illegal input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << endl;
    cout << "Item Added" << endl;
    cout << endl;
    cout << "Returning to Main menu"<< endl;
    cout << endl;
    cout << "--------XXXXXXXXXX--------" << endl;
    cout << endl;
    return temp;
}

void write_tf(vector <item> vec)
{
    ofstream myfile ("inventory.txt");

    if (!myfile.is_open())
    {
        cerr << "Unable to open file" << endl;
    }

    else
    {
        unsigned int i = 0;
        for (i = 0; i < vec.size()-1; i++)
        {
            myfile << vec[i].name << " ";
            myfile << vec[i].price << " ";
            myfile << vec[i].quantity << " ";
            myfile << vec[i].serial <<endl;
        }
            myfile << vec[i].name << " ";
            myfile << vec[i].price << " ";
            myfile << vec[i].quantity << " ";
            myfile << vec[i].serial ;

    myfile.close();
    }
}

void get_inv()
{
            string name;
            double price;
            int quantity;
            int serial;
            item temp;

            ifstream readfile("inventory.txt");
            while(!readfile.eof())
            {
                readfile >> name;
                //cout << "Name: " << name <<endl;
                temp.name = name;
                readfile >> price;
                //cout << "Price: " << price <<endl;
                temp.price = price;
                readfile >> quantity;
                //cout << "Quantity: " << quantity <<endl;
                temp.quantity = quantity;
                readfile >> serial;
                //cout << "Serial: " << serial <<endl;
                temp.serial = serial;
                //cout << endl;
                vec.push_back(temp);
            }
    readfile.close();
    }


void view_inv()
{
        cout << "--------Current inventory--------" << endl;
        cout << endl;

        for(unsigned int i =0; i < vec.size(); i++)
        {
            cout << "Item Number: " << i + 1 << endl;
            cout << "Name: " << vec[i].name <<endl;
            cout << "Price: " << vec[i].price <<endl;
            cout << "Quantity: " << vec[i].quantity <<endl;
            cout << "Serial: " << vec[i].serial <<endl;
            cout << endl;
        }
        cout << "--------XXXXXXXXXX--------" << endl;
        cout << endl;
}

void del_menu()
{
    cout << "--------Delete Menu--------" << endl;
    cout << endl;
    unsigned int del = 0;

    view_inv();
    for (;;)
    {
        cout << "Enter item number to delete: ";
        if (cin >> del)
        {
            if (del <= vec.size())
            {
                break;
            }
            else
            {
                cout << "Please enter a valid choice, input value out of range" << endl;
            }
        }
        else
        {
        cout << "Please enter a valid choice, illegal input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    del--;
    vec.erase(vec.begin() + del);

    cout << "Item number " << del++ << " deleted" << endl;
    cout << endl;

    int re = -1;
    for (;;)
    {
        cout << "Enter 1 to delete again or 0 to return to Main menu: ";
        if (cin >> re)
        {
            break;
            }
        else
        {
            cout << "Please enter a valid number, illegal input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

        if (re == 0)
        {
            cout << "Returning to Main menu"<< endl;
            cout << endl;
            cout << "--------XXXXXXXXXX--------" << endl;
            cout << endl;
        }
        else if (re == 1)
        {
            cout << endl;
            del_menu();
        }
}


int search_m()
{
    cout << "--------Search Menu--------" << endl;
    cout << endl;

    cout << "Enter choice to search by" << endl;
    cout << "1. Name" << endl;
    cout << "2. Price" << endl;
    cout << "3. Quantity" << endl;
    cout << "4. Serial" << endl;
    cout << endl;


    int s_c = 0;
    int loc = -1;
    for (;;)
        {
            cout << "Choice: ";
            if (cin >> s_c)
            {
                if (s_c <= 4 && s_c >= 1)
                {
                    break;
                }
                else
                {
                    cout << "Please enter a valid choice, input value out of range" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid choice, illegal input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    cout << endl;

    if (s_c == 1)
    {
        string user_n = "";
        for (;;)
        {
            cout << "Enter name of item (case sensitive): ";
            if (cin >> user_n)
            {
                break;
            }
            else
            {
                cout << "Please enter a valid name, illegal input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }


        for (unsigned int i = 0; i < vec.size(); i++)
        {
            if (vec[i].name == user_n)
            {
                loc = i;
            }
        }
    }

    if (s_c == 2)
    {
        double user_p = 0;
        for (;;)
        {
            cout << "Enter price of item: ";
            if (cin >> user_p)
            {
                break;
            }
            else
            {
                cout << "Please enter a valid price, illegal input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        for (unsigned int i = 0; i < vec.size(); i++)
        {
            if (vec[i].price == user_p)
            {
                loc = i;
            }
        }
    }

    if (s_c == 3)
    {
        int user_q = 0;
        for (;;)
        {
            cout << "Enter quantity of item: ";
            if (cin >> user_q)
            {
                break;
            }
            else
            {
                cout << "Please enter a valid quantity, illegal input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        for (unsigned int i = 0; i < vec.size(); i++)
        {
            if (vec[i].quantity == user_q)
            {
                loc = i;
            }
        }
    }

    if (s_c == 4)
    {
        int user_s = 0;
        for (;;)
        {
            cout << "Enter serial of item: ";
            if (cin >> user_s)
            {
                break;
            }
            else
            {
                cout << "Please enter a valid serial, illegal input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        for (unsigned int i = 0; i < vec.size(); i++)
        {
            if (vec[i].serial == user_s)
            {
                loc = i;
            }
        }


    }

    cout << endl;

    if (loc == -1)
    {
        cout << "Item not found" << endl;
        cout << endl;

        int re = -1;
        for (;;)
        {
            cout << "Enter 1 to search again or 0 to return to Main menu: ";
            if (cin >> re)
            {
                break;
            }
            else
            {
                cout << "Please enter a valid number, illegal input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (re == 0)
        {
            return loc;
        }
        else if (re == 1)
        {
            cout << endl;
            search_m();
        }
    }

    else
    {
        cout << "--------Search result-------" << endl;
        cout << endl;
        cout << "Item Number " << loc + 1 << endl;
        cout << "Name: " << vec[loc].name <<endl;
        cout << "Price: " << vec[loc].price <<endl;
        cout << "Quantity: " << vec[loc].quantity <<endl;
        cout << "Serial: " << vec[loc].serial <<endl;
        cout << endl;
    }
    return loc;
    loc = -1;
    cout << "Returning to Main menu" << endl;
    cout << endl;
    cout << "--------XXXXXXXXXX--------" << endl;
    cout << endl;
}

void update()
{
    cout << "--------Modification menu--------" << endl;
    cout << endl;

    view_inv();

    unsigned int Ri_in = 0;
    for (;;)
        {
            cout << "Enter item number to modify: ";
            if (cin >> Ri_in)
            {
                if (Ri_in <= vec.size())
                {
                    break;
                }
                else
                {
                    cout << "Please enter a number from the list" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid number, illegal input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

    int i_in = Ri_in - 1;
    cout << endl;

    cout << "Enter attribute to modify " << endl;
    cout << "1. Name" << endl;
    cout << "2. Price" << endl;
    cout << "3. Quantity" << endl;
    cout << "4. Serial" << endl;
    cout << endl;

    int u_in = 0;

    for (;;)
        {
            cout << "Choice: ";
            if (cin >> u_in)
            {
                if (u_in <= 4 && u_in >= 1)
                {
                    break;
                }
                else
                {
                    cout << "Please enter a valid choice, input value out of range" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid choice, illegal input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

    cout << endl;

    if (u_in == 1)
    {
        string user_n = "";
        for (;;)
        {
            cout << "Enter new name for "<< vec[i_in].name << ": ";
            if (cin >> user_n)
            {
                break;
            }
            else
            {
                cout << "Please enter a valid name, illegal input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        vec[i_in].name = user_n;
    }

    if (u_in == 2)
    {

        double user_p = 0;
        for (;;)
        {
            cout << "Enter new price for " << vec[i_in].name << ": ";
            if (cin >> user_p)
            {
                break;
            }
            else
            {
            cout << "Please enter a valid number, illegal input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        vec[i_in].price = user_p;
    }


    if (u_in == 3)
    {
        int user_q = 0;
        for (;;)
        {
            cout << "Enter new quantity for " << vec[i_in].name << ": ";
            if (cin >> user_q)
            {
                break;
            }
            else
            {
                cout << "Please enter a valid quantity, illegal input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        vec[i_in].quantity = user_q;

    }


    if (u_in == 4)
    {
        int user_s = 0;
        for (;;)
        {
            cout << "Enter new serial for " << vec[i_in].name << ": ";
            if (cin >> user_s)
            {
                break;
            }
            else
            {
                cout << "Please enter a valid serial, illegal input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        vec[i_in].serial = user_s;
    }

    cout << "Item updated, returning to Main menu" << endl;
    cout << endl;
    cout << "--------XXXXXXXXXX--------" << endl;
    cout << endl;


}


int menu()
{
    while (1)
    {

    int choice = 0;

    cout << "--------Main Menu--------" << endl;
    cout << endl;
    cout << "1. View inventory" << endl;
    cout << "2. Add an item" << endl;
    cout << "3. Delete an item " << endl;
    cout << "4. Search" << endl;
    cout << "5. Modify item" << endl;
    cout << "6. Exit" << endl;
    cout << endl;


    for (;;)
        {
            cout << "Please Enter your choice: ";
            if (cin >> choice)
            {
                if (choice <= 6 && choice >= 1)
                {
                    break;
                }
                else
                {
                   cout << "Please enter a valid choice, input value out of range" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid choice, illegal input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    cout << endl;

    if (choice == 1)
    {
        view_inv();
    }

    if (choice == 2)
    {
        vec.push_back(add_item());
    }

    if (choice == 3)
    {
        del_menu();
    }


    if (choice == 4)
    {
        search_m();
    }

    if (choice == 5)
    {
        update();
    }

    if (choice == 6)
    {
        write_tf(vec);
        cout << "Exiting Program" << endl;
        cout << "--------XXXXXXXXXX--------" << endl;
        cout << endl;
        return 0;
    }
    }

}

void login()
{
    string pass = "letmein";
    string user = "";

    cout << "-------LOGIN-------" << endl;
    cout << endl;

    for(;;)
    {
        cout << "Enter Password: " << endl;
        cin >> user;
        if (pass == user)
        {
            cout << "Welcome user" << endl;
            cout << endl;
            cout << endl;
            menu();
            break;
        }
        else
        {
            cout << "Password incorrect" << endl;
            cout << endl;
        }


    }
}


int main()
{
    vector<item> vec;
    get_inv();
    cout << "--------Inventory Management System--------" << endl;
    cout << endl;
    login();


}



