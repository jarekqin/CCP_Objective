#include <iostream>
using namespace std;

class Film
{
    public:
        void store_title(const string &t) {title=t;}
        void store_title(const char *t) {title=t;}
        void store_director(const string &d) {director=d;}
        void store_director(const char *d) { director=d;}
        void store_time(int t){ time=t; }
        void store_quality(int q) { quality=q; }
        void output() const;

    private:
        string title;
        string director;
        int time;
        int quality;
};

class DirectorCut :public Film
{
    public:
        void store_rev_time(int t) { rev_time=t;}
        void store_changes(const string &t) { changes=t; }
        void store_changes(const char *d) { changes=d; }
        void output() const;
    private:
        int rev_time;
        string changes;
};

class ForeignFilm:public Film
{
    public:
        void store_language(const string &t ) { language=t;}
        void store_language(const char *t) { language=t; }
        void output() const;

    private:
        string language;
};

void Film::output() const
{
    cout << "Title:" << title  << endl;
    cout << "DIrector: " << director << endl;
    cout << "Time: " << time << endl;
    cout << "Quanlity: " << quality << endl;

    for (int i=0;i<quality; i++)
        cout << "*";
    cout << endl;
}

void DirectorCut::output() const
{
    Film::output();
    cout << "Revised time: " << rev_time << " mins" << endl;
    cout << "Changes: " << changes << endl;
}

void ForeignFilm::output() const
{
    Film::output();
    cout << "Language: " << language << endl;
}


int main()
{
    Film f;
    
    f.store_title("Rear Window.");
    f.store_director(" Jarek Qin.");
    f.store_time(112);
    f.store_quality(4);
    cout << "Film--" << endl;
    f.output();
    cout << endl;

    DirectorCut d;
    d.store_title("The story of King of National United Kingdom of China!");
    d.store_director(" Qin Hai Peng");
    d.store_time(110);
    d.store_quality(5);
    cout << "Director--" << endl;
    d.output();
    cout << endl;

    ForeignFilm ff;
    ff.store_title("The story of King of National United Kingdom of China2");
    ff.store_director(" Jarek I");
    ff.store_time(115);
    ff.store_quality(10);
    cout << "ForeignFilm--" << endl;
    ff.output();
    cout << endl;

    return 0;
}