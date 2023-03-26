#include "String.h"

const int String::BaseBufferSize = 32;

String::String() : buffer(nullptr), size() {}

String::String(const String &other) : size(other.size) {

    buffer = new char[other.size + 1];

    for(size_t i = 0; i < other.size; i++) { buffer[i] = other.buffer[i]; }

    buffer[other.size] = '\0';

}

String::String(String &&other) : size(other.size), buffer(nullptr) {

    std::swap(this->buffer, other.buffer);
    other.size = 0;

}

String::String(const char *str) {

    size_t newSize = 0;

    const char* checkSize = str;
    while(*checkSize++ != '\0') { newSize++; }

    buffer = new char[newSize + 1];
    this->size = newSize;

    for(size_t i = 0; i < newSize; i++) { buffer[i] = str[i]; }

    buffer[newSize] = '\0';

}

String::~String() {

    clear();

}

bool String::operator==(const char *other) const {

    if(!buffer || !other) { return false;}
    const char* thisStr = buffer;

    for(size_t i = 0; *other ; i++) {

        if(i > size || *other++ != *thisStr++) { return false; }

    }

    return true;

}

bool String::operator!=(const char *other) const {

    return !(*this == other);

}

bool String::operator==(const String &other) const {

    const char* otherStr = other.buffer;

    return *this == otherStr;

}

String &String::operator+=(const char *other) {

    String str(other);
    *this += str;

    return *this;
}

String &String::operator+=(const String &other) {

    size_t newSize = other.size + size;

    String tmpOther(other);
    String tmpThis(*this);

    delete[] buffer;
    buffer = new char[newSize + 1];
    for(size_t i = 0; i < size; i++) { buffer[i] = tmpThis[i]; }
    for(size_t i = 0; i < other.size; i++) { buffer[i + size] = tmpOther[i]; }

    buffer[newSize] = '\0';
    size = newSize;

    return *this;

}

String &String::operator=(const char *other) {

    if(!other) { return *this; }

    size_t newSize = 0;
    for(; *(other+newSize); newSize++) {}

    clear();

    buffer = new char[newSize + 1];
    size = newSize;

    for(size_t i = 0; i < newSize; i++) { buffer[i] = other[i]; }

    buffer[newSize] = '\0';

    return *this;

}

String &String::operator=(const String &other) {

    if(this == &other) { return *this; }

    *this = (const char*) other.buffer;

    return *this;
}

void String::clear() {

    size = 0;
    delete[] buffer;
    buffer = nullptr;

}

size_t String::length() const { return size; }

String::operator const char*() const { return buffer; }

char& String::operator[](size_t index) { return buffer[index]; }

char String::operator[](size_t index) const { return buffer[index]; }

std::ostream& operator<<(std::ostream& out, const String& str) {

    for(size_t i = 0; i < str.size; i++) { out << str.buffer[i]; }

    return out;
}

std::istream& operator>>(std::istream& in, String& str) {

    size_t strSize = String::BaseBufferSize;
    char* c = new char[strSize + 1];
    int next;
    size_t charCount = 0;

    while ((next = in.get()) && !std::isspace(next)) {

        if(charCount >= strSize) {

            strSize *= 2;
            char* newC = new char[strSize + 1];

            for(int i = 0; c[i] ; i++) { newC[i] = c[i]; }

            delete[] c;
            c = newC;

            newC = nullptr;

        }

        c[charCount++] = next;

    }

    c[charCount] = '\0';

    if(str.buffer) {str.clear();}
    str.size = charCount;
    str.buffer = c;

    return in;
}

String &String::operator=(const char other) {

    String newString = " ";
    newString[0] = other;
    *this = newString;

    return *this;

}




