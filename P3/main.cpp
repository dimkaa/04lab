#include <iostream>
#include "string.h"
#include "sdt.h"

using namespace std;
void To_Hex(int value)
{
    switch(value)
    {
    case 15:
        cout<<"F";
        break;
    case 14:
        cout<<"E";
        break;
    case 13:
        cout<<"D";
    case 12:
        cout<<"C";
    case 11:
        cout<<"B";
        break;
    case 10:
        cout<<"A";
        break;
    case 9:
        cout<<"9";
        break;
    case 8:
        cout<<"8";
        break;
    case 7:
        cout<<"7";
        break;
    case 6:
        cout<<"6";
        break;
    case 5:
        cout<<"5";
        break;
    case 4:
        cout<<"4";

        break;
    case 3:
        cout<<"3";
        break;
    case 2:
        cout<<"2";
        break;
    case 1:
        cout<<"1";
        break;
    case 0:
        cout<<"0";
        break;

    }

}

void In_hex(uint8_t byte)//
{

    uint8_t del=byte/16;
    uint8_t ost=byte%16;
    To_Hex(del);
    To_Hex(ost);
}
void In_Binary(uint8_t byte)
{
    int i=128;
    uint8_t j=0;
    while(true)
    {
        ++j;
        if(i==0)
            break;
        if(i&byte)
            cout<<"1";
        else
            cout<<"0";
        i=i>>1;
        if(j==4)
        {
            cout<<" ";
            j=0;
        }
    }
}
//++a//адрес элемента
void print_in_binary(const void* data, size_t size)
{
    uint8_t* bytes=(uint8_t*) data;
    for(int i=0; i<size; i++)
    {
        if(i%4==0)
            cout<<"\n";
        uint8_t byte=*(bytes+i);
        In_Binary(byte);

    }
}
void print_in_hex(const void* data, size_t size)\
{
    uint8_t* bytes=(uint8_t*) data;
    for(int i=0; i<size; i++)
    {
        uint8_t byte=*(bytes+i);
        In_hex(byte);
        cout<<" ";
    }
}
struct student
{
    char name[15];
    int year;
    double mean; //средний балл
    bool sex;
    uint8_t curs;
    student* starost;
};
int main()
{
    student Group[3];
    //староста
    strcpy(Group[0].name,"Ivanov");
    Group[0].year=2004;
    Group[0].mean=3.4;
    Group[0].sex=true;//man
    Group[0].curs=22;
    Group[0].starost=NULL;
    // первый студент
    strcpy(Group[1].name,"Petrova");
    Group[1].year=2004;
    Group[1].mean=4.2;
    Group[1].sex=false;//woman
    Group[1].curs=22;
    Group[1].starost=Group[0].starost;
    //второй студент
    strcpy(Group[2].name,"BatMan");
    Group[2].year=2008;
    Group[2].mean=1.9;
    Group[2].sex=true;//batman
    Group[2].curs=24;
    Group[2].starost=Group[0].starost;
    //вывод адреса массива и элементов
    cout<<"Array adress="<<Group<<"  "<<"size="<<sizeof(Group)<<"\n";
    cout<<"Group[0] adress="<<Group<<"  "<<"size="<<sizeof(Group[0])<<"\n";
    cout<<"Group[1] adress="<<Group+1<<"  "<<"size="<<sizeof(Group[1])<<"\n";
    cout<<"Group[2] adress="<<Group+2<<"  "<<"size="<<sizeof(Group[2])<<"\n";
    cout<<"\n";
    //вывод адреса,смещения,двочного и шестнадцатиричного представления полей структуры Group[1]
    cout<<"Student 1(Group[1]):\n";
    cout<<"field name:adress:"<<&Group[1].name<<"\n";
    cout<<"offset="<<offsetof(student,name)<<"\n";
    cout<<"size="<<sizeof(Group[1].name)<<"\n";
    print_in_hex(Group[1].name,sizeof(Group[1].name));
    cout<<"\n";
    print_in_binary(Group[1].name,sizeof(Group[1].name));
    cout<<"\n";
    //year(int)
    cout<<"field year:adress:"<<&Group[1].year<<"\n";
    cout<<"offset="<<offsetof(student,year)<<"\n";
    cout<<"size="<<sizeof(Group[1].year)<<"\n";
    print_in_hex(&Group[1].year,sizeof(Group[1].year));
    cout<<"\n";
    print_in_binary(&Group[1].year,sizeof(Group[1].year));
    //mean(double)
    cout<<"\n";
    cout<<"field mean:adress:"<<&Group[1].mean<<"\n";
    cout<<"offset="<<offsetof(student,mean)<<"\n";
    cout<<"size="<<sizeof(Group[1].mean)<<"\n";
    print_in_hex(&Group[1].mean,sizeof(Group[1].mean));
    cout<<"\n";
    print_in_binary(&Group[1].mean,sizeof(Group[1].mean));
    //curs(uint8_t)
    cout<<"\n";
    cout<<"field curs:adress:"<<&Group[1].curs<<"\n";
    cout<<"offset="<<offsetof(student,curs)<<"\n";
    cout<<"size="<<sizeof(Group[1].curs)<<"\n";
    print_in_hex(&Group[1].curs,sizeof(Group[1].curs));
    cout<<"\n";
    print_in_binary(&Group[1].curs,sizeof(Group[1].curs));
    //starost(uint8_t)
    cout<<"\n";
    cout<<"field starost:adress:"<<&Group[1].starost<<"\n";
    cout<<"offset="<<offsetof(student,starost)<<"\n";
    cout<<"size="<<sizeof(Group[1].starost)<<"\n";
    print_in_hex(&Group[1].starost,sizeof(Group[1].starost));
    cout<<"\n";
    print_in_binary(&Group[1].starost,sizeof(Group[1].starost));
    cout<<"\n";
    //вывод массива структур в шестнадцатиричном виде
    for(int i=0; i<=2; i++)
    {
        cout<<"Group["<<i<<"]\n";
        cout<<"name\n";
        print_in_hex(Group[i].name,sizeof(Group[i].name));
        cout<<"\n";
        cout<<"year\n";
        print_in_hex(&Group[i].year,sizeof(Group[i].year));
        cout<<"\n";
        cout<<"mean\n";
        print_in_hex(&Group[i].mean,sizeof(Group[i].mean));
        cout<<"\n";
        cout<<"sex\n";
        print_in_hex(&Group[i].sex,sizeof(Group[i].sex));
        cout<<"\n";
        cout<<"curs\n";
        print_in_hex(&Group[i].curs,sizeof(Group[i].curs));
        cout<<"\n";
        cout<<"starost\n";
        print_in_hex(&Group[i].starost,sizeof(Group[i].starost));
        cout<<"\n";
    }
    //код в цикле равносилен
    // print_in_hex(&Group[i],sizeof(group[i]));
    //выводу всего элемента массива сразу
    // сделан вывод полей,чтобы указать имя блока данных полей
    //(удобство чтения)
}
