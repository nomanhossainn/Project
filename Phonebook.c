
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    char name[30];
    char dept[10];
    char student_id[9];
    long int mble_no;
    char address[20];
    char sex[8];
    char blood_grp[10];
    char mail[100];
};

typedef struct person person;

void remove_all();
void print_menu();
void add_person();
void list_record();
void search_person();
void remove_person();
void update_person();
void take_input(person *p);

void start()
{
    int choice;
    while (1)
    {
        print_menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            list_record();
            getchar();
            getchar();
            break;
        case 2:
            add_person();
            getchar();
            getchar();
            break;
        case 3:
            search_person();
            getchar();
            getchar();
            break;
        case 4:
            remove_person();
            getchar();
            getchar();
            break;
        case 5:
            update_person();
            getchar();
            getchar();
            break;
        case 6:
            remove_all();
            getchar();
            getchar();
            break;

        case 7:
            system("clear");
            printf("Thank you for using UIU students phonebook. Visit again :)\n");
            getchar();
            getchar();
            exit(1);
            break;

        default:
            printf("\n");
            printf("\t\t\tInvalid input! Please enter 1 to 7.\n");
            printf("\t\t\tPress any key to continue: ");
            getchar();
            getchar();
            break;
        }
    }
}

int main()
{
    start();
    return 0;
}

void print_menu()
{
    system("clear");
    printf("\t\t****************************************************************\n");
    printf("\t\t*              WELCOME TO UIU STUDENTS PHONEBOOK               *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\t\t1. View All Deatils.\n\n");
    printf("\t\t\t2. Create New Contact.\n\n");
    printf("\t\t\t3. Search Person Details.\n\n");
    printf("\t\t\t4. Remove Person Details.\n\n");
    printf("\t\t\t5. Update Person Details.\n\n");
    printf("\t\t\t6. Delete All Contacts.\n\n");
    printf("\t\t\t7. Exit Phonebook.\n\n");

    printf("\t\t\tEnter your Choice: ");
}

void add_person()
{
    system("clear");
    FILE *fp;
    fp = fopen("phonebook_db", "ab+");
    if (fp == NULL)
    {
        printf("Error in file opening. Please try again!\n");
        printf("Press any key to continue: ");
        return;
    }
    else
    {
        person p;
        take_input(&p);
        fwrite(&p, sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);
        system("clear");
        printf("Congratulations!! Your details added successfully.\n");
        printf("Press any key to continue: ");
    }
}

void take_input(person *p)
{
    system("clear");
    getchar();
    printf("Enter Name: ");
    scanf("%[^\n]s", p->name);

    printf("Enter Department: ");
    scanf("%s", p->dept);

    printf("Enter Student ID: ");
    scanf("%s", p->student_id);

    printf("Enter Phone No: ");
    scanf("%ld", &p->mble_no);

    printf("Enter Address: ");
    scanf("%s", p->address);

    printf("Enter Sex: ");
    scanf("%s", p->sex);

    printf("Enter Blood Group: ");
    scanf("%s", p->blood_grp);

    printf("Enter Email: ");
    scanf("%s", p->mail);
}

void list_record()
{
    system("clear");
    FILE *fp;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening. Please try again!\n");
        printf("Press any key to continue: ");
        return;
    }
    else
    {
        person p;
        printf("\n\t\t\t\t******************************************************************************\n");
        printf("\t\t\t\t*                  HERE IS ALL RECORDS LISTED IN PHONEBOOK                   *\n");
        printf("\t\t\t\t******************************************************************************\n\n\n");
        printf("NAME\t\t        DEPARTMENT     STUDENT ID\tPHONE NO\t  ADDRESS\t SEX       BLOOD GROUP     EMAIL\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");

        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            int i;

            int len1 = 24 - strlen(p.name);
            int len5 = 15 - strlen(p.dept);
            int len2 = 17 - strlen(p.student_id);
            int len3 = 8;
            int len6 = 15 - strlen(p.address);
            int len4 = 10 - strlen(p.sex);
            int len7 = 16 - strlen(p.blood_grp);

            printf("%s", p.name);
            for (i = 0; i < len1; i++)
                printf(" ");

            printf("%s", p.dept);
            for (i = 0; i < len5; i++)
                printf(" ");

            printf("%s", p.student_id);
            for (i = 0; i < len2; i++)
                printf(" ");

            printf("%ld", p.mble_no);
            for (i = 0; i < len3; i++)
                printf(" ");

            printf("%s", p.address);
            for (i = 0; i < len6; i++)
                printf(" ");

            printf("%s", p.sex);
            for (i = 0; i < len4; i++)
                printf(" ");

            printf("%s", p.blood_grp);
            for (i = 0; i < len7; i++)
                printf(" ");

            printf("%s", p.mail);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue: ");
    }
}

void search_person()
{
    system("clear");
    long int phone;
    printf("Enter the phone number of the person you want to search: ");
    scanf("%ld", &phone);

    FILE *fp;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening. Please try again!\n");
        printf("Press any key to continue: ");
        return;
    }
    else
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (p.mble_no == phone)
            {
                printf("NAME\t\t        DEPARTMENT     STUDENT ID\tPHONE NO\t  ADDRESS\t SEX       BLOOD GROUP     EMAIL\n");
                printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");

                int i;

                int len1 = 24 - strlen(p.name);
                int len5 = 15 - strlen(p.dept);
                int len2 = 17 - strlen(p.student_id);
                int len3 = 8;
                int len6 = 15 - strlen(p.address);
                int len4 = 10 - strlen(p.sex);
                int len7 = 16 - strlen(p.blood_grp);

                printf("%s", p.name);
                for (i = 0; i < len1; i++)
                    printf(" ");

                printf("%s", p.dept);
                for (i = 0; i < len5; i++)
                    printf(" ");

                printf("%s", p.student_id);
                for (i = 0; i < len2; i++)
                    printf(" ");

                printf("%ld", p.mble_no);
                for (i = 0; i < len3; i++)
                    printf(" ");

                printf("%s", p.address);
                for (i = 0; i < len6; i++)
                    printf(" ");

                printf("%s", p.sex);
                for (i = 0; i < len4; i++)
                    printf(" ");

                printf("%s", p.blood_grp);
                for (i = 0; i < len7; i++)
                    printf(" ");

                printf("%s", p.mail);
                printf("\n");

                flag = 1;
                break;
            }
            else
                continue;
        }

        if (flag == 0)
        {
            system("clear");
            printf("The person's details are not on the phonebook!!:)\n");
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue: ");
    }
}

void remove_person()
{
    system("clear");
    long int phone;
    printf("Enter the phone number of the person you want to remove from the phonebook: ");
    scanf("%ld", &phone);

    FILE *fp, *temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp", "wb+");
    if (fp == NULL)
    {
        printf("Error in file opening. Please try again!\n");
        printf("Press any key to continue: ");
        return;
    }
    else
    {
        person p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (p.mble_no == phone)
            {
                system("clear");
                printf("Person removed successfully!\n");
                flag = 1;
            }
            else
                fwrite(&p, sizeof(p), 1, temp);
            fflush(stdin);
        }
        if (flag == 0)
        {
            system("clear");
            printf("No record found for %ld number!!\n", phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp", "phonebook_db");
        fflush(stdin);
        printf("Press any key to continue: ");
    }
}

void update_person()
{

    system("clear");
    long int phone;
    printf("Enter the phone number of the person whose details you want to update: ");
    scanf("%ld", &phone);

    FILE *fp, *temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp", "wb+");
    if (fp == NULL)
    {
        printf("Error in file opening. Please try again!\n");
        printf("Press any key to continue: ");
        return;
    }
    else
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (p.mble_no == phone)
            {
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp);
                system("clear");
                printf("Congratulations! Person details updated successfully.\n");
                flag = 1;
            }
            else
                fwrite(&p, sizeof(p), 1, temp);
            fflush(stdin);
        }

        if (flag == 0)
        {
            system("clear");
            printf("No record found for %ld number\n", phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp", "phonebook_db");
        fflush(stdin);
        printf("Press any key to continue: ");
    }
}

void remove_all()
{
    char choice;
    system("clear");
    remove("./phonebook_db");
    printf("All data in the phonebook deleted successfully\n");
    printf("Press any key to continue: ");
}
