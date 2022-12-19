#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;

void login();
void registration();
void forgot();


int main()
{
    int choice;
    cout<< endl;
    cout<< "\t\t\t__________________________________________________________\n\n\n";
    cout<< "\t\t\t                Welcome to the Login page                 \n\n\n";
    cout<< "\t\t\t_______________________    MENU    _______________________\n\n";
    cout<< "\t\t\t|       Press 1 to LOGIN                                  |"<<endl;
    cout<< "\t\t\t|       Press 2 to REGISTER                               |"<<endl;
    cout<< "\t\t\t|       Press 3 if you forgot your PASSWORD               |"<<endl;
    cout<< "\t\t\t|       Press 4 to EXIT                                   |"<<endl;
    cout<< "\t\t\t|       Enter your choise  :                              |"<<endl;
    
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
    {
        login();
        break;
    }
    case 2:
    {
        registration();
        break;
    }
    case 3:
    {
        forgot();
        break;
    }
    case 4:
    {
        cout<< "\t\t\t|             Thank you!                                  |"<<endl;
        break;
    }
    
    default:
    {
        cout<< "\t\t\t|   Please select from the options given above            |"<<endl;
        Sleep(1000);
        system("cls");
        main();
        break;
        }
    }


}

void login()
{
    int count;
    string userID, password, ID, pass;
    system("cls");
    cout<< "\t\t\t|   Please enter the username and password                |"<<endl;
    cout<< endl;
    cout<< "\t\t\t| USERNAME :                                              |"<<endl;
    cin>> userID;
    cout<< endl;
    cout<< "\t\t\t| PASSWORD :                                              |"<<endl;
    cin>> password;
    
    ifstream input("records.txt");

    while(input>>ID>>pass)
    {
        if(ID==userID && pass==password);
        system("cls");
    }
    
    input.close();

    if(count = 1)
    {
        cout<<userID<<"\n Your LOGIN is successefull \n Thanks for logging in!"<<endl;
        main();
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check your username";
        main();
    }

}
void registration()
{
    string reg_userID, reg_password, reg_ID, reg_pass;
    system("clr");
    cout<<"\t\t\t|   Enter the username :                                   |"<<endl;
    cin>> reg_userID;
    cout<<"\t\t\t|   Enter the password :                                   |"<<endl;
    cin>> reg_password;

    ofstream f1("records.txt", ios::app);
    f1<<reg_userID<<' '<<reg_password<<endl;
    system("cls");
    cout<< "\t\t\t|   Regestration is successfull                           |"<<endl;
    main();

}
void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t|   You forgot password& No worries                       |"<<endl;
    cout<<"\t\t\t|   Press 1 to search your id by username                 |"<<endl;
    cout<<"\t\t\t|   Press 2 to go to the mein menu                        |"<<endl;
    cout<<"\t\t\t|       Enter your choise  :                              |"<<endl;
    cin>> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string s_userID, s_ID, s_pass;
        cout<<"\t\t\t|       Enter the username which you renenbered            |"<<endl;
        cin>>s_userID;

        ifstream f2("records.txt");
        while(f2>>s_ID>>s_pass)
        {
            if(s_ID==s_userID)
            {
                count = 1;
            }

        }
        f2.close();
        if(count == 1)
        {
            cout<<"\n\n Your accaunt is found! \n";
            cout<<"\n\n Your password is : "<<s_pass;

            main();
        }
        else{
            cout<<"\n\n Sorry! Your accaunt is not found! \n";
        }
        break;
    }
    
    case 2:
        main();
        break;
    
    default:
    {
        cout<< "\t\t\t|   Please select from the options given above            |"<<endl;
        forgot();
        break;
    }
    }

}