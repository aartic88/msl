#include <gtest/gtest.h>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
class ArrayList
{
public:
    ArrayList() : capacity(DEFAULT_CAPACITY), size(0), arr(new string[DEFAULT_CAPACITY])
    {
        cout << "Constuctor called" << endl;
    }

    ArrayList(const std::initializer_list<string> &list) : capacity(DEFAULT_CAPACITY), size(0), arr(new string[DEFAULT_CAPACITY])
    {
        cout << "List Constuctor called" << endl;
        for (auto it = list.begin(); it != list.end(); it++)
        {
            push_back(*it);
        }
    }

    ArrayList(const ArrayList &copy)
    {
        cout << "Copy Constuctor called" << endl;
        arr = new string[copy.capacity];
        for (int i = 0; i < copy.size; i++)
        {
            arr[i] = copy[i];
        }
        capacity = copy.capacity;
        size = copy.size;
    }

    ArrayList &operator=(const ArrayList &rhs)
    {
        cout << "Assignment operator called" << endl;
        ArrayList temp(rhs);
        swap(this->size, temp.size);
        swap(this->capacity, temp.capacity);
        swap(this->arr, temp.arr);
        return *this;
    }

    ~ArrayList()
    {
        cout << "Destructor called" << endl;
        delete[] arr; // new string[DEFAULT];
        // delete arr ; // new string();
    }

    void push_back(const string &value)
    {
        if (size == capacity)
        {
            uint32_t prevCapcity = capacity;
            capacity = 2 * capacity;
            string *newArr = new string[capacity];
            for (int i = 0; i < prevCapcity; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size++] = value;
    }

    string &operator[](int index)
    {
        return arr[index];
    }

    const string &operator[](int index) const
    {
        return arr[index];
    }

    uint32_t getSize() const
    {
        return size;
    }

private:
    const static uint32_t DEFAULT_CAPACITY = 16;
    string *arr;
    uint32_t capacity;
    uint32_t size;
};

TEST(testIsArrayList, basicTest)
{
    ArrayList arr;
    arr.push_back("Aarya");
    arr.push_back("Deepak");
    arr.push_back("Rani");
    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr[0], "Aarya");
    EXPECT_EQ(arr[1], "Deepak");
    EXPECT_EQ(arr[2], "Rani");
}

TEST(testIsArrayList, basicDynamicTest)
{
    ArrayList *arr = new ArrayList();
    for (int i = 0; i < 120; i++)
    {
        arr->push_back("Deepak");
    }
    EXPECT_EQ(arr->getSize(), 120);
    EXPECT_EQ((*arr)[119], "Deepak");
    EXPECT_EQ((*arr)[0], "Deepak");
    EXPECT_EQ((*arr)[100], "Deepak");

    (*arr)[100] = "Rani";
    EXPECT_EQ((*arr)[100], "Rani");
    delete arr;
}

TEST(testIsArrayList, basicCopyDynamicTest)
{
    ArrayList arr;
    arr.push_back("Aarya");
    arr.push_back("Deepak");
    arr.push_back("Rani");
    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr[0], "Aarya");
    EXPECT_EQ(arr[1], "Deepak");
    EXPECT_EQ(arr[2], "Rani");
    ArrayList arr2(arr);
    arr2 = arr;
}

TEST(testIsArrayList, basicConstDynamicTest)
{
    const ArrayList arr{"Deepak", "Aarya", "Rani", "Aarti"};
    EXPECT_EQ(arr[3], "Aarti");
    EXPECT_EQ(arr.getSize(), 4);
}