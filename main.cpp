#include <iostream> //библиотека для ввода и вывода в консоль
#include <string> //для использования строк (string)
#include <fstream> //для работы с файлами
#include <cmath>

void getXY(std::string s, double &x, double &y);

int main(){ //главная функция
    std::string s;
    std::ifstream in("D:\\github\\homework_cpp\\homework_cpp\\in.txt"); //берёт файл из заданного адреса

    if(getline(in,s)){
        double xn=0,yn=0;
        getXY(s,xn,yn);
        double anglen=atan2(yn,xn);
        double xl=0,yl=0,xr=0,yr=0;
        double angleMin=anglen;
        double angleMax=anglen;

        while(getline(in,s)){ //строка in записывается в переменную s
            double x=0,y=0;
            getXY(s,x,y);
            double angle=atan2(y,x);

            if(angle>angleMax){
                angleMax=angle;
                xl=x;
                yl=y;
            }
            else if(angle<angleMin){
                angleMin=angle;
                xr=x;
                yr=y;
            }
        }
        std::cout<<"Leftmost: "<<xl<<" "<<yl<<std::endl<<"Rightmost: "<<xr<<" "<<yr;
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