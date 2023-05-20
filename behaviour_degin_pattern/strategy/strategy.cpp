#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SortStrategy {
public:
    virtual vector<int> sort(vector<int> &dataset) = 0;
    virtual ~SortStrategy()=default;
};

class BubbleSortStrategy: public SortStrategy {
public:
    virtual vector<int> sort(vector<int> &dataset) override
    {
        cout << "sorting using bubble sort" << endl;
        return dataset;
    }
};

class QuickSortStrategy: public SortStrategy {
public:
    virtual vector<int> sort(vector<int> & dataset) override
    {
        cout << "sorting using quick sort" << endl;
        return dataset; 
    }
};

class Sorter {
public:
    Sorter(SortStrategy* smallsort, SortStrategy* largesort)
    {
        this->smallsort = smallsort;
        this->largesort = largesort;
    }
    vector<int> sort(vector<int> &dataset)
    {
        if(dataset.size() > 5)
        {
            return largesort->sort(dataset);
        }
        else
        {
            return smallsort->sort(dataset);
        }
    }
private:
    SortStrategy* smallsort = nullptr;
    SortStrategy* largesort = nullptr;
};

int main(int argc, char** argv)
{
    SortStrategy* bubble_sort = new BubbleSortStrategy();
    SortStrategy* quick_sort = new QuickSortStrategy();

    Sorter *sort_algrithom = new Sorter(bubble_sort, quick_sort);

    vector<int> array1 = {1,2,3,4,5};
    vector<int> array2 = {1,2,3,4,5,6,7,8,10};
    sort_algrithom->sort(array1);
    sort_algrithom->sort(array2);\
    delete bubble_sort;
    delete quick_sort;
    delete sort_algrithom;

    return 0;
}
