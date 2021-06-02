#include <iostream>
#include <string.h>
using namespace std;
static int n=2;
static int fn=6;
struct name_pass
{
    char names[20];
    char pass[20];
}name_pass[1000];
struct order
{
    char foods[20];
    float price;
}order[50];


void signup();
void login();
void list();
void mainmenu();
void editmenu();
void newlist();
void editfood();
void addfood();
void removefood();


int main()
{
    cout << "------------------------ << Welcome to the Restaurant Managemant System >> ------------------------"<< endl;
    cout << "Menu:"<< "\n" << "<1> Signup" <<"\n" << "<2> Login"<< endl;
    cout << endl;
    cout << "Please Enter a Number: ";
    int a;
    cin >> a;
    if(a==1)
        signup();
    else if(a==2)
        login();
    return 0;
}
void signup()
{
    cout << "Signup as a User or Admin? Enter 'u' or 'a': ";
    char b;
    cin >> b;
    cout << endl;

    if(b == 'a')
    {
        if(name_pass[0].pass[0]=='\0')
        {
            strcpy(name_pass[0].names,"admin");
            cout << "Your username is \"admin\". Please select a password for your account: ";
            cin >> name_pass[0].pass;
            cout << "You are successfully signed up." << endl;
        }
        else if(name_pass[0].pass!= '\0')
        {
            cout << "Admin already exists!" << endl;
            main();
        }
    }
    else if( b == 'u')
    {
        bool repeated = false;
        char user[20];
        while(repeated == false)
        {
            cout << "Enter your username: ";
            cin >> user;

            for( int i=1 ; i<n ; i++)
            {
                if(!strcmp(name_pass[i].names,user))
                {
                    cout << "The username is repeatitive." << endl;
                    repeated = false;
                    break;
                }
                repeated = true;
            }
        }
        strcpy(name_pass[n-1].names, user);
        cout << "Enter your password: ";
        cin >> name_pass[n-1].pass;
        n++;
        cout << "You are successfully signed up." << endl;
    }
    main();
}
void login()
{
    cout << "Enter your username: ";
    char user[20],pass[20];
    cin >> user;
    bool success=false;
    if(!strcmp(name_pass[0].names,user))
    {
        bool exist = false;
        while(true)
        {
            if(exist == true)
                break;
            cout << "Enter your password: ";
            cin >> pass;
            if(!strcmp(name_pass[0].pass,pass))
            {
                exist = true;
                success=true;
                editmenu();
            }

        }
    }
    for(int i=1 ; i<n ; i++)
    {
        if(!strcmp(name_pass[i].names,user))
        {
            bool exist = false;
            while(true)
            {
                if(exist == true)
                    break;
                cout << "Enter your password: ";
                cin >> pass;
                if(!strcmp(name_pass[i].pass,pass))
                {
                    exist = true;
                    success=true;
                    mainmenu();
                }
            }
        }
    }
    if(success==false)
    {
        cout << "Envalid username. First you need to sign up. Choose sign up in menu." << endl;
        main();
    }
}
void list()
{
    if(order[0].foods[0]=='\0')
    {
        strcpy(order[0].foods, "Chicken Biryani");
        order[0].price = 2;
        strcpy(order[1].foods, "Chicken Palao");
        order[1].price = 1.5;
        strcpy(order[2].foods, "Chinese Rice ");
        order[2].price = 2.5;
        strcpy(order[3].foods, "Chicken Burgar");
        order[3].price = 1;
        strcpy(order[4].foods, "Nawabi Pizza  ");
        order[4].price = 4.5;
        strcpy(order[5].foods, "2.5 Litre Coke");
        order[5].price = 1.75;
    }

    for(int i=0 ; i<fn ;i++)
        cout << i+1 << "  " << order[i].foods << "\t\t\t\t" << "$" << order[i].price << " only." << endl;
}
void mainmenu()
{
    cout << "------------------------------ << MAIN MENU >> ------------------------------ "<< endl;
    cout << "<1> See Menu\n<2> Log out" << endl;
    cout << "Enter a number:";
    int a;
    cin >> a;
    if(a==1)
    {
order1:        cout << "------------------------------ << MENU >> ------------------------------ "<< endl;
        cout << endl << endl;
        list();
        cout << endl;
        cout << "Please select the order number: ";
        int food,foodnum;
        cin >> food;
        cout << "Please select the number of deals: ";
        cin >> foodnum;
        food--;
        cout << endl;
        cout << "Order: " << order[food].foods << endl;
        cout << "Number of deals: " << foodnum << endl;
        cout << "Price of each deal: $" << order[food].price << " only." << endl;
        cout << "Total price: $" << foodnum*order[food].price << " only." << endl;
        cout << "-------------------- << THANK YOU FOR COMING >> --------------------" << endl;
        cout << endl;
        cout << "Do you want to <1> order something else or <2> back to main menu?" << endl;
        int b;
        cin >> b;
        if(b==1)
            goto order1;
        else if(b==2)
            mainmenu();
    }
    else if(a==2)
      main();
}
void removefood()
{
    char food[20];
    cout << endl;
    list();
    cout << endl;
    cout << "Enter the name of food you want to remove: ";
    cin.ignore();
    cin.getline(food,20);
    for( int i=0 ; i<fn ; i++)
    {
        if(!strcmp(order[i].foods,food))
        {
            for( int j=i ; j<fn-1 ; j++)
            {
                strcpy(order[j].foods,order[j+1].foods);
                order[j].price = order[j].price;
            }
            cout << "Food is removed." << endl;
            fn--;
            break;
        }
    }
    cout << endl;
    cout << "Do you want to <1> remove another food or <2> go back to edit menu?" << endl;
    int a;
    cin >> a;
    if(a==1)
        removefood();
    else if(a==2)
        editmenu();
}
void editfood()
{
    cout << endl;
    list();
    cout << endl;
    char food[20];
    cout << "Enter the name of food which you want to edit: ";
    cin.ignore();
    cin.getline(food,20);

    for( int i=0 ; i<fn ; i++)
    {
        if(!strcmp(order[i].foods,food))
        {
            cout << "Enter the new name: ";
            cin.getline(order[i].foods,20);
            cout << "Enter the new price: ";
            cin >> order[i].price;
            break;
        }
    }
    cout << "Save Changes..." << endl;
    cout << "Do you want to <1> edit another food or <2> go back to edit menu?" << endl;
    int a;
    cin >> a;
    cout << endl;
    if(a==1)
        editfood();
    else if(a==2)
        editmenu();
}
void addfood()
{
    cout << endl;
    cout << "Enter the food name you want to add: ";
    cin.ignore();
    cin.getline(order[fn].foods,20);
    cout << "Enter the price of food: ";
    cin >> order[fn].price;
    fn++;
    cout <<"Food added. Do you want to <1> add another food or <2> go back to edit menu?" << endl;
    int a;
    cin >> a;
    cout << endl;
    if(a==1)
        addfood();
    else if(a==2)
        editmenu();
}
void newlist()
{
    cout << endl;
    if(order[0].foods[0]=='\0')
    {
        strcpy(order[0].foods, "Chicken Biryani");
        order[0].price = 2;
        strcpy(order[1].foods, "Chicken Palao");
        order[1].price = 1.5;
        strcpy(order[2].foods, "Chinese Rice ");
        order[2].price = 2.5;
        strcpy(order[3].foods, "Chicken Burgar");
        order[3].price = 1;
        strcpy(order[4].foods, "Nawabi Pizza  ");
        order[4].price = 4.5;
        strcpy(order[5].foods, "2.5 Litre Coke");
        order[5].price = 1.75;
    }
    for(int i=0 ; i<fn ;i++)
        cout << i+1 << "  " << order[i].foods << "\t\t\t\t" << "$" << order[i].price << " only." << endl;
    cout << endl;
    editmenu();
}
void editmenu()
{
    cout << "------------------------------ << EDIT MENU >> ------------------------------ "<< endl;
    cout << "Menu:\n<1> Edit Food\n<2> Add Food\n<3> Remove Food\n<4> Print The New List\n<5> Log Out" << endl;
    cout << "Please enter a number: ";
    int a;
    cin >> a;
    if(a==1)
        editfood();
    else if(a==2)
        addfood();
    else if(a==3)
        removefood();
    else if(a==4)
        newlist();
    else if(a==5)
        main();

}









