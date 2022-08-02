#pragma once

#include <map>
#include <vector>
#include <string>
#include <iostream>


/* Enum for keeping track of what a node on the scope
 * tree actually is */
enum ObjectType_t {
    OBJ_TYPE_FUNC,
    OBJ_TYPE_VAR,
    OBJ_TYPE_STRUCT,
    OBJ_TYPE_UNION,
    OBJ_TYPE_PAREN,
    OBJ_TYPE_NAMESPACE
};

/* Structure for a node on the tree. Each node has a
 * name, a type, an object type, a parent and a vector
 * containing the children of the node, which are of
 * the same type as the parent. */
struct Object_t {
    std::string name;
    std::string type;
    std::vector<std::string> metadata;
    ObjectType_t obj_type;

    Object_t* parent;
    std::vector<Object_t*> children;

    Object_t(std::string name, std::string type, ObjectType_t obj_type);
};

/* Class to handle the tree of `Object_t`s. Provides
 * useful functions to allow manipulation and appending
 * to the tree of `Object_t`s. */
class Scope_t {
public:
    Scope_t();                                      /* constructor */

    void add_child(Object_t obj);                   /* function to add a child to the tree */
    void free();                                    /* function to free all memory allocated */

    /* moves the current object to the object with the name attribute "name". */
    bool traverse(const std::string& name);
    /* moves the current object to the parent of the current object. If the parent
     * is a nullptr, then no move takes place. */
    bool traverse_back();
    /* checks if the current node's children contains a node with the name `name`. */
    bool contains_node(const std::string& name);
    /* checks recursively if the entire tree contains a node with the name `name`. */
    bool has_node(const std::string& name);
    /* checks if the tree contains the node `name` by traversing upwards until
     * the global scope is reached. If the node is found, an Object_t* is returned */
    Object_t* contains_node_up(const std::string& name);
    Object_t* get();                                /* returns `current_object` */
    void print();                                   /* prints the entire tree */
    void push();                                    /* pushes `current_object` to the stack */
    void pop();                                     /* pops an Object_t* from the stack and sets `current_object` */
    void set(Object_t* root);                       /* sets `current_object` to `root` */
    /* collects the names of all objects above `current_object` */
    std::vector<std::string> collect();
private:
    Object_t* current_object;                       /* the current object in use */

    /* recursive function to free all children of `root` */
    void free_tree(Object_t* root);
    /* checks recursively if `root` has a node with the name `name`. */
    bool tree_has_node(Object_t* root, const std::string& name);
    /* recursively prints the contents of the tree starting from `root` */
    void recursive_print(Object_t* root, unsigned long tab_count);
    /* stack of nodes that can be acessed with push() and pop() */
    std::vector<Object_t*> stack;
};
