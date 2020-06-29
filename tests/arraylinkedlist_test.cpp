#include <gtest/gtest.h>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
class ArrayLinkedList;
class Node
{
    friend class ArrayLinkedList;
    friend ostream &operator<<(ostream &out, ArrayLinkedList &arr);
    string data;
    int next;
};
class ArrayLinkedList
{
    friend ostream &operator<<(ostream &out, ArrayLinkedList &arr);
    int freeListIndex;
    int rootIndex;
    std::vector<Node> elements;

public:
    ArrayLinkedList() : freeListIndex(0), rootIndex(-1), elements(vector<Node>(16))
    {
        for (int i = 0; i < elements.size() - 1; i++)
        {
            elements[i].next = i + 1;
        }
        elements[elements.size() - 1].next = -1;
    }

    int insert(const string &str)
    {
        int nodeFromFreeList = freeListIndex;
        freeListIndex = elements[freeListIndex].next;
        Node &newNode = elements[nodeFromFreeList];
        newNode.data = str;

        int prevRoot = rootIndex;
        newNode.next = prevRoot;
        rootIndex = nodeFromFreeList;
        return nodeFromFreeList;
    }
};

ostream &operator<<(ostream &out, ArrayLinkedList &arr)
{
    int currentNodeIndex = arr.rootIndex;

    out << "root List = [";
    while (currentNodeIndex != -1)
    {
        Node &node = arr.elements[currentNodeIndex];
        out << "( " << node.data << ", " << node.next << "), ";
        currentNodeIndex = node.next;
    }
    out << "]" << endl;

    currentNodeIndex = arr.freeListIndex;
    out << "free List = [";
    while (currentNodeIndex != -1)
    {
        Node &node = arr.elements[currentNodeIndex];
        out << "( " << node.data << ", " << node.next << "), ";
        currentNodeIndex = node.next;
    }
    out << "]" << endl;
}

TEST(testIsArrayLinkedList, basicTest)
{
    ArrayLinkedList arr;
    arr.insert("Deepak");
    int a = arr.insert("Aarti");
    arr.insert("Aarya");
    int b = arr.insert("Rani");
    cout << arr << endl;
}