#ifndef EXTRACT_HPP
#define EXTRACT_HPP

struct datai{
    int id;
    int duration;
};

struct datai* extract_data(const char* str);

#endif // EXTRACT_HPP
