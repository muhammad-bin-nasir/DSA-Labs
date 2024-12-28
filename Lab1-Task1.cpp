#include <iostream>
using namespace std;

class Array
{
    private:
    int *arr = new int;
    int size;

    public:
    Array()
    {
        char temp;
        int temp2;

        cout<<"Do you want to give a size to array? (default size = 15) \n(y/n) "<<endl;
        cin>>temp;

        //An array of user defined size is created, or if user says so, of size 15 is created.

        if (temp=='y')
        {
            cout<<"Enter the size of array:"<<endl;
            cin>>temp2;
            arr[temp2];
            size = temp2;
        }
        else
        {
            cout<<"An array of size 15 is created."<<endl;
            arr[15];
            size = 15;
        }
    }

    void addArray()
    {
        char temp;
        cout<<"Do you want to give values? (if not, random values will be placed)\n(y/n)"<<endl;
        cin>>temp;

        //A for loop takes in user input for array, or automatically puts in 14 -> 0.

        if (temp=='y')
        {
            cout<<"Give the values of the indices\n";               
            for (int i=0;i<size;i++)
            {
                cout<<i+1<<"th index: ";
                cin>>arr[i];
                cout<<endl;
            }            
        }
        else
        {
            for (int i=0;i<size;i++)                                
            {
                arr[i] = size-1-i;
            }

        }
    }    

    void updateArray()
    {
        int temp,temp2;

        //User gives index and new value, which is placed.

        cout<<"WHich index do you want to update?\n";               
        cin>>temp;
        if (temp<0 || temp>=size)
        {
            cout<<"Invalid index."<<endl;
            return;
        }
        cout<<"Give the new value\n";
        cin>>temp2;
        arr[temp] = temp2;

    }

    void displayArray()
    {
        cout<<"The array is:"<<endl;
        cout<<"[ ";

        //Array is displayed using for loop. Cout statements used for better output.

        for (int i=0;i<size;i++)
        {
            cout<<arr[i];
            if (i!=size-1)                                            
            {
                cout<<" , ";
            }
            else
            {
                cout<<" ] ";
            }
        }
    }

    void deleteArray()
    {
        delete[] arr;
    }    
};

int main()
{
    Array obj;
    int temp;

    obj.addArray();

    //A while true loop is used to keep program from finishing, unless asked to do so.

    while (true)
    {
        cout<<endl<<"What do you want to do?(answer from 1 to)"<<endl
            <<"1. Update an element"<<endl
            <<"2. Display the array"<<endl
            <<"3. Delete the array"<<endl
            <<"4. Exit"<<endl;
        cin>>temp;
    
        if (temp==1)
        {
            obj.updateArray();
        }    

        else if (temp==2)
        {
            obj.displayArray();
        }

        else if (temp==3)
        {
            obj.deleteArray();
            break;
        }
        
        else if (temp==4)
        {
            break;
        }
        
        else
        {
            cout<<"Please give a valid input."<<endl;
        }
    }    

    cout<<"Program has reached completion."<<endl;

    return 0;
}