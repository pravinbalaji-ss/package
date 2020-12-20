#include<stdlib.h>
#include<stdio.h>
int seat=100;


void Ground_details();
void buy_ticket();
void old_record();
void main()
{
        int ch;
        do{
        printf("\n\t\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t         BCCI CRICKET TICKET BOOKING");
        printf("\n\t\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

        printf("\n\nEnter >1< For Stadium Details");
        printf("\nEnter  >2< To Buy Ticket");
        printf("\nEnter  >3< To View All Transactions");
        printf("Enter >0< To Exit");

        printf("\nEnter your Choice ::");
        scanf("%d",&ch);


        switch(ch)
        {
                case 1:
                Ground_details();
        break;
                case 2:
                buy_ticket();
        break;

                case 3:
                old_record();

                case 0:
               exit(0);
        break;

                default:
                printf("Wrong choice!");
        break;
        }
      }while(ch!=0);

}

void Ground_details()
{

        char ch;
        FILE *fp;

        fp=fopen("data.txt","a+");
        if(fp==NULL)
        {
                printf("file does not found!");
                exit(1);

        }
        else
        {
                while((ch=fgetc(fp))!=EOF)
                        printf("%c",ch);
        }

        fclose(fp);
}
void buy_ticket()
{
    int ground_code;
    printf("Ground code:");
    scanf("%d",&ground_code);
    if(ground_code==123)
    {
        printf("Stadium : Chepauk\n ");

        printf("Date : 21/12/2020\n");
        printf("Time : 7:30PM\n");
        printf("CSK vs MI\n");
    }
    else if(ground_code==789)
    {
        printf("Stadium : Eden Gardens, Kolkata\n");
        printf("Date : 22/12/2020\n");
        printf("Time : 7;30PM\n");
        printf("RCB vs SRH\n");
    }
    else if(ground_code==456)
    {
        printf("Stadium : Chinnaswamy, Bangalore\n");
        printf("Date : 23/12/2020\n");
        printf("Time : 7:30PM\n");
        printf("DC vs KKR\n");
    }
    else
    {
        printf("Wrong ground code");
    }
    char name[10];
    int mobile;
    int total_seat;

    printf(" Your name :");
    scanf("%s",&name);
    printf("\n Mobile number :");
    scanf("%d",&mobile);
    printf("\n Total number of tickets :");
    scanf("%d",&total_seat);
    if(total_seat>=10)
    {
        printf("You can't book these amount of tickets\n");
        printf("Please book between 10 tickets\n");
        printf("\nPlease re-enter total number of tickets : ");
        scanf("%d",&total_seat);
    }
    int i,j;
    int seat[10];
        printf("\n\t\t\t\t                                                 SCREEN\n\n\n");
        for(i=1;i<=100;i++)
        {

                printf("%d\t",i);

                if(i%10==0)
                printf("\n\n");
        }
		FILE *fp;
		FILE *ufp;
        printf("\n Booked seats\n");
        fp=fopen("BookedSeat.txt","r");
        char ch;
   if(fp==NULL)
   {
        printf("file does not found !");
        exit(1);

   }
   else
   {
        while( (ch=fgetc(fp) )!=EOF)
                printf("%c",ch);
   }
   fclose(fp);
        printf("\n These seats are booked for this Stadium");
        printf("\n Please choose others seats");
        for(i=1;i<=total_seat;i++) {
                printf("\n Choose seat number :");
   scanf("%d",&j);

   if(j>100||j<1)
        {
                printf("%d seat is unavailable in this ground\n",j);
                printf("Please re-enter seat number: ");
                scanf("%d",&j);
        }
        ufp=fopen("Bookedseat.txt","a");
   if(ufp==NULL)
   {
        printf("File not Found");
        printf("File not Found");
   }
   else
   {
        fprintf(ufp,"%d \n",j);
        printf("\n Record insert Successful to the Booked seat file");
        seat[i-1]=j;
   }
        printf("\n");
   fclose(ufp);
   fclose(fp);

        }

             int cost;
        cost=1000;
        int total_amount;
   total_amount=cost*total_seat;

        printf("\n\n");
        printf("\t\t\t\t\t\t\t   ------------------------------STADIUM BOOKING TICKET-------------------------------\n");
        printf("\t\t\t\t\t\t\t=======================================================================================\n");
        printf("\n\t\t\t\t\t\t Name :%s",&name);
        printf("\n\t\t\t\t\t                                             Total seats : %d",total_seat);
        printf("\n\t\t\t\t\t                                             Cost per ticket : %d Rs",cost);
        printf("\n\t\t\t\t\t                                             Total Amount : %d Rs",total_amount);
        printf("\n\t\t\t\t\t                                             Seat Number : ");
        for(i=1;i<=total_seat;i++)
        {
                printf("%d ",seat[i-1]);
        }
        printf("\n");


        printf("\n\t\t\t\t\t\t\t                                 Payment                             \n");
        printf("\n\t\t\t\t\t\t\t    ****************************WELCOME***************************************  \n");
        printf("\n Merchant Number: 01869738641\n");
        printf("\n Your number:%d\n",&mobile);
        printf("\n Total Amount : %d Rs\n",total_amount);
        printf("\n\n\t\t\t\t\t\t\t\t ******************BOOKING CONFIRMED**************** \n");
        printf("\n\n\t\t\t\t\t\t\t\t $$$$$$$$$$$$$$$   ENJOY THE MATCH   $$$$$$$$$$$$$$$$ \n");
        ufp=fopen("oldTransaction.txt","a");
        if(ufp==NULL)
        {
               printf("File not found");
        }
        else
        {
                fprintf(ufp,"%s %d %d %d %s %d %s %s \n",name,mobile,total_seat,total_amount);
                printf("\n Record insert successful to the old record file");
        }
            printf("\n");
        fclose(ufp);
        fclose(fp);

}

void old_record()
{
        char ch;
        FILE *fp;
        fp=fopen("oldTransaction.txt","t");
        if(fp=NULL)
        {
                printf("file does not found !");
                exit(1);

        }
        else
        {
                while((ch=fgetc(fp))!=EOF)
                     printf("%c",ch);

        }
        fclose(fp);

}

