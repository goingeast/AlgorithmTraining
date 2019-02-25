// The API: int read4(char *buf) reads 4 characters at a time from a file.

// The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

// By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

// Note:
// The read function may be called multiple times.

// Example 1: 

// Given buf = "abc"
// read("abc", 1) // returns "a"
// read("abc", 2); // returns "bc"
// read("abc", 1); // returns ""
// Example 2: 

// Given buf = "abc"
// read("abc", 4) // returns "abc"
// read("abc", 1); // returns ""

int readN(char* buf, int n){
    static int readPos = 0;
    static int writePos = 0;
    static char buff[4];

    for(int i = 0; i < n; ++i){
        if( readPos == writePos){
            writePos = read4(buff);
            if(writePos == 0){
                return i;
            }
        }

        buf[i] = buff[readPos++];
    }
    return n;
}