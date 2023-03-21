#include "String.h"

const int String::BaseBufferSize = 32;

String::String() : buffer(nullptr), size() {}

String::String(const String &other) : size(other.size) {

    buffer = new char[other.size];

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
    while(*++checkSize) { newSize++; }

    buffer = new char[++newSize];
    this->size = newSize;

    for(size_t i = 0; i < newSize; i++) { buffer[i] = str[i]; }

    buffer[newSize] = '\0';

}

String::~String() {

    size = 0;
    delete[] buffer;

}

bool String::operator==(const char *other) const {

    const char* thisStr = buffer;

    for(size_t i = 0; *other ; i++) {

        if(i > size || *other++ != *thisStr++) { return false; }

    }

    return true;

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

    tmpThis[size] = ' '; //delete null-termination char

    delete[] buffer;
    buffer = new char[newSize];

    for(size_t i = 0; i < size; i++) { buffer[i] = tmpThis[i]; }
    for(size_t i = size; i < newSize; i++) { buffer[i] = tmpOther[i - size]; }

    buffer[newSize] = '\0';
    size = newSize;

    return *this;

}

String &String::operator=(const char *other) {

    size_t newSize = 0;
    for(; *(other+newSize); newSize++) {}

    clear();

    if(newSize == 0) { return *this; }

    buffer = new char[newSize];
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

    char* c = new char[String::BaseBufferSize];
    char extract[2];
    size_t strSize = String::BaseBufferSize;
    size_t charCount = 0;

    while (in.get(extract, 2)) {

        if(*c == ' ') { break; }
        if(charCount >= strSize) {

            strSize *= 2;
            char* newC = new char[strSize];

            for(int i = 0; c[i] ; i++) { newC[i] = c[i]; }

            delete[] c;
            c = newC;

            newC = nullptr;

        }

        c[charCount] = extract[0];
        charCount++;
    }

    c[charCount] = '\0';

    str.clear();
    str.size = charCount;
    str.buffer = c;

    return in;
}