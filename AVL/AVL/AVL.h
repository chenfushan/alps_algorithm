//
//  AVL.h
//  AVL
//
//  Created by Alps on 14-8-7.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#ifndef AVL_AVL_h
#define AVL_AVL_h

#define ElementType int

struct TreeNode;
typedef TreeNode* AVL;
typedef TreeNode* Position;

Position Find(ElementType key, AVL A);
Position FindMax(AVL A);
Position FindMin(AVL A);

AVL Insert(ElementType key, AVL A);
AVL Delete(ElementType key, AVL A);

struct TreeNode{
    ElementType element;
    AVL left;
    AVL right;
    int height;
};


#endif
