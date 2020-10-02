//----------Includes----------------//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
#include<string>
//-xx---------Includes----------xx------//
//-----------Global Variblees -----------//
typedef struct library {
    char name[100];
    int id;
    int quantity;
}Library;
Library Books[100];
library _temp[100];
FILE* fptr;
FILE* fptr2;
char book1Id[100]; char book1Quantity[100];
char book2Id[100]; char book2Quantity[100];
char book3Id[100]; char book3Quantity[100];
int Bookindex = 3;
int loop_option=1;
int option;
//----xx-------Global Variblees -------xx----//
//-------------Functions Prototype-----------//
void insertBook();
void displayBooks();
void deleteById();
void bubleSort(Library Books[], int size );
int binarySearch(Library Books[], char* keyy, int low, int high);
int linearSearch(Library Books[], int key, int size,int index);
//----xx---------Functions Prototype------xx-----//
int main()
{
    // ------------Writing 3 Books in the File ---------------//
    if ((fptr=fopen("Books.txt", "w")) == NULL)
    {
        printf("File Cannot Be Opened");
    }
    else
        fprintf(fptr,"How To C Programing,2,140\n");
        fprintf(fptr, "Java Programing,3,75\n");
        fprintf(fptr, "JavaScript Toturials,1,220\n");

    fclose(fptr);
    // ----xx--------Writing 3 Books in the File ----------xx-----//

    // ------------Reading 3 Books from the File and Saving it in array of strucuture ---------------//

    if ((fptr = fopen("Books.txt", "r+")) == NULL)
    {
        printf("File Cannot Be Opened");
    }
    else
       // First Book Reading//
        fread(&Books[0].name, 19 * sizeof(char), 1, fptr);
        rewind(fptr);
        fseek(fptr, 20, SEEK_SET);
        fread(&book1Id,sizeof(char), 1, fptr);
        rewind(fptr);
        fseek(fptr,22, SEEK_SET);
        fread(&book1Quantity,3* sizeof(char), 1, fptr);
        // Second Book Reading//
        rewind(fptr);
        fseek(fptr, 27, SEEK_SET);
        fread(&Books[1].name, 15 * sizeof(char), 1, fptr);
        rewind(fptr);
        fseek(fptr, 43, SEEK_SET);
        fread(&book2Id, sizeof(char), 1, fptr);
        rewind(fptr);
        fseek(fptr, 45, SEEK_SET);
        fread(&book2Quantity,2* sizeof(char), 1, fptr);
        // Third Book Reading//
        rewind(fptr);
        fseek(fptr, 49, SEEK_SET);
        fread(&Books[2].name, 20 * sizeof(char), 1, fptr);
        rewind(fptr);
        fseek(fptr, 70, SEEK_SET);
        fread(&book3Id, sizeof(char), 1, fptr);
        rewind(fptr);
        fseek(fptr, 72, SEEK_SET);
        fread(&book3Quantity, 3 * sizeof(char), 1, fptr);
        //--------- Saving the ids and quantity to the array of structure --------//
      //ids
        Books[0].id = atoi(book1Id);
        Books[1].id = atoi(book2Id);
        Books[2].id = atoi(book3Id);
     // quantities
        Books[0].quantity = atoi(book1Quantity);
        Books[1].quantity = atoi(book2Quantity);
        Books[2].quantity = atoi(book3Quantity);
        //--xx------- Saving the ids and quantity to the array of structure ----xx----//
    fclose(fptr);
    //--------------------Saving The Name Of Books In  A Temp Struct---------------------//
    for (int i = 0; i < Bookindex; i++)
    {
        _temp[i].id = Books[i].id;
        strcpy_s(_temp[i].name, Books[i].name);
        _temp[i].quantity = Books[i].quantity;
    }
    //-------xx-------------Saving The Name Of Books In  A Temp Struct-------------xx--------//


    // -----xx-------Readimg 3 Books from the File and Saving it in array of strucuture ----------xx-----//
 //---------------------Main Menu and Options Codeing---------------------------------//
    printf("Hello User , Welcome To My Book Library Program\n");
    printf("A Couple of Options will be shown in front of you\n");
    printf("Please Enter The Number Of Each Option to Preform it \n");
    printf("Option 1 : Insert A Book to the Library\n");
    printf("Option 2 : Delete A Book By ID From the Library\n");
    printf("Option 3 : Search For A Book By  ID In The Library\n");
    printf("Option 4 : Search For A Book By  Name In The Library\n");
    printf("Option 5 : Sort All Books By Name And Print Them And Their Crossponding IDs And Quantites\n");
    printf("Option 6 : Display All Books Unsorted, Their IDs, Names And Quantity (As Entered)\n");

    while (loop_option==1)
    {
        printf("Please Enter Option Number\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insertBook();
            printf("Do You Want To Preform Another Operation\nEnter 0 To Exit or 1 To Continue\n");
            scanf("%d", &loop_option);
            continue;
        case 2:
            deleteById();
            printf("\nDo You Want To Preform Another Operation\nEnter 0 To Exit or 1 To Continue\n");
            scanf("%d", &loop_option);
            continue;
        case 3:
            printf("Please The ID Of The Book You Want To  Search\n"); int id;
            scanf("%d", &id); int idsearch;
            idsearch = linearSearch(Books, id, Bookindex, 0);
            if (idsearch == -1)
            {
                printf("Not Found\n");
            }
            else
            {
                printf("The Book Name and Quantity you searched for  are :\n");
                printf("%s", Books[idsearch].name);
                printf(",%d\n", Books[idsearch].quantity);
            }
            printf("Do You Want To Preform Another Operation\nEnter 0 To Exit or 1 To Continue\n");
            scanf("%d", &loop_option);
            continue;
        case 4:
            bubleSort(Books, Bookindex);
            printf("Please Enter Name Of Book You Want To Search\n");
            char bookname[100];
            scanf(" %[^\n]%*c", bookname);
             int namesearch;
            namesearch = binarySearch(Books, bookname, 0, Bookindex);
            if (namesearch == -1)
            {
                printf("Not Found\n");
            }
            else
            {
                printf("The Book Id and Quantity you searched for  are :\n");
                printf("%d", Books[namesearch].id);
                printf(",%d\n", Books[namesearch].quantity);
            }
            printf("Do You Want To Preform Another Operation\nEnter 0 To Exit or 1 To Continue\n");
            scanf("%d", &loop_option);
            continue;
        case 5:
            bubleSort(Books, Bookindex);
            for (int i = 0; i < Bookindex; i++)
            {
                printf("%s", Books[i].name);
                printf(",%d", Books[i].id);
                printf(",%d\n", Books[i].quantity);
            }
            printf("Do You Want To Preform Another Operation\nEnter 0 To Exit or 1 To Continue\n");
            scanf("%d", &loop_option);
            continue;
        case 6:
            displayBooks();
            printf("Do You Want To Preform Another Operation\nEnter 0 To Exit or 1 To Continue\n");
            scanf("%d", &loop_option);
            continue;

        default:
            printf("Please Input Correct Option Number");
            continue;
        }
    }



 //----xx-----------------Main Menu and Options Codeing-----------------------------xx----//





    return 0;
}
//---------------Functions-----------------//
//-------------Insert a Book Function-------//
void insertBook()
{
    printf("Please Enter BookName,BookId,BookQuantity\n");

    scanf(" %[^\n]%*c", Books[Bookindex].name);
    scanf("%d%d",&Books[Bookindex].id,&Books[Bookindex].quantity);
    _temp[Bookindex].id = Books[Bookindex].id;
    strcpy_s(_temp[Bookindex].name, Books[Bookindex].name);
    _temp[Bookindex].quantity = Books[Bookindex].quantity;
    printf("The Book You Entered Is\n");
    printf("%s", Books[Bookindex].name);
    printf(",%d", Books[Bookindex].id);
    printf(",%d\n", Books[Bookindex].quantity);
    if ((fptr = fopen("Books.txt", "a+")) == NULL)
    {
        printf("File Cannot Be Opened");
    }
    else

        fprintf(fptr, "%s,%d,%d\n", Books[Bookindex].name, Books[Bookindex].id, Books[Bookindex].quantity);
        fclose(fptr);
        Bookindex++;

}
//---xx----------Insert a Book Function----xx---//
//-------------Delete a Book Function by ID-------//
void deleteById( ) ///       int id  to get from main
{

    int cntr; int id;
    printf("Please Enter The Id Of Book To Be Deleted\n");
    scanf("%d", &id); int check_id = 0; int i;
    for (cntr = 0; cntr < Bookindex; cntr++)
    {
        if (id == Books[cntr].id)
        {
            for (cntr; cntr < Bookindex; cntr++)
            {
                strcpy(Books[cntr].name, Books[cntr + 1].name);
                Books[cntr].id = Books[cntr + 1].id;
                Books[cntr].quantity = Books[cntr + 1].quantity;
                strcpy(_temp[cntr].name, _temp[cntr + 1].name);
                _temp[cntr].id = _temp[cntr + 1].id;
                _temp[cntr].quantity = _temp[cntr + 1].quantity;
                check_id++;
            }
            Bookindex--;
        }

    }
    if (check_id == 0)
    {
        printf("Id Not Found");
    }
    if ((fptr2 = fopen("Books_Temp.txt", "w+")) == NULL)
    {
        printf("Erorr While Opening File");
    }
    else
        for (i = 0; i < Bookindex; i++)
        {
            fprintf(fptr2, "%s,%d,%d\n", Books[i].name, Books[i].id, Books[i].quantity);
        }
    fclose(fptr2);

    remove("Books.txt");
    rename("Books_Temp.txt", "Books.txt");


}
//-xx------------Delete a Book Function by ID-----xx--//
//-----------------Buble Sort Function-------------xx---//
void bubleSort(struct library Books[], int size)
{
    for (int cntr1 = 0; cntr1 < size - 1; cntr1++)
    {
        for (int cntr2 = cntr1 + 1; cntr2 < size; cntr2++)
        {
            if (strcmp(Books[cntr1].name, Books[cntr2].name) > 0)
            {
                char temp[100];
                strcpy(temp, Books[cntr1].name);
                strcpy(Books[cntr1].name, Books[cntr2].name);
                strcpy(Books[cntr2].name, temp);
                int temp1 = Books[cntr1].id;
                Books[cntr1].id = Books[cntr2].id;
                Books[cntr2].id = temp1;
                int  temp2 = Books[cntr1].quantity;
                Books[cntr1].quantity = Books[cntr2].quantity;
                Books[cntr2].quantity = temp2;

            }
        }
    }

}

//---xx--------------Buble Sort Function-------------xx---//
//-----------------Linear Search Function---------------//
int linearSearch(Library Books[], int key, int size,int index)
{

    if (size <= index)
    {
        return -1;
    }
    else if (Books[index].id == key)
    {

        return index;
    }
    else
        return linearSearch(Books, key, size, index + 1);

}
//-xx----------------Linear Search Function---------xx------//
//-----------------Binary Search Function---------------//
int binarySearch(Library Books[], char* keyy, int low, int high)
{
    int middle;

    while (low<=high)
    {
         middle =(high + low)/ 2;
        if (strcmp(keyy,Books[middle].name)==0)
        {
            return middle;
        }
        else if (strcmp(keyy, Books[middle].name) < 0)
        {
            high = middle - 1;

        }
        else
        {
            low = middle + 1;
        }

    }
    return  -1;
}
//--xx---------------Binary Search Function-----------xx----//
//-------------------Display Books Function-------------------//
void displayBooks()
{
    for (int i = 0; i < Bookindex; i++)
    {

        printf("%s", _temp[i].name);
        printf(",%d", _temp[i].id);
        printf(",%d\n", _temp[i].quantity);
    }

}
//----xx---------------Display Books Function---------------xx----//
//--xx-------------Functions-------------xx----//
