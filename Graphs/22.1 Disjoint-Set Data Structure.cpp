#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*

Problem: We have some number of items. We are allowed to merge any two items to consider them equal. At any point, we are allowed to ask whether two items are considered equal or not.

What is a disjoint-set?
 
A disjoint-set is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. In other words, disjoint set is a group of sets where no item can be in more than one set. It is also called a union–find data structure as it supports union & find operations on subsets. Lets begin by defining them –

Find: It determines in which subset a particular element is in and returns the representative of that particular set. An item from this set typically acts as a “representative” of the set.

Union: It merges two different subsets into a single subset and representative of one set becomes representative of other.

The disjoint-set also supports one other important operation called MakeSet which creates a set containing only a given element in it.

How does union–find work?
 

We can determine whether two elements are in the same subset or not by comparing the result of two Find operations. If the two elements are in the same set, they have same representative else they belong to different sets. If the union is called on two elements, we merge the two subsets which the two elements were belonging to.

How to implement Disjoint sets?
 
Disjoint-set forests are data structures where each set is represented by a tree data in which each node holds a reference to its parent node and the representative of each set is the root of that set’s tree.

Find follows parent nodes until it reaches the root.
Union combines two trees into one by attaching the root of one tree into the root of the other.
For example, consider five disjoint sets S1, S2, S3, S4 and S5 that are represented by a tree as shown in below diagram. Each set initially contains only one element each so their parent pointer is pointing to itself or to NULL.
S1 = {1}, S2 ={2}, S3 = {3}, S4 ={4} and S5 = {5}
The Find operation on element i will return representative of Si where 1 <= i <= 5. i.e. Find(i) = i

union-find

If we do Union (S3, S4), S3 and S4 will be merged into one disjoint set S3. Now
S1 = {1}, S2 ={2}, S3 = {3, 4} and S5 = {5}.
Find(4) will return representative of set S3. i.e. Find(4) = 3

union-find-1

If we do Union (S1, S2), S1 and S2 will be merged into one disjoint S1. Now
S1 = {1, 2}, S3 = {3, 4} and S5 = {5}.
Find(2) or Find(1) will return representative of set S1. i.e. Find(2) = Find(1) = 1

union-find-2

If we do Union (S3, S1), S3 and S1 will be merged into one disjoint set S3. Now
S3 = {1, 2, 3, 4} and S5 = {5}.

union-find-3

One way of implementing these might be:

function MakeSet(x)
    x.parent = x

function Find(x)
    if x.parent == x
        return x
    else
        return Find(x.parent)

function Union(x, y)
    xRoot = Find(x)
    yRoot = Find(y)
    xRoot.parent = yRoot

*/

// class to represent a disjoint set
class DisjointSet
{
    unordered_map<int, int> parent;

public:

    // perform MakeSet operation
    void makeSet(vector<int> const &universe)
    {
        // create n disjoint sets (one for each item)
        for (int i : universe)
            parent[i] = i;
    }

    // Find the root of the set in which element k belongs
    int Find(int k)
    {
        // if k is root
        if (parent[k] == k)
            return k;

        // recurse for parent until we find root
        return Find(parent[k]);
    }

    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // find root of the sets in which elements
        // x and y belongs
        int x = Find(a);
        int y = Find(b);

        parent[x] = y;
    }
};

void printSets(vector<int> const &universe, DisjointSet &ds)
{
    for (int i : universe)
        cout << ds.Find(i) << " ";

    cout << '\n';
}

// Disjoint-Set Data Structure (Union Find Algorithm)
int main()
{
    // universe of items
    vector<int> universe = { 1, 2, 3, 4, 5 };

    // initialize DisjointSet class
    DisjointSet ds;

    // create singleton set for each element of universe
    ds.makeSet(universe);
    printSets(universe, ds);

    ds.Union(4, 3); // 4 and 3 are in same set
    printSets(universe, ds);

    ds.Union(2, 1); // 1 and 2 are in same set
    printSets(universe, ds);

    ds.Union(1, 3); // 1, 2, 3, 4 are in same set
    printSets(universe, ds);

    return 0;
}
