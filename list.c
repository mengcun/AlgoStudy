/*File name:list.c
 *Type: C source file
 *Date: 2017/06/22 
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <string.h>
/***********************************************************************/
/*             以下是关于线性表链接存储（单链表）操作的19种算法        */ 
/* 1.初始化线性表，即置单链表的表头指针为空 */
/* 2.创建线性表，此函数输入负数终止读取数据*/
/* 3.打印链表，链表的遍历*/
/* 4.清除线性表L中的所有元素，即释放单链表L中所有的结点，使之成为一个空表 */
/* 5.返回单链表的长度 */
/* 6.检查单链表是否为空，若为空则返回１，否则返回０ */
/* 7.返回单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行 */
/* 8.从单链表中查找具有给定值x的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL */
/* 9.把单链表中第pos个结点的值修改为x的值，若修改成功返回１，否则返回０ */
/* 10.向单链表的表头插入一个元素 */
/* 11.向单链表的末尾添加一个元素 */
/* 12.向单链表中第pos个结点位置插入元素为x的结点，若插入成功返回１，否则返回０ */
/* 13.向有序单链表中插入元素x结点，使得插入后仍然有序 */
/* 14.从单链表中删除表头结点，并把该结点的值返回，若删除失败则停止程序运行 */
/* 15.从单链表中删除表尾结点并返回它的值，若删除失败则停止程序运行 */
/* 16.从单链表中删除第pos个结点并返回它的值，若删除失败则停止程序运行 */
/* 17.从单链表中删除值为x的第一个结点，若删除成功则返回1,否则返回0 */
/* 18.交换2个元素的位置 */
/* 19.将线性表进行快速排序 */
/************************************************************************/


struct Node
{
    ElementType Element;
    Position Next;
};
/* 1.初始化线性表，即置单链表的表头指针为空 */
void initList(List L)
{
    L = NULL;
    printf("Initial the List finished!\n");
}
/* 2.创建线性表，此函数输入负数终止读取数据*/
struct Node *creatList(List L)
{
    struct Node *p1;
    struct Node *p2;
    p1=p2=(Position)malloc(sizeof(struct Node));//申请新节点

    if(p1 == NULL || p2 == NULL)
    {
        printf("Failure to malloc the memory!\n");
        exit(0);
    }
    memset(p1, 0, sizeof(struct Node));

    scanf("%d", &p1->Element);//输入新节点
    p1->Next = NULL;//新节点的指针置为空

    while(p1->Element > 0)//输入的值大于0则继续，直到输入的值为负
    {
        if(L == NULL)//空表，接入表头
            L = p1;
        else
            p2->Next = p1;//非空表，接入表尾

        p2 = p1;
        p1 = (Position)malloc(sizeof(struct Node));//再重申请一个节点
        if(p1 == NULL || p2 == NULL)
        {
            printf("内存分配失败\n");
            exit(0);
        }
        memset(p1,0,sizeof(struct Node));
        scanf("%d",&p1->Element);
        p1->Next = NULL;
    }
    printf("creatList success!\n");
    return L;//返回链表的头指针
}

/* 3.打印链表，链表的遍历*/
void printList(struct Node *PtrToNode)
{
    if(PtrToNode == NULL)
        printf("printList execute but the List is empty!\n");
    else
    {
        while(PtrToNode != NULL)
        {
            printf("%d", PtrToNode->Element);
            PtrToNode = PtrToNode->Next;
        }
        printf("\n");
    }
}


/* 4.清除线性表L中的所有元素，即释放单链表L中所有的结点，使之成为一个空表 */
void clearList(struct Node *PtrToNode)
{
    struct Node *PtrToNext;
    if(PtrToNode == NULL)
    {
        printf("clearList execute and the List is Empty!\n");
        return;
    }
    while(PtrToNode->Next != NULL)
    {
        PtrToNext = PtrToNode->Next;//保存下一结点的指针
        free(PtrToNode);
        PtrToNode = PtrToNext;//表头下移
    }
    printf("clearList execute and the List has been clearup!\n");
}

/* 5.返回单链表的长度 */
int sizeList(struct Node *PtrToNode)
{
    int size = 0;
    while(PtrToNode != NULL)
    {
        size++;
        PtrToNode = PtrToNode->Next;//遍历链表size大小比链表的实际长度小1
    }
    printf("sizeList execute and the length is %d\n", size);
    return size;//链表的实际长度
}


/* 6.检查单链表是否为空，若为空则返回１，否则返回０ */
int isEmptyList(struct Node *PtrToNode)
{
    if(PtrToNode == NULL)
    {
        printf("isEmptyList executed and the List is Empty!\n");
        return 1;
    }
    printf("isEmptyList executed and the List isn't Empty!\n");
    return 0;

}

/* 7.返回单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行 */
ElementType getElement(struct Node *PtrToNode, int position)
{
    int i = 0;
    if(position < 1)
    {
        printf("getElement executed but the position is invalid!\n");
        return 0;
    }
    if(PtrToNode == NULL)
    {
        printf("getElement executed but the PtrToNode is invalid!\n");
        return 0;
    }
    while(PtrToNode != NULL)
    {
        ++i;
        if(i == position)
        {
            break;
        }
        PtrToNode = PtrToNode->Next;
    }
    if(i < position)
    {
        printf("getElement executed but the position is too large!\n");
        return 0;
    }

    return PtrToNode->Element;
}

/* 8.从单链表中查找具有给定值x的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL */
unsigned int *getElementAddress(struct Node *PtrToNode, ElementType x)
{
    if(PtrToNode == NULL)
    {    
        printf("getElementAddress executed but the List is empty!\n");
        return NULL;
    }

    if(x < 0)
    {
        printf("getElementAddress executed but the Element X is invalid!\n");
        return NULL;
    }
    while((PtrToNode->Next != NULL) && (PtrToNode->Element != x)) //判断是否到链表末尾，以及是否存在所要找的元素
    {
        PtrToNode = PtrToNode->Next;
    }
    if((PtrToNode->Element != x) && (PtrToNode != NULL))
    {
        printf("getElementAddress executed but didn't find the value!\n");
        return NULL;
    }
    if(PtrToNode->Element == x)
    {
        printf("getElementAddress executed and the address for Element %d is 0x%x\n", x,(unsigned int)&(PtrToNode->Element));
    }

    return &(PtrToNode->Element);//返回元素的地址
}

/* 9.把单链表中第position个结点的值修改为x的值，若修改成功返回１，否则返回０ */
int modifyElement(struct Node *PtrToNode, int position, ElementType x)
{
    int i = 0;
    struct Node *headerNode;
    headerNode = PtrToNode;
    if(x < 0)
    {
        printf("modifyElement executed but the Element X is invalid!\n");
        return 0;
    }
    if(position < 1)
    {
        printf("getElement executed but the position is invalid!\n");
        return 0;
    }
    if(headerNode == NULL)
    {
        printf("getElement executed but the PtrToNode is invalid!\n");
        return 0;
    }
    while(headerNode != NULL)
    {
        ++i;
        if(i == position)
        {
            break;
        }
        headerNode = headerNode->Next;
    }
    if(i < position)
    {
        printf("getElement executed but the position is too large!\n");
        return 0;
    }
    PtrToNode = headerNode;
    PtrToNode->Element = x;
    printf("modifyElement executed and success\n");
    return 1;
}

/* 10.向单链表的表头插入一个元素 */
struct Node *insertHeadList(struct Node *PtrToNode, ElementType insertElement)
{
    struct Node *insertNode;
    if(insertElement < 0)
    {
        printf("insertHeadList executed but the Element X is invalid!\n");
        return 0;
    }
    insertNode = (struct Node *)malloc(sizeof(struct Node));
    if(insertNode == NULL)
    {
       printf("内存分配失败\n");
       exit(0);
    }
    memset(insertNode, 0, sizeof(struct Node));
    insertNode->Element = insertElement;
    insertNode->Next = PtrToNode;
    
    printf("insertHeadList executed and success!\n");
    return insertNode;
}

/* 11.向单链表的末尾添加一个元素 */
int insertLastList(struct Node *PtrToNode, ElementType insertElement)
{
    struct Node *insertNode;
    struct Node *headerNode;
    struct Node *tempNode;//定义一个临时链表用来存放第一个节点
    headerNode = PtrToNode;
    tempNode = headerNode;
    if(insertElement < 0)
    {
        printf("insertLastList executed but the Element X is invalid!\n");
        return 0;
    }
    insertNode = (struct Node *)malloc(sizeof(struct Node));
    if(insertNode == NULL)
    {
       printf("内存分配失败\n");
       exit(0);
    }
    memset(insertNode, 0, sizeof(struct Node));
    insertNode->Element = insertElement;
    while(headerNode->Next != NULL)
    {
        headerNode = headerNode->Next;
    }
    headerNode->Next = insertNode;
    insertNode->Next = NULL;
    PtrToNode = tempNode;
    printf("insertLastList executed and success!\n");
}

/* 12.向单链表中第pos个结点位置插入元素为x的结点，若插入成功返回１，否则返回０ */
int insertNode(struct Node *PtrToNode, int position, ElementType insertElement)
{
    struct Node *tempNode;
    struct Node *insertNode;
    int i = 0;
    if(insertElement < 0)
    {
        printf("insertNode executed but the Element X is invalid!\n");
        return 0;
    }
    tempNode = (struct Node *)malloc(sizeof(struct Node));
    insertNode = (struct Node *)malloc(sizeof(struct Node));
    if(tempNode == NULL ||insertNode ==NULL)
    {
       printf("内存分配失败\n");
       exit(0);
    }
    memset(tempNode, 0, sizeof(struct Node));
    memset(insertNode, 0, sizeof(struct Node));
    insertNode->Element = insertElement;

    if(position < 1)
    {
        printf("insertNode executed but the position is invalid!\n");
        return 0;
    }
    if(PtrToNode == NULL)
    {
        printf("insertNode executed but the PtrToNode is invalid!\n");
        return 0;
    }
    while(PtrToNode != NULL)
    {
        ++i;
        if(i == position)
        {
            break;
        }
        PtrToNode = PtrToNode->Next;
    }
    if(i < position)
    {
        printf("insertNode executed but the position is too large!\n");
        return 0;
    }

    tempNode = PtrToNode->Next;
    PtrToNode->Next = insertNode;
    insertNode->Next = tempNode;
    printf("insertNode executed and success!\n");
    return 1;
}

 /* 13.向有序单链表中插入元素x结点，使得插入后仍然有序 H->L*/
struct Node *insertSortNode(struct Node *PtrToNode, ElementType insertElement)
{
    struct Node *insertSortNode;
    struct Node *tempNode;
    struct Node *newPtrToNode;
    struct Node *firstPtrToNode;
    firstPtrToNode = PtrToNode;
    if(PtrToNode == NULL)
    {
        printf("insertSortNode executed but the PtrToNode is empty!\n");
        return firstPtrToNode;
    }
    if(insertElement < 0)
    {
        printf("insertSortNode executed but the Element X is invalid!\n");
        return firstPtrToNode;
    }
    tempNode = (struct Node *)malloc(sizeof(struct Node));
    insertSortNode = (struct Node *)malloc(sizeof(struct Node));
    if(tempNode == NULL ||insertSortNode == NULL)
    {
       printf("内存分配失败\n");
       exit(0);
    }
    memset(tempNode, 0, sizeof(struct Node));
    memset(insertSortNode, 0, sizeof(struct Node));
    
    if((PtrToNode->Element) <= insertElement)
    {
        newPtrToNode = insertHeadList(PtrToNode, insertElement);
        printf("insertSortNode executed and use the insertHeadList!\n");
        return newPtrToNode;
    }
    else
    {
        while(PtrToNode->Next != NULL)
        {
            if((PtrToNode->Element) >= insertElement)
            {
                tempNode = PtrToNode;
                PtrToNode = PtrToNode->Next;    
            }
            else
            {
                tempNode->Next = insertSortNode;
                insertSortNode->Next = PtrToNode;
                insertSortNode->Element = insertElement;
                printf("insertSortNode executed!\n");
                return firstPtrToNode;
            }
        }
        insertLastList(PtrToNode, insertElement);
        printf("insertSortNode executed and use the insertLastList!\n");
        return firstPtrToNode;
    }
}

/* 14.从单链表中删除表头结点，并把该结点的值返回，若删除失败则停止程序运行 */
struct Node *deleteHeader(struct Node *PtrToNode)
{
    struct Node *newPtrToNode;
    struct Node *tempNode;
    if(PtrToNode == NULL)
    {
        printf("deleteHeader executed but the PtrToNode is empty!\n");
        return PtrToNode;
    }
    tempNode = PtrToNode->Next;
    free(PtrToNode);
    newPtrToNode = tempNode;
    return newPtrToNode;
}

/* 15.从单链表中删除表尾结点并返回它的值，若删除失败则停止程序运行 */
struct Node *deleteLast(struct Node *PtrToNode)
{
    struct Node *newPtrToNode;
    struct Node *tempNode;
    newPtrToNode = PtrToNode;
    if(PtrToNode == NULL)
    {
        printf("deleteLast executed but the PtrToNode is empty!\n");
        return PtrToNode;
    }
    while(PtrToNode->Next != NULL)
    {
        tempNode = PtrToNode;
        PtrToNode = PtrToNode->Next;
    }
    free(PtrToNode);
    tempNode->Next = NULL;
    printf("deleteLast executed and success!\n");
    return newPtrToNode;
}

/* 16.从单链表中删除第pos个结点并返回它的值，若删除失败则停止程序运行 */
struct Node *deletePosition(struct Node *PtrToNode, int position)
{
    int i = 0;
    struct Node *frontNode;
    struct Node *currentNode;
    struct Node *newPtrToNode;
    newPtrToNode = PtrToNode;
    if(position < 1)
    {
        printf("deletePosition executed but the position is invalid!\n");
        return 0;
    }

    if(PtrToNode == NULL)
    {
        printf("deletePosition executed but the PtrToNode is invalid!\n");
        return 0;
    }

    if(position > 1)
    {
        while(PtrToNode != NULL)
        {
            ++i;
            if(i == position)
            {
                currentNode = PtrToNode;
                break;
            }
            frontNode = PtrToNode;
            PtrToNode = PtrToNode->Next;
        }
        
        if(PtrToNode == NULL)
        {
            newPtrToNode = deleteLast(newPtrToNode);    
            printf("deletePosition executed and use deleteLast()!\n");
            return newPtrToNode;
        }

        if(i < position)
        {
            printf("deletePosition executed but the position is too large!\n");
            return 0;
        }
        frontNode->Next = currentNode->Next;
        free(currentNode);
        printf("deletePosition executed and success!\n");
        
    }

    if(position == 1)
    {
        newPtrToNode = deleteHeader(newPtrToNode);
        printf("deletePosition executed and use deleteHeader!\n");
    }

    return newPtrToNode;
}

/* 17.从单链表中删除值为x的第一个结点，若删除成功则返回1,否则返回0 */
//int 

int main()
{
    struct Node *PtrToNode = NULL;
    struct Node *newPtrToNode;
    ElementType pos_element;
    int length = 0;
    unsigned int position;
    initList(PtrToNode);//链表初始化
    printList(PtrToNode);//遍历链表，打印链表

    PtrToNode = creatList(PtrToNode);//创建链表
    printList(PtrToNode);


    length = sizeList(PtrToNode); //链表的长度

    isEmptyList(PtrToNode);//判断链表是否为空链表
    
    pos_element = getElement(PtrToNode,3);
    printf("getElement executed and the Element in Position 3 is %d\n", pos_element);

    position = getElementAddress(PtrToNode, 55);
    printf("getElementAddress executed and the address for Element 55 is 0x%x\n", position);
   
    modifyElement(PtrToNode, 4, 10);//将链表中位置4上的元素修改为10
    printList(PtrToNode);

    newPtrToNode = insertHeadList(PtrToNode, 100);
    printList(newPtrToNode);

    insertLastList(newPtrToNode, 4);
    printList(newPtrToNode);

    insertNode(newPtrToNode, 6, 99);
    printList(newPtrToNode);

    newPtrToNode  = insertSortNode(newPtrToNode, 120);
    printList(newPtrToNode);

    newPtrToNode  = insertSortNode(newPtrToNode, 10);
    printList(newPtrToNode);
    
    newPtrToNode  = insertSortNode(newPtrToNode, 3);
    printList(newPtrToNode);
   
    newPtrToNode = deleteHeader(newPtrToNode);
    printList(newPtrToNode);

    newPtrToNode = deleteLast(newPtrToNode);
    printList(newPtrToNode);

    newPtrToNode = deletePosition(newPtrToNode, 2);
    printList(newPtrToNode);
    
    newPtrToNode = deletePosition(newPtrToNode, 11);
    printList(newPtrToNode);

    newPtrToNode = deletePosition(newPtrToNode, 1);
    printList(newPtrToNode);
    
    clearList(newPtrToNode);
}
