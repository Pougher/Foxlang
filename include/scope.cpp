#include <scope.hpp>

Object_t::Object_t(std::string name, std::string type, ObjectType_t obj_type)
{
    this->name = name;
    this->type = type;
    this->obj_type = obj_type;
}

Scope_t::Scope_t()
{
    Object_t* new_obj = new Object_t("GLOBAL", "NONE", ObjectType_t::OBJ_TYPE_STRUCT);
    new_obj->parent = nullptr;
    this->current_object = new_obj;
}

void Scope_t::add_child(Object_t obj)
{
    Object_t* new_obj = new Object_t(obj.name, obj.type, obj.obj_type);
    new_obj->children = obj.children;
    new_obj->parent = this->current_object;
    new_obj->metadata = obj.metadata;

    this->current_object->children.push_back(new_obj);
}

bool Scope_t::traverse(const std::string& name)
{
    for (auto child : this->current_object->children) {
        if (child->name == name) {
            this->current_object = child;
            return true;
        }
    }
    return false;
}

bool Scope_t::traverse_back()
{
    if (this->current_object->parent != nullptr) {
        this->current_object = this->current_object->parent;
        return true;
    }

    return false;
}

void Scope_t::free()
{
    while (this->traverse_back()) {} // move back to the root node
    this->free_tree(this->current_object);
    delete this->current_object;
}

void Scope_t::free_tree(Object_t* root)
{
    for (auto i : root->children) {
        this->free_tree(i);
        delete i;
    }
}

bool Scope_t::contains_node(const std::string& name)
{
    for (auto i : this->current_object->children) {
        if (i->name == name) return true;
    }

    return false;
}

bool Scope_t::has_node(const std::string& name)
{
    Object_t* head = this->current_object;

    while (this->traverse_back()) {}
    bool result = this->tree_has_node(this->current_object, name);

    this->current_object = head;

    return result;
}

bool Scope_t::tree_has_node(Object_t* root, const std::string& name)
{
    for (auto i : root->children) {
        if (i->name == name) {
            return true;
        } else {
            if (this->tree_has_node(i, name)) {
                return true;
            }
        }
    }
    return false;
}

Object_t* Scope_t::get()
{
    return this->current_object;
}

Object_t* Scope_t::contains_node_up(const std::string& name)
{
    Object_t* head = this->current_object;
    Object_t* found = nullptr;
    
    do {
        for (auto obj : head->children) {
            if (obj->name == name) {
                found = obj;
                break;
            }
        }
        if (found != nullptr) break;
        head = head->parent;
    } while (head != nullptr);
    return found;
}

void Scope_t::print()
{
    Object_t* old_head = this->current_object;
     while (this->traverse_back()) {}

    this->recursive_print(this->current_object, 0);

    this->current_object = old_head;
}

void Scope_t::recursive_print(Object_t* root, unsigned long tab_count)
{
    if (root->children.size() > 0) {
        std::cout << std::string(tab_count * 4, ' ') << root->name << " | " << root->type << " | " << root->obj_type << std::endl;
        for (auto x : root->children) {
            this->recursive_print(x, tab_count + 1);
        }
    } else {
        std::cout << std::string(tab_count * 4, ' ') << root->name << " | " << root->type << " | " << root->obj_type << std::endl;
    }
}

std::vector<std::string> Scope_t::collect()
{
    std::vector<std::string> ret;
    Object_t* head = this->current_object;
    
    do {
        for (auto obj : head->children) {
            ret.push_back(obj->name);
        }
        if (head->parent != nullptr) head = head->parent;
    } while(head->parent != nullptr);
    return ret;
}

void Scope_t::push()
{
    this->stack.push_back(this->current_object);
}

void Scope_t::pop()
{
    this->current_object = this->stack[this->stack.size()-1];
    this->stack.pop_back();
}

void Scope_t::set(Object_t* set)
{
    this->current_object = set;
}