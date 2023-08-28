//done.
#include<iostream>
using namespace std;
class node{             //defining and declaring class node.
    public:             
    int data;           
    node *next;
        node()          //constructors for class node.
        {
        data=0;         
        next=NULL;  
        }   
    }*head,*tail;
class linkedlist{
    public:        
        node *head;         
        node *tail;
        int n;
        int ifsort;     //it'll check if sorting is done or not.
        //declaring the functions.
        void display();
        void insert(int data);
        linkedlist()    //constructor for linkedlist class.
        {
            head=NULL ;
            tail=NULL;
            n=0;
        }
};
void linkedlist::insert(int number)         //defining insert function.
    {
        node *temp=new node;
        temp->data=number;
        if(head==NULL)          //if initially no nodes are present.
        {
            head=temp;          //the new node is the head
            tail=temp;          //and the tail.
            n++;                //no.  of node =1
        }   
        else                    //if some at least 1 node is present.
        {
            tail->next=temp;    //tail points to temp.
            tail=temp;          //temp is the new tail.
            n++;                //increment in no. of nodes.
        }
};
void linkedlist::display()
    {
        node *slider=head;      //a slider is pointed to head.
        while(slider!=NULL)     //condition for which the while function ceases to run.
            {
                cout<<slider->data;     
                cout<<"->";
                slider=slider->next;    //slider points to its next node.
            }
        cout<<"NULL"<<endl;             
    }
class bubble{                       //bubble class is created in which the required functions are present.
    public:
    void bubblesort(node *head);    //bubblesort for linkedlist.
    void bubblesortarray(int arr[],int size);   //bubblesort for array.
};
void bubble::bubblesort(node *head)         //defining the bubblesort function.
    {
    int stamp;                  //an variable to hold the the to be swapped numbers temporarily.
    node *slider2=head;
    int k=0;                    //counting no. of nodes.
        while(slider2!=NULL)
        {
            slider2=slider2->next;
            k++;
        }
    slider2=head;           //again assigining slider2 to the head. 
    //start of bubble sort.     
        for(int i=0;i<k-1;i++)  //first loop of bubblesort.
            {
                for(int j=0;j<k-1-i;j++)    //second loop of bubblesort.
                {
                    if(slider2->data>(slider2->next)->data)   //conditons for swapping.
                        {
                            //swapping.
                            stamp=slider2->data;             
                            slider2->data=(slider2->next)->data;
                            (slider2->next)->data=stamp;
                        }
                slider2=slider2->next;          
                }
            slider2=head;       //after completion of each pass of the first loop the slider2 pointer points to head.
            }
    node *slider3=head;         //printing the sorted linked list.        
    while(slider3!=NULL)        //conditions for which the printing will stop.
        {
            cout<<slider3->data;    
            cout<<"->";
            slider3=slider3->next;
        }
        cout<<"NULL"<<endl;
    }
void bubble::bubblesortarray(int *arr,int size) //defining bubblesortarray for the array.
{   
    int temp=0;                                 //intitilizing a variable for holding values during the swap.             
    for(int count=0;count<size-1;count++)
        {
            for(int count1=0;count1<size-1-count;count1++)  //first loop of bubblesort.
                {
                    if(arr[count1]>arr[count1+1])           //second loop of bubblesort.
                        {
                            temp=arr[count1];
                            arr[count1]=arr[count1+1];
                            arr[count1+1]=temp;
                        }
                }
        }
}
int main()            
    {
    bubble b;           //object of class bubble.
    linkedlist l;       //object of linkedlist class.
    l.insert(9);        //input of numbers in the linked list.
    l.insert(87);
    l.insert(89);
    l.insert(7);
    l.insert(76);
    l.insert(65);
    l.insert(23423);
    l.insert(754);
    l.insert(8868);
    l.insert(43);
    l.display();    //display of unsorted linked list.
    b.bubblesort(l.head);   //sorting and display of sorted linked list.
    int arr[9];     //declaring an array.
                     cout<<"Enter numbers for array"<<endl;
                     for(int z=0;z<9;z++)
                     cin>>arr[z];
    b.bubblesortarray(arr,9);       //sorting of the array.
    cout<<"The sorted array is"<<endl;
    for(int p=0;p<9;p++)    
    cout<<arr[p]<<endl;
    return 0;
    }
