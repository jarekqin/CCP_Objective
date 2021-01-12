#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <errno.h>
using namespace std;

class Film
{
    public:
        Film()
        {
            store_title();
            store_director();
            store_time();
            store_quality();
        }
        void store_title(const string &t) {title=t;}
        void store_title(const char *t="") {title=t;}
        void store_director(const string &d) {director=d;}
        void store_director(const char *d="") { director=d;}
        void store_time(int t=0) {time=t;}
        void store_quality(int q=0){quality=q;}
        virtual void output();
        virtual void input(ifstream &);
        static bool read_input(const char *,Film *[],int);
    private:
        string title;
        string director;
        int time;
        int quality;
};

void Film::input(ifstream &fin)
{
    string inbuff;
    getline(fin,inbuff);
    store_title(inbuff);
    getline(fin,inbuff);
    store_director(inbuff);
    getline(fin,inbuff);
    store_time(atoi(inbuff.c_str()));
    getline(fin,inbuff);
    store_quality(atoi(inbuff.c_str()));
}

void Film::output()
{
    cout <<"Title: " << title << endl;
    cout << "Director: " << director << endl;
    cout <<"Time: " << time << endl;
    cout << "Quality: ";
    for (int i=0;i<quality;i++)
        cout << "*";
    cout << endl;
}

class DirectorCut:public Film
{
    public:
        DirectorCut()
        {
            store_rev_time();
            store_changes();
        }
        void store_rev_time(int t=0) { rev_time=t;}
        void store_changes(const string &c) { changes=c;}
        void store_changes(const char * c1="") { changes=c1;}
        virtual void output();
        virtual void input( ifstream& );
    private:
        int rev_time;
        string changes;
};

void DirectorCut::input( ifstream &fin)
{
    Film::input(fin);
    string inbuff;
    getline(fin,inbuff);
    store_rev_time(atoi(inbuff.c_str()));
    getline(fin,inbuff);
    store_changes(inbuff);
}

void DirectorCut::output()
{
    Film::output();
    cout << "Revised time: " << rev_time << endl;
    cout <<"Changes: " << changes << endl;
}

class ForeignFilm:public Film
{
    public:
        ForeignFilm() { store_language();}
        void store_language( const string &l) {language=l;}
        void store_language(const char * l1="") {language=l1;}
        virtual void output();
        virtual void input(ifstream&);
    private:
        string language;
};

void ForeignFilm::input(ifstream &fin)
{
    Film::input(fin);
    string inbuff;
    getline(fin,inbuff);
    store_language(inbuff);
}

void ForeignFilm::output()
{
    Film::output();
    cout << "Langeuage: " <<language<< endl;
}

bool Film::read_input(const char * file,Film *films[],int a)
{
    string inbuff;
    ifstream fin(file);
    if(!fin)
        return false;
    int next=0;
    while (getline(fin,inbuff) && next < a)
    {
        if (inbuff=="Film")
            films[next]=new Film();
        else if (inbuff=="ForeignFilm")
            films[next]=new ForeignFilm();
        else if (inbuff=="DirectorCut")
            films[next]=new DirectorCut();
        else
            continue;
        films[next++]->input(fin);
    }
    fin.close();
    return true;
}

