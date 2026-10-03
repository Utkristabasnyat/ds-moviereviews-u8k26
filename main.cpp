#include <iostream>
#include <string>
using namespace std;

struct ReviewNode
{
    double rating;
    string comment;
    ReviewNode *next;
};

class Movie
{
private:
    string title;
    ReviewNode *head;

public:
    Movie()
    {
        title = "";
        head = nullptr;
    }

    void setTitle(string t)
    {
        title = t;
    }

    string getTitle()
    {
        return title;
    }
};

int main()
{
    Movie movie1;

    movie1.setTitle("Elephants in the Fog");

    cout << "Movie: " << movie1.getTitle() << endl;

    return 0;
}