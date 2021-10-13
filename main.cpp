#include <iostream>
#include <string>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>

void getXY(std::string s, double &x, double &y);

int main(){ //главная функция
    std::string s;
    std::ifstream in("D:\\github\\homework_cpp\\homework_cpp\\in.txt");

    if(getline(in,s)){
        double xn=0,yn=0;
        getXY(s,xn,yn);
        double angle_n=atan2(yn,xn);
        double xl=0,yl=0,xr=0,yr=0;
        double angleRight=angle_n;
        double angleLeft=angle_n;

        while(getline(in,s)){
            double x=0,y=0;
            getXY(s,x,y);
            double angle=atan2(y,x);
            if(angle<angle_n && (angle_n-M_PI)<=angle){
                if(angle<angleRight){
                    angleRight=angle;
                    xr=x;
                    yr=y;
                }
            }
            else if(angle>angle_n || (angle_n-M_PI)>angle){
                if((angle>0) && angle>angleLeft){
                    angleLeft=angle;
                    xl=x;
                    yl=y;
                }
                else if(angle<0){
                    angle=M_PI*2+angle;
                    if(angle>angleLeft){
                        angleLeft=angle;
                        xl=x;
                        yl=y;
                    }
                }
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