#include <iostream>
#include <initializer_list>

class String {

	char* buffer;
	size_t size;

    static const int BaseBufferSize;

    public:

	String();

	String(String&& other);

	String(const String& other);

    String(const char* str);

	~String();

	size_t length() const;

    operator const char* () const;

	String& operator+=(const char* other);

    String& operator+=(const String& other);

    char& operator[](size_t index);

    char operator[](size_t index) const;

    bool operator==(const char* other) const;

    bool operator==(const String& other) const;

	String& operator=(const char* other);

	String& operator=(const String& other);

    void clear();

	friend std::ostream& operator<<(std::ostream& out, const String& str);

	friend std::istream& operator>>(std::istream& in, String& str);

};