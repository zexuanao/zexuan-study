#ifndef DMA_H
#define DMA_H

#include <iostream>

// Base Class Using DMA
class baseDMA {
private:
    char * label;
    int rating;

public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
};

// Derived class without DMA
// No destructor needed
// Uses implicit copy constructor
// Uses implicit assignment operator
class lacksDMA : public baseDMA {
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];

public:
    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char *c, const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);
};

// Class with DMA
// Derived class hasDMA
class hasDMA : public baseDMA {
private:
    char * style;

public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};

#endif
