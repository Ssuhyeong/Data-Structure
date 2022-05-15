#include <stdio.h>

typedef int element;
int size;

void intervalSort(element a[], int begin, int end, int interval)
{
    int i, j;
    element item;
    for(i = begin + interval;i<=end;i = i+interval)
    {
        item = a[i];
        for(j = i - interval;j >= begin && item <a[j]; j = j - interval) // interval에 있는 값이 interval 앞에 값보다 작으면 교환
        {
            a[j+interval] = a[j];
        }
        a[j+interval] = item;
    }
}

void shellSort(int a[], int size)
{
    int i, t,interval;
    printf("\n 정렬할 원소 : ");
    for(t = 0;t<size;t++) printf("%d",a[t]);
    printf("\n\n<<<<<<<<<<< 셸 정렬 수행<<<<<<<<<<<<\n");
    interval = size/2;
    while(interval >= 1)
    {
        for(i = 0;i<interval;i++) intervalSort(a, 0, size-1, interval);
        printf("\n interval = %d >>", interval);
        for(t=0;t<size;t++) printf("%d ", a[t]);
        interval = interval / 2;
    }
}

int main(void)
{
    int list[8] = {69, 10, 30, 2, 16, 8, 31, 22};
    size = 8;
    
    shellSort(list, size);
    return 0;
}
