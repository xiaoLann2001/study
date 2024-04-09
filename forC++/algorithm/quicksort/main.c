#include <stdio.h>
#include <stdlib.h>

#define N 15

int quick_sort(int *data, int low, int high);
int partion(int *data, int low, int high);


int main()
{
    int data[N] = {0};

    srandom(10);
    
    for (int i = 0; i < N; i++)
    {
        data[i] = random() % 100;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", data[i]);
    }
    puts("");
    
    quick_sort(data, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        printf("%d ", data[i]);
    }
    puts("");

    return 0;
}

int quick_sort(int *data, int low, int high)
{
    int t;
    
    if (NULL == data)
    {
        printf("error array\n");
        return -1;
    }

    if (low >= high)
    {
        return -1;
    }

    t = partion(data, low, high);
    quick_sort(data, low, t - 1);
    quick_sort(data, t + 1, high);

    return t;
}

int partion(int *data, int low, int high)
{
    int flag = 0;
    int mid = low;

    while (low < high)
    {
        if ((flag == 0) && (data[mid] > data[high]))
        {
            // exchange
            int temp = data[mid];
            data[mid] = data[high];
            data[high] = temp;
            mid = high;

            // change direction
            flag = 1;
            low++;
        }
        else if ((flag == 1) && (data[mid] <= data[low]))
        {
            // exchange
            int temp = data[mid];
            data[mid] = data[low];
            data[low] = temp;
            mid = low;

            // change direction
            flag = 0;
            high--;
        }
        else
        {
            if (0 == flag)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
    }
    return low;
}