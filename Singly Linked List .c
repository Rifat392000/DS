#include<stdio.h>
#include<conio.h>
struct Node
{
    int data;
    struct Node *next;

};
struct Node *head=NULL;

void display()
{
    struct Node *d = head;
    while(d != NULL)

    {
        printf(" %d---> ", d->data);

        d = d->next ;

    }
}

void Insert()
{
    int k;

    printf("\n1. Insert node at beginning\n");
    printf("2. Insert node at any position\n");
    printf("3. Insert node at the end\n");
    printf("Choose your option : ");
    scanf("%d",&k);
    printf("\n");
    if(k==1)
    {
        struct Node *p=(struct Node*) malloc(sizeof(struct Node*));
        printf("Enter your value : ");
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            p->next=head;
            head=p;
        }
        printf("\n");
        display();
    }
    else if(k==2)
    {
        struct Node *p=(struct Node*) malloc(sizeof(struct Node*));
        int point ;
        printf("Enter your value : ");
        scanf("%d",&p->data);
        printf("Enter your position : ");
        scanf("%d",&point);
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            struct Node *temp=head,*temp1;
            for(int i=0; i<point; i++)
            {
                temp1=temp;
                temp=temp->next;
            }
            temp1->next = p;
            p->next=temp;
        }
        printf("\n");
        display();
    }
    else
    {
        struct Node *p=(struct Node*) malloc(sizeof(struct Node*));
        printf("Enter your value : ");
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            struct Node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=p;
        }
        printf("\n");
        display();
    }
    printf("\n");
}

void Delete()
{
    int k;
    printf("\n1. Delete node at beginning\n");
    printf("2. Delete node at any position\n");
    printf("3. Delete node at the end\n");
    printf("Choose your option : ");
    scanf("%d",&k);
    printf("\n");
    if(k==1)
    {
        struct Node *temp;
        if(head!=NULL)
        {
            temp = head;
            head=head->next;
        }
        free(temp);
        display();
    }
    else if(k==2)
    {
        int dv;
        printf("Which value do you want to delete : ");
        scanf("%d",&dv);
        struct Node *temp1,*temp;
        if(head!=NULL)
        {
            temp=head;
            while(temp->next!=NULL && temp->data!=dv)
            {
                temp1=temp;
                temp=temp->next;
            }
            if(temp->data==dv)
            {
                temp1->next=temp->next;
                free(temp);
            }

        }
        display();

    }
    else
    {
        struct Node *temp1,*temp;
        if(head!=NULL)
        {
            temp= head;
            while(temp->next!=NULL)
            {
                temp1=temp;
                temp=temp->next;
            }
        }
        temp1->next=NULL;
        free(temp);
        display();
    }
    printf("\n");
}

void Reverse()
{
    struct Node *temp=NULL,*temp1;
    if(head!=NULL)
    {
        while(head != NULL)
        {
            temp1=head->next;
            head->next=temp;
            temp=head;
            head=temp1;
        }
        head=temp;
    }
    display();
    printf("\n");
}
void DuplicateRemove()
{
    struct Node *temp,*temp1,*t;
    temp=head;
    while(temp!=NULL&&temp->next!=NULL)
    {
        temp1=temp;
        while(temp1->next!=NULL)
        {
            if(temp->data==temp1->next->data)
            {
                t=temp1->next;
                temp1->next= temp1->next->next;
                free(t);
            }
            else
                temp1=temp1->next;

        }
        temp=temp->next;

    }
    display();
    printf("\n");
}
int main()
{
    while(1)
    {
        int n;
        printf("________________LinkedList____________________\n\n1.Insert\n2.Delete\n3.Reverse\n4.Duplicate Remove\n5.Exit\nChoose your option : ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Reverse();
            break;
             case 4:
            DuplicateRemove();
            break;
        default:
            exit(0);

        }
    }
    getch();
}
