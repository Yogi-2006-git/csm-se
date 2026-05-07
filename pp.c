#include <stdio.h>

int mutex = 1;
int full = 0;
int empty = 5;
int x = 0;

void producer()
{
    mutex--;
    empty--;
    full++;
    x++;
    printf("Produced item: %d\n", x);
    mutex++;
}

void consumer()
{
    mutex--;
    empty++;
    full--;
    printf("Consumed item: %d\n", x);
    x--;
    mutex++;
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n1: Producer\n2: Consumer\n3: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (mutex == 1 && empty != 0)
                producer();
            else
                printf("Buffer is Full\n");
            break;

        case 2:
            if (mutex == 1 && full != 0)
                consumer();
            else
                printf("Buffer is Empty\n");
            break;

        case 3:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
