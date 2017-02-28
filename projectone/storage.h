#ifndef STORAGE_H
#define STORAGE_H


namespace Storage
{

class row_Storage
{

private:
    row_Storage();
    static bool init;
    static int count;
public:


     static void initialization(int af) {if(init) {row_Storage::count = af;init =0;} }
     static int get(){return row_Storage::count++;}
     static bool status() { return init;}
     static int show() {return row_Storage::count;}


};

class counter_Storage
{
private:
    counter_Storage();
    static bool init;
    static int count;
    static int temp;
    static int row;
    static bool initrow;
    static int stop;
    static bool flag;

public:


     static void initialization(int af) {if(init) {counter_Storage::count = af;init =0;temp =af; }}
     static int get(){if((--temp)<0){temp = counter_Storage::count; return 1;}  return 0; }
     static bool status() {  return init;   }
     static int getcountrow() { return counter_Storage::row;    }
     static void initialiazation_row(int af) {if(initrow) {counter_Storage::row = af;initrow =0;}}
     static bool rowstatus() {return initrow;}
     static void fl() {flag =0;}
     static bool showfl(){return flag;}







};

}











#endif // STORAGE_H

