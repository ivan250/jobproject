#include "forms.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>


Forms::point Forms::operator + (const  point & a,const  point & b){

    point temp;
    temp.x = a.x + b.x;
    temp.y = a.y + b.y;

    return temp;

}

Forms::shape* Forms::free_mem::operator() (Forms::shape* sh) const { delete sh; return 0; }






Forms::shape* Forms::move_to(shape* s,point p){
    s->move(p); return s;

}

void Forms::update_position(std::list<shape*> & vs1,std::vector<point> & vs2){

    std::transform(vs1.begin(),vs1.end(),vs2.begin(),vs1.begin(),move_to);

}


Forms::rectangle::rectangle(point a, point b)
{
    if (a.x <= b.x) {
       if (a.y <= b.y) {
            sw = a;
            ne = b;
       }
       else {
            sw = point(a.x, b.y);
            ne = point(b.x, a.y);
       }
    }
    else {
       if (a.y <= b.y) {
            sw = point(b.x, a.y);
            ne = point(a.x, b.y);
       }
       else {
            sw = b;
            ne = a;
       }
    }
}




 Forms::triangle::triangle(point p1,point p2,int hight)
{

     if (p1.x <= p2.x){
        if(hight > p1.y){
           sw = p1; se = p2; n = point((sw.x+se.x)/2,hight);
        }
        else{
         sw = p1; se = p2; n = point((sw.x+se.x)/2,(sw.x+se.x)/2);
        }
    }
    else{
         if(hight > p1.y){
            sw =p1; se =p2;n = point((sw.x+se.x)/2,hight);
         }
         else{
         sw = point(p2.x,p1.y);
         se = point(p1.x,p2.y);
         n = point((sw.x+se.x)/2,(sw.x+se.x)/2);
        }
    }
}

 void Forms::clear_mem(std::list<shape*> li){

     std::transform(li.begin(),li.end(),li.begin(),free_mem());

 }








