#include <iostream>
#include "string.h"
#include "stdio.h"
using namespace std;
// функция проверяет корректно ли имя пункт 4.2
bool CorrectName(char* name)
{
    //проверка на некорректные символы (кроме :)
    if((strchr(name,'"')!=NULL) or (strchr(name,'*')!=NULL) or (strchr(name,'<')!=NULL) or (strchr(name,'>')!=NULL) or (strchr(name,'?')!=NULL) or (strchr(name,'|')!=NULL)  )
    {
        cout<<"Uncorrect Name\n";
        return false;
    }
    // проверка на двоеточие,не 2 символом
    if(strchr(name,':')!=NULL and strchr(name,':')!=&name[1])
    {
        cout<<"Uncorrect Name\n";
        return false;
    }
    //проверка на двоеточие,стоящее 2 символом
    //условия:перед двоеточием символ,после '\'
    if(strchr(name,':')==&name[1])
    {
        if(isalpha(name[0]==0) or name[2]!='\\' )
        {
            cout<<"Uncorrect Name\n";
            return false;
        }
    }
    int leng=strlen(name);
    // проверка на тип файла .txt
    if((name[leng-1]!='T' or name[leng-1]!='t') and (name[leng-2]!='x' or name[leng-2]!='X') and (name[leng-3]!='T' or name[leng-3]!='t') and (name[leng-4]!='.' ))
    {
        cout<<"Uncorrect Name\n";
        return false;
    }
    return true;
}
int main()
{
    char FileName[30];
    cout<<"Enter FileName\n";
    cin>>FileName;
    //п 4.2
    while(CorrectName(FileName))
    {
        // открытие файла
        FILE* f=fopen(FileName,"rb");
        if (f!=NULL)
        {
            //определить размер файла
            long size;
            fseek(f, 0, SEEK_END);
            size = ftell(f);
            fseek(f, 0, SEEK_SET);
            char* Mass;
            Mass = new char [size];
            // выгрузка в массив содержимое файла
            fread(Mass,1,size,f);
            char str[30];
            cout<<"enter string\n";
            cin>>str;
            bool fl=false;
            //узнать есть ли строка в файле
            for(int i=0; i<size; i++)
            {
                if(Mass[i]==str[0] and size-i>=strlen(str))
                {
                    fl=true;
                    for(int j=1; j<strlen(str); j++)
                    {
                        if(Mass[i+j]!=str[j])
                        {
                            fl=false;
                            break;
                        }
                    }

                }
                if(fl==true)
                    break;

            }
            if(fl)
                cout<<"string="<<str<<" contained in the file\n";
            else
            {
                cout<<"string="<<str<<" is not contained in the file\n";
            }
            //пункт 4.6
            char** StrMass;// массив строчек(предложений)
            int n=0;//количество предложний
            // узнаем количество предложений в тексте
            for(int i=0; i<size; i++)
            {
                if(Mass[i]=='.' or Mass[i]=='?' or Mass[i]=='!' )
                    n=n+1;
            }
            // задаем указатель на количество предложений
            StrMass=new char*[n];
            int* len;
            len=new int[n];
            n=0;// количество предложений
            int k=0;//вспомогательные счетчики
            int h=0;//вспомогательные счетчики для разбиения текста в массив по предложениям
            // заполняем массив
            for(int i=0; i<size; i++)
            {

                if(Mass[i]=='.' or Mass[i]=='?' or Mass[i]=='!' )
                {

                    StrMass[n]=new char[i-k];
                    len[n]=i-k;
                    //i-k количество символов в текущем предложении
                    for(int j=k; j<i+1; j++)
                    {

                        StrMass[n][h]=Mass[j];
                        ++h;
                    }
                    k=i+1;
                    h=0;
                    n=n+1;
                }
            }
            // вывод на экран массива
            for(int i=0; i<n; i++)
            {
                cout<<"\n";
                for(int j=0; j<=len[i]; j++)
                    cout<<StrMass[i][j];
            }
            cout<<"\n---- sorted array---------";
            //сортировка массива по длинне,по возрастанию
            char* temp;
            int temp_;
            for (int i =1; i<n; ++i)
            {
                for (int j =n-1; j>=i; --j)
                {
                    if (len[j-1]>len[j])
                    {
                        temp_=len[j-1];
                        len[j-1]=len[j];
                        len[j]=temp_;
                        temp = StrMass[j-1];
                        StrMass[j-1] = StrMass[j];
                        StrMass[j] = temp;
                    }
                }
            }
            //вывод в консоль
            for(int i=0; i<n; i++)
            {
                cout<<"\n";
                for(int j=0; j<=len[i]; j++)
                    cout<<StrMass[i][j];
            }
            // вывод в файл
            FILE* write_=fopen("Result.txt","w");
            //
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<=len[i]; j++)
                    fwrite(&StrMass[i][j],sizeof(char), 1,write_);
            }

            delete[] StrMass;
            delete[] Mass;
            delete write_;
            delete f;
            break;
        }
        else
        {
            cout<<"File not open";
            break;
        }
    }
    return 0;
}
