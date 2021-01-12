#include "film.h"
using namespace std;

int main()
{
    const unsigned n=5;
    Film *films[n];
    if (!Film::read_input("film.dat",films,n))
    {
        cerr << "Unable to read file from films.dat. Exiting." << endl;
        exit(EXIT_FAILURE);
    }
    for (unsigned i=0;i<n;i++)
        films[i]->output();

    return 0;
}