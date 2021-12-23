#include <iostream>
#include <string>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

struct point{
    double x;
    double y;
};
class rectangle{
    public:
    rectangle(double x1,double y1,double x2,double y2){
    double xl;
    double xr;
    double yt;
    double yb;
    if(x1<x2){
        xl=x1;
        xr=x2;
    }
    else{
        xl=x2;
        xr=x1;
    }
    if(y1<y2){
        yt=y2;
        yb=y1;
    }
    else{
        yt=y1;
        yb=y2;
    }
    this->lt.x=xl;
    this->lt.y=yt;
    this->lb.x=xl;
    this->lb.y=yb;
    this->rt.x=xr;
    this->rt.y=yt;
    this->rb.x=xr;
    this->rb.y=yb;
    }
    point lt,lb,rt,rb;
};

void getXY(std::string s, double &x,double &y);

int main() {
    std::string s;
    std::ifstream rect("D:\\github\\homework_cpp\\homework_cpp\\rect.txt");

    if (getline(rect, s)) {
        if (s == "RECTANGLE") {
            double x1 = 0, y1 = 0;
            if (getline(rect, s)) {
                getXY(s, x1, y1);
            }
            double x2 = 0, y2 = 0;
            if (getline(rect, s)) {
                getXY(s, x2, y2);
            }
            rectangle f1(x1, y1, x2, y2);
        } else {
            return 1;
        }
    }
}


void getXY(std::string s, double &x, double &y) {
    unsigned char flagX = 0;
    unsigned char flagMinus = 0;
    unsigned int shift = 0;
    char flagDot = 0;
    for (unsigned long i = 0; i < s.length(); i++) {
        if (flagX == 0) {
            if (s[i] == ' ') {
                flagX = 1;
                flagDot = 0;
                shift = 0;
                if (flagMinus == 1) {
                    flagMinus = 0;
                    x = -1 * x;
                }
            } else {
                if (s[i] == '.' || s[i] == ',') {
                    flagDot = 1;
                } else if (s[i] == '-') {
                    flagMinus = 1;
                } else {
                    if (flagDot == 1) {
                        shift++;
                        x = x + (s[i] - '0') / pow(10, shift);
                    } else {
                        x = x * 10 + (s[i] - '0');
                    }
                }
            }
        } else {
            if (s[i] == '.' || s[i] == ',') {
                flagDot = 1;
            } else if (s[i] == '-') {
                flagMinus = 1;
            } else {
                if (flagDot == 1) {
                    shift++;
                    y = y + (s[i] - '0') / pow(10, shift);
                } else {
                    y = y * 10 + (s[i] - '0');
                }
            }
        }
    }
    if (flagMinus == 1) {
        y = -1 * y;
    }
}