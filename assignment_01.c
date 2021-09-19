// A C Program to store and get the cheapest price of walnut.      
#include<stdio.h>
#include<stdlib.h>
//Line 2 & 3: Including libraray files for the predefined functions used in this program.
struct info
{
char name[30];
int price;
struct info *next;
};
struct info *temp,*disp,*head;
//Line 5-11: Creating a user defined data type using structure to satisfy the memory storage of this program.
void addrecord();
void display();
void displaymin();
void displaymax();
void deleterecord();
//Line 14-17: Declaring user defined functions for this program.

int main()
{
  int ch, ch1;
  while (1) 
  //Line 23: Using loop so that our function doesn't get close after a specific function, untill we enter the assigned input for exiting.
    {
      printf("\n~Akhrot tracker~\n");
      printf("\n 1. To add records.");
      printf("\n 2. To delete records.");
      printf("\n 3. To view the records.");
      printf("\n 4. To exit.");
      printf("\n Enter your choice: ");
//Line 26-31: Print functions used for creating a user inteface.
      scanf("%d",&ch);
//Line 33: Scan function is used to get the user input.       
      fflush(stdin);
      switch(ch)
            {
              case 1:
                  addrecord();
                      break;

              case 2:
                  deleterecord();
                    break;
              
              case 3:
                  printf("\n1. Display whole list.");
                  printf("\n2. Display minimum price.");
                  printf("\n3. Display maximum price.");
                  printf("\n Enter desired display option: ");
                  scanf("%d", &ch1);
                  switch(ch1)
                  {
                    case 1:
                      display();
                        break;

                    case 2:
                      displaymin();
                        break;

                    case 3:
                      displaymax();
                        break;

                    default:
                      printf("\n Invalid choice! :/");
                        break;
                  }
                      break;

              case 4:
                  exit(0);
                      break;

              default:
                  printf("Invalid choice! :/");
                    break;
            }
//Line 36-79: Switch case is used to determine the function to be performed as per user input.

    }
return 0;
}

//Here onwards: The body of our declared functions.
void addrecord()
{
  struct info *add;
  //Line 89: Using our user defined data structure a pointer variable is created.
  
  add=(struct info*)malloc(sizeof(struct info));
  //Line 92: Memory is allocated to our variable using malloc.
  
  printf("\n Enter the name of dealer: ");
  gets(add->name);
  //Line 96: As a name is generally considered as string so, gets is used to read that string & assign to the variable.
  fflush(stdin);
  printf("\n Enter the price of akhrot: ");
  scanf("%d",&add->price);
  //Line 100: As a price is generally considered as number so, scanf is used to read that number & assign to the variable.
  fflush(stdin);

    if(head==NULL|| head->price>=add->price)
      {
        add->next=head;
        head=add;
      }
    else
      {
        temp=head;
          
          while(temp->next!=NULL && temp->next->price < add->price)
            {
              temp=temp->next;
            }
//Line 113-116: A loop is used so that it can iterate through whole list and place the data entered in ascending order with respect to price.
        add->next=temp->next;
        temp->next=add;
      }

//Line 104-120: if-else statements are used to insert/add the user input into the list.
  return;
 }

void display()
{
  int count=0;
//Line 128: A integer value is declared for printing serial number.
  if(head==NULL)
    {
      printf("\n No records to view\n");
      return;
    }
//Line 130-134: If it is observed that the list is empty than the program will display the print statement & return back to main function.

  for(disp=head;disp!=NULL;disp=disp->next)
    {
      printf("\n -- \nSerial number: %d", count);
      printf("\nName of dealer: %s",disp->name);
      printf("\nPrice of akhrot: %d \n",disp->price);
      count++;
      //Line 142: This will keep on increasing the value of interger by 1 each time the loop iterates.
    }
//Line 137-144: The loop will iterate through whole list & keep on printing untill it reaches to the end of list.
  count=0;
//Line 146: The variable declared would get initialed by zero.
return;
}

void deleterecord()
{
    display();
//Line 153: The purpose of display function used here is to display user all the records then he can have precise information of record to be deleted.
    int i,pos;
    struct info *temp,*ptr;
    if(head==NULL)
    {
        printf("\nThe List is Empty! :/");
        return;
    }
//Line 157-161: If it is observed that the list is empty than the program will display the print statement & return back to main function.
    else
    {
        printf("\nEnter the serial number of record to be deleted: ");
        scanf("%d",&pos);
            if(pos==0)
            {
                ptr=head;
                head=head->next;
                printf("\nRecord deleted!");
                    free(ptr);
            }
            else
            {
                ptr=head;
                for(i=0;i<pos;i++) 
                { 
                    temp=ptr; 
                    ptr=ptr->next;
                    if(ptr==NULL)
                    {
                        printf("\nNode not found :/");
                        return;
                    }
                }
                temp->next=ptr->next;
                printf("\nRecord deleted!");
                    free(ptr);
            }
    }
//Line 163-191: if-else statements are used to delete the record from the list based on user input.
}

void displaymin()
{
  if(head==NULL)
    {
      printf("\n No records to view!\n");
      return;
    }
//Line 197-201: If it is observed that the list is empty than the program will display the print statement & return back to main function.

  for(disp=head;disp!=NULL;disp=disp->next)
    {
      if(disp=head)
      {
        printf("\nName of dealer: %s",disp->name);
        printf("\nPrice of akhrot: %d \n",disp->price); 
        return; 
      }
    }
//Line 204-212: The loop will iterate through whole list & will print the first element from loop as it will has minimum numeric value(price) in whole list.
return;  
}

void displaymax()
{
  int count1=0, count2=0;
  //Line 219: Two variables are declared to used as counter
  for(disp=head;disp!=NULL;disp=disp->next)
  {
    count1++;
  }
//Line 221-224: A counter variable count1 is iterated in loop to get its value as the number of elements in list.

  for(disp=head;disp!=NULL;disp=disp->next)
  {
    count2++;
    //Line 229: A counter variable count2 is iterated in loop to get its value increased by 1 each time it iterates.
    if(count1==count2)
    {
    printf("\nName of dealer: %s",disp->name);
    printf("\nPrice of akhrot: %d \n",disp->price);
    return;
    }
    //Line 231-236: If statement is used to check whether if both the counter variables are equal, if it does then it is determined that the loop has reached the end and it will print the record.
  }
    count1=0;
    count2=0;
}