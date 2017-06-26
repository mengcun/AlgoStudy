/*Selection problem
*题目：编写一个程序解决选择问题。令k = N / 2。画出表格显示你的程序对于N为不同值时的运行时间。
*设有一组N个数确定其中第k个最大者，称选择问题(selection problem)
*思路：读入前k个数到临时数组tmp（并按降序排列）。然后逐个读取后续数字X，当X大于第k个数时，将其加入数组tmp（并按降序排列）。最后返回位置k-1上的值。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 90000
int select_k(int arr[], int numberofarr, int k);

int main(void)
{
    int * arr;
    int value;
    clock_t elapse;

    srand((unsigned)time(NULL));//use the time as the source og random
    arr = (int *)malloc(sizeof(int) * N);
    for (int j = 0; j < N; j++)
    {
        arr[j] = rand() % 10000;
        printf("arr[%d] = %d\n", j, arr[j]);
    }

    elapse = clock();
    value = select_k(arr,N,N/2);
    elapse = clock() - elapse;
    printf("Value: %d, elapse: %.4lfms\n", value, (double)elapse / 1000);
    free(arr);
    //system("pause");
    return 0;
}

int select_k(int arr[], int numberofarr, int k)
{
    int * tmp;
    int i, j, ret;
    tmp = (int *)malloc(sizeof(int) * k);
    tmp[0] = arr[0];
    for(i = 1; i < k; i++)//Read number of K
    {
        tmp[i] = arr[i];
        for(j = i; j > 0; j--)//sort as descending
        {
            if(arr[i] > tmp[j-1])
            {
                tmp[j] = tmp[j-1];
                tmp[j-1] = arr[i];
            }
        }
    }

    for(i = k; i < numberofarr; i++)
    {
        if(tmp[k-1] < arr[i])
        {
            tmp[k-1] = arr[i];
            for(j = k-1; j > 0; j--)
            {
                if(arr[i] > tmp[j-1])
                {
                    tmp[j] = tmp[j-1];
                    tmp[j-1] = arr[i];
                }
            }
        } 
    }

    ret = tmp[k-1];
    free(tmp);
    return ret;
}
