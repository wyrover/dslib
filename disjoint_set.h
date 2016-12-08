#include "dslib.h"

class GroupSet {
    public:
    GroupSet();
    GroupSet(int num);
    friend class DisjointSet;
    friend GroupSet* combine_groups(GroupSet& A, GroupSet&B);
    friend ostream& operator << (ostream& os, GroupSet& gs);
    private:
        set<int> _groupset;
        int repr;
        bool is_in_group(int elem);
        int get_repr();
};

class DisjointSet {

public:
    vector<GroupSet>  djset;
    int num_sets;

    DisjointSet(vector<int>& elems);
    int findRepr(int n);
    void makeSet(int a_set, int b_set);
    ~DisjointSet();
    friend ostream& operator << (ostream& os, DisjointSet& dj);
};



