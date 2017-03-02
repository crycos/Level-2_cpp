#include <iostream>
using namespace std;
#define N 30

int value = N;

#ifndef X
#undef N
#endif


/*
class PersonInfo {
public:
    void   SetNumKids(int personsKids);
    void   IncNumKids();
    int    GetNumKids() const;
private:
    int    numKids;
};

void PersonInfo::SetNumKids(int personsKids) {
    numKids = personsKids;
    return;
}

void PersonInfo::IncNumKids() {
    numKids = numKids + 1;
    return;
}

int PersonInfo::GetNumKids() const {
    return numKids;
}

int main() {
    PersonInfo person1;
    person1.SetNumKids(3);

    /* Your solution goes here  */
  /*  person1.GetNumKids();
    person1.IncNumKids();
    return 0;
*/
