#include <vector>
using namespace std;
#include "BST.h"

int main()
{
    int adding[] = {50, 25, 75, 12, 40, 60, 80, 5, 18, 30, 45, 55, 80};
    BST b;

    for (int i = 0; i < 13; i++)
    {
        b.add(adding[i]);
    }

    b.ancestors(45);

    return 0;
}
