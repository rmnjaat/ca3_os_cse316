
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define the structure
struct student
{
    int stu_no;
    int gift_number;
};

int compareByGiftNumber(const void *a, const void *b)
{
    struct student *aa = (struct student *)a;
    struct student *bb = (struct student *)b;

    return bb->gift_number - aa->gift_number;
}

// Fuction to sort an array of stu_arr by gift number
void sortstu_arrByGiftNumber(struct student *stu_arr, int num_student)
{
    qsort(stu_arr, num_student, sizeof(struct student), compareByGiftNumber);
}

int main()
{
    // Define an array of stu_arr
    int num_student = 3;
    struct student stu_arr[num_student];
    srand(time(NULL));
    for (int i = 0; i < num_student; i++)
    {
        stu_arr[i].stu_no=i+1;
        stu_arr[i].gift_number = rand() % 100;
    }

    // Sort the array based on "gift_number"
    sortstu_arrByGiftNumber(stu_arr, num_student);

    printf("\n\nLess Priority number is equivalent to HIGH PRIORITY \n\n");
    printf("Printing student according to their priority on Billing counter :\n\n");
    // Print the sorted list of stu_arr
        printf("Priority No.\t Student Name\tNumber of gifts\n\n");
    for (int i = 0; i < num_student; i++)
    {

        printf(" %d\t\t\tS%d\t\t%d\n", i + 1,stu_arr[i].stu_no, stu_arr[i].gift_number);
        printf("\n");
    }

    return 0;
}
