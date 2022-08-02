#pragma once

#include <iostream>
#include <map>
#include <string>


/* State class for keeping information on the state of other classes.
 * may take any type as a template argument. */

template<typename T>
class State_t {
public:
    /* function to set the value of an element within
     * the `m_state` variable */
    void set(std::string i, T value)
    {
        if (this->m_state.count(i)) {
            this->m_state[i] = value;
        } else {
            this->m_state.insert({i, value});
        }
    }

    /* overrides of [] to retrieve the value of an entry
     * within the `m_state` variable. */
    T operator[](std::string& i)
    {
        if (this->m_state.count(i)) {
            return this->m_state[i];
        } else {
            T new_t = {0};
            this->m_state.insert({i, new_t});
            return new_t;
        }
    }

    T operator[](const char* i)
    {
        std::string n_s = std::string(i);
        if (this->m_state.count(n_s)) {
            return this->m_state[n_s];
        } else {
            T new_t = {0};
            this->m_state.insert({n_s, new_t});
            return new_t;
        }
    }
private:
    /* std::map that contains records that can be accessed */
    std::map<std::string, T> m_state;
};
