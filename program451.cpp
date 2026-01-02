//singly circual
#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCL()
        {
            cout << "Object of SinglyCL gets created\n";
            this->first=NULL;
            this->last=NULL;
            iCount=0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn->data = no;
            newn->next = NULL; 

            if((first == NULL) && (last == NULL))
            {
                first = newn;
                last = newn;
            }
            else
            {
                newn->next = first;
                first = newn;
            }
            last->next=first;

            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if((first == NULL)  && (last == NULL))
            {
                first = newn;
                last = newn;
            }
            else
            {
                last->next=newn;
                last = newn;
            }

            last->next = first;

            iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
            if(pos < 1 || pos > iCount+1)
            {
                cout << "Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount + 1)
            {
                InsertLast(no);
            }
            else 
            {
                int iCnt=0;
                PNODE temp;
                PNODE newn=NULL;
                newn = new NODE;

                newn->data=no;
                newn->next=NULL;

                temp = first;
                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp=temp->next;
                }
                newn->next = temp->next;
                temp->next=newn;
                
                iCount++;
            }
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if((first == NULL) && (last == NULL))
            {
                return;
            }
            else if(first == last)
            {
                delete first;
                first = NULL;
                last = NULL;
            }
            else
            {
                temp = first;
                first = temp->next;
                delete temp;
            }

            last->next = first;
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if((first == NULL) && (last == NULL))
            {
                return;
            }
            else if(first == last)
            {
                delete first;
                first = NULL;
                last = NULL;
            }
            else
            {
                temp = first;
                while(temp->next->next != first)
                {
                    temp=temp->next;
                }
                delete temp->next;
                last = temp;
            }

            last->next = first;
            iCount--;
        }

        void DeleteAtPos(int pos)
        {
            if(pos < 1 || pos > iCount)
            {
                cout << "Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else 
            {
                int iCnt = 0;
                PNODE temp = NULL;
                PNODE target = NULL;

                temp=first;
                for(iCnt=1; iCnt < pos - 1; iCnt++)
                {
                    temp=temp->next;
                }

                target = temp->next;
                temp->next = target->next;
                delete target;

                iCount--;
            }
        }

        void Display()
        {
            int iCnt=0;
            PNODE temp = NULL;
            temp = first;
            
            for(iCnt = 1; iCnt <= iCount; iCnt++)
            {
                cout<<" | "<<temp->data<<" | -> ";
                temp=temp->next;
            }
            cout<<" \n ";

        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    int iRet=0;
    SinglyCL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet=obj.Count();
    cout << "Number of nodes are: " << iRet << "\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet=obj.Count();
    cout << "Number of nodes are: " << iRet << "\n";

    obj.DeleteFirst();

    obj.Display();

    iRet=obj.Count();
    cout << "Number of nodes are: " << iRet << "\n";

    obj.DeleteLast();

    obj.Display();

    iRet=obj.Count();
    cout << "Number of nodes are: " << iRet << "\n";

    obj.InsertAtPos(105, 4);

    obj.Display();

    iRet=obj.Count();
    cout << "Number of nodes are: " << iRet << "\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet=obj.Count();
    cout << "Number of nodes are: " << iRet << "\n";

    return 0;
}