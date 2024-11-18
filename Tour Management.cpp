#include<bits/stdc++.h>
#include <string>
#include <fstream>


using namespace std;
class User
{
protected:
    char username[20];
    char password[20];
    int budget;
public:
    User() {}                             //No argument constructor
    User(char* username, char* password)    //constructor
    {
         strcpy( username,username);
         strcpy(password,password);
    }
    ~ User() {}                       //destructor

    void setUsername(const char* u)
    {
        strcpy(username, u);
    }
    void setPassword(const char* p)
    {
        strcpy(password, p);
    }
    void setBudget(const int b)
    {
        budget=b;
    }
    const char* getUsername() const
    {
        return username;
    }
    const char* getPassword() const
    {
        return password;
    }
   const int getBudget() const
    {
        return budget;
    }
    bool login(char * username_,char * password_)
    {
        if(strcmp(username_,username)==0 && strcmp(password_,password)==0)
        {
            return 1;
        }
        return 0;
    }
    friend void createUser();
};

void createUser()
{
    User user;
    char username[20];
    char password[20];
    int budget;
    ofstream outFile("users.dat",ios::binary | ios::app ); //input password
    cout << "Enter username: ";
    cin >> username;
    user.setUsername(username);
    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);
    /*cout << "Enter Budget: ";
    cin >> budget;
    user.setBudget(budget);*/

    outFile.write(reinterpret_cast<char*>(&user), sizeof(User));

    outFile.close();
}

bool login()
{
    User user;
    char username[20];
    char password[20];
    ifstream inFile("users.dat", ios::out | ios::binary); //checking password

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    while (inFile.read(reinterpret_cast<char*>(&user), sizeof(User)))
    {
        if (user.login(username,password))
        {
            return true;
        }
    }
    inFile.close();
    return false;
}
class TouristPackage:public User
{
private:
    char packageCode[20];
    char packageName[100];
    int duration;
    double price;
public:
    TouristPackage() {}
    TouristPackage(User *username, User *password,char *packageCode,char *packageName,int duration,double price) : duration(duration),price(price)
    {
        //strcpy( username,username);
        //strcpy(password,password);
        strcpy(packageCode,packageCode);
        strcpy(packageName,packageName);
    }
   virtual ~TouristPackage() {}
    void setPackageCode(char code[])
    {
        strcpy(packageCode, code);
    }
    void setPackageName(char name[])
    {
        strcpy(packageName, name);
    }
    void setDuration(int days)
    {
        duration = days;
    }
    void setPrice(double cost)
    {
        price = cost;
    }
    char* getPackageCode()
    {
        return packageCode;
    }
    char* getPackageName()
    {
        return packageName;
    }
    int getDuration()
    {
        return duration;
    }
    double getPrice()
    {
        return price;
    }
    int comp(int budget)
    {
        if(price<=budget)
            return 1;
    }
};

void addPackage(TouristPackage package)
{

    ofstream outFile("packages.dat", ios::binary|ios::app);
    outFile.write(reinterpret_cast<char *>(&package), sizeof(TouristPackage)); //input
    outFile.close();
}

void displayAllPackages()
{
    TouristPackage package;
    ifstream inFile("packages.dat", ios::binary);
    if(!inFile)
    {
        cout << "Error opening file. Please try again later." << endl; //checking
        return;
    }
    cout << "===============================" << endl;
    cout << "Tour Packages" << endl;
    cout << "===============================" << endl;
    while(inFile.read(reinterpret_cast<char *>(&package), sizeof(TouristPackage)))
    {
        cout << "Package no: " << package.getPackageCode() << endl;
        cout << "Package Name: " << package.getPackageName() << endl;
        cout << "Duration (in days): " << package.getDuration() << endl;
        cout << "Price: $" << package.getPrice() << endl;
        cout << "------------------------------" << endl;
    }
    cout<<"\n\nWant to Buy a Package(y/n): ";
    char ch;
    cin>>ch;
    if(ch=='n')
    {
        return;
    }
    cout<<"Which Package :";
    int n;
    cin>>n;
    cout<<"~~Package Purchase Successfull~~\n";
    cout<<"~Thanks for Being With us~~\n";
    inFile.close();
}
class Hotel
{
    int bookingmoney;
    int meal;
public:
    void fivestar_hotel()
    {
        srand(time(0));
        int lb=100;
        int ub=1000;
        bookingmoney=((rand() % (ub - lb + 1)) + lb);
        srand(time(0));
        lb=10;
        ub=25;
        meal=((rand() % (ub - lb + 1)) + lb);
        cout<<"1. Hotel Paradise"<<endl;
        cout<<"2. Hotel Pan-Pacific"<<endl;
        cout<<"3. Hotel Arkine"<<endl;
        cout<<"4. Hotel Blue Gate Gardening"<<endl;
        cout<<"5. Hotel Cambria"<<endl;
    }
    void threestar_hotel()
    {
        srand(time(0));
        int lb=50;
        int ub=80;
        bookingmoney=((rand() % (ub - lb + 1)) + lb);
        srand(time(0));
        lb=5;
        ub=15;
        meal=((rand() % (ub - lb + 1)) + lb);
        cout<<"1. Hotel Sea shore"<<endl;
        cout<<"2. Hotel Marketine"<<endl;
        cout<<"3. Hotel Lindner Strand"<<endl;
        cout<<"4. Hotel Montukmanor"<<endl;
        cout<<"5. Hotel Strand Sylt"<<endl;
    }
    void lowbudget_hotel()
    {
        srand(time(0));
        int lb=30;
        int ub=45;
        bookingmoney=((rand() % (ub - lb + 1)) + lb);
        srand(time(0));
        lb=1;
        ub=4;
        meal=((rand() % (ub - lb + 1)) + lb);
        cout<<"1. Hotel Prantor"<<endl;
        cout<<"2. Hotel Tripura"<<endl;
        cout<<"3. Hotel Meghaloy"<<endl;
        cout<<"4. Hotel Naga_dine"<<endl;
        cout<<"5. Hotel Severines"<<endl;
    }
    void operator ++ () //operator overloading
    {
        int y=bookingmoney+meal;
        cout<<"Your Total Cost: $"<<y<<endl;
        return ;
    }
    int n;
    void hotel_list()
    {
        cout<<"1. Five Star Hotel"<<endl;
        cout<<"2. Three Star Hotel"<<endl;
        cout<<"3. Low Budget Hotel"<<endl;
        cin>>n;
        while(n)
        {
            if(n==1)
            {
                fivestar_hotel();
                break;
            }
            else if(n==2)
            {
                threestar_hotel();
                break;
            }
            else if(n==3)
            {
                lowbudget_hotel();
                break;
            }
            else
            {
                cout<<"Invalid Choice...."<<endl;
                //getch();
                //return 0;
            }
        }

    }
    void choice_list()
    {
        system("cls");
        int p;
        cout<<"Desire Hotel : ";
        cin>>p;
        while(p!=5)
        {
            if(n==1 && p<=5)
            {

                if(n==1&&p==1)
                {
                    cout<<"Hotel Paradise"<<endl;
                    break;
                }
                else if(n==1&&p==2)
                {
                    cout<<"Hotel Pan-Pacific"<<endl;
                    break;
                }
                else if (n==1&&p==3)

                {
                    cout<<"Hotel Arkine"<<endl;
                    break;
                }
                else if(n==1&&p==4)

                {
                    cout<<"Hotel Blue Gate Gardening"<<endl;
                    break;
                }
                else if(n==1&&p==5)

                {
                    cout<<"Hotel Cambria"<<endl;

                    break;
                }
                else
                {
                    cout<<"Invalid Choice...."<<endl;
                    // getch();
                    choice_list();
                }

            }
            else if(n==2 && p<=5)
            {

                if(n==2&&p==1)
                {

                    cout<<"Hotel Sea shore"<<endl;
                    break;
                }
                else if(n==2&&p==2)
                {
                    cout<<"Hotel Marketine"<<endl;
                    break;
                }
                else if (n==2&&p==3)

                {
                    cout<<"Hotel Lindner Strand"<<endl;
                    break;
                }
                else if(n==2&&p==4)

                {
                    cout<<"Hotel Montukmanor"<<endl;
                    break;
                }
                else if(n==2&&p==5)

                {
                    cout<<"Hotel Strand Sylt"<<endl;

                    break;
                }
                else
                {
                    cout<<"Invalid Choice...."<<endl;
                    //getch();
                    choice_list();
                }
            }
            else if(n==3 && p<=5)
            {
                if(n==3&&p==1)

                {

                    cout<<"Hotel Prantor"<<endl;
                    break;
                }
                else if(n==3&&p==2)
                {
                    cout<<"Hotel Tripura"<<endl;
                    break;
                }
                else if (n==3&&p==3)

                {
                    cout<<"Hotel Meghaloy"<<endl;
                    break;
                }
                else if(n==3&&p==4)

                {
                    cout<<"Hotel Naga_dine"<<endl;
                    break;
                }
                else if(n==3&&p==5)

                {
                    cout<<"Hotel Severines"<<endl;

                    break;
                }
                else
                {
                    cout<<"Invalid Choice...."<<endl;
                    //getch();
                    choice_list();
                }

            }
            else
            {
                cout<<"Invalid Choice...."<<endl;
                //getch();
                choice_list();
            }
            cout<<"~~HOTEL BOOKING Successfull~~\n";
            cout<<"~Thanks for Being With us~~\n";


        }
    }

};
int main()
{

    TouristPackage package;
    int choice;
    char code[20], name[100];
    int duration;
    double price;
AB:
    while(true)
    {
        system("cls");
        cout << "Welcome to the Tourist Package Management System" << endl;
        cout << "===============================================" << endl;
        cout << "1. Admin Login for Adding Package" << endl;
        //cout << "2. Display All Packages" << endl;
        cout << "2. User(Create account or login)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        cin.ignore();

        if(choice==1)
        {
            //system("cls");
            char arr[]="Opi&&Rownak";
            cout<<"Verify if you are admin!!\nEnter Admin code: ";
            char j[80];
            cin>>j;
            getchar();
            if(strcmp(j,arr)==0)
            {
                cout << "Enter package code: ";
                cin.getline(code, 20);
                package.setPackageCode(code);
                cout << "Enter package name: ";
                cin.getline(name, 100);
                package.setPackageName(name);
                cout << "Enter duration (in days): ";
                cin >> duration;
                package.setDuration(duration);
                cout << "Enter price: $";
                cin >> price;
                package.setPrice(price);
                addPackage(package);
            }
            else
            {
                cout<<"Sorry!Admin Code invalid!You Can Not Add Package!"<<endl;
                system("pause");
                goto AB;
            }

        }
        else if(choice==2)
        {

            //system("cls");
            int choic;
            bool loggedIn = false;
BA:
            do
            {
                system("cls");
                cout << "1. Create account" << endl;
                cout << "2. Login" << endl;
                cout << "3. GO Back" << endl;
                cout << "Enter your choice: ";
                cin >> choic;

                switch (choic)
                {
                case 1:
                    createUser();
                    break;
                case 2:
                    loggedIn = login();
                    if (loggedIn)
                    {

                        cout << "\n\tLogin successful" << endl;
                        system("pause");
                        int ch=1;
                        while(ch)
                        {

                            system("cls");
                            cout << "1. Select Package" << endl;
                            cout << "2. Select Hotel" <<endl;
                            cout << "3. Go Back" << endl;
                            cout << "4. Logout" << endl;
                            cin>>ch;
                            if(ch==1)
                            {
                                displayAllPackages();
                                system("pause");
                            }
                            /*else if(ch==3)
                            {
                                goto BA;
                            }*/
                            else if(ch==2)
                            {
                                Hotel h;
                                h.hotel_list();
                                // ++h;
                                cout<<"\n\n Do you want to Buy a Package(1/0): ";
                                int cha;
                                cin>>cha;
                                if(cha)
                                {
                                    h.choice_list();
                                    ++h;
                                    system("pause");
                                }


                            }
                            else if(ch==3)
                            {
                                goto BA;
                            }
                            else if(ch==4)
                            {
                                cout<<"~Good bye~"<<endl;
                                exit(0);
                            }
                            else
                            {
                                cout << "Invalid Index" << endl;
                                //system("pause");
                            }
                        }
                    }

                    else
                    {
                        cout << "Invalid username or password" << endl;
                        system("pause");
                    }

                    break;
                case 3:
                    goto AB;
                    break;
                case 4:
                    cout<<"~Good bye~"<<endl;
                    exit(0);
                default:
                    cout << "Invalid choice" << endl;
                }
            }
            while(1);
        }
        else if(choice==3)
        {
            cout<<"~Good bye~"<<endl;
            exit(0);
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

    }
    return 0;
}
