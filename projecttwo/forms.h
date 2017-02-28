#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <list>
#include <vector>

namespace Forms
{



struct point {
   int x,y;
   point() {}
   point(int a, int b) { x=a; y=b; }
};




inline int max(int a, int b) { return a<b ? b : a; }
inline int min(int a, int b) { return a<b ? a : b; }




class shape {

public:

  virtual point north() const = 0;
  virtual point south() const = 0;
  virtual point east() const = 0;
  virtual point west() const = 0;
  virtual point neast() const = 0;
  virtual point seast() const = 0;
  virtual point nwest() const = 0;
  virtual point swest() const = 0;
  virtual void move(const point &) = 0;
  virtual point centre() const =0;
  virtual ~shape(){}

};



class line : public shape {

  point w, e;
 public:

  line(point a, point b) { w = a; e = b;}
  line(point a, int len) { w = point(a.x + len - 1, a.y); e = a; }

  point north() const
    { return point((w.x+e.x)/2, max(e.y,w.y)); }
  point south() const
    { return point((w.x+e.x)/2, min(e.y,w.y)); }
  point east() const
    { return point(max(e.x, w.x), (w.y+e.y)/2); }
  point west() const
    { return point(min(e.x, w.x), (w.y+e.y)/2); }
  point neast() const
    { return point(max(e.x, w.x), max(e.y, w.y)); }
  point seast() const
    { return point(max(e.x, w.x), min(e.y, w.y)); }
  point nwest() const
    { return point(min(e.x, w.x), max(e.y, w.y)); }
  point swest() const
    { return point(min(e.x, w.x), min(e.y, w.y)); }
  point centre() const {return point((w.x+e.x)/2,(w.y+e.y)/2); }
  void move(const point & p)
    { w.x += p.x; w.y += p.y; e.x += p.x; e.y += p.y; }

  virtual ~line(){}

};

class rectangle : public shape {

    point sw, ne;

public:

 rectangle(point, point);


  point north() const
    { return point((sw.x+ne.x)/2, ne.y); }
  point south() const
    { return point((sw.x+ne.x)/2, sw.y); }
  point east() const
    { return point(ne.x, (ne.y+sw.y)/2); }
  point west() const
    { return point(sw.x, (ne.y+sw.y)/2); }
  point neast() const { return ne; }
  point seast() const
    { return point(ne.x, sw.y); }
  point nwest() const
    { return point(sw.x, ne.y); }
  point swest() const { return sw; }
  point centre() const
    {return point((sw.x+ne.x)/2,(sw.y+ne.y)/2);}
  void move(const point & p)
    { sw.x += p.x; sw.y += p.y; ne.x += p.x; ne.y += p.y; }

  virtual ~rectangle(){}

};

class triangle : public shape
{

    point sw,se,n;

public:

    triangle(point p1,point p2,int hight);


    point north() const
      { return point((sw.x+se.x)/2, n.y); }
    point south() const
      { return point((sw.x+se.x)/2, min(sw.y,se.y)); }
    point east() const
      { return point(se.x, (n.y+se.y)/2); }
    point west() const
      { return point(sw.x, (n.y+sw.y)/2); }
    point neast() const
      { return point(se.x,n.y); }
    point seast() const { return se; }
    point nwest() const
      { return point(sw.x, n.y); }
    point swest() const { return sw; }

    point centre() const {return point((sw.x+se.x)/2,(sw.y+n.y)/2);}
    void move(const point & p)
      { sw.x += p.x; sw.y += p.y; se.x += p.x; se.y += p.y;n.x += p.x; n.y += p.y;}

    virtual ~triangle(){}

};



point operator + (const  point & a,const  point & b);

shape* move_to(shape* s,point p);

void update_position(std::list<shape*> & vs1,std::vector<point> & vs2);

void clear_mem(std::list<shape*> );


struct free_mem{

  shape* operator() (shape* ) const;

};







}


#endif
