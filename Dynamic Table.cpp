#include <bits/stdc++.h>

using namespace std;

int *table =(int*) malloc(sizeof(int));
int max_size =1;
int len=0;
void add()
{
    cout<<"Given number :";
    int item;
    cin>>item;
    if (len == max_size)
    {

        max_size = 2 * max_size;
        int *temp_table = (int*) malloc(sizeof(int));
        for (int i = 0; i < len; i++)
        {
            temp_table[i] = table[i];
        }
        delete [] table;

        table = temp_table;

    }
    table[len]=item;
    len++;
}


void display()
{
    for (int i = 0; i < len; i++)
    {
        cout << table[i] << "\t";
    }
}

void findnum(int num)
{
    int c=0;
    for (int i = 0; i < len; i++)
    {
        if (table[i] == num)
            cout << "Number is Found and Position is " << (i + 1) << endl;
            c=-1;
    }
    if(c==0)
    cout << "Number did not found" << endl;
}

int maximum()
{
    int max=table[0];
    for(int i=1; i<len; i++)
    {
        if(table[i]>max)
        {
            max=table[i];
        }
    }
    return max;
}

int minimum()
{
    int min=table[0];
    for(int i=1; i<len; i++)
    {
        if(table[i]<min)
        {
            min=table[i];
        }
    }
    return min;
}

int sum()
{
    int sum=0;
    for(int i=0; i<len; i++)
    {
        sum+= table[i];
    }
    return(sum);
}

void sorting()
{
    int i,j;
    int swap;
    for(i=0; i<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(table[j]<table[i])
            {
                swap=table[i];
                table[i]=table[j];
                table[j]=swap;
            }
        }
    }

}


void delete_ele(int data)
{
    for(int i=0; i<len; i++)
    {
        if(table[i]==data)
        {
            for(int j=0; j<(len-i-1); j++)
            {
                table[i+j]=table[i+j+1];
            }
            table[len-1]=NULL;
            len--;
        }

    }
    if (len == max_size/2)
    {

        max_size =max_size/2;

        int *temp_table = (int*) malloc(sizeof(int));

        for (int i = 0; i < len; i++)
        {
            temp_table[i]=table[i];
        }
        delete [] table;
        table = temp_table;
        for(int i=0; i<len; i++)
        {
            table[i] = temp_table[i];
        }

    }

}

int main()
{
    int  output,input, index;
    do
    {
        cout << "1. Insert Number" << endl;
        cout << "2. Print Dynamic Table" << endl;
        cout << "3. Find Number" << endl;
        cout << "4. Print Maximum Number" << endl;
        cout << "5. Print Minimum Number" << endl;
        cout << "6. Sum of all Elements" << endl;
        cout << "7. Sort Dynamic Table" << endl;
        cout << "8. Delete Element" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter Your Option :";
        cin >> index;
        switch (index)
        {
        case 1:
            add();
            cout<<endl;
            break;
        case 2:
            display();
            cout << endl;

            break;
        case 3:
            cout << "Searching Number :";
            cin >> input;
            findnum(input);
            break;
        case 4:
            output=maximum();
            cout<<"Maximum number is "<<output<<endl;
            break;
        case 5:
            output=minimum();
            cout<<"Minimum number is "<<output<<endl;
            break;
        case 6:
            output=sum();
            cout<<"Sum of all number is "<<output<<endl;
            break;
        case 7:
            sorting();
            display();
            cout<<endl;
            break;
        case 8:
            cout<<"Delete Value :";
            cin>>input;
            delete_ele(input);
            break;
        }
    }
    while (index != 9);
    cout<<"Maximum Size of the Dynamic Table is "<<max_size<<" and length is "<<len<<endl;
    delete [] table;
    exit(0);
}

