#ifndef TREE_H
#define TREE_H
 
#include "TreeNode.h"
#include <iostream>
template< typename T >
class Tree
{
    template< typename Type >
    friend Type max(const Type &, const Type &);
 
public:
    Tree();
    ~Tree();
 
    void insert(const T &);
    void remove(const T &);
    T get();
    bool empty();
 
private:
    TreeNode< T > *_root;
 
    void insert_helper(TreeNode< T > **, const T &);
    void remove_helper(TreeNode< T > **, const T &);

    void delete_helper(TreeNode< T > *);

};
 
template< typename T >
Tree< T >::Tree():
_root(0)
{
}
template<typename T>
bool Tree<T>::empty(){
    if( _root->get_data() != nullptr) return true;
    return false;
}
template <typename T>
T Tree<T>::get(){
    return _root->get_data();
}
template< typename T >
Tree< T >::~Tree()
{
    delete_helper(_root);
}
 
template< typename T >
void Tree< T >::delete_helper(TreeNode< T > *node)
{
    if (node != 0)
    {
        delete_helper(node->_left);
        delete_helper(node->_right);
 
        delete node;
    }
}
 
template< typename T >
void Tree< T >::insert(const T &data)
{
    insert_helper(&_root, data);
}
 
template< typename T >
void Tree< T >::insert_helper(TreeNode< T > **node, const T &data)
{
    if (*node == 0)
        *node = new TreeNode< T > (data);
    else
    {
        if ((*node)->_data > data)
            insert_helper(&((*node)->_left), data);
        else
        {
            if ((*node)->_data < data)
                insert_helper(&((*node)->_right), data);
        }
    }
}
 
template< typename T >
void Tree< T >::remove(const T &data)
{
    remove_helper(&_root, data);
}
 
template< typename T >
void Tree< T >::remove_helper(TreeNode< T > **node, const T &data)
{
    if ((*node)->_data == data)
    {
        TreeNode< T > *del_node = *node;
 
        if ((*node)->_left == 0 && (*node)->_right == 0)
        {
            *node = 0;
 
            delete del_node;
        }
        else
        {
            if ((*node)->_left == 0)
            {
                *node = (*node)->_right;
 
                delete del_node;
            }
            else
            {
                if ((*node)->_right == 0)
                {
                    *node = (*node)->_left;
 
                    delete del_node;
                }
                else
                {
                    TreeNode< T > *p = *node;
                    TreeNode< T > *i = (*node)->_left;
 
                    while (i->_right != 0)
                    {
                        p = i;
                        i = i->_right;
                    }
 
                    *node = i;
                    p->_right = i->_left;
                    i->_right = del_node->_right;
                    i->_left = p;
 
                    delete del_node;
                }
            }
        }
    }
    else
    {
        if ((*node)->_data > data)
            remove_helper(&((*node)->_left), data);
        else
        {
            if ((*node)->_data < data)
                remove_helper(&((*node)->_right), data);
        }
    }
}
 

template< typename Type >
Type max(const Type &left, const Type &right)
{
    return left > right ? left : right;
}
 
#endif