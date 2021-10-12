#include <iostream> //библиотека для ввода и вывода в консоль
#include <string> //для использования строк (string)
#include <fstream> //для работы с файлами
#include <cmath>

void getXY(std::string s, double &x, double &y);

int main(){ //главная функция
    std::string s;
    std::ifstream in("D:\\github\\homework_cpp\\homework_cpp\\in.txt"); //берёт файл из заданного адреса

    while(getline(in,s)){ //строка in записывается в переменную s
        double x=0,y=0;
        getXY(s,x,y);
        std::cout<<x<<" "<<y<<std::endl;
    }
    return 0;
}

void getXY(std::string s, double &x, double &y){
    char flagX=0;
    char flagMinus=0;
    unsigned int shift=0;
    char flagDot=0;
    for(unsigned long i=0; i<s.length();i++){
        if(flagX==0){
            if(s[i]==' '){
                flagX=1;
                flagDot=0;
                shift=0;
                if(flagMinus==1){
                    flagMinus=0;
                    x=-1*x;
                }
            }
            else{
                if(s[i]=='.'||s[i]==','){
                    flagDot=1;
                }
                else if(s[i]=='-'){
                    flagMinus=1;
                }
                else{
                    if(flagDot==1){
                        shift++;
                        x=x+(s[i]-'0')/pow(10,shift);
                    }
                    else{
                        x=x*10+(s[i]-'0');
                    }
                }
            }
        }
        else{
            if(s[i]=='.'||s[i]==','){
                flagDot=1;
            }
            else if(s[i]=='-'){
                flagMinus=1;
            }
            else{
                if(flagDot==1){
                    shift++;
                    y=y+(s[i]-'0')/pow(10,shift);
                }
                else{
                    y=y*10+(s[i]-'0');
                }
            }
        }
    }
    if(flagMinus==1){
        y=-1*y;
    }
}