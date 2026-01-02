// Doubly Linear
#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class DoublyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        DoublyLL()
        {
            cout << "Object of DoublyLL gets created\n";
            this->first=NULL;
            this->iCount=0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new NODE();

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(this->first == NULL)
            {
                this->first = newn;
            }
            else
            {
                newn->next = this->first;
                this->first->prev = newn;
                this->first = newn;
            }

            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            newn = new NODE();

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(this->first == NULL)
            {
                this->first = newn;
            }
            else
            {
                PNODE temp = NULL;
                temp = this->first;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newn;
                newn->prev = temp; 
                
            }

            this->iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
            int iCnt=0;
            PNODE temp = NULL;
            PNODE newn= NULL;

            int iSize = Count();

            if(pos < 1 || pos > iSize+1)
            {
                cout << "Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                this->InsertFirst(no);
            }
            else if(pos == iSize + 1)
            {
                this->InsertLast(no);
            }
            else
            {
                newn = new NODE();

                newn->data= no;
                newn->next=NULL;
                newn->prev = NULL;

                temp = this->first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp=temp->next;
                }
                newn->next=temp->next;
                temp->next=newn;

                newn->prev = temp;
                newn->next->prev = newn;

                this->iCount++;
            }
        }

        void DeleteFirst()
        {
            if(this->first == NULL)
            {
                return;
            }
            else if(this->first -> next == NULL)
            {
                delete this->first;
                this->first = NULL;
            }
            else
            {
                this->first = this->first->next;
                delete this->first->prev;
                this->first->prev = NULL;
            }

            this->iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;
            PNODE target = NULL;
            if(this->first == NULL)
            {
                return;
            }
            else if(this->first -> next == NULL)
            {
                delete this->first;
                this->first = NULL;
            }
            else
            {
                temp = this->first;
                while(temp->next->next != NULL)
                {
                    temp=temp->next;
                }
                target = temp->next;

                delete target;
                temp->next = NULL;
            }

            this->iCount--;
        }

        void DeleteAtPos(int pos)
        {
            int iCnt=0;
            PNODE temp = NULL;
            PNODE target = NULL;

            int iSize = Count();

            if(pos < 1 || pos > iSize)
            {
                cout << "Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                this->DeleteFirst();
            }
            else if(pos == iSize)
            {
                this->DeleteLast();
            }
            else
            {
                temp = this->first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp=temp->next;
                }
                target = temp->next;
                temp->next = target->next;
                delete target;
                temp->next->prev = temp;

                this->iCount--;
            }
        }

        void Display()
        {
            PNODE temp = NULL;
            temp = first;

            while(temp != NULL)
            {
                cout << " | " << temp->data << " | -> ";
                temp=temp->next;
            }
            cout<<"\n";

            //Other way
            // for(int iCnt=1; iCnt<=iCount; iCnt++)
            // {
            //     cout << " | " << temp->data << " | -> ";
            //     temp=temp->next;
            // }
            // cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    int iRet=0;
    DoublyLL obj;

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