/* Tutorial 8 array of structures */

#include <stdio.h>

struct entry
{
    char firstname[20];
    char lastname[20];
    char phone[10];
};

int main(void)
{
    struct entry list[4];

    for (int i = 0; i < 4; i++)
    {
        printf("\nEnter first name: ");
        scanf("%s", list[i].firstname);
        printf("Enter last name: ");
        scanf("%s", list[i].lastname);
        printf("Enter phone in 123-4567 format: ");
        scanf("%s", list[i].phone);
    }

    for (int i = 0; i < 4; i++)
    {
        printf("\nName: %s %s\tPhone: %s", list[i].firstname, list[i].lastname, list[i].phone);
    }
}