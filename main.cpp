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

    void addReview(double rating, string comment)
    {
        ReviewNode *newNode = new ReviewNode;

        newNode->rating = rating;
        newNode->comment = comment;
        newNode->next = head;

        head = newNode;
    }

    void outputReviews()
    {
        cout << "Movie: " << title << endl;

        ReviewNode *current = head;

        while (current)
        {
            cout << "Rating: " << current->rating << endl;
            cout << "Review: " << current->comment << endl;

            current = current->next;
        }
    }
};

int main()
{
    Movie movie1;

    movie1.setTitle("Elephants in the Fog");

    movie1.addReview(
        4.5,
        "The movie shows how important courage is when facing difficult situations."
    );

    movie1.addReview(
        4.2,
        "It gives a strong message about hope, perseverance, and continuing even when life becomes uncertain."
    );

    movie1.outputReviews();

    return 0;
}