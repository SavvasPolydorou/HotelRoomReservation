#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
void filefout(int A[],string B[],int C[],string D[],double sum[],int N)
{
    int i;
    char filename[30];
    cout<<"Give a filename:";
    cin>>filename;
    ofstream fout(filename);
        fout<<"Room_Number "<<setw(10)<<"Type "<<setw(10)<<" Price "<<setw(10)<<" Reserved "<<setw(10)<<" Total price "<<endl;
        for(i=0;i<N;i++)
            fout<<A[i]<<setw(20)<<B[i]<<setw(6)<<C[i]<<setw(6)<<D[i]<<setw(9)<<"$"<<sum[i]<<endl;
            fout.close();
}

int main()
{
ifstream fin("hotels.txt");
int days,i,counter=0,choice;
int user_room_number,room_number[5],price[5];
double sum_timi[5];
bool found;
string type[5],reserved[5],temp;
fin>>temp>>temp>>temp>>temp;
while(!fin.eof())
{
    fin>>room_number[counter];
    fin>>type[counter];
    fin>>price[counter];
    fin>>reserved[counter];
    counter++;
}
do
{
    cout<<"1.Present the status of all rooms"<<endl;
    cout<<"2.Reserve room"<<endl;
    cout<<"3.Cancel reservation"<<endl;
    cout<<"4.Room checkout"<<endl;
    cout<<"5.Save"<<endl;
    cout<<"6.Exit"<<endl;
    cout<<"Give choice 1-6"<<endl;
    cin>>choice;
    cout<<endl;
switch(choice)
{
    case 1:
            cout<<"Room_Number "<<setw(10)<<"Type "<<setw(10)<<" Price "<<setw(10)<<" Reserved "<<endl;
            for(i=0;i<counter;i++)
                {
                    cout<<room_number[i]<<setw(20)<<type[i]<<setw(6)<<price[i]<<setw(7)<<reserved[i];
                    cout<<endl;
                        }
                        cout<<endl;
                    break;
    case 2:
            cout<<"Room Number:";
            cin>>user_room_number;
            cout<<endl;
            found=false;
            i=0;
            while((found!=true)&&(i<counter))
                {
                if(user_room_number==room_number[i])
                {
                    found=true;
                    if(reserved[i]=="No")
                    {
                        cout<<"The room is not reserved!"<<endl;
                        reserved[i]="Yes";
                    }
                    else if(reserved[i]=="Yes")
                        cout<<"The room is reserved!"<<endl;
                }
                i++;
            }
            if(found==false)
                cout<<"There is no such room!"<<endl;
            cout<<endl;
            break;
    case 3:
            cout<<"Room Number:";
            cin>>user_room_number;
            cout<<endl;
            found=false;
            i=0;
            while((found!=true)&&(i<counter))
                {
                if(user_room_number==room_number[i])
                {
                    found=true;
                    if(reserved[i]=="Yes")
                    {
                        cout<<"The room is no longer reserved!"<<endl;
                        reserved[i]="No";
                    }
                    else
                        cout<<"The room is not reserved!"<<endl;
                }
                i++;
            }
            if(found==false)
                cout<<"There is no such room!"<<endl;
            cout<<endl;
            break;
    case 4:
             cout<<"Room number and how many days you stayed in:";
            cin>>user_room_number>>days;
            cout<<endl;
            found=false;
            for(i=0;i<counter;i++){
                if((user_room_number==room_number[i])&&(reserved[i]=="No")){
                        cout<<"The room was not reserved"<<endl;
                        reserved[i]="Yes";
                        cout<<endl;
                        break;
                }
               else if(user_room_number==room_number[i]&&(reserved[i]=="Yes")&&(found==false)){
                    sum_timi[i]=0;
                    found=true;
                    sum_timi[i]=days*price[i];
                    sum_timi[i]=sum_timi[i]*1.19;
                    cout<<"Total sum: $"<<sum_timi[i]<<endl;
                    cout<<endl;
                    reserved[i]="No";
                }}

                break;
    case 5:
            filefout(room_number,type,price,reserved,sum_timi,counter);
                    break;
    case 6:
                cout<<"Bye!"<<endl;
                    break;
    default:    cout<<"Wrong input.. try again:"<<endl;
                cout<<endl;
}
}while(choice!=6);
fin.close();
return 0;
}
