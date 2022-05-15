#include <stdio.h>

int size;

void insertionSort(int a[], int size)
{
    int i, j, t, temp;
    printf("\n 정렬할 원소 : ");
    for(t = 0;t<size;t++) printf("%d ", a[t]);
    printf("\n\n<<<<<<<<삽입 정렬 수행<<<<<<<<<<\n");
    for(i = 1;i<size;i++)
    {
        temp = a[i];
        j = i;
        while((j>0) && (a[j-1]>temp)) // 비교 대상이 0보다 작거나 넣을 자리보다 크면 스탑
        {
            a[j] = a[j-1];
            j = j - 1;
        }
        a[j] = temp;
        printf("\n %d단계 : ", i);
        for(t = 0;t<size;t++) printf("%3d", a[t]);
    }
}

int main(void)
{
    int list[8] = {69, 10, 30, 2, 16, 8, 31, 22};
    size  = 8;
    
    insertionSort(list, size);
    return 0;
}
