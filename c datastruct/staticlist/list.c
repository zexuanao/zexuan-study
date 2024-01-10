#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 定义静态链表的最大长度

// 静态链表结点的定义
typedef struct {
    int data; // 存储的数据
    int next; // 指向下一个结点的索引
} Node;

// 初始化静态链表
void initList(Node list[], int *head) {
    for (int i = 0; i < MAX_SIZE - 1; ++i) {
        list[i].next = i + 1; // 每个结点的下一个结点索引指向下一个位置
    }
    list[MAX_SIZE - 1].next = -1; // 最后一个结点作为链表的末尾，next置为-1
    *head = -1; // 头指针初始指向-1，表示空链表
}

// 在指定位置插入结点
int insertNode(Node list[], int *head, int pos, int data) {
    if (pos < 0 || pos >= MAX_SIZE) {
        return 0; // 位置不合法
    }

    int newNodeIndex = list[0].next; // 获取一个空闲结点的索引
    if (newNodeIndex == -1) {
        return 0; // 静态链表已满
    }

    list[0].next = list[newNodeIndex].next; // 更新空闲结点的索引

    list[newNodeIndex].data = data; // 设置新结点的数据
    if (pos == 0) {
        list[newNodeIndex].next = *head;
        *head = newNodeIndex; // 新结点成为头结点
    } else {
        int curr = *head;
        for (int i = 0; i < pos - 1; ++i) {
            curr = list[curr].next;
            if (curr == -1) {
                return 0; // 位置超出范围
            }
        }
        list[newNodeIndex].next = list[curr].next;
        list[curr].next = newNodeIndex;
    }

    return 1; // 插入成功
}

// 删除指定位置的结点
int deleteNode(Node list[], int *head, int pos) {
    if (pos < 0 || *head == -1) {
        return 0; // 空链表或位置不合法
    }

    int delIndex;
    if (pos == 0) {
        delIndex = *head;
        *head = list[*head].next; // 删除头结点
    } else {
        int curr = *head;
        for (int i = 0; i < pos - 1; ++i) {
            curr = list[curr].next;
            if (curr == -1 || list[curr].next == -1) {
                return 0; // 位置超出范围
            }
        }
        delIndex = list[curr].next;
        list[curr].next = list[delIndex].next;
    }

    list[delIndex].next = list[0].next; // 将删除的结点的 next 指针指向空闲结点
    list[0].next = delIndex; // 将删除的结点标记为空闲结点

    return 1; // 删除成功
}

// 输出静态链表的内容
void printList(Node list[], int head) {
    if (head == -1) {
        printf("Empty List\n");
        return;
    }

    printf("List: ");
    int curr = head;
    while (curr != -1) {
        printf("%d ", list[curr].data);
        curr = list[curr].next;
    }
    printf("\n");
}

int main() {
    Node staticList[MAX_SIZE]; // 静态链表数组
    int head; // 头指针

    initList(staticList, &head); // 初始化静态链表

    // 在第 0 个位置插入元素
    insertNode(staticList, &head, 0, 10);
    printList(staticList, head); // 打印链表

    // 在第 1 个位置插入元素
    insertNode(staticList, &head, 1, 20);
    printList(staticList, head); // 打印链表

    // 删除第 1 个位置的元素
    deleteNode(staticList, &head, 1);
    printList(staticList, head); // 打印链表

    return 0;
}
