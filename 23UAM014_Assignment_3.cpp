#include<iostream>
using namespace std;
class LibraryBook
{
    private:
        string title;
        string writer;
        int total_pages;
        bool isDigital;
        float *chapter_lengths;
        int total_chapters;
     
    public:
    	
        LibraryBook()
        {
            title = "";
            writer = "";
            total_pages = 0;
            isDigital = 0;
            chapter_lengths = 0;
            total_chapters = 0;
        }
        
        LibraryBook(string bookTitle, string bookWriter, int pages, bool format, float* chapters, int numChapters)
        {
            title = bookTitle;
            writer = bookWriter;
            total_pages = pages;
            isDigital = format;
            chapter_lengths = new float[numChapters];
            for (int i = 0; i < numChapters; i++)
            {
                chapter_lengths[i] = chapters[i];
            }
            total_chapters = numChapters;
        }

        void showDetails()
        {
            cout << "Book Title: " << title << endl;
            cout << "Author: " << writer << endl;
            cout << "Total Pages: " << total_pages << endl;
            cout << "Digital Format: " << isDigital << endl;
            cout << "Chapter Lengths: ";
            for (int i = 0; i < total_chapters; i++)
            {
                cout << chapter_lengths[i] << " ";
            }
            cout << "\nTotal Chapters: " << total_chapters << endl;
        }

        LibraryBook(const LibraryBook& obj)
        {
            title = obj.title;
            writer = obj.writer;
            total_pages = obj.total_pages;
            isDigital = obj.isDigital;
            total_chapters = obj.total_chapters;
        
            chapter_lengths = new float[total_chapters];
            for (int i = 0; i < total_chapters; i++)
            {
                chapter_lengths[i] = obj.chapter_lengths[i];
            }
        }
        
        LibraryBook(const LibraryBook& obj, bool deepCopy)
        {
            if (deepCopy)
            {
                title = obj.title;
                writer = obj.writer;
                total_pages = obj.total_pages;
                isDigital = obj.isDigital;
                total_chapters = obj.total_chapters;

                chapter_lengths = new float[total_chapters];
                for (int i = 0; i < total_chapters; i++)
                {
                    chapter_lengths[i] = obj.chapter_lengths[i];
                }

                cout << "\nDeep copy constructor is called\n";
            }
            else
            {
                *this = obj;
            }
        }

        ~LibraryBook()
        {
            delete[] chapter_lengths;
            cout << "\nDestructor is called" << endl;
        }
};

int main()
{
    float chapterSizes[] = {10, 20, 30, 40, 50};
    LibraryBook book1("Data Structures and Algorithms", "Alice Smith", 100, true, chapterSizes, 5);
    book1.showDetails();
    
    cout << "\nSecond book:\n";
    LibraryBook book2 = book1;
    book2.showDetails();
    
    cout << "\nThird book (deep copy of the first book):\n";
    LibraryBook book3(book1, true);  // Deep copy
    book3.showDetails();
    return 0;
}
