#include <stdio.h>
#include <string.h>
#include <math.h>

// Create users variable
struct userInfo
{
    int account_number;
    int phone_number;
    int account_balance;
    char full_name[50];
    char user_name[50];
    char user_password[50];
};
struct userInfo userAccounts[100];
int user_count = 0;
int creat_account_count = 0;


//Transaction history variable
struct transaction
{
    int deposit;
    int withdrawal;
};
struct transaction tr_hestory[100];


int userList()
{
    int i,go_back;
    printf("\n\n\t\t\t\tBank user list : \n\n");
    for(i=0; i<user_count; i++)
    {
        printf("\n\t\t\t\t%d. %s",i+1,userAccounts[i].full_name);
    }
    printf("\n\n\t\t\t\tPress 0 to back :");
    scanf("%d",&go_back);
    if(go_back == 0)
    {
        system("cls");
        admin_menu();
    }
}

// Select edit user account information function
int edit_user_information(int user_account)
{
    int i;
    for(i=0; i<user_count; i++)
    {
        if(userAccounts[i].account_number == user_account)
        {
            printf("\n\n\t\t\t\t%s's information : ",userAccounts[i].full_name);
            printf("\n\n\t\t\t\t1. Name : %s",userAccounts[i].full_name);
            printf("\n\n\t\t\t\t2. Phone : %d",userAccounts[i].phone_number);
            printf("\n\n\t\t\t\t3. Account Number : %d",userAccounts[i].account_number);
            printf("\n\n\t\t\t\t4. User name : %s",userAccounts[i].user_name);
            printf("\n\n\t\t\t\t5. Password  : %s",userAccounts[i].user_password);
            int choice;
            printf("\n\n\t\t\t\tWhich information you want to edit (Press 0 to back) : ");
            scanf("%d",&choice);
            if(choice == 1)
            {
                system("cls");
                printf("\n\n\t\t\t\tEnter %s's new full name : ",userAccounts[i].full_name);
                scanf("%s",&userAccounts[i].full_name);
                system("cls");
                edit_user_information(userAccounts[i].account_number);
            }
            else if(choice == 2)
            {
                system("cls");
                printf("\n\n\t\t\t\tEnter %s's new Phone number : ",userAccounts[i].full_name);
                scanf("%d",&userAccounts[i].phone_number);
                system("cls");
                edit_user_information(userAccounts[i].account_number);
            }
            else if(choice == 3)
            {
                system("cls");
                printf("\n\n\t\t\t\tEnter %s's new Account number : ",userAccounts[i].full_name);
                scanf("%d",&userAccounts[i].account_number);
                system("cls");
                edit_user_information(userAccounts[i].account_number);
            }
            else if(choice == 4)
            {
                system("cls");
                printf("\n\n\t\t\t\tEnter %s's new user name : ",userAccounts[i].full_name);
                scanf("%s",&userAccounts[i].user_name);
                system("cls");
                edit_user_information(userAccounts[i].account_number);
            }
            else if(choice == 5)
            {
                system("cls");
                printf("\n\n\t\t\t\tEnter %s's new Password : ",userAccounts[i].full_name);
                scanf("%s",&userAccounts[i].user_password);
                system("cls");
                edit_user_information(userAccounts[i].account_number);
            }
            else if(choice == 0)
            {
                system("cls");
                edit_user_list();
            }
        }
    }
}
// Edit user account list function
int edit_user_list()
{
    int i,choice;
    printf("\n\n\t\t\t\tBank user list : \n\n");
    for(i=0; i<user_count; i++)
    {
        printf("\n\t\t\t\t%d. %s",i+1,userAccounts[i].full_name);
    }
    printf("\n\n\t\t\t\tSelect a user from the list (Press 0 to back) : ");
    scanf("%d",&choice);
    if(choice == 0)
    {
        system("cls");
        admin_menu();
    }
    else
    {
        system("cls");
        int user_account = userAccounts[choice-1].account_number;
        edit_user_information(user_account);
    }
}

int delete_user_information(user_account)
{
    int i;
    for(i=0; i<user_count; i++)
    {
        if(userAccounts[i].account_number == user_account)
        {
            //userAccounts[i]
        }
    }
}
// Delete user account list
int delete_user_list()
{
    int i,choice;
    printf("\n\n\t\t\t\tBank user list : \n\n");
    for(i=0; i<user_count; i++)
    {
        printf("\n\t\t\t\t%d. %s",i+1,userAccounts[i].full_name);
    }
    printf("\n\n\t\t\t\tSelect a user from the list (Press 0 to back) : ");
    scanf("%d",&choice);
    if(choice == 0)
    {
        system("cls");
        admin_menu();
    }
    else
    {
        system("cls");
        int user_account = userAccounts[choice-1].account_number;
        delete_user_information(user_account);
    }
}

// Admin menu function
int admin_menu()
{
    system("cls");
    int choice_admin_menu;
    printf("\n\t\t\t\tThe admin menu : ");
    printf("\n\t\t\t\t1. List of customer");
    printf("\n\t\t\t\t2. Edit user information");
    printf("\n\t\t\t\t3. Delete user");
    printf("\n\t\t\t\t4. Log out");

    printf("\n\n\t\t\t\tEnter your choice : ");
    scanf("%d",&choice_admin_menu);
    if(choice_admin_menu == 1)
    {
        system("cls");
        userList();
    }
    else if(choice_admin_menu == 2)
    {
        system("cls");
        edit_user_list();
    }
    else if(choice_admin_menu == 3)
    {
        system("cls");
        delete_user_list();
    }
    else if(choice_admin_menu == 4)
    {
        system("cls");
        main();
    }
}
// Admin wrong information function
int admin_wrong_info()
{
    int try_again;
    system("color 4");
    printf("\n\n\t\t\t\tWrong information! Press 1 to try again :");
    scanf("%d",&try_again);
    if(try_again == 1)
    {
        system("cls");
        admin_login();
    }
    else
    {
        return 0;
    }

}
// Admin login function
int admin_login()
{
    system("color 7");
    char admin_username[100],admin_password[100],theAdmin[100] = "team8",adminPass[100] = "team8";
    printf("\n\n\t\t\t\tWelcome to the admin panel.\n");
    printf("\n\t\t\t\tPlease enter your user name : ");
    scanf("%s",&admin_username);
    printf("\n\t\t\t\tPlease enter your password : ");
    scanf("%s",&admin_password);
    if(strcmp(admin_username,theAdmin) == 0 && strcmp(admin_password,adminPass) == 0)
    {
        admin_menu();
    }
    else
    {
        system("cls");
        admin_wrong_info();
    }

}
// User menu function
int user_menu(int user_account_number)
{
    system("cls");
    int choice_user_menu,account_number = user_account_number;
    printf("\n\t\t\t\tThe user menu : ");
    printf("\n\n\t\t\t\t1. Make deposit");
    printf("\n\t\t\t\t2. Make withdrawal");
    printf("\n\t\t\t\t3. View account balance");
    printf("\n\t\t\t\t4. Edit profile");
    printf("\n\t\t\t\t5. Delete profile");
    printf("\n\t\t\t\t6. Log out");

    printf("\n\n\t\t\t\tEnter your choice : ");
    scanf("%d",&choice_user_menu);
    if(choice_user_menu == 6)
    {
        system("cls");
        main();
    }
}
// User wrong information function
int user_wrong_information()
{
    int try_again;
    system("color 4");
    printf("\n\n\t\t\t\tWrong information! Press 1 to try again :");
    scanf("%d",&try_again);
    if(try_again == 1)
    {
        system("cls");
        user_login();
    }
    else
    {
        return 0;
    }
}

// check user name and password
int check_user_info(int user_account_number,char pass[50]){
    int i;
    for(i=0;i<user_count;i++){
        if(userAccounts[i].account_number == user_account_number && strcmp(userAccounts[i].user_password, pass) == 0){
            user_menu(userAccounts[i].account_number);
        }else{
            continue;
        }
    }

    system("cls");
    user_wrong_information();

}

// User login function
int user_login()
{
    system("color 7");
    int user_account_number;
    char user_password[100];
    printf("\n\n\t\t\t\tWelcome to the user panel.\n");
    printf("\n\t\t\t\tPlease enter your account number : ");
    scanf("%d",&user_account_number);
    printf("\n\t\t\t\tPlease enter your password : ");
    scanf("%s",&user_password);
    check_user_info(user_account_number,user_password);
}

// Create user account function

int create_account()
{

    printf("\n\t\t\t\tPlease enter all the information : ");
    printf("\n\n\t\t\t\tEnter a account number : ");
    scanf("%d",&userAccounts[creat_account_count].account_number);
    printf("\n\t\t\t\tEnter a phone number : ");
    scanf("%d",&userAccounts[creat_account_count].phone_number);
    printf("\n\t\t\t\tEnter your full name : ");
    scanf("%s",&userAccounts[creat_account_count].full_name);
    printf("\n\t\t\t\tEnter a username : ");
    scanf("%s",&userAccounts[creat_account_count].user_name);
    printf("\n\t\t\t\tEnter a password : ");
    scanf("%s",&userAccounts[creat_account_count].user_password);

    if(userAccounts[creat_account_count].account_number != 0 && userAccounts[creat_account_count].phone_number != 0 && userAccounts[creat_account_count].full_name != 0 && userAccounts[creat_account_count].user_name != 0 && userAccounts[creat_account_count].user_password != 0)
    {
        creat_account_count ++;
        user_count++;
        int action;
        printf("\n\n\t\t\t\tAccount create successful. Press 1 to create new account (Press 0 to go back) : ");
        scanf("%d",&action);
        if(action == 0)
        {
            system("cls");
            main();
        }
        else if(action == 1)
        {
            system("cls");
            create_account();
        }

    }
}

// Make deposit function
int user_deposit(){
    system("cls");
    int amount;
    printf("\n\t\t\t\tPlease enter a amount : ");
    scanf("%d",&amount);

}
// Initialize user account
int initializer_account()
{
    // Ashik
    userAccounts[0].account_number = 12345;
    userAccounts[0].phone_number = 12345678910;
    userAccounts[0].account_balance = 0;
    strcpy(userAccounts[0].full_name,"Ashik");
    strcpy(userAccounts[0].user_name,"user1");
    strcpy(userAccounts[0].user_password,"12345");

    // Rahul
    userAccounts[1].account_number = 12346;
    userAccounts[1].phone_number = 12345678911;
    userAccounts[1].account_balance = 0;
    strcpy(userAccounts[1].full_name,"Rahul");
    strcpy(userAccounts[1].user_name,"user2");
    strcpy(userAccounts[1].user_password,"12345");

    user_count = 2;
    creat_account_count = 2;
}
// Main function
int main()
{
    printf("\n\t\t\t\tWelcome to Bank Management System.");
    printf("\n\n\t\t\t\t1. Create bank account");
    printf("\n\t\t\t\t2. User login");
    printf("\n\t\t\t\t3. Admin login");
    printf("\n\t\t\t\t4. Exit");
    initializer_account();
    int login_select;
    printf("\n\n\t\t\t\tEnter your choice : ");
    scanf("%d",&login_select);
    // Check user choice
    if(login_select == 1)
    {
        system("cls");
        // Redirect to the create new account option
        create_account();
    }
    else if(login_select == 2)
    {
        system("cls");
        // Redirect to the user login view
        user_login();
    }
    else if(login_select == 3)
    {
        system("cls");
        // Redirect to the admin login view
        admin_menu();
    }
    else if(login_select == 4)
    {
        return 0;
    }
    else
    {
        system("cls");
        // Choice again
        printf("\n\n\t\t\t\tWrong input! Please try again\n\n");
        main();

    }
}
