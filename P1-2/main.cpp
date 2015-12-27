#include <iostream>
#include "sdt.h"
using namespace std;
void To_Hex(int value)//ка
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
void In_hex(uint8_t byte)   //перевод в 16тир. 1 байта
{
    uint8_t del=byte/16;
    uint8_t ost=byte%16;
    To_Hex(del);
    To_Hex(ost);
}
void In_Binary(uint8_t byte)   //перевод в двоичную 1 байта
{
    int i=128;  //в двоичной 1000 0000
    uint8_t j=0;  //8бит(уокроченный инт) перменная
    while(true)
    {
        ++j;
        if(i==0)
            break;
        if(i&byte)
            cout<<"1";
        else
            cout<<"0";

        i=i>>1;//сдвиг на 1
        if(j==4)//пробел
        {
            cout<<" ";
            j=0;
        }
    }
}
void print_in_binary(const void* data, size_t size)//вывод на экран данные размера size(указатель без типа)
{
    uint8_t* bytes=(uint8_t*) data;//проход по каждому байту
    for(int i=0; i<size; i++)
    {
        uint8_t byte=*(bytes+i);
        In_Binary(byte);
    }
}
void print_in_hex(const void* data, size_t size)//16
{
    uint8_t* bytes=(uint8_t*) data;
    for(int i=0; i<size; i++)
    {
        uint8_t byte=*(bytes+i);
        In_hex(byte);
    }
}
int main()
{
    const uint8_t size=2;//2 байта(16бит)
    uint16_t a,b;
    char oper;
    cout<<"enter value and operand(& | ^)\n";
    cin>>a>>oper>>b;
    uint16_t c;
    switch(oper)
    {
    case '&':
        c=a&b;
        break;
    case '^':
        c=a^b;
        break;
    case '|':
        c=a|b;
        break;
    }
    print_in_hex(&a,size);
    cout<<oper;
    print_in_hex(&b,size);
    cout<<" =";
    print_in_binary(&a,size);
    cout<<oper;
    print_in_binary(&b,size);
    cout<<"=\n";
    print_in_binary(&c,size);
    return 0;
}
