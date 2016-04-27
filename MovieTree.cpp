#include "MovieTree.h"
#include <sstream>
#include <iostream>
#include <istream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{

MovieNode* tmp = root;
MovieNode* nnode = new MovieNode(ranking, title, releaseYear, quantity);
nnode->leftChild = NULL;
nnode->rightChild = NULL;
nnode->parent = NULL;
MovieNode* parent = NULL;



        while (tmp != NULL)
            {
                parent = tmp;
                if(nnode->title < tmp->title)
                {
                 tmp = tmp->leftChild;
                }
                else
                {
                 tmp = tmp->rightChild;
                }
            }

        if (parent == NULL)
                {
                        root = nnode;
                }
        else if(nnode->title < parent->title)
                {
                        parent->leftChild = nnode;
                        nnode->parent = parent;
                }
            else
                {
                        parent->rightChild = nnode;
                        nnode->parent = parent;
                }
return;
        }

MovieTree::MovieTree()
{
root = NULL;
}

MovieTree::~MovieTree()
{
    //dtor
}

void MovieTree::printMovieInventory(MovieNode* node)
{   if (node == NULL)
        return;
        printMovieInventory(node->leftChild);
    cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
        printMovieInventory(node->rightChild);
}

void MovieTree::printMovieInventory()
{
printMovieInventory(root);
}

void MovieTree::findMovie(std::string title)
{
MovieNode* tmp;
tmp = root;

while (tmp != NULL)
{
    if (tmp->title > title )
        {
        tmp = tmp->leftChild;
        }
    else if (tmp->title < title)
        {
        tmp = tmp->rightChild;
        }
    else if (tmp->title == title)
        {
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << tmp->ranking << endl;
        cout << "Title:" << tmp->title << endl;
        cout << "Year:" << tmp->year << endl;
        cout << "Quantity:" << tmp->quantity << endl;
        return;
        }
    else
        {
        cout << "Movie not found." << endl;
        return;
        }
}
return;
}

void MovieTree::rentMovie(std::string title)
{
MovieNode* tmp = root;
while (tmp != NULL)
{
    if (tmp->title > title)
        {
        tmp = tmp->leftChild;
        }
    else if (tmp->title < title)
        {
        tmp = tmp->rightChild;
        }
    else if (tmp->title == title)
    {
            if (tmp->quantity > 0)
            {
            cout << "Movie has been rented." << endl;
            cout << "Movie Info:" << endl;
            cout << "===========" << endl;
            cout << "Ranking:" << tmp->ranking << endl;
            cout << "Title:" << tmp->title << endl;
            cout << "Year:" << tmp->year << endl;
            cout << "Quantity:" << tmp->quantity << endl;
            tmp->quantity = tmp->quantity-1;
            return;
            }
            else
            {
            cout << "Movie out of stock." << endl;
            }
    }
    else
        {
        cout << "Movie not found." << endl;
        return;
        }
}
return;
}

MovieNode* MovieTree::treeMinimum(MovieNode *node)
{
  while(node->leftChild != NULL)
        node = node->leftChild;

    return node;
}
void MovieTree::deleteMovieNode(std::string title)
{
MovieNode* tmp = root;
while (tmp != NULL)
{
    if (tmp->title > title)
        {
        tmp = tmp->leftChild;
        }
    else if (tmp->title < title)
        {
        tmp = tmp->rightChild;
        }
                    else if (tmp->title == title)
                    {
                           // Case 1: No Child
                            if(tmp->leftChild == NULL && tmp->rightChild == NULL)
                           {
                               if ((tmp->parent)->leftChild == tmp)
                                {
                                (tmp->parent)->leftChild = NULL;
                                 delete tmp;
                                 return;
                                }
                               else
                               {
                                (tmp->parent)->rightChild = NULL;
                                 delete tmp;
                                 return;
                                 }
                           }
                           // Case 2: one child
                            if((tmp->leftChild == NULL && tmp->rightChild != NULL) || (tmp->leftChild != NULL && tmp->rightChild == NULL))
                            {
                             // Right Leaf Present, No Left Leaf
                                if(tmp->leftChild == NULL && tmp->rightChild != NULL)
                                {
                                // If child is left child
                                if( (tmp->parent)->leftChild == tmp)
                                {
                                    // then tmp left tree becomes parent left tree
                                    // and delete tmp
                                     (tmp->parent)->leftChild=tmp->rightChild;
                                      delete tmp;
                                      cout<<"removed"<<endl;
                                      return;
                                }

                                else
                                {
                                    // then tmp right tree becomes parents right tree
                                    // and delete tmp
                                   (tmp->parent)->rightChild = tmp->rightChild;
                                    delete tmp;
                                    cout<<"removed"<<endl;
                                    return;
                                }
                            }
                            else // Left Leaf Present, No Right Leaf Present
                            {
                                if ((tmp->parent)->leftChild == tmp)
                                {
                                    (tmp->parent)->leftChild=tmp->leftChild;
                                    delete tmp;
                                    cout<<"removed"<<endl;
                                    return;
                                }
                                else
                                {
                                    (tmp->parent)->rightChild=tmp->leftChild;
                                    delete tmp;
                                    cout<<"removed"<<endl;
                                    return;
                                }
                            }

                            }
                            //Case 3: two childs
                            if(tmp->leftChild != NULL && tmp->rightChild != NULL)
                                    {

                                    }


                  }
}
return;
}



void MovieTree::countMovieNodes(MovieNode *node, int *c)
{
    int tmp;
    if (node == NULL)
        return;

        countMovieNodes(node->leftChild, c);
        tmp = *c;
        tmp++;
        *c = tmp;
        countMovieNodes(node->rightChild, c);

}

void MovieTree::DeleteAll(MovieNode* node)
{

 /* if(root == NULL)
     return root;
  else if(title < root->title)
  deleteMovieNode(root->left);
  else if(title > root->title)
  deleteMovie(root->right);
*/
}

int MovieTree::countMovieNodes()
{
int counter = 0;
int *counterptr = &counter;

countMovieNodes(root, counterptr);

return *counterptr;
}
