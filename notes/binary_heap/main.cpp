#include <bits/stdc++.h>

class BinaryHeap
{
private:
    std::vector<int> array;

    // This is O(logn)
    void sift_up(size_t index)
    {
        int parentIndex;

        while (index != 0 && array[(parentIndex = (index - 1) / 2)] > array[index])
        {
            std::swap(array[parentIndex], array[index]);
            index = parentIndex;
        }
    }

    // This is O(logn)
    void sift_down(size_t index)
    {
        size_t leftChildIndex = 0;
        size_t rightChildIndex = 0;
        size_t minIndex = 0;

        while (true)
        {
            leftChildIndex = 2 * index + 1;
            rightChildIndex = 2 * (index + 1);

            if (leftChildIndex >= array.size())
            {
                return;
            }

            minIndex = leftChildIndex;

            if (rightChildIndex < array.size() && array[rightChildIndex] < array[leftChildIndex])
            {
                minIndex = rightChildIndex;
            }

            if (array[index] <= array[minIndex])
            {
                return;
            }

            std::swap(array[index], array[minIndex]);

            index = minIndex;
        }
    }

    // This is O(n)
    void heapify()
    {
        for (int i = static_cast<int>(array.size()) / 2 - 1; i >= 0; i--)
        {
            sift_down(i);
        }
    }

public:

    BinaryHeap();
    BinaryHeap(const std::vector<int>& vec)
    {
        array = vec;
        heapify();
    }

    // This is O(logn)
    void insert(const int x)
    {
        array.push_back(x);
        // Then you must sift upwards
        sift_up(array.size() - 1);
    }

    // This is O(1)
    int min()
    {
        if (array.size()) { return array[0]; }
        else
        {
            std::cerr << "Cannot get min of size zero heap!\n";
            exit(-1);
        }
    }

    // This is O(logn)
    int extract_min()
    {
        if (array.size())
        {
            int result = array[0];

            std::swap(array[0], array[array.size() - 1]);

            array.pop_back();

            sift_down(0);

            return array[0];
        }
        else
        {
            std::cerr << "Cannot get min of size zero heap!\n";
            exit(-1);
        }
    }

    // This is O(n)
    void print_heap()
    {
        int count = 1;

        for (size_t i = 0; i < array.size(); i++)
        {
            std::cout << array[i] << ", ";

            if (i + 2 >= pow(2, count))
            {
                std::cout << '\n';
                count++;
            }
        }

        std::cout << '\n';
    }
};

int main()
{
    std::vector<int> myArray = {9, 4, 7, 1, -2, 6, 5};
    BinaryHeap bheap(myArray);

    bheap.print_heap();

}
