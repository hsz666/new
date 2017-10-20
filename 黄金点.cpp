#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Udecide_n();
int  Decide_n();
void Delete_n(int n);           //申请空间的释放
void Delete_u();                //申请空间的释放
typedef struct Pnode            //一个人的信息:输入的数，获得的分数
{
    float number;              //输入的数
    float absoluten_n;         //与黄金点差的绝对值
    int grade;                   //获得的分数
}Pnode;
typedef struct PNode
{
    float number;              //输入的数
    float absoluten_n;         //与黄金点差的绝对值
    int grade;                   //获得的分数
    struct PNode * next;
};
typedef struct Decide_Node     //决定进行游戏轮数的结构体
{
    float average;               //黄金点的值
    Pnode *node;               //
}Decide_Node;
typedef struct U_decide_Node   //未决定进行游戏轮数的结构体
{
    float average;             //黄金点的值
    PNode *node;               //每轮数据的成员
    struct U_decide_Node  *next;
}U_decide_Node;
Decide_Node   *Dhead;         //决定游戏使用的是结构数组，结构数组的头部
U_decide_Node *udhead, *udnext, *udtail;  //未决定的游戏轮数的，游戏每一局由一个结构体来表示，使用结构的3个指针
PNode *phead, *pnext, *ptail;  //每一轮游戏下的，参加的游戏的人是不确定得是，使用结构来表示，这里是表示人结构的3个指针
void main()
{
    int i;
    int n;                   //知道游戏轮数的   游戏轮数
    printf("\t\t\t\t┌───────┐\n");
    printf("\t\t\t\t│              │\n");
    printf("\t\t\t\t│  黄金点游戏  │\n");
    printf("\t\t\t\t│              │\n");
    printf("\t\t\t\t└───────┘\n");;
    printf("游戏规则如下：\n");
    printf("N个同学（N通常大于10），每人写一个0~100之间的有理数 (不包括0或100)");
    printf("交给裁判，裁判算出所有数字的平均值，然后乘以0.618（所谓黄金分割常数）," );
    printf("得到G值。提交的数字最靠近G（取绝对值）的同学得到N分，离G最远的同学得到－2分，其他同学得0分。\n");
    printf("1.没有决定游戏进行几轮，先来一次\n2.决定游戏进行几轮\n3.退出\n"); //每一轮的次数是N次
next2:printf("请选择选项:");
    scanf("%d",&i);
    switch (i)
    {
    case 1: Udecide_n(); break;
    case 2:
    {
              n = Decide_n();

              break;
    }
    case 3:; break;
    default:
    {
               printf("请重新输入\n");
               goto next2;
    }
    }
    printf("谢谢惠顾\n");
    Delete_n(n);                             //释放空间
    Delete_u();                              //释放空间
}
void Delete_n(int n)
{
    int i;
    for (i = 0; i < n;i=0)
    {
        free(Dhead[i].node);
    }
    free(Dhead);
}
int Decide_n()
{
    int n;           //玩游戏的总轮数
    int i;           //记录游戏玩到第几轮
    int m;           //玩一轮游戏，参加游戏的人数
    int j;           //在一轮游戏中，玩游戏的人
    float sum;         //一轮游戏中全部输入的数字和,同时也是黄金点的值
    float abmax;       //输入的数与黄金点相差的绝对值最大值
    float abmin;       //输入的数与黄金点相差的绝对值最小值
    int x;           //是否输出每一轮的输入的信息
    printf("请输入要进行的轮数:");
    scanf("%d", &n);
    Dhead = (Decide_Node*)malloc(n*sizeof(Decide_Node));
    if (Dhead == NULL)
    {
        printf("Decide_Node空间申请失败\n");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {

        printf("请输入有几个人进行游戏:");
        scanf("%d", &m);
        Dhead[i].node = (Pnode *)malloc(m*sizeof(Pnode));
        if (Dhead[i].node == NULL)
        {
            printf("Dhead[%d].node申请空间失败\n", i);
            exit(1);
        }
        sum = 0;
        for (j = 0; j < m; j++)
        {
            printf("请第%d个人输入数字:", j + 1);
            scanf("%f", &Dhead[i].node[j].number);
            sum = sum + Dhead[i].node[j].number;
        }
        sum = sum / j*0.618;
        Dhead[i].average = sum;
        abmax = 0;
        abmin = 100;
        for (j = 0; j < m; j++)                               //计算每一个输入的数字与黄金的绝对值，并且找出最大绝对值和最小绝对值
        {
            Dhead[i].node[j].absoluten_n = abs(Dhead[i].node[j].number - sum);
            if (abmax < Dhead[i].node[j].absoluten_n)
            {
                abmax = Dhead[i].node[j].absoluten_n;
            }
            if (abmin>Dhead[i].node[j].absoluten_n)
            {
                abmin = Dhead[i].node[j].absoluten_n;
            }
        }
        for (j = 0; j < m; j++)                                 //给每一个参加游戏的人打分
        {
            if (Dhead[i].node[j].absoluten_n == abmax)
            {
                Dhead[i].node[j].grade = -2;
            }
            else if (Dhead[i].node[j].absoluten_n == abmin)
            {
                Dhead[i].node[j].grade = m;
            }
            else
            {
                Dhead[i].node[j].grade = 0;
            }
        }
        printf("黄金点值：%.2f\n",Dhead[i].average);
        printf("输出各自的得分情况\n");
        for (j = 0; j < m; j++)
        {
            printf("第%d个人得分是;%d\n",j+1,Dhead[i].node[j].grade);
        }
next1:    printf("是否要输出所有人数的数字\n");
        printf("1,是\t\t2,否\n");
        printf("请输入选项:");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
        {
                  for (j = 0; j < m; j++)
                  {
                      printf("第%d个人输入的数是:%d\n", j + 1,(int)Dhead[i].node[j].number);
                  }
                  break;
        }
        case 2:break;
        default:
        {
                   printf("输入无效，请重新输入\n");
                   goto next1;
        }
        }
    }
    return n;
}
void Delete_u()
{
    udnext = udhead->next;
    while (udnext)
    {
        phead = udnext->node;
        pnext = phead->next;
        while (pnext)
        {
            phead->next == pnext->next;
            free(pnext);
            pnext = phead->next;
        }
        free(phead);
        udhead->next = udnext->next;
        free(udnext);
        udnext = udhead->next;
    }
    free(udhead);
}
void Udecide_n()
{
    int i;             //是否还有下一个人参与游戏在一轮中中的标志
    int j;             //是否进行下一轮游戏的标志
    int n;             //每轮游戏参与游戏的人
    float sum;         //一轮游戏中全部输入的数字和,同时也是黄金点的值
    float abmax;       //输入的数与黄金点相差的绝对值最大值
    float abmin;       //输入的数与黄金点相差的绝对值最小值
    int x;             //是否输出每一轮的输入的信息
    udhead = (U_decide_Node *)malloc(sizeof(U_decide_Node));
    if (!udhead)
    {
        printf("udhead空间申请失败\n");
        exit(1);
    }
    udtail = udhead;
    while (1)
    {
        udnext = (U_decide_Node *)malloc(sizeof(U_decide_Node));
        if (!udnext)
        {
            printf("udnext空间申请失败\n");
            exit(1);
        }
        udnext->next = NULL;
        udtail->next = udnext;
        udtail = udnext;
        phead = (PNode *)malloc(sizeof(PNode));
        if (!phead)
        {
            printf("phead空间申请失败\n");
            exit(1);
        }
        phead->next = NULL;
        udnext->node = phead;
        ptail = phead;
        sum = 0;
        n = 0;
        printf("请至少输入3个数\n");
        while (1)                                 //构建每一轮游戏的链表
        {
            pnext = (PNode *)malloc(sizeof(PNode));
            if(!pnext)
            {
                printf("pnext空间申请失败\n");
                exit(1);
            }
            pnext->next = NULL;
            ptail->next = pnext;
            ptail = pnext;
            printf("请第%d个人输入:",n+1);
            scanf("%f",&pnext->number);
            n++;
            sum = sum + pnext->number;
            if (n >=3)
            {
    next3:        printf("是否要再输入:\n");
                printf("1.是\t\t2.不是\n");
                printf("请选择选项:");
                scanf("%d", &i);
                if (i == 2)
                {
                    break;
                }
                else if (i != 1)
                {
                    printf("输入无效请重新输入\n");
                    goto next3;
                }
            }
        }
        sum = sum / n*0.618;
        udnext->average=sum;
        abmin = 100;
        abmax = 0;
        pnext = phead->next;
        while (pnext)                                //计算每一个输入的数字与黄金的绝对值，并且找出最大绝对值和最小绝对值
        {
            pnext->absoluten_n = abs(pnext->number - sum);
            if (abmax < pnext->absoluten_n)
            {
                abmax =pnext->absoluten_n;
            }
            if (abmin>pnext->absoluten_n)
            {
                abmin = pnext->absoluten_n;
            }
            pnext = pnext->next;                  
        }
        pnext = phead->next;
        while (pnext)                                // 给每一个参加游戏的人打分
        {
            if (pnext->absoluten_n == abmax)
            {
                pnext->grade = -2;
            }
            else if (pnext->absoluten_n == abmin)
            {
                pnext->grade = n;
            }
            else
            {
                pnext->grade = 0;
            }
            pnext=pnext->next;
        }
        printf("黄金点值：%.2f\n", udnext->average);
        printf("输出各自的得分情况:\n");
        pnext = phead->next;
        n = 0;
        while(pnext)
        {
            printf("第%d个人得分是;%d\n", n+1, pnext->grade);
            n++;
            pnext = pnext->next;
        }
next4:    printf("是否要输出所有人数的数字:\n");
        printf("1,是\t\t2,否\n");
        printf("请输入选项:");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
        {
                  for (n = 0,pnext=phead->next; pnext; n++, pnext = pnext->next)
                  {
                      printf("第%d个人输入的数是:%d\n", n + 1, (int)pnext->number);
                  }
                  break;
        }
        case 2:break;
        default:
        {
                   printf("输入无效，请重新输入\n");
                   goto next4;
        }
        }
next5:    printf("是否要再进行一轮游戏:\n");
        printf("1.是\t\t2.不是\n");
        printf("请选择选项:");
        scanf("%d", &j);
        if (j == 2)
        {
            break;
        }
        else if (j != 1)
        {
            printf("输入无效请重新输入\n");
            goto next5;
        }

    }    
}