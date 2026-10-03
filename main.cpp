#include <iostream>
#include <iomanip>
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
        cout << "\nMovie: " << title << endl;

        ReviewNode *current = head;
        double total = 0.0;
        int count = 0;

        while (current)
        {
            count++;

            cout << "Review #" << count << endl;
            cout << "Rating: " << fixed << setprecision(1)
                 << current->rating << endl;
            cout << "Comment: " << current->comment << endl;

            total += current->rating;
            current = current->next;
        }

        if (count > 0)
        {
            double average = total / count;

            cout << "Average Rating: " << fixed << setprecision(1)
                 << average << endl;
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