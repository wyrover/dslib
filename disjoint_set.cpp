#include "disjoint_set.h"

ostream& operator << (ostream& os, GroupSet& gj)
{
    for (auto&i : gj._groupset) {
        os << i <<"\t";
    }
    return os;
}

int GroupSet::get_repr()
{
    return repr;
}

GroupSet::GroupSet()
{

}

GroupSet::GroupSet(int num)
{
    _groupset.insert(num);
    repr = num;

}

GroupSet* combine_groups(GroupSet& A, GroupSet& B)
{
    GroupSet* union_set = new GroupSet();
    union_set->_groupset = A._groupset;
    union_set->_groupset.insert(B._groupset.begin(),
                                B._groupset.end());
    union_set->repr = *(union_set->_groupset.rbegin());
    return union_set;
}

bool GroupSet::is_in_group(int elem)
{

    if (_groupset.count(elem)) {
        // x is in the set, count is 1
        return true;
    } else {
        // count zero, i.e. x not in the set
        return false;
    }
}

ostream& operator << (ostream& os, DisjointSet& dj)
{
    for (auto&i : dj.djset) {
        os << i;
        os <<endl;
    }

    return os;
}

DisjointSet::DisjointSet(vector<int>& elems)
{
    num_sets = elems.size();

/*
    try {
        djset = new GroupSet[v];
    } catch(bad_alloc&) {
        cout << "bad_alloc exception handled.\n";
    } catch (exception &e) {
        cout << "Exception handled.\n" <<e.what();
    } catch(...) {
        printf("default exception.\n");
    }
*/
    for (auto&i : elems) {
        djset.push_back(*(new GroupSet(i)));
    }

}


DisjointSet::~DisjointSet()
{

}

int DisjointSet::findRepr(int v)
{


    return 0;
}

void DisjointSet::makeSet(int a, int b)
{

    vector<GroupSet>:: iterator it_1;
    vector<GroupSet>:: iterator it_2;
    int repr_A = 0, repr_B=0;

    for (it_1 = djset.begin(); it_1!= djset.end(); ++it_1) {
        if (it_1->is_in_group(a)) {
            repr_A = it_1->get_repr();
            break;
        }
    }

    for (it_2 = djset.begin(); it_2!= djset.end(); ++it_2) {
        if (it_2->is_in_group(b)) {
            repr_B = it_2->get_repr();
            break;
        }
    }

    if(repr_A != repr_B) {
        /* Store second set in a temp var since we lose iterator after an erase
         * operation */
        GroupSet temp_B = *it_2;
        djset.erase(it_2);
        GroupSet* union_set = combine_groups(*it_1, temp_B);
        vector<GroupSet>::iterator it = djset.erase(it_1);
        djset.insert(it, *union_set);
        num_sets--;
    } else {
        cout << a << "  " << b <<" are already in the same set" <<endl;
    }
}

