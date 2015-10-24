//
//  main.cpp
//  Red_Black_Tree
//
//  Created by Alps on 15/5/13.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
typedef bool rb_tree_color;
const rb_tree_color rb_tree_red = false; //红色为false
const rb_tree_color rb_tree_black = true; //黑色为true

struct rb_tree_node_base{
    typedef rb_tree_color color_type;
    typedef rb_tree_node_base* base_ptr;
    
    color_type color;
    base_ptr parent;
    base_ptr left;
    base_ptr right;
    
    static base_ptr minnum(base_ptr T){
        while(T->left != NULL){
            T = T->left;
        }
        return T;
    }
    
    static base_ptr maxnum(base_ptr T){
        while(T->right != NULL){
            T = T->right;
        }
        return T;
    }
};


struct rb_tree_node : public rb_tree_node_base{
    typedef rb_tree_node* link_type;
    int value_field;
};

class rb_tree{
public:
    typedef rb_tree_node* link_type;
    typedef size_t size_type;
    typedef rb_tree_node_base* base_ptr;
    link_type header;
    size_type node_count;
    
    link_type& root() const{
        return (link_type&) header->parent;
    }
    link_type& leftmost() const{
        return (link_type&) header->left;
    }
    link_type& rightmost() const{
        return (link_type&) header->right;
    }
    
    //取极大值和极小值 用rb_tree_node自带的来实现
    static link_type minnum(link_type T){
        return (link_type)rb_tree_node::minnum(T);
    }
    static link_type maxnum(link_type T){
        return (link_type)rb_tree_node::maxnum(T);
    }
    
protected:
    link_type get_node(){
        return (link_type)malloc(sizeof(struct rb_tree_node));
    }
    
    static link_type& left(base_ptr x){
        return (link_type&)(x->left);
    }
    static link_type& right(base_ptr x){
        return (link_type&)(x->right);
    }
    static link_type& parent(base_ptr x){
        return (link_type&)(x->parent);
    }
    
private:
    void init(){
        header = get_node();
        header->color = rb_tree_red;
        root() = NULL;
        leftmost() = header;
        rightmost() = header;
    }
    
public:
    rb_tree():node_count(0){
        init();
    }
    ~rb_tree(){
//        clear();
//        put_node(header);
    }
private:
    link_type& insert_tree(base_ptr x, base_ptr y, const int v);
    
public:
    link_type insert_equal(const int v){
        link_type y = header;
        link_type x = root();
        while (x != 0) {
            y = x;
            x = (v > x->value_field ? left(x) : right(x));
        }
        return insert_tree(x, y, v);
    }
    pair<link_type, bool> insert_unique(const int v){
        link_type y = header;
        link_type x = root();
        while (x != 0) {
            y = x;
            x = v > x->value_field ? right(x) : left(x);
        }
        link_type z = y;
        if (v < y->value_field) {
            if (y->left == NULL) {
                return make_pair(_insert(x, y, v), true);
            }else{
                z = (link_type)z->parent; //不太懂
            }
            
        }
        
        return make_pair(y, false);
    }
    
    link_type _insert(base_ptr x, base_ptr y, const int v){
        return (link_type)x;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
