#include<iostream>

using namespace std;

#include<fstream>

#include<stdio.h>



class hostel

{

    int room_no;

    char name[30];

    char address[50];

    char phone[10];



    public:

   int main_menu();

   int rules();

    int add();

    int display();

    int rooms();

    int edit();

    int check(int);

    int modify(int);

    int delete_rec(int);

};



int hostel::main_menu()

{



    int choice=0;



    while(choice!=5)

    {

        cout<<"\n\t\t\t\t*****";

        cout<<"\n\t\t\t\t* MAIN MENU *";

        cout<<"\n\t\t\t\t*****";

        cout<<"\n\n\n\t\t\t1.Book A Room";

        cout<<"\n\t\t\t2.student record";

        cout<<"\n\t\t\t3.Rooms Allotted";

        cout<<"\n\t\t\t4.Edit record";

        cout<<"\n\t\t\t5.Rules & Regulations";

        cout<<"\n\t\t\t6.Exit";

        cout<<"\n\n\t\t\tEnter Your Choice: ";

        cin>>choice;



        switch(choice)

        {

            case 1: add();

                    break;

            case 2: display();

                    break;

            case 3: rooms();

                    break;

            case 4: edit();

                    break;

            case 5: rules();

                    break;

            case 6: break;

            default:

                    {

                        cout<<"\n\n\t\t\tWrong choice!!!";

                        cout<<"\n\t\t\tPress any key to continue!!";

                        return 0;

                       system("pause");

                    }

        }

    }

}



int hostel::add()

{

    int r,flag;

    ofstream fout("newest.txt",ios::app);



    cout<<"\n Enter Customer Detalis";

    cout<<"\n ********";

    cout<<"\n\n Room no: ";

    cin>>r;

    flag=check(r);



    if(flag)

        cout<<"\n Sorry..!!!Room is already booked";

    else

    {
        room_no=r;

        cout<<"\n Name:\t ";

        cin>>name;

        cout<<"\n Address:\t ";

        cin>>address;

        cout<<"\n Phone No:\t ";

        cin>>phone;

        fout.write((char*)this,sizeof(*this));

        cout<<"\n Room is booked!!!";

    }



    cout<<"\n Press any key to continue!!";

  system("pause");

    fout.close();

    return 0;

}



int hostel::display()

{



    ifstream fin("newest.txt",ios::in);

    int r;

    cout<<"\n Enter room no: ";

    cin>>r;



    while(!fin.eof())

    {

        fin.read((char*)this,sizeof(*this));



           if(room_no = r)

                 {

            cout<<"\n Cusromer Details";

            cout<<"\n ******";

            cout<<"\n\n Room no: "<<room_no;

            cout<<"\n Name: "<<name;

            cout<<"\n Address: "<<address;

            cout<<"\n Phone no: "<<phone;



              }





       else{

        cout<<"\n Sorry Room no. not found or vacant!!";



              cout<<"\n\n Press any key to continue!!";}

    system("pause");

    fin.close();

    return 0;

              }}

int hostel::rooms()
{
    ifstream fin("newest.txt",ios::in);

    cout<<"\n\t\t\tList Of Rooms Allotted";
    cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(*this));
        cout<<"\n\n"<<room_no<<"\t\t"<<name;
        cout<<"\t\t"<<address<<"\t\t"<<phone;
    }

    cout<<"\n\n\n\t\t\tPress any key to continue!!";
    system("pause");
    fin.close();
    return 0;
}



int hostel::edit()
{
    int choice,r;

    cout<<"\n EDIT MENU";
    cout<<"\n ***";
    cout<<"\n\n 1.Modify Customer newest";
    cout<<"\n 2.Delete Customer newest";

    cout<<"\n Enter your choice: ";
    cin>>choice;

    cout<<"\n Enter room no: ";
    cin>>r;

    switch(choice)
    {
        case 1: modify(r);

                break;

        case 2: delete_rec(r);

                break;

        default: cout<<"\n Wrong Choice!!";

    }



    cout<<"\n Press any key to continue!!!";

    return 0;

  system("pause");

}



int hostel::check(int r)

{

    int flag=0;

    ifstream fin("newest.txt",ios::in);

    while(!fin.eof())

    {

        fin.read((char*)this,sizeof(*this));

        if(room_no==r)

        {

            flag=1;

                break;

        }

    }



    fin.close();

    return(flag);

}



int hostel::modify(int r)

{

    long pos , flag;

    fstream file("newest.txt",ios::in|ios::out|ios::binary);

    flag=0;

    while(!file.eof())

       {

         pos=file.tellg();

        file.read((char*)this,sizeof(*this));

        if(room_no==r)

              {

            cout<<"\n Enter New Details";

            cout<<"\n *******";

            cout<<"\n Name: ";

            cin>>name;

            cout<<" Address: ";

            cin>>address;

            cout<<" Phone no: ";

            cin>>phone;

            file.seekg(pos);



            file.write((char*)this,sizeof(*this));

            cout<<"\n newest is modified!!";

               flag=1;

            break;

              }}



    if(flag==0)



                     cout<<"\n Sorry Room no. not found or vacant!!";



              file.close();

              return 0;

       }



int hostel::delete_rec(int r)

{

    int flag=0;

    char ch;

    ifstream fin("newest.txt",ios::in);

    ofstream fout("temp.txt",ios::out);



    while(!fin.eof())

    {

        fin.read((char*)this,sizeof(*this));

        if(room_no==r)

        {

            cout<<"\n Name: "<<name;

            cout<<"\n Address: "<<address;

            cout<<"\n Pone No: "<<phone;

            cout<<"\n\n Do you want to delete this newest(y/n): ";

            cin>>ch;



            if(ch=='n')

            fout.write((char*)this,sizeof(*this));



            flag=1;

        }

        else

            fout.write((char*)this,sizeof(*this));

    }



    fin.close();

    fout.close();



    if(flag==0)

        cout<<"\n Sorry room no. not found or vacant!!";

    else

    {

        remove("newest.txt");

        rename("temp.txt","newest.txt");

        return 0;

    }

}

int hostel::rules(){
     cout << "          RULE & REGULATION  " << endl;
 cout << "1 : No ceagrat allowed in hostel.." << endl;
cout << "2 : Facilaty of generater is available and it will continous 5PM every Day.." << endl;
cout << "3 : The gate will be closed about 10:30 PM and open 6:00 AM every Day.." << endl;
 cout << "4 : Outsider are not allowed in hostel in night only friends are allowed in Exame night.. " << endl;
cout << "5 : Family member can stay in Hostel only 2 days otherwise it will be charged.." << endl;

return 0;
system("pause");
}


int main()

{

    hostel h;





    cout<<"\n\t\t\t**********";

    cout<<"\n\t\t\t* HOSTEL MANAGEMENT PROJECT *";

    cout<<"\n\t\t\t**********";




    cout<<"\n\n\n\n\n\t\t\t\tPress any key to continue!!";

    system("pause");

    h.main_menu();

    system("pause");

}
