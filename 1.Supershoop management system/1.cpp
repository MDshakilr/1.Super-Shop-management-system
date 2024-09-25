

//Super shop management system


#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;



const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";


class shopping

{

private:

    int pcode;  //product code

    float price;  //product price
    float dis;
    string pname;   //product name

public:

    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();                 //some function
    void rem();
    void list();
    void receipt();
    string inputPassword();
    string inputPasswordWithMasking(bool& showPassword);


};

string shopping::inputPassword()

{
    string password = "";
    char ch;
    bool showPassword = false;

    cout << "Enter password: ";

    while (true)

    {
        ch = getch();
        if (ch == 13)
            break;
        else if (ch == '\b')

        {
            if (!password.empty())

            {
                cout << "\b \b";
                password.pop_back();
            }
        }

        else if (ch == ' ' && password.empty())

        {
            continue;
        }

        else if (ch == 9)
        {
            showPassword = !showPassword;

            cout << "\rEnter password: ";
            if (showPassword)

            {
                cout << password;  // Show actual password
            }

            else
            {
                for (char c : password)

                {
                    cout << '*';  // Show '' for each password character
                }
            }
        }

        else

        {
            password.push_back(ch);
            if (showPassword)

            {
                cout << ch;  // Show actual character
            }

            else

            {
                cout << '*';  // Show ''
            }
        }
    }

    cout << endl;
    return password;
}




void shopping::menu()

{
//system("Color 4b");
n: //label
    int choice;
    string email;
    string password;

    cout <<CYAN<< "\t\t\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\t\t                                              \n";
    cout << "\t\t\t\t\t            Super shop main menu              \n";
    cout << "\t\t\t\t\t                                              \n";
    cout << "\t\t\t\t\t----------------------------------------------\n";

    cout << "\t\t\t\t\t          |                   |\n";
    cout << "\t\t\t\t\t          |  1. Administrator |\n";
    cout << "\t\t\t\t\t          |                   |\n";
    cout << "\t\t\t\t\t          |  2. Buyer         |\n";
    cout << "\t\t\t\t\t          |                   |\n";
    cout << "\t\t\t\t\t          |  3. Exit          |\n";
    cout << "\t\t\t\t\t          |                   |\n";
    cout << RESET;
    cout << "\n";
    cout <<"\t\t\t\t\t\t Please select: ";
    cin >> choice;

    switch (choice)

    {

    case 1:
        cout << GREEN <<  "\t\t\t Please login \n";
        cout << "Enter Email:";
        cin >> email;
        //cout << "Enter password:";
        //cin >> password;
        password = inputPassword();


        if (email == "srshakilrana.sr@gmail.com" && password == "sha1234")

        {
            administrator();
        }

        else

        {
            cout << RED <<  "Invalid email/password" << RESET << endl;
        }

        break;

    case 2:
    {


        buyer();
    }

    case 3:
    {


        exit(0);
    }

    default:
    {

        cout << RED << "Please select from the given options."<< RESET << endl;

    }
    }
    goto n;  //label call
}

void shopping::administrator()

{

n:
    int choice;
    cout << YELLOW <<  "\n\n\n\t\t\t\t\t Administrator menu"<< RESET;
    cout << "\n\t\t\t|  --------------1) Add the product----------   |";
    cout << "\n\t\t\t|                                               |";
    cout << "\n\t\t\t|  --------------2) Modify the product----------|";
    cout << "\n\t\t\t|                                               |";
    cout << "\n\t\t\t|  ------------- 3) Delete the product---------  |";
    cout << "\n\t\t\t|                                               |";
    cout << "\n\t\t\t|  ------------- 4)Back to main menu---------   |";

    cout << "\n\t\t\t Please enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:

        add();
        break;

    case 2:

        edit();
        break;

    case 3:

        rem();
        break;

    case 4:

        menu();
        break;

    default:
        cout <<RED <<  "Invalid choice"<<RESET << endl;
    }

    goto n;
}




void shopping ::buyer()


{

n:
    int choice;
    cout<<BLUE <<"\t\t\t Buyer "<< RESET << endl;
    cout<<"\t\t\t----------         \n";
    cout<<"\t\t\t                    \n";
    cout<<"\t\t\t   1.Buy product        \n";
    cout<<"\t\t\t                     \n";
    cout<<"\t\t\t   2.Go back             \n";

    cout<<"\t\t\t   Enter your choice: ";
    cin>>choice;

    switch(choice)

    {


    case 1 :

        receipt();
        break;

    case 2:

        menu();


    default:

        cout<<RED <<"invailed choice"<< RESET << endl;





    }

    goto n;


}



void shopping::add()

{
n:

    fstream data;
    int c;
    int token = 0;     //check if the file already has a same product code
    float p;
    float d;
    string n;

    cout << GREEN <<  "\n\n\t\t\t Add new product"<< RESET << endl;
    cout << "\n\n\t Product code of the product: ";
    cin >>pcode;
    cout << "\n\n\t Name of the product: ";
    cin >> pname;
    cout << "\n\n\t Price of the product: ";  //user input
    cin >> price;
    cout << "\n\n\t Discount on product: ";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)

    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }

    else
    {



        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();


        if (token == 1)
            goto n;
        else

        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    cout << GREEN << "\n\n\t\t Record inserted!"<< RESET << endl;
}



void shopping ::edit()

{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<< YELLOW << "\n\t\t\t modify the record"<< RESET << endl;
    cout<<"\n\t\t\t Product code:";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)

    {
        cout<< RED << "\n\nFile  doesn't exist!"<< RESET << endl;
    }

    else

    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())

        {
            if(pkey==pcode)

            {
                cout<<"\n\t\t Product new code:";
                cin>>c;
                cout<<"\n\t\tName of the product:";
                cin>>n;
                cout<<"\n\t\t price:";
                cin >>p;
                cout<<"\n\t\t discount:";
                cin>>d;

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<< GREEN <<"Record edited"<< RESET << endl;
                token++;

            }

            else

            {
                data1<<" "<<pcode<<" "<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }

            data>>pcode>>pname>>price>>dis;

        }

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<< RED << "\n\n Record not fount sorry!" << RESET << endl;
        }
    }

}

void shopping :: rem()

{
    fstream data,data1;
    int pkey;
    int token =0;
    cout << YELLOW << "\n\n\t Delete product" << RESET << endl;
    cout<<"\n\n\t Product code: ";


    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)

    {
        cout<< RED <<"File dosent exits"<< RESET << endl;

    }

    else

    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)

            {
                cout<<GREEN << "\n\n\t product delete successfully"<< RESET << endl;
                token++;
            }

            else

            {

                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)

        {
            cout<< RED <<"\n\n Record not fount sorry!"<< RESET << endl;
        }
    }
}


void shopping::list()

{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|------------------------------------------------------\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|------------------------------------------------------\n"<< RESET;

    data>>pcode>>pname>>price>>dis;
    while(!data.eof())

    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }

    data.close();

}

void shopping::receipt()

{

    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis= 0;
    float total = 0;

    cout << GREEN << "\n\n\t\t\t\t Receipt"<< RESET << endl;
    data.open("database.txt", ios::in);

    if (!data)

    {
        cout << RED << "\n\n Empty database"<< RESET << endl;
    }

    else

    {
        data.close();

        list();
        cout << YELLOW <<"\n----------------------------------------- \n";
        cout << "\n                                          \n";
        cout << "\n      Please place the order              \n";
        cout << "\n                                          \n";
        cout << "\n----------------------------------------- \n"<< RESET;

        do

        {

n:
            cout << "\n\n Enter product code:";
            cin >> arrc[c];
            cout << "\n\n Enter the product quantity:";
            cin >> arrq[c];


            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout <<RED <<  "\n\n Duplicate product code. Please try again"<< RESET << endl;
                    goto n;
                }
            }

            c++;
            cout << "\n\n Do you want to buy another product? Press y for yes and n for no: ";
            cin >> choice;

        }

        while (choice == 'y');

        cout << GREEN <<  "\n\n\t\t\t\t-----------Receipt ---------------\n";
        cout << "\nProduct No\t Product name\t Quantity\t Price\t Amount\t Amount with Discount\n"<< RESET;

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;

            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total += dis;  //total =total+dis

                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }

                data >> pcode >> pname >> price >> dis;
            }

            data.close();
        }

        cout << "\n\n-------------------------------------------------------";
        cout << "\n Total Amount: " << total;
        cout << "\n";
        cout << "\n";
    }
}


int main()

{
    shopping s;
    s.menu();

}

