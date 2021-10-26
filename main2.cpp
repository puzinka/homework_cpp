#include <iostream>
#include <string>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "structure.h"
#include "functions.h"

int main(){
    std::string s;
    std::ifstream data("D:\\github\\homework_cpp\\homework_cpp\\data.txt");

    if(getline(data,s)){
        double h0=0;
        get_h0(s,h0);
        std::cout<<h0<<std::endl;
    }
    if(getline(data,s)){
        double vx=0, vy=0;
        getXY(s,vx,vy);
        std::cout<<vx<<" "<<vy<<std::endl;
    }
    std::vector <wall> Mass;
    while(getline(data,s)){
        wall p;
        double x=0, h=0;
        getXY(s,x,h);
        p.x=x;
        p.h=h;
        Mass.push_back(p);
    }
    for(int i=0; i<Mass.size(); i++){
        std::cout<<Mass.at(i).x<<" "<<Mass.at(i).h<<std::endl;
    }
    return 0;
}

void get_h0(std::string s,double &h0){
    unsigned char flagDot=0;
    unsigned int shift=0;
    h0=0;
    for(unsigned long i=0; i<s.length(); i++){
        if(s[i]=='.'||s[i]==','){
            flagDot=1;
        }
        else{
            if(flagDot==1){
                shift++;
                h0=h0+(s[i]-'0')/pow(10,shift);
            }
            else{
                h0=h0*10+(s[i]-'0');
            }
        }
    }
}

void getXY(std::string s, double &x, double &y){
    unsigned char flagX=0;
    unsigned char flagMinus=0;
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