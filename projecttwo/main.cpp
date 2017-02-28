#include "forms.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <list>
#include <iterator>
#include <typeinfo>

using namespace std;
using namespace Forms;


void print_points(const list<shape*> & li){

for(auto x : li) std::cout<<"Class name "<< typeid(*x).name()<<
    ", coordinates of west point is  x: "<<x->west().x<<"  y: "<< x->west().y<<endl;

}


//Ýòî ðàííÿÿ âåðñèÿ.Â ýòîì íåáîëüøîì ïðèìåðå ÿ õîòåë ïîêàçàòü ïðèìåíåíèå ìåòîäîâ îîï .


int main()
{



    shape* p1 = new rectangle(point(10,10),point(23,23));
    shape* p2 = new line(point(0,40),17);
    shape* p3 = new triangle(point(15,10),point(27,10),20);


    list<shape*> li;
    li.push_back(p1);
    li.push_back(p2);
    li.push_back(p3);

    cout<<"Coordinates figures is :"<<endl<<endl;

    print_points(li);

    vector<point> vp;
    vp.push_back(point (10,10));
    vp.push_back(point (10,10));
    vp.push_back(point (20,20));

    cout<<endl<<endl;

    cout<<"Coordinates after moving figures :"<<endl;

    update_position(li,vp);
    print_points(li);

    clear_mem(li);//îñâîáîæäàåì ïàìÿòü äëÿ âñåõ îáúåêòîâ.






  return 0;

}
