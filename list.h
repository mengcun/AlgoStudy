/*File name: list.h
 *Type: C header file
 *Date: 2017/06/22
 */

#ifndef LIST_H
#define LIST_H

#ifdef __cplusplus
extern "C"{
#endif

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
/*定义单链表结点类型*/
typedef int ElementType;
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
/* 1.初始化线性表，即置单链表的表头指针为空 */
void initList(List L);
/* 2.创建线性表，此函数输入负数终止读取数据*/
struct Node *creatList(List L);
/* 3.打印链表，链表的遍历*/
void printList(struct Node *PtrToNode);
/* 4.清除线性表L中的所有元素，即释放单链表L中所有的结点，使之成为一个空表 */
void clearList(struct Node *PtrToNode);
/* 5.返回单链表的长度 */
int sizeList(struct Node *PtrToNode);
/* 6.检查单链表是否为空，若为空则返回１，否则返回０ */
int isEmptyList(struct Node *PtrToNode);
/* 7.返回单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行 */
ElementType getElement(struct Node *PtrToNode, int position);
/* 8.从单链表中查找具有给定值x的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL */
unsigned int *getElementAddress(struct Node *PtrToNode, ElementType x);
/* 9.把单链表中第pos个结点的值修改为x的值，若修改成功返回１，否则返回０ */
int modifyElement(struct Node *PtrToNode, int position, ElementType x);
/* 10.向单链表的表头插入一个元素 */
struct Node *insertHeadList(struct Node *PtrToNode, ElementType insertElement);
/* 11.向单链表的末尾添加一个元素 */
int insertLastList(struct Node *PtrToNode, ElementType insertElement);
/* 12.向单链表中第pos个结点位置插入元素为x的结点，若插入成功返回１，否则返回０ */
int insertNode(struct Node *PtrToNode, int position, ElementType insertElement);
/* 13.向有序单链表中插入元素x结点，使得插入后仍然有序 */
struct Node *insertSortNode(struct Node *PtrToNode, ElementType insertElement);
/* 14.从单链表中删除表头结点，并把该结点的值返回，若删除失败则停止程序运行 */
struct Node *deleteHeader(struct Node *PtrToNode);
/* 15.从单链表中删除表尾结点并返回它的值，若删除失败则停止程序运行 */
struct Node *deleteLast(struct Node *PtrToNode);
/* 16.从单链表中删除第pos个结点并返回它的值，若删除失败则停止程序运行 */
struct Node *deletePosition(struct Node *PtrToNode, int position);
/* 17.从单链表中删除值为x的第一个结点，若删除成功则返回1,否则返回0 */
struct Node *deleteElement(struct Node *PtrToNode, ElementType deleteElement); 
/* 18.交换2个元素的位置 */
struct Node *exchangElement(struct Node *PtrToNode, ElementType x, ElementType y);
#ifdef __cplusplus
}
#endif
#endif
