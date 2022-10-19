//---------------------------Rail way reservation project by using c programming language--------------------------
//---------------------------------------header file start-----------------------------------------
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
//---------------------------------------header file close-------------------------------------------
//---------------------------------------user define function start----------------------------------
void viewinfo();
void bookticket();
void cancelticket();
void admin();
void password();
void viewpassenger();
void addtrain();
void dlttrain();
void awrite();
void aread();
void bookticket_write();
void viewpassengers_read();
void checkavailability();
//-----------------------------------------user define function close-----------------------------------
//-----------------------------------------structure start----------------------------------------------
struct adddata
{
    char si[10];
    char train_number[10];
    char train_name[35];
    char start[35];
    char destination[35];
    char price[10];
    int seat;
    char time[10];
} add[1000];

struct bookticket
{
    char train_number[20];
    char name[35];
    char phone[20];
    char date[20];
    int seat;
} book[1000];
//---------------------------------------structure close----------------------------------------------
//---------------------------------------global variable----------------------------------------------
int k=0,u=0;
char trn_nmbr[100],name[100],phn[100];
//---------------------------------------main function start------------------------------------------
int main()
{
    aread();
    viewpassengers_read();
    system("COLOR 0f");
    int ch;
    time_t currentTime;
    time(&currentTime);
    printf("\n\t\t\t     %s\n",ctime(&currentTime));

    printf("\n\t\t\t************************************\n");
    printf("\t\t\t**** RAILWAY RESERVATION SYSTEM ****\n");
    printf("\t\t\t************************************\n");
    printf("\n\t\t\t<<<<<<<<<< WELCOME USERS >>>>>>>>>>\n");
    printf("\n\n\t\t\t\t      MENU\n");
    printf("\t\t\t             ******");
    printf("\n\t\t\t[1] VIEW INFORMATION\n");
    printf("\n\t\t\t[2] BOOK TICKET\n");
    printf("\n\t\t\t[3] CANCEL TICKET\n");
    printf("\n\t\t\t[4] ADMIN");
    printf("\n\n\t\t\t[5] SEARCH FOR PARTICULAR TICKET");
    printf("\n\n\t\t\t[6] EXIT\n");
    printf("\n\t\t\t**********************************");
    printf("\n\t\t\t**********************************");
    printf("\n\t\t\tENTER YOUR CHOICE: ");

    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        viewinfo();
        break;
    case 2:
        bookticket();
        break;
    case 3:
        cancelticket();
        break;
    case 4:
        password();
        break;
    case 6:
        system("cls");
        printf("\n\t\t\t ===========================================\n");
        printf("\t\t\t ******* RAILWAY RESERVATION SYSTEM *******\n");
        printf("\t\t\t =================================================\n");
        printf("\n\n\t\t\tBROUGHT TO YOU BY\n\n");
        printf("\t\t\t\t***SYEDA NOWSHIN IBNAT SOHA***\n");
        printf("\t\t\t\t***FATEMA-TUZ ZOHRA***\n");
        printf("\t\t\t\t***MAHMUDA BEGUM***\n");
        getch();
        exit(0);
        break;
    case 5:
        checkavailability();
        break;
    default:
        system("cls");
        printf("\n\t\t\t================================================\n");
        printf("\t\t\t   ******* RAILWAY RESERVATION SYSTEM *******\n");
        printf("\t\t\t   ================================================\n");
        printf("\n\n\t\t\t<<<<<<<<    WRONG CHOICE    >>>>>>>>\n");
        printf("\t\t\t<<<<<<<< PLEASE ENTER RIGHT THING >>>>>>>>\n");
        getch();
        system("cls");
        main();
    }
    return 0;
}
//---------------------------------------main function close--------------------------------------------------
//---------------------------------------book ticket function-----------------------------------------------



///*********************************************************************************
void bookticket()
{
    int c,j,n,i,found=-1;
    char v,train_number[10];
    system ("cls");
    aread();
    printf("\n\n\t\t\t==============================================");
    printf("\n\t\t\t********* RAILWAY RESERVATION SYSTEM *********\n");
    printf("\t\t\t==============================================");
    printf("\n\n\t\t\tHow many ticket do you want to buy: ");
    scanf("%d",&n);
    for(j=u; j<u+n; j++)
    {
        printf("\n\n\t\t\tEnter train number: ");
        scanf("%s", book[j].train_number);
        for(i=0; i<k; i++)
        {
            if(strcmp(book[j].train_number,add[i].train_number)==0)
            {
                if(add[i].seat==0)
                {
                    printf("\n\n\t\t\tSorry! The train is full.");

                    getch();
                    system("cls");
                    main();
                }
                else
                {
                    found=1;
                    printf("\n\t\t\tBooking %d number ticket ",j+1);
                    printf("\n\t\t\tEnter date: ");
                    scanf("%s",book[j].date);
                    printf("\n\t\t\tEnter your name: ");
                    scanf("%s",book[j].name);
                    printf("\n\t\t\tEnter your phone number: ");
                    scanf("%s",book[j].phone);
                    printf("\n\t\t\tYour Seat number is: %d",add[i].seat );
                    book[j].seat=add[i].seat;
                    bookticket_write();
                    add[i].seat--;
                    awrite();
                }
            }
        }
        if(found==-1)
        {
            printf("\n\n\t\t\ttrain not found!!");
            getch();
            system("cls");
            main();
        }

    }
    u=j;
    bookticket_write();
    printf("\n\n\t\t\tEnter '1' for main menu & press any key to exit: ");
    scanf("%d",&c);
    if(c==1)
    {
        system("cls");
        main();
    }
    if(c!=1)
    {
        exit;
    }
}
//---------------------------------------cancel ticket function---------------------------------------------
void cancelticket()
{
    viewpassengers_read();
    char pnnmbr[100];
    int location = -1,e;
    printf ("\n\n\t\t\tEnter phone number: ");
    scanf ("%s",pnnmbr);
    for (e=0; e<u; e++)
    {
        if (strcmp(pnnmbr,book[e].phone)==0)
        {
            location=e;
            break;
        }
    }
    if (location==-1)
    {
        printf ("\n\n\t\t\t<<<<<<<<<<<<<< Data Not Found >>>>>>>>>>>>>>>>> \n");
        getch();
        system("cls");
        main();
    }
    else
    {
        for (e=location; e<u; e++)
        {
            strcpy(book[e].date,book[e+1].date);
            strcpy(book[e].train_number,book[e+1].train_number);
            strcpy(book[e].name,book[e+1].name);
            strcpy(book[e].phone,book[e+1].phone);
            bookticket_write();
        }
        u--;
        bookticket_write();
        printf("\n\n\t\t\t<<<<<<<<<<<<<<< Ticket canceled successfully. >>>>>>>>>>>>");
        getch();
        system("cls");
        main();
    }
}
//-------------------------------------admin portal function----------------------------------------
void admin()
{
    int chhh;
    system("cls");
    printf("\n     ====================================================================");
    printf("\n     ******************** RAILWAY RESERVATION SYSTEM *******************");
    printf("\n     ====================================================================");
    printf("\n\n");
    printf("           <<<<<<<<<<<<<<< WELCOME TO ADMIN PANEL >>>>>>>>>>>>>>>\n");
    printf("\n\n");
    printf("              ************************************\n");
    printf("              ||      CHOOSE YOUR OPERATION     ||\n");
    printf("              ||--------------------------------||\n");
    printf("              ||      [1] VIEW PASSENGERS       ||\n");
    printf("              ||      [2] ADD TRAIN             ||\n");
    printf("              ||      [3] DELETE TRAIN          ||\n");
    printf("              ||      [4] BACK                  ||\n");
    printf("              ||                                ||\n");
    printf("              ************************************\n\n");
    printf("     *********************************************************************\n");
    printf("\n\t\tENTER YOUR CHOICE: ");
    scanf("%d",&chhh);

    switch(chhh)
    {
    case 1:
        viewpassenger();
        break;
    case 2:
        addtrain();
        break;
    case 3:
        dlttrain();
        break;
    case 4:
        system("cls");
        getch();
        main();
        break;
    default:
        getch();
        printf("\n\t\t\tYou entered wrong KEY!!!!");
        getch();
        system("cls");
        main();
    }
    getch();
}
//-----------------------------password function----------------------------------
void password()
{
    int number=12345;
    int pass;
    printf("\n\t\t\tEnter password: ");
    scanf("%d",&pass);
    if(pass==number)
    {
        printf("\n\n\t\t\t<<<<< Logged in successfully >>>>>");
        getch();
        system("cls");
        admin();
    }
    else
    {
        printf("\n\n\t\t\t\t   ERROR!!!!!");
        printf("\n\n\t\t\t<<<<<<<< Wrong password >>>>>>>>");
        getch();
        system("cls");
        main();
    }
}
//------------------------------------delete train function----------------------------------------------
void dlttrain()
{
    aread();
    char train[100];
    int location = -1,f;
    printf ("\n\n\tEnter train number: ");
    scanf ("%s",train);
    for (f=0; f<k; f++)
    {
        if (strcmp(train,add[f].train_number)==0)
        {
            location=f;
            break;
        }
    }
    if (location==-1)
    {
        printf ("\n\n\t<<<<<<<<<<<<<< Data Not Found. >>>>>>>>>>>>>>>>> \n");
        getch();
        system("cls");
        admin();
    }
    else
    {
        for (f=location; f<k; f++)
        {
            strcpy(add[f].si,add[f+1].si);
            strcpy(add[f].train_number,add[f+1].train_number);
            strcpy(add[f].train_name,add[f+1].train_name);
            strcpy(add[f].start,add[f+1].start);
            strcpy(add[f].destination,add[f+1].destination);
            strcpy(add[f].price,add[f+1].price);

            strcpy(add[f].time,add[f+1].time);
            awrite();
        }
        k--;
        awrite();
        printf("\n\n\t<<<<<<<<<<<<< Train deleted successfully...>>>>>>>>>>>>>");
        getch();
        system("cls");
        admin();
    }
}
//--------------------------------------view passengers function----------------------------------------
void viewpassenger()
{
    int a,j;
    system("cls");
    viewpassengers_read();
    printf("\n\t\t\t       ************************************************************");
    printf("\n\t\t\t       ******************** RAILWAY RESERVATION SYSTEM ********************");
    printf("\n\t\t\t       ************************************************************");
    printf("\n\n\t\t\ttrain number\tname\t\tphone number\t\tdate\t\tseat\n");
    printf("\n\t\t\t**********************************************************************************\n");
    for(j=0; j<u; j++)
    {
        printf("\n\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d",book[j].train_number,book[j].name,book[j].phone,book[j].date,book[j].seat);
        book[j].seat++;
    }
    printf("\n\t\t\t**********************************************************************************\n");
    printf("\n\n\t\t\tEnter '1' for main menu & enter '0' for back: ");
    scanf("%d",&a);
    if(a==1)
    {
        system("cls");
        main();
    }
    if(a==0)
    {
        system("cls");
        admin();
    }
}
//--------------------------------------add train function--------------------------------------------
void addtrain()
{
    system("cls");
    int ch;
    aread();
    int i,a;
    printf("\n\t\t     **********************************************************");
    printf("\n\t\t     ******************** RAILWAY RESERVATION SYSTEM ********************");
    printf("\n\t\t     **********************************************************");
    printf("\n\n\t\t\tHow many trains do you want to add: ");
    scanf("%d",&a);
    for(i=k; i<k+a; i++)
    {
        printf("\n\t\t\tCAUTION: Serial number's length should be within (2-3)digit");
        printf("\n\t\t\t         Train number's length should be within (4-6)digit");
        printf("\n\t\t\t         Train name's length should be within (10-11)latter");
        printf("\n\t\t\t         Destination name's length should be within (10-11)latter");
        printf("\n\t\t\t         Price length should be within (3-4)digit");
        printf("\n\t\t\t         Seat length should be within (3-4)digit\n\n");


        printf("\n\t\t\tEnter %d number train details ",i+1);
        printf("\n\t\t\t\tEnter serial number: ");
        scanf("%s",add[i].si);
        printf("\n\t\t\t\tEnter train number: ");
        scanf("%s",add[i].train_number);
        printf("\n\t\t\t\tEnter train name: ");
        scanf("%s",add[i].train_name);
        printf("\n\t\t\t\tEnter start place: ");
        scanf("%s",add[i].start);
        printf("\n\t\t\t\tEnter destination place: ");
        scanf("%s",add[i].destination);
        printf("\n\t\t\t\tEnter price: ");
        scanf("%s",add[i].price);
        printf("\n\t\t\t\tEnter seat: ");
        scanf("%d",&add[i].seat);
        printf("\n\t\t\t\tEnter time: ");
        scanf("%s",add[i].time);
    }

    printf("\n\n\t\t\tConfirm train: (y=1/n=0):- ");
    scanf("%d",&ch);
    if(ch==1)
    {
        awrite();
        k=i;
        awrite();
        system("cls");
        printf("\n\n\t\t\t********************************************************************");
        printf("\n\t\t\t******************** RAILWAY RESERVATION SYSTEM ********************");
        printf("\n\t\t\t********************************************************************");
        printf("\n\n");
        printf("\n\t\t\t********************************************************************");
        printf("\n\t\t\t<<<<<<<<<<<<<<<<<<< Train added successfully !!! >>>>>>>>>>>>>>>>>>>");
        printf("\n\t\t\t********************************************************************");
        getch();
        system("cls");
        main();
    }
    if(ch==0)
    {
        system("cls");
        admin();
    }
    if((ch!=1)&&(ch!=0))
    {
        system("cls");
        main();
    }
}
//-----------------------------------view information function--------------------------------------
void viewinfo()
{
    int ch,i;
    system("cls");
    aread();
    printf("\n\t\t     ************************************************************");
    printf("\n\t\t     **************** RAILWAY RESERVATION SYSTEM ****************");
    printf("\n\t\t     ************************************************************");
    //printf("\n\n\n    SI\tTrain number\tTrain name\tStart place\tDestination place\tPrice\tSeat\tTime\n\n");
    printf("\n\n\nSI\tTrain no.\tTrain name\t\tStart\t\tDestination\tPrice\tSeat\tTime\n\n");
    for(i=0; i<k; i++)
    {
        printf("%s\t%s\t\t%s\t\t%s\t\t%s\t%s\t%d\t%s\n",add[i].si,add[i].train_number,add[i].train_name,add[i].start,add[i].destination,add[i].price,add[i].seat,add[i].time);
    }
    printf("********************************************************************************************************\n");
    printf("\n\t\t\tPress '1' for main menu & press any key for exit:  ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        system("cls");
        main();
        break;
    default:
        exit(0);
    }
}
///*********************************************************************************
void checkavailability()
{

    int location = -1,e, n;
    printf ("\n\n\t\t\tEnter ticket number: ");
    scanf ("%d", &n);
    for (e=0; e<u; e++)
    {
        if (n==book[e].seat)
        {
            location=e;
            break;
        }
    }
    if (location==-1)
    {
        printf ("\n\n\t\t\t<<<<<<<<<<<<<< Seat Available !!! >>>>>>>>>>>>>>>>> \n");
        getch();
        system("cls");
        main();
    }
    else
    {

        printf("\n\n\t\t\t<<<<<<<<<<<<<<< Sorry!....Seat is not available....>>>>>>>>>>>>");
        getch();
        system("cls");
        main();
    }
}
/// **********************************************************************************************

//------------------------------------------book ticket file start-----------------------------------------
void bookticket_write()
{
    FILE *booklist;
    booklist=fopen("booklist.txt","w");
    fwrite(&book,sizeof(book),1,booklist);
    fclose(booklist);

    FILE *booklistreport;
    booklistreport=fopen("booklistreport.txt","w");
    fwrite(&u,sizeof(u),1,booklistreport);
    fclose(booklistreport);
}
void viewpassengers_read()
{
    FILE *booklist;
    booklist=fopen("booklist.txt","r");
    fread(&book,sizeof(book),1,booklist);
    fclose(booklist);

    FILE *booklistreport;
    booklistreport=fopen("booklistreport.txt","r");
    fread(&u,sizeof(u),1,booklistreport);
    fclose(booklistreport);
}
//-----------------------------------------add train file start---------------------------------------------------
void awrite()
{
    FILE *train_details;
    train_details = fopen("train_details.txt","w");
    fwrite(&add,sizeof(add),1,train_details);
    fclose(train_details);

    FILE *train_report;
    train_report = fopen("train_report.txt","w");
    fwrite(&k,sizeof(k),1,train_report);
    fclose(train_report);
}
void aread()
{
    FILE *train_details;
    train_details = fopen("train_details.txt","r");
    fread(&add,sizeof(add),1,train_details);
    fclose(train_details);

    FILE *train_report;
    train_report = fopen("train_report.txt","r");
    fread(&k,sizeof(k),1,train_report);
    fclose(train_report);

}
//----------------------------------------------------file close----------------------------------------------
//----------------------------------------------------program close----------------------------------------
