#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <functional>
#include <list>
#include <iomanip>
#include <locale>
#include <ctime>

#include "input_string.h"
#include "projmanip.h"
#include "myfunctors.h"

using namespace std;


using namespace Projmanip;



Inputstring & operator << (Inputstring & os ,const pair<string,string> & i)
{
    os<<gsetwl(15,i.first.c_str())<<gline(10,' ')<<std::setw(35)<<std::left<<grus(i.second);
    return os;

}



void print_list(vector<string> & v,ostream & os)
{
    copy(v.begin(),v.end(),ostream_iterator<string>(os));


}





//öåëüþ ýòîãî èíòåðôåéñà - áûëî ïðîñòî ïîêàçàòü ðàáîòó ìàíèïóëÿòîðîâ íå áîëüøå íå ìåíüøå.

int main()
{
    setlocale(LC_ALL,"Russian");



    ifstream fin("//text.txt");
    ofstream fout("//text.txt",ios_base::app);

    if(!fin) { std::cerr<<"Cannnot open input file"<<'\n';std::exit(1); }
    if(!fout){ std::cerr<<"Cannnot open output file"<<'\n';std::exit(1); }

    fin>>prow;

    Inputstring out;

    vector<string> data;
    data.reserve(1000);

    char ch;

do{



    string translate;
    string word;
    cout<<"Enter a word in english : \t";

    getline(cin,word);
    system("cls");

    cout<<"Enter translation :\t";

    getline(cin,translate);

    system("cls");

    auto pr = make_pair(word,translate);




    out<<setw(4)<<right<<gnumstr<<") "<<pr<<std::left<<gtime<<gdesc(3,"\n") <<'\n';

    cout<<endl<<endl<<"The resulting string :"<<endl<<out.str();
    cout<<endl<<"The length of the resulting string - \t"<<out.size()<<endl;

    data.push_back(out.str());
    out.clear();
    cout<<endl<<endl<<endl;
    cout<<"Сontinue input ?(y/n) \t";cin>>ch;
    system("cls");
    cin.ignore(256,'\n');


}while(ch != 'n' && ch != 'N');


cout<<endl<<endl;


print_list(data,cout);

print_list(data,fout);

fin.close();fout.close();


cin.get();cin.get();

    return 0;
}


















