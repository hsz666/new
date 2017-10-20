#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Udecide_n();
int  Decide_n();
void Delete_n(int n);           //����ռ���ͷ�
void Delete_u();                //����ռ���ͷ�
typedef struct Pnode            //һ���˵���Ϣ:�����������õķ���
{
    float number;              //�������
    float absoluten_n;         //��ƽ���ľ���ֵ
    int grade;                   //��õķ���
}Pnode;
typedef struct PNode
{
    float number;              //�������
    float absoluten_n;         //��ƽ���ľ���ֵ
    int grade;                   //��õķ���
    struct PNode * next;
};
typedef struct Decide_Node     //����������Ϸ�����Ľṹ��
{
    float average;               //�ƽ���ֵ
    Pnode *node;               //
}Decide_Node;
typedef struct U_decide_Node   //δ����������Ϸ�����Ľṹ��
{
    float average;             //�ƽ���ֵ
    PNode *node;               //ÿ�����ݵĳ�Ա
    struct U_decide_Node  *next;
}U_decide_Node;
Decide_Node   *Dhead;         //������Ϸʹ�õ��ǽṹ���飬�ṹ�����ͷ��
U_decide_Node *udhead, *udnext, *udtail;  //δ��������Ϸ�����ģ���Ϸÿһ����һ���ṹ������ʾ��ʹ�ýṹ��3��ָ��
PNode *phead, *pnext, *ptail;  //ÿһ����Ϸ�µģ��μӵ���Ϸ�����ǲ�ȷ�����ǣ�ʹ�ýṹ����ʾ�������Ǳ�ʾ�˽ṹ��3��ָ��
void main()
{
    int i;
    int n;                   //֪����Ϸ������   ��Ϸ����
    printf("\t\t\t\t������������������\n");
    printf("\t\t\t\t��              ��\n");
    printf("\t\t\t\t��  �ƽ����Ϸ  ��\n");
    printf("\t\t\t\t��              ��\n");
    printf("\t\t\t\t������������������\n");;
    printf("��Ϸ�������£�\n");
    printf("N��ͬѧ��Nͨ������10����ÿ��дһ��0~100֮��������� (������0��100)");
    printf("�������У���������������ֵ�ƽ��ֵ��Ȼ�����0.618����ν�ƽ�ָ����," );
    printf("�õ�Gֵ���ύ���������G��ȡ����ֵ����ͬѧ�õ�N�֣���G��Զ��ͬѧ�õ���2�֣�����ͬѧ��0�֡�\n");
    printf("1.û�о�����Ϸ���м��֣�����һ��\n2.������Ϸ���м���\n3.�˳�\n"); //ÿһ�ֵĴ�����N��
next2:printf("��ѡ��ѡ��:");
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
               printf("����������\n");
               goto next2;
    }
    }
    printf("лл�ݹ�\n");
    Delete_n(n);                             //�ͷſռ�
    Delete_u();                              //�ͷſռ�
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
    int n;           //����Ϸ��������
    int i;           //��¼��Ϸ�浽�ڼ���
    int m;           //��һ����Ϸ���μ���Ϸ������
    int j;           //��һ����Ϸ�У�����Ϸ����
    float sum;         //һ����Ϸ��ȫ����������ֺ�,ͬʱҲ�ǻƽ���ֵ
    float abmax;       //���������ƽ�����ľ���ֵ���ֵ
    float abmin;       //���������ƽ�����ľ���ֵ��Сֵ
    int x;           //�Ƿ����ÿһ�ֵ��������Ϣ
    printf("������Ҫ���е�����:");
    scanf("%d", &n);
    Dhead = (Decide_Node*)malloc(n*sizeof(Decide_Node));
    if (Dhead == NULL)
    {
        printf("Decide_Node�ռ�����ʧ��\n");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {

        printf("�������м����˽�����Ϸ:");
        scanf("%d", &m);
        Dhead[i].node = (Pnode *)malloc(m*sizeof(Pnode));
        if (Dhead[i].node == NULL)
        {
            printf("Dhead[%d].node����ռ�ʧ��\n", i);
            exit(1);
        }
        sum = 0;
        for (j = 0; j < m; j++)
        {
            printf("���%d������������:", j + 1);
            scanf("%f", &Dhead[i].node[j].number);
            sum = sum + Dhead[i].node[j].number;
        }
        sum = sum / j*0.618;
        Dhead[i].average = sum;
        abmax = 0;
        abmin = 100;
        for (j = 0; j < m; j++)                               //����ÿһ�������������ƽ�ľ���ֵ�������ҳ�������ֵ����С����ֵ
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
        for (j = 0; j < m; j++)                                 //��ÿһ���μ���Ϸ���˴��
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
        printf("�ƽ��ֵ��%.2f\n",Dhead[i].average);
        printf("������Եĵ÷����\n");
        for (j = 0; j < m; j++)
        {
            printf("��%d���˵÷���;%d\n",j+1,Dhead[i].node[j].grade);
        }
next1:    printf("�Ƿ�Ҫ�����������������\n");
        printf("1,��\t\t2,��\n");
        printf("������ѡ��:");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
        {
                  for (j = 0; j < m; j++)
                  {
                      printf("��%d�������������:%d\n", j + 1,(int)Dhead[i].node[j].number);
                  }
                  break;
        }
        case 2:break;
        default:
        {
                   printf("������Ч������������\n");
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
    int i;             //�Ƿ�����һ���˲�����Ϸ��һ�����еı�־
    int j;             //�Ƿ������һ����Ϸ�ı�־
    int n;             //ÿ����Ϸ������Ϸ����
    float sum;         //һ����Ϸ��ȫ����������ֺ�,ͬʱҲ�ǻƽ���ֵ
    float abmax;       //���������ƽ�����ľ���ֵ���ֵ
    float abmin;       //���������ƽ�����ľ���ֵ��Сֵ
    int x;             //�Ƿ����ÿһ�ֵ��������Ϣ
    udhead = (U_decide_Node *)malloc(sizeof(U_decide_Node));
    if (!udhead)
    {
        printf("udhead�ռ�����ʧ��\n");
        exit(1);
    }
    udtail = udhead;
    while (1)
    {
        udnext = (U_decide_Node *)malloc(sizeof(U_decide_Node));
        if (!udnext)
        {
            printf("udnext�ռ�����ʧ��\n");
            exit(1);
        }
        udnext->next = NULL;
        udtail->next = udnext;
        udtail = udnext;
        phead = (PNode *)malloc(sizeof(PNode));
        if (!phead)
        {
            printf("phead�ռ�����ʧ��\n");
            exit(1);
        }
        phead->next = NULL;
        udnext->node = phead;
        ptail = phead;
        sum = 0;
        n = 0;
        printf("����������3����\n");
        while (1)                                 //����ÿһ����Ϸ������
        {
            pnext = (PNode *)malloc(sizeof(PNode));
            if(!pnext)
            {
                printf("pnext�ռ�����ʧ��\n");
                exit(1);
            }
            pnext->next = NULL;
            ptail->next = pnext;
            ptail = pnext;
            printf("���%d��������:",n+1);
            scanf("%f",&pnext->number);
            n++;
            sum = sum + pnext->number;
            if (n >=3)
            {
    next3:        printf("�Ƿ�Ҫ������:\n");
                printf("1.��\t\t2.����\n");
                printf("��ѡ��ѡ��:");
                scanf("%d", &i);
                if (i == 2)
                {
                    break;
                }
                else if (i != 1)
                {
                    printf("������Ч����������\n");
                    goto next3;
                }
            }
        }
        sum = sum / n*0.618;
        udnext->average=sum;
        abmin = 100;
        abmax = 0;
        pnext = phead->next;
        while (pnext)                                //����ÿһ�������������ƽ�ľ���ֵ�������ҳ�������ֵ����С����ֵ
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
        while (pnext)                                // ��ÿһ���μ���Ϸ���˴��
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
        printf("�ƽ��ֵ��%.2f\n", udnext->average);
        printf("������Եĵ÷����:\n");
        pnext = phead->next;
        n = 0;
        while(pnext)
        {
            printf("��%d���˵÷���;%d\n", n+1, pnext->grade);
            n++;
            pnext = pnext->next;
        }
next4:    printf("�Ƿ�Ҫ�����������������:\n");
        printf("1,��\t\t2,��\n");
        printf("������ѡ��:");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
        {
                  for (n = 0,pnext=phead->next; pnext; n++, pnext = pnext->next)
                  {
                      printf("��%d�������������:%d\n", n + 1, (int)pnext->number);
                  }
                  break;
        }
        case 2:break;
        default:
        {
                   printf("������Ч������������\n");
                   goto next4;
        }
        }
next5:    printf("�Ƿ�Ҫ�ٽ���һ����Ϸ:\n");
        printf("1.��\t\t2.����\n");
        printf("��ѡ��ѡ��:");
        scanf("%d", &j);
        if (j == 2)
        {
            break;
        }
        else if (j != 1)
        {
            printf("������Ч����������\n");
            goto next5;
        }

    }    
}