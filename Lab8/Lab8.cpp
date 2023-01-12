#include <iostream>
using namespace std;
struct tnode
{
    int field;
    struct tnode* left;
    struct tnode* right;
};
void treeprint(tnode* tree)
{
    if (tree != NULL)
    {
        treeprint(tree->left);
        cout << tree->field << " ";
        treeprint(tree->right);
    }
}
struct tnode* addnode(int x, tnode* tree)
{
    if (tree == NULL)
    {
        tree = new tnode;
        tree->field = x;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
        if (x < tree->field)
            tree->left = addnode(x, tree->left);
        else
            tree->right = addnode(x, tree->right);
    return(tree);
}
int main()
{
    struct tnode* root = 0;
    int a;
    for (int i = 0; i < 6; i++)
    {
        cout << "Input tnode " << i + 1 << " : ";
        cin >> a;
        root = addnode(a, root);
    }
    treeprint(root);
    cin.get();
    return 0;
}
